PR = "${INC_PR}.0"

SRC_URI = "${SOURCEFORGE_MIRROR}/openhpi/openhpi-${PV}.tar.gz \
           file://openhpi_openclovis.patch \
           file://my_changes.patch \
           file://xml.patch \
           file://openhpid.service \
          "
SRC_URI[md5sum] = "6fb7a9fd60463d2a1a9d21af2c21a941"
SRC_URI[sha256sum] = "3eccd33c24af71aefb28816cfb3b3002176829267c142657d109f297c59ce64f"

require openhpi.inc
