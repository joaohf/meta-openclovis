DESCRIPTION = "The openhpi-subagent package contains the Service Availability Forum's Hardware Platform Interface SNMP sub-agent."
SECTION = "console/network"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://COPYING;md5=fc94392823a2f9536e4ca1dc82381bc1"
DEPENDS = "openssl zlib openhpi net-snmp"

INC_PR = "r0"

inherit pkgconfig autotools gettext

EXTRA_OECONF = "--with-net-snmp-config=${STAGING_BINDIR}/net-snmp-config"

FILES_${PN} += "${datadir}/snmp/*"
