DESCRIPTION = "This is the OpenIPMI library, a library that makes simplifies building complex IPMI management software."
SECTION = "console/network"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"
DEPENDS = " \
    openssl \
    popt \
    zlib \
    ncurses \
    glib-2.0 \
    gdbm \
    "

INC_PR = "r2"

inherit autotools gettext update-alternatives systemd

PACKAGECONFIG ??= "net-snmp"

PACKAGECONFIG[net-snmp] = ",--with-ucdsnmp=no,net-snmp"
PACKAGECONFIG[python] = "--with-python,--without-python,python,"
PACKAGECONFIG[perl] = "--with-perl=${STAGING_BINDIR_NATIVE},--with-perl=no,perl,"
PACKAGECONFIG[tcl] = "--with-tcl,--without-tcl,tcl,"

EXTRA_OECONF = "\
    --prefix=${prefix} \
    "

S = "${WORKDIR}/OpenIPMI-${PV}"

PARALLEL_MAKEINST = ""

do_install_append() {
    install -d ${D}/etc/init.d
    install -m 755 ${WORKDIR}/openipmi.initscript ${D}/etc/init.d/ipmi
    install -d ${D}/${systemd_unitdir}/system
    install -m 644 ${WORKDIR}/openipmi.service ${D}/${systemd_unitdir}/system/ipmi.service
    sed -i -e 's,@libexecdir@,${libexecdir},g' ${D}/${systemd_unitdir}/system/ipmi.service
    install -d ${D}/${libexecdir}
    install -m 755 ${WORKDIR}/openipmi.initscript ${D}${libexecdir}/openipmi-helper
}

FILES_${PN} += "/usr/lib/perl5 \
                ${systemd_unitdir}"
FILES_${PN}-dbg += "/usr/lib/perl5/auto/OpenIPMI/.debug"
