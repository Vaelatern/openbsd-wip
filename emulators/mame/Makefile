# $OpenBSD: Makefile.template,v 1.76 2017/02/25 16:04:20 danj Exp $

ONLY_FOR_ARCHS = amd64

USE_WXNEEDED =	Yes

COMMENT =	Multiple Arcade Machine Emulator

V =		189

GH_ACCOUNT =	mamedev
GH_PROJECT =	mame
GH_TAGNAME =	mame0${V}

DISTNAME =	mame-0.${V}

CATEGORIES =	emulators

HOMEPAGE =	http://mamedev.org/

MAINTAINER =	Frederic Cambus <fcambus@openbsd.org>

PATCHORIG =	.orig.port

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${COMPILER_LIBCXX} FLAC GL SDL2 SDL2_ttf X11 Xinerama
WANTLIB += c expat fontconfig freetype jpeg lua5.3 m sqlite3 util z

MODULES =	lang/lua \
		lang/python

MODLUA_VERSION = 5.3

MODPY_RUNDEP = No

BUILD_DEPENDS += lang/python/${MODPY_DEFAULT_VERSION_2}

LIB_DEPENDS =	audio/flac \
		databases/sqlite3 \
		devel/sdl2 \
		devel/sdl2-ttf \
		graphics/jpeg

CFLAGS =	-I${PREFIX}/include -I${X11BASE}/include -I${MODLUA_INCL_DIR}
CFLAGS +=	-Wno-ignored-qualifiers

MAKE_ENV =	NOWERROR=1 VERBOSE=1 TOOLS=1 \
		OVERRIDE_CC="${CC}" OVERRIDE_CXX="${CXX}" \
		OPT_FLAGS="${CXXFLAGS}" \
		PYTHON_EXECUTABLE="${MODPY_BIN}" \
		USE_SYSTEM_LIB_EXPAT=1 \
		USE_SYSTEM_LIB_ZLIB=1 \
		USE_SYSTEM_LIB_JPEG=1 \
		USE_SYSTEM_LIB_FLAC=1 \
		USE_SYSTEM_LIB_LUA=1 \
		USE_SYSTEM_LIB_SQLITE3=1 \
		USE_QTDEBUG=0 # avoid depending on Qt

.if ${MACHINE_ARCH} == "amd64"
MAKE_ENV +=	PTR64=1
.endif

CONFIGURE_STYLE = none

USE_GMAKE =	Yes

MAKE_FILE =	makefile

NO_TEST =	Yes

post-extract:
	@mv ${WRKSRC}/3rdparty/genie/build/gmake.freebsd \
		${WRKSRC}/3rdparty/genie/build/gmake.bsd
	@sed -i 's,"lua","lua${MODLUA_VERSION}",g' ${WRKSRC}/scripts/extlib.lua
	@mv ${WRKSRC}/src/lib/util/png.h ${WRKSRC}/src/lib/util/localpng.h
	@sed -i 's|"png.h"|"localpng.h"|' ${WRKSRC}/src/emu/*.cpp \
		${WRKSRC}/src/lib/util/*.cpp ${WRKSRC}/src/tools/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mame64 ${PREFIX}/bin/mame
	${INSTALL_DATA} ${WRKSRC}/docs/man/mame.6 ${PREFIX}/man/man6
.for f in castool chdman floptool jedutil imgtool ldresample ldverify romcmp
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/man/${f}.1 ${PREFIX}/man/man1
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/mame
	@cp -r ${WRKSRC}/artwork ${PREFIX}/share/mame

.include <bsd.port.mk>
