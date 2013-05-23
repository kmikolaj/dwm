# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

# vim: set et ts=4 sw=4:

pkgname=dwm
pkgver=6.1
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
source=("http://git.suckless.org/dwm/snapshot/dwm-1bdb393f81541506c9e7d8259855e30523b71238.tar.gz"
        "dwm.desktop")

md5sums=('62a378744b5a96316cdda59b0453f33b'
         '939f403a71b6e85261d09fc3412269ee')

build() {
    cd "${srcdir}" && cd "`find . -type d -name dwm-\*`"
    cp ${srcdir}/config.h config.h

    patch -Np1 < ../../01-dwm-6.1-pertag2.diff
    patch -Np1 < ../../02-dwm-6.1-push.diff
    patch -Np1 < ../../03-dwm-6.1-cycle.diff
    patch -Np1 < ../../04-dwm-6.1-gaplessgrid.diff
    patch -Np1 < ../../05-dwm-6.1-pidgin.diff
    #patch -Np1 < ../../06-dwm-6.1-monocle_count.diff
    #patch -Np1 < ../../07-dwm-6.1-monocle_borderless.diff
    patch -Np1 < ../../08-dwm-6.1-clicktofocus.diff
    patch -Np1 < ../../09-dwm-6.1-viewontag.diff
    patch -Np1 < ../../10-dwm-6.1-scratchpad.diff
    patch -Np1 < ../../11-dwm-6.1-togglemax.diff
    patch -Np1 < ../../12-dwm-6.1-autoresize.diff
    #patch -Np1 < ../../13-dwm-6.1-increase_mfact_limit.diff
    patch -Np1 < ../../14-dwm-6.1-remember-tags.diff
    patch -Np1 < ../../15-dwm-6.1-centred-floating.diff
    patch -Np1 < ../../16-dwm-6.1-focusurgent.diff
    patch -Np1 < ../../17-dwm-6.1-statuscolors.diff
    patch -Np1 < ../../18-dwm-6.1-save_floats.diff
    patch -Np1 < ../../19-dwm-6.1-systray.diff
    patch -Np1 < ../../20-dwm-6.1-centerwindow.diff
    patch -Np1 < ../../21-dwm-6.1-attach_normally.diff
    patch -Np1 < ../../22-dwm-6.1-moveresize.diff
	#patch -Np1 < ../../23-dwm-6.1-xft.diff
    patch -Np1 < ../../24-dwm-6.1-runorraise.diff
	#patch -Np1 < ../../25-dwm-6.1-mouse.diff

    make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
    cd "${srcdir}" && cd "`find . -type d -name dwm-\*`"
    make PREFIX=/usr DESTDIR=$pkgdir install
    install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
    install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
    install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}

