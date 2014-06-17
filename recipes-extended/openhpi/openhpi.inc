DESCRIPTION = "This is the OpenIPMI library, a library that makes simplifies building complex IPMI management software."
SECTION = "console/network"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=e3c772a32386888ccb5ae1c0ba95f1a4"
DEPENDS = "openssl zlib sysfsutils"

INC_PR = "r1"

inherit autotools gettext update-alternatives

PACKAGECONFIG ??= "net-snmp"

PACKAGECONFIG[net-snmp] = "--with-net-snmp-config=${STAGING_BINDIR}/net-snmp-config,, net-snmp"

EXTRA_OECONF = "--with-libxml2=${STAGING_LIBDIR}/.."

FILES_${PN} += "${libdir}/${PN}/*"

INSANE_SKIP_${PN} = "dev-so"
