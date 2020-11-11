AM_CPPFLAGS = -I$(top_srcdir)/include

AM_CFLAGS = $(GLOBAL_CFLAGS) $(libusb_CFLAGS)
AM_LDFLAGS = 	$(libplist_LIBS)

bin_PROGRAMS = idevicerestore 

idevicerestore_SOURCES = idevicerestore.c
idevicerestore_CFLAGS = $(AM_CFLAGS)
idevicerestore_LDFLAGS = $(AM_LDFLAGS)
idevicerestore_LDADD = $(top_srcdir)/src/libidevicerestore-1.0.la
