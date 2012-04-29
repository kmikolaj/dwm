# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	dwm.desktop)
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee')

build() {
    cd $srcdir/$pkgname-$pkgver
    cp $srcdir/config.h config.h
    sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
    sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
    sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
    sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
    sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk

    patch -p1 < ../../01-dwm-6.0-pertag2.diff
    patch -p1 < ../../02-dwm-6.0-push.diff
    patch -p1 < ../../03-dwm-6.0-cycle.diff
    patch -p1 < ../../04-dwm-6.0-gaplessgrid.diff
    patch -p1 < ../../05-dwm-6.0-pidgin.diff
    patch -p1 < ../../06-dwm-6.0-monocle_count.diff 

    patch -p1 < ../../09-dwm-6.0-viewontag.diff
    patch -p1 < ../../10-dwm-6.0-scratchpad.diff
    patch -p1 < ../../11-dwm-6.0-togglemax.diff
    patch -p1 < ../../12-dwm-6.0-autoresize.diff

    patch -p1 < ../../14-dwm-6.0-remember-tags.diff
    patch -p1 < ../../15-dwm-6.0-centred-floating.diff
    patch -p1 < ../../16-dwm-6.0-focusurgent.diff
    patch -p1 < ../../17-dwm-6.0-statuscolors.diff
    patch -p1 < ../../18-dwm-6.0-save_floats.diff
    patch -p1 < ../../19-dwm-6.0-netactivewindow.diff
    patch -p1 < ../../20-dwm-6.0-moveresize.diff
    #patch -p1 < ../../21-dwm-6.0-xft.diff
    patch -p1 < ../../22-dwm-6.0-systray.diff

    make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
    cd $srcdir/$pkgname-$pkgver
    make PREFIX=/usr DESTDIR=$pkgdir install
    install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
    install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
    install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
