AM_CFLAGS =	                   \
	$(GLOBAL_CFLAGS)           \
	$(LFS_CFLAGS)              \
	$(libirecovery_CFLAGS)     \
	$(libimobiledevice_CFLAGS) \
	$(libplist_CFLAGS)         \
	$(libzip_CFLAGS)           \
	$(zlib_CFLAGS)             \
	$(openssl_CFLAGS)          \
	$(libcurl_CFLAGS)					 \
	-I$(top_srcdir)/include

AM_LDFLAGS =\
	$(AC_LDFLAGS)              \
	$(libirecovery_LIBS)       \
	$(libimobiledevice_LIBS)   \
	$(libplist_LIBS)           \
	$(libzip_LIBS)             \
	$(zlib_LIBS)               \
	$(openssl_LIBS)            \
	$(libcurl_LIBS)

AM_LDADD = $(AC_LDADD)

lib_LTLIBRARIES = libidevicerestore-1.0.la

libidevicerestore_1_0_la_SOURCES = common.c tss.c fls.c mbn.c img3.c img4.c ftab.c ipsw.c normal.c dfu.c recovery.c restore.c asr.c fdr.c limera1n.c download.c locking.c socket.c thread.c jsmn.c json_plist.c
libidevicerestore_1_0_la_CFLAGS = $(AM_CFLAGS)
libidevicerestore_1_0_la_LDFLAGS = $(AM_LDFLAGS)
libidevicerestore_1_0_la_LIBADD = $(AM_LDADD)
