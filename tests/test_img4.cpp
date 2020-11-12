#include "catch.hpp"
#include "idevicerestore.h"
#include "img4.h"

TEST_CASE( "img4_get_type(invalid)", "[img4]" ) {
  REQUIRE(img4_get_type("./data/external/iBridge2,1,iBridge2,10,iBridge2,12,iBridge2,14,iBridge2,15,iBridge2,16,iBridge2,19,iBridge2,20,iBridge2,21,iBridge2,22,iBridge2,3,iBridge2,4,iBridge2,5,iBridge2,6,iBridge2,7,iBridge2,8_4.6_17P6610_Restore/BuildManifest.plist") == kImg4Invalid);
}

TEST_CASE( "img4_get_type(im4m)", "[img4]" ) {
  REQUIRE(img4_get_type("./data/apticket.j313ap.im4m") == kImg4Manifest);
}

TEST_CASE( "img4_get_type(im4p)", "[img4]" ) {
  REQUIRE(img4_get_type("./data/external/iBridge2,1,iBridge2,10,iBridge2,12,iBridge2,14,iBridge2,15,iBridge2,16,iBridge2,19,iBridge2,20,iBridge2,21,iBridge2,22,iBridge2,3,iBridge2,4,iBridge2,5,iBridge2,6,iBridge2,7,iBridge2,8_4.6_17P6610_Restore/Firmware/all_flash/LLB.j213.RELEASE.im4p") == kImg4Payload);
}
