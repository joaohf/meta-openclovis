DESCRIPTION = "This is the OpenIPMI library, a library that makes simplifies building complex IPMI management software."
SECTION = "console/network"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=e3c772a32386888ccb5ae1c0ba95f1a4"
DEPENDS = "openssl zlib net-snmp sysfsutils"

INC_PR = "r0"

inherit autotools gettext update-alternatives

EXTRA_OECONF = "--with-libxml2=${STAGING_LIBDIR}/.. --with-net-snmp-config=${STAGING_BINDIR}/net-snmp-config"

FILES_${PN} += "${libdir}/${PN}/*"

INSANE_SKIP_${PN} = "dev-so"
