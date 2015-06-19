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

inherit autotools gettext update-alternatives pkgconfig systemd

PACKAGECONFIG ??= "net-snmp"

PACKAGECONFIG[net-snmp] = "--with-net-snmp-config=${STAGING_BINDIR}/net-snmp-config,, net-snmp"

SYSTEMD_SERVICE_${PN} = "openhpid.service"
SYSTEMD_AUTO_ENABLE = "disable"

do_install_append() {
    install -d 777 ${D}/var/lib/openhpi
    install -d ${D}/${systemd_unitdir}/system
    install -m 644 ${WORKDIR}/openhpid.service ${D}/${systemd_unitdir}/system
    sed -i -e 's,@SBINDIR@,${sbindir},g' ${D}/${systemd_unitdir}/system/openhpid.service
    sed -i -e 's,@SYSCONFDIR@,${sysconfdir},g' ${D}/${systemd_unitdir}/system/openhpid.service
}

FILES_${PN} += "${libdir}/${PN}/*"

INSANE_SKIP_${PN} = "dev-so"
