DESCRIPTION = "This is the OpenIPMI library, a library that makes simplifies building complex IPMI management software."
SECTION = "console/network"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"
DEPENDS = "openssl popt zlib"

INC_PR = "r0"

inherit autotools gettext update-alternatives

EXTRA_OECONF = "\
    --prefix=${prefix} \
    --without-python \
    ${@base_contains("OPENCLOVIS_FEATURES_ENABLE", "snmp", "--with-ucdsnmp=no", "", d)} \
    "

S = "${WORKDIR}/OpenIPMI-${PV}"

PARALLEL_MAKEINST = ""
