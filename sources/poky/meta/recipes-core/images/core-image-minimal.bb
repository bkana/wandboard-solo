SUMMARY = "A small image just capable of allowing a device to boot."

IMAGE_INSTALL = "packagegroup-core-boot ${ROOTFS_PKGMANAGE_BOOTSTRAP} ${CORE_IMAGE_EXTRA_INSTALL}"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

DEV_SDK_INSTALL = " \
    cpp \
    cpp-symlinks \
    diffutils \
    file \
    gcc \
    gcc-symlinks \
    g++ \
    g++-symlinks \
    libstdc++ \
    libstdc++-dev \
    libtool \
    make \
    cmake \
 "
EXTRA_TOOLS_INSTALL += " \
    bzip2 \
    ethtool \
    nano \
    wget \
    unzip \
    zip \
"
IMAGE_INSTALL += " \
    ${DEV_SDK_INSTALL} \
    ${EXTRA_TOOLS_INSTALL} \
"

IMAGE_INSTALL_append = " socketClient"

IMAGE_ROOTFS_SIZE ?= "8192"

