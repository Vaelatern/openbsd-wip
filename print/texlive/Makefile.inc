# $OpenBSD: Makefile.inc,v 1.17 2017/05/22 09:05:49 sthen Exp $

CATEGORIES ?=	print
HOMEPAGE ?=	http://tug.org/texlive/
MAINTAINER ?=	Edd Barrett <edd@openbsd.org>

# http://tug.org/texlive/LICENSE.TL
PERMIT_PACKAGE_CDROM ?=		Yes
PERMIT_PACKAGE_FTP ?=		Yes
PERMIT_DISTFILES_FTP ?=		Yes

EXTRACT_SUFX ?=		.tar.xz

V ?=		2017
DIST_V ?=	${V}0524

# Note: The TUG FTP server is frequently overloaded and doesn't work with
# ftp(1)'s keepalive implementation.
MASTER_SITES ?=	http://ftp.math.utah.edu/pub/tex/historic/systems/texlive/2017/ \
		http://ftp.heanet.ie/pub/ftp.frugalware.org/pub/frugalware/frugalware-2.1/source/xapps-extra/texlive/ \
		https://paclan.it/distfiles/ \
		ftp://ftp.tug.org/texlive/historic/${V}/

PATCHORIG ?=	.origy
