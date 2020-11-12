AM_CPPFLAGS = -I$(top_srcdir)/include

AM_CXXFLAGS = $(GLOBAL_CFLAGS) $(libusb_CFLAGS)
AM_LDFLAGS = 	$(libplist_LIBS)

bin_PROGRAMS = idevicerestore_tests

idevicerestore_tests_SOURCES = idevicerestore_tests.cpp test_img4.cpp test_devinfo.cpp
idevicerestore_tests_CXXFLAGS = -std=c++14 $(AM_CFLAGS)
idevicerestore_tests_LDFLAGS = $(AM_LDFLAGS)
idevicerestore_tests_LDADD = $(top_srcdir)/src/libidevicerestore-1.0.la

TESTS = idevicerestore_tests
