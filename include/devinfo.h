

#ifndef IDEVICERESTORE_DEVINFO_H
#define IDEVICERESTORE_DEVINFO_H

#ifdef __cplusplus
extern "C" {
#endif


#include "libirecovery.h"
#include <plist/plist.h>

int devinfo_parse_plist(plist_t node, struct irecv_device_info* info);
int devinfo_parse_plist_file(const char* path, struct irecv_device_info* info);

#ifdef __cplusplus
}
#endif


#endif
