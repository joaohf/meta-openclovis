#
#
#

SUMMARY = "SAFplus Base Packages"
DESCRIPTION = "Packages required to satisfy the Open Clovis SAFplus"
PR = "r0"
LICENSE = "MIT"

inherit packagegroup

OPENCLOVIS_FEATURES_ENABLE ?= "snmp hpi"

PACKAGES = "\
    packagegroup-saf-base \
    packagegroup-saf-snmp \
    packagegroup-saf-hpi \
    "

SUMMARY_packagegroup-saf-base = "SAF Base"
DESCRIPTION_packagegroup-saf-base = "Packages required to support SAF frameworks"
RDEPENDS_packagegroup-saf-base = "\
    sqlite3 \
    glib-2.0 \
    gdbm \
    tipcutils \
    ${@bb.utils.contains("OPENCLOVIS_FEATURES_ENABLE", "snmp", "packagegroup-saf-snmp", "", d)} \
    ${@bb.utils.contains("OPENCLOVIS_FEATURES_ENABLE", "hpi", "packagegroup-saf-hpi", "", d)} \
    "

SUMMARY_packagegroup-saf-snmp = "SAF SNMP support"
DESCRIPTION_packagegroup-saf-snmp = "Packages required to support SAF frameworks with SNMP"
RDEPENDS_packagegroup-saf-snmp = "\
    net-snmp-libs \
    net-snmp-server \
    "

SUMMARY_packagegroup-saf-hpi = "SAF HPI support"
DESCRIPTION_packagegroup-saf-hpi = "Packages required to support SAF frameworks with HPI"
RDEPENDS_packagegroup-saf-hpi = "\
    openhpi \
    openipmi \
    ${@bb.utils.contains("OPENCLOVIS_FEATURES_ENABLE", "snmp", "openhpi-subagent", "", d)} \
    "
