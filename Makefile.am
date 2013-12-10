
bin_PROGRAMS = gnome-openraster-thumbnailer gnome-kra-thumbnailer

gnome_openraster_thumbnailer_SOURCES = gnome-openraster-thumbnailer.c gnome-thumbnailer-skeleton.c gnome-thumbnailer-skeleton.h
gnome_openraster_thumbnailer_CPPFLAGS =			\
	$(THUMBNAILER_CFLAGS)				\
	-DTHUMBNAILER_RETURNS_DATA			\
	-DTHUMBNAILER_USAGE="\"Thumbnail OpenRaster images\""	\
	$(WARN_CFLAGS)
gnome_openraster_thumbnailer_LDADD = $(THUMBNAILER_LIBS)

gnome_kra_thumbnailer_SOURCES = gnome-kra-thumbnailer.c gnome-thumbnailer-skeleton.c gnome-thumbnailer-skeleton.h
gnome_kra_thumbnailer_CPPFLAGS =			\
	$(THUMBNAILER_CFLAGS)				\
	-DTHUMBNAILER_RETURNS_DATA			\
	-DTHUMBNAILER_USAGE="\"Thumbnail Krita images\""\
	$(WARN_CFLAGS)
gnome_kra_thumbnailer_LDADD = $(THUMBNAILER_LIBS)

thumbnailerdir = $(datadir)/thumbnailers/
thumbnailer_DATA = gnome-openraster-thumbnailer.thumbnailer gnome-kra-thumbnailer.thumbnailer
gnome-openraster-thumbnailer.thumbnailer: gnome-openraster-thumbnailer.thumbnailer.in Makefile
	$(AM_V_GEN) $(SED) -e "s|\@bindir\@|$(bindir)|" $< > $@
gnome-kra-thumbnailer.thumbnailer: gnome-kra-thumbnailer.thumbnailer.in Makefile
	$(AM_V_GEN) $(SED) -e "s|\@bindir\@|$(bindir)|" $< > $@

EXTRA_DIST = gnome-openraster-thumbnailer.thumbnailer.in gnome-kra-thumbnailer.thumbnailer.in AUTHORS COPYING README

CLEANFILES = $(thumbnailer_DATA)
