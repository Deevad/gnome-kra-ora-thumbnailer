/*
 * Copyright (C) 2013 Bastien Nocera <hadess@hadess.net>
 *
 * Authors: Bastien Nocera <hadess@hadess.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include "gnome-thumbnailer-skeleton.h"

#ifndef THUMBNAILER_USAGE
#error "THUMBNAILER_USAGE must be set"
#endif

static int output_size = 256;
static gboolean g_fatal_warnings = FALSE;
static char **filenames = NULL;

static const GOptionEntry entries[] = {
	{ "size", 's', 0, G_OPTION_ARG_INT, &output_size, "Size of the thumbnail in pixels", NULL },
	{"g-fatal-warnings", 0, 0, G_OPTION_ARG_NONE, &g_fatal_warnings, "Make all warnings fatal", NULL},
	{ G_OPTION_REMAINING, '\0', 0, G_OPTION_ARG_FILENAME_ARRAY, &filenames, NULL, "[INPUT FILE] [OUTPUT FILE]" },
	{ NULL }
};

int main (int argc, char **argv)
{
	char *input_filename;
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	GOptionContext *context;
	GFile *input;
	const char *output;

#ifdef THUMBNAILER_RETURNS_PIXBUF
	/* Nothing */
#elif THUMBNAILER_RETURNS_DATA
	char *data = NULL;
	gsize length;
#endif

	g_type_init ();

	/* Options parsing */
	context = g_option_context_new (THUMBNAILER_USAGE);
	g_option_context_add_main_entries (context, entries, NULL);

	if (g_option_context_parse (context, &argc, &argv, &error) == FALSE) {
		g_warning ("Couldn't parse command-line options: %s", error->message);
		g_error_free (error);
		return 1;
	}

	/* Set fatal warnings if required */
	if (g_fatal_warnings) {
		GLogLevelFlags fatal_mask;

		fatal_mask = g_log_set_always_fatal (G_LOG_FATAL_MASK);
		fatal_mask |= G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL;
		g_log_set_always_fatal (fatal_mask);
	}

	if (filenames == NULL || g_strv_length (filenames) != 2) {
		g_print ("Expects an input and an output file\n");
		return 1;
	}

	input = g_file_new_for_commandline_arg (filenames[0]);
	input_filename = g_file_get_path (input);
	g_object_unref (input);

	output = filenames[1];

#ifdef THUMBNAILER_RETURNS_PIXBUF
	pixbuf = file_to_pixbuf (input_filename, &error);
#elif THUMBNAILER_RETURNS_DATA
	data = file_to_data (input_filename, &length, &error);
	if (data) {
		GInputStream *mem_stream;

		mem_stream = g_memory_input_stream_new_from_data (data, length, g_free);
		pixbuf = gdk_pixbuf_new_from_stream_at_scale (mem_stream, output_size, -1, TRUE, NULL, &error);
		g_object_unref (mem_stream);
	} else {
		pixbuf = NULL;
	}
#else
#error "One of THUMBNAILER_RETURNS_PIXBUF or THUMBNAILER_RETURNS_DATA must be set"
#endif
	g_free (input_filename);

	if (!pixbuf) {
		g_warning ("Could not thumbnail '%s': %s", filenames[0], error->message);
		g_error_free (error);
		g_strfreev (filenames);
		return 1;
	}

	if (gdk_pixbuf_save (pixbuf, output, "png", &error, NULL) == FALSE) {
		g_warning ("Couldn't save the thumbnail '%s' for file '%s': %s", output, filenames[0], error->message);
		g_error_free (error);
		return 1;
	}

	g_object_unref (pixbuf);

	return 0;
}
