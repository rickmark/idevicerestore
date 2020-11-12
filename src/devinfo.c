#include "devinfo.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT_NODE_TYPE_OR_RETURN(node, type)  if (!_PLIST_IS_TYPE(node, type)) { return -2; }

static const uint8_t hextable[] = {
   ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // faster for most modern processors,
   ['A'] = 10, 11, 12, 13, 14, 15,       // for the space conscious, reduce to
   ['a'] = 10, 11, 12, 13, 14, 15        // signed char.
};

uint64_t hexDecode(const char* input) {
  uint64_t result = 0;
  while (*input && result >= 0) {
     result = (result << 4) | hextable[(uint8_t)*input++];
  }

  return result;
}

int devinfo_parse_plist(plist_t node, struct irecv_device_info* info) {
  uint64_t int_val;
  if (!PLIST_IS_DICT(node)) { return -1; }
  if (info == NULL) { return -2;}

  plist_t cpid = plist_dict_get_item(node, "CPID");
  ASSERT_NODE_TYPE_OR_RETURN(cpid, UINT)
  plist_get_uint_val(cpid, &int_val);
  info->cpid = (unsigned int)int_val;

  plist_t cprv = plist_dict_get_item(node, "CPRV");
  ASSERT_NODE_TYPE_OR_RETURN(cprv, UINT)
  plist_get_uint_val(cprv, &int_val);
  info->cprv = (unsigned int)int_val;

  plist_t cpfm = plist_dict_get_item(node, "CPFM");
  ASSERT_NODE_TYPE_OR_RETURN(cpfm, UINT)
  plist_get_uint_val(cpfm, &int_val);
  info->cpfm = (unsigned int)int_val;

  plist_t scep = plist_dict_get_item(node, "SCEP");
  ASSERT_NODE_TYPE_OR_RETURN(scep, UINT)
  plist_get_uint_val(scep, &int_val);
  info->scep = (unsigned int)int_val;

  plist_t bdid = plist_dict_get_item(node, "BDID");
  ASSERT_NODE_TYPE_OR_RETURN(bdid, UINT)
  plist_get_uint_val(bdid, &int_val);
  info->bdid = (unsigned int)int_val;

  plist_t ecid = plist_dict_get_item(node, "ECID");
  ASSERT_NODE_TYPE_OR_RETURN(ecid, STRING)
  char* ecidString;
  plist_get_string_val(ecid, &ecidString);
  info->ecid = hexDecode(ecidString);

  plist_t srtg = plist_dict_get_item(node, "SRTG");
  ASSERT_NODE_TYPE_OR_RETURN(srtg, STRING)
  plist_get_string_val(srtg, &info->serial_string);

  plist_t apnonce = plist_dict_get_item(node, "APNonce");
  ASSERT_NODE_TYPE_OR_RETURN(apnonce, DATA)
  plist_get_data_val(apnonce, (char**)&info->ap_nonce, &int_val);
  info->ap_nonce_size = (unsigned int)int_val;

  plist_t sepnonce = plist_dict_get_item(node, "SEPNonce");
  ASSERT_NODE_TYPE_OR_RETURN(sepnonce, DATA)
  plist_get_data_val(apnonce, (char**)&info->sep_nonce, &int_val);
  info->sep_nonce_size = (unsigned int)int_val;

  return 0;
}


int devinfo_parse_plist_file(const char* path, struct irecv_device_info* info) {
  if ((path == NULL) || (info == NULL)) return -1;

  plist_t device_plist = NULL;
  struct stat infoFileStat;
  int infoFile = open(path, O_RDONLY);
  fstat(infoFile, &infoFileStat);
  void* infoBuffer = malloc(infoFileStat.st_size);
  if (infoBuffer == NULL) {
    fprintf(stderr, "could not allocate memory\n");
    return -2;
  }

  if (read(infoFile, infoBuffer, infoFileStat.st_size) != infoFileStat.st_size) {
    fprintf(stderr, "unable to read info file\n");
    return -3;
  }

  plist_from_memory(infoBuffer, infoFileStat.st_size, &device_plist);
  free(infoBuffer);
  if (device_plist == NULL) {
    fprintf(stderr, "unable to parse info file plist\n");
    return -4;
  }

  int result = devinfo_parse_plist(device_plist, info);
  plist_free(device_plist);

  return result;
}
