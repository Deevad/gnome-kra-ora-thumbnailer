/*
 * Copyright (C) 2013 Bastien Nocera <hadess@hadess.net>
 *
 * Authors: Bastien Nocera <hadess@hadess.net>
 *
 *          DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 * TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 * 0. You just DO WHAT THE FUCK YOU WANT TO.
 *
 */

#include <string.h>
#include <glib.h>

#include "gnome-thumbnailer-skeleton.h"

#include <archive.h>
#include <archive_entry.h>

static char *
file_get_zipped_contents (const char   *filename,
			  GCompareFunc  func,
			  gpointer      user_data,
			  gsize        *length)
{
	struct archive *a;
	struct archive_entry *entry;
	char *ret = NULL;
	int r;

	*length = 0;

	a = archive_read_new ();
	archive_read_support_format_zip (a);
	r = archive_read_open_filename (a, filename, 10240);
	if (r != ARCHIVE_OK) {
		g_print ("Failed to open archive %s\n", filename);
		return NULL;
	}

	while (1) {
		const char *name;

		r = archive_read_next_header(a, &entry);

		if (r != ARCHIVE_OK) {
			if (r != ARCHIVE_EOF && r == ARCHIVE_FATAL)
				g_warning ("Fatal error handling archive: %s", archive_error_string (a));
			break;
		}

		name = archive_entry_pathname (entry);
		if (func (name, user_data) == 0) {
			size_t size = archive_entry_size (entry);
			char *buf;
			ssize_t read;

			buf = g_malloc (size);
			read = archive_read_data (a, buf, size);
			if (read <= 0) {
				g_free (buf);
				if (read < 0)
					g_warning ("Fatal error reading '%s' in archive: %s", name, archive_error_string (a));
				else
					g_warning ("Read an empty file from the archive");
			} else {
				ret = buf;
				*length = size;
			}
			break;
		}
		archive_read_data_skip(a);
	}
	archive_read_free(a);

	return ret;
}

char *
file_to_data (const char  *path,
	      gsize       *ret_length,
	      GError     **error)
{
	char *data;
	gsize length;

	/* Look for the cover in the metafile */
	data = file_get_zipped_contents (path, (GCompareFunc) g_strcmp0, "preview.png", &length);
	if (data == NULL) {
		g_set_error_literal (error, G_IO_ERROR, G_IO_ERROR_FAILED, "Could not find preview.png file");
		return NULL;
	}

	*ret_length = length;

	return data;
}
