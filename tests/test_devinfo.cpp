#include "catch.hpp"
#include "idevicerestore.h"
#include "img4.h"
#include "devinfo.h"

TEST_CASE( "devinfo_parse_plist_file()", "[devinfo]" ) {
  struct irecv_device_info info;
  memset(&info, 0, sizeof(struct irecv_device_info));

  REQUIRE(devinfo_parse_plist_file("./data/devinfo.plist", &info) == 0);
  REQUIRE(info.cpid == 0x8027);
  REQUIRE(info.cprv == 0x01);
  REQUIRE(info.cpfm == 0x03);
  REQUIRE(info.scep == 0x01);
  REQUIRE(info.bdid == 0x42);
  REQUIRE(info.ecid == 0x1F1F1F1FE0E0E0E0);
  REQUIRE(strlen(info.serial_string) > 10);
  REQUIRE(info.ap_nonce_size >= 32);
  REQUIRE(info.sep_nonce_size >= 32);
}
