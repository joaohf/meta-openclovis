PR = "${INC_PR}.0"

SRC_URI = "${SOURCEFORGE_MIRROR}/openhpi/openhpi-subagent-${PV}.tar.gz \
          file://fix_autoconf.patch \
          file://openhpi-subagent-2.3.4-format.patch \
          file://remove_unused_but_set_variable.patch \
          file://glib.patch \
          file://glib_mutex.patch \
          file://netsnmp_unused.patch \
          file://configure_pkgconfig_openhpiutils.patch \
          "
SRC_URI[md5sum] = "17e84d43ef1d24ae8caa52615efb9512"
SRC_URI[sha256sum] = "76ed0a84fdf6952341e90fc1588c2bc38021d742a65eefab92e82fd40099639a"

require openhpi-subagent.inc
