#!/usr/bin/env bash

BASEDIR=$(dirname "$0")
EXTERNAL_DATA="$BASEDIR/data/external"
mkdir -p $EXTERNAL_DATA

#wget -P $EXTERNAL_DATA "http://updates-http.cdn-apple.com/2020/macos/001-36803-20200810-A97B835C-DB65-11EA-B99D-EC2029ACBA60/iBridge2,1,iBridge2,10,iBridge2,12,iBridge2,14,iBridge2,15,iBridge2,16,iBridge2,19,iBridge2,20,iBridge2,21,iBridge2,22,iBridge2,3,iBridge2,4,iBridge2,5,iBridge2,6,iBridge2,7,iBridge2,8_4.6_17P6610_Restore.ipsw"
#wget -P $EXTERNAL_DATA "http://updates-http.cdn-apple.com/2020FallFCS/fullrestores/001-74658/96D473B0-9ADD-4A40-8DB3-38892C812FDE/iPhone11,2,iPhone11,4,iPhone11,6,iPhone12,3,iPhone12,5_14.2_18B92_Restore.ipsw"

for ipsw in $EXTERNAL_DATA/*.ipsw
do
  BASE_FILE=$(basename "$ipsw" ".ipsw")
  IPSW_DIR="$EXTERNAL_DATA/$BASE_FILE"
  mkdir -p $IPSW_DIR
  unzip $ipsw -d $IPSW_DIR
done
