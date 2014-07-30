DESCRIPTION = "OpenHPI provides an open source implementation of the Service Availability Forum (SAF) Hardware Platform Interface (HPI)."
SECTION = "console/network"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=e3c772a32386888ccb5ae1c0ba95f1a4"
DEPENDS = " \
    openssl \
    zlib \
    sysfsutils \
    glib-2.0 \
    util-linux \
    net-snmp \
    libxml2 \
    "

INC_PR = "r1"

inherit autotools gettext update-alternatives pkgconfig

PACKAGECONFIG ??= "net-snmp"

PACKAGECONFIG[net-snmp] = "--with-net-snmp-config=${STAGING_BINDIR}/net-snmp-config,, net-snmp"

EXTRA_OECONF = "--with-libxml2=${STAGING_LIBDIR}/.."

FILES_${PN} += "${libdir}/${PN}/*"

INSANE_SKIP_${PN} = "dev-so"
