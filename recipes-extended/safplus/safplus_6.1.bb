DESCRIPTION = "The canonical example of init scripts"
SECTION = "base"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"
PR = "r0"

DEPENDS = "sqlite3 glib-2.0 gdbm"
RDEPENDS_${PN} = "sqlite3 glib-2.0 gdbm"
RPROVIDES_${PN} += "libClUtils.so libmw.so libClDbal.so"

SRC_URI = "git://github.com/OpenClovis/SAFplus-Availability-Scalability-Platform"

inherit autotools

S = "${WORKDIR}/${BP}/src/SAFplus"

OC_SDK = "${WORKDIR}/clovis"
OC_ASP_BUILD = "${WORKDIR}/asp_build"

OC_TARGET_DIR = "${prefix}/target/${TARGET_ARCH}/${TARGET_OS}"

EXTRA_OECONF = " \
  --with-sdk-dir=${OC_SDK} \
  --with-safplus-build \
  --without-snmp-build \
  --prefix=${D}${prefix} \
  "

do_configure () {

    mkdir -p ${OC_SDK}/6.1/sdk
    mkdir -p ${OC_SDK}/6.1/buildtools/yocto
    mkdir -p ${OC_ASP_BUILD}
    cd ${OC_ASP_BUILD}

    TARGET=${TARGET_OS} \
    ARCH=${TARGET_ARCH} \
    MARCH=${TARGET_ARCH} \
    ${S}/configure ${EXTRA_OECONF}
}

do_compile () {

    cd ${OC_ASP_BUILD}/asp/build/local
    make

}

do_install () {
    cd ${OC_ASP_BUILD}/asp/build/local
    make safplus-install
}

INSANE_SKIP_${PN} += "dev-so libdir"
INSANE_SKIP_${PN}-dbg += "libdir"

FILES_${PN}-dbg += " ${OC_TARGET_DIR}/lib/.debug ${OC_TARGET_DIR}/lib/shared-*/.debug"
FILES_${PN}-staticdev += " ${OC_TARGET_DIR}/lib/*.a"
FILES_${PN} += " ${OC_TARGET_DIR}"
