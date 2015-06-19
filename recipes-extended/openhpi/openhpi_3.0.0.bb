PR = "${INC_PR}.0"

SRC_URI = "${SOURCEFORGE_MIRROR}/openhpi/openhpi-${PV}.tar.gz \
           file://openhpi_openclovis.patch \
           file://my_changes.patch \
           file://xml.patch \
           file://openhpid.service \
          "
SRC_URI[md5sum] = "9089cb59b732ff00b3805a1809405b4b"
SRC_URI[sha256sum] = "2af5f40040a1b99b0c0a60f1bc03505d3d51f5c445cd04b1f832eb060acbb227"

require openhpi.inc
