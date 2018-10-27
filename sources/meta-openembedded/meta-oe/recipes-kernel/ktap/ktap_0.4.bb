# Released under the MIT license (see COPYING.MIT for the terms)

require ktap.inc

SUMMARY = "KTAP is a scripting dynamic tracing tool for Linux"
DEPENDS = "ktap-module"

# Only build the userspace app
EXTRA_OEMAKE += "ktap"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/ktap ${D}${bindir}/
}

PACKAGE_ARCH = "${MACHINE_ARCH}"
RDEPENDS_${PN} = "kernel-module-ktapvm"
