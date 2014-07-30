DESCRIPTION = "This is the OpenIPMI library, a library that makes simplifies building complex IPMI management software."
SECTION = "console/network"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"
DEPENDS = " \
    openssl \
    popt \
    zlib \
    ncurses \
    "

INC_PR = "r1"

inherit autotools gettext update-alternatives

PACKAGECONFIG ??= "net-snmp"

PACKAGECONFIG[net-snmp] = ",--with-ucdsnmp=no,net-snmp"

EXTRA_OECONF = "\
    --prefix=${prefix} \
    --without-python \
    "

S = "${WORKDIR}/OpenIPMI-${PV}"

PARALLEL_MAKEINST = ""

FILES_${PN} += "/usr/lib/perl5"
FILES_${PN}-dbg += "/usr/lib/perl5/auto/OpenIPMI/.debug"
