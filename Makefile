# $NetBSD$
#

DISTNAME=	xkanon-gtk2-090830
PKGNAME=	xkanon-090830
CATEGORIES=	games
MASTER_SITES=	http://www.creator.club.ne.jp/~jagarl/
DISTFILES=	${DEFAULT_DISTFILES} xkanon-071209.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.creator.club.ne.jp/~jagarl/
COMMENT=	Interpreter to execute AVG32 games for Microsoft Windows
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/xkanon-gtk
GNU_CONFIGURE=  yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	msgfmt

post-extract:
	cp ${WRKDIR}/xkanon/ayusys.ja.po ${WRKDIR}/xkanon-gtk/ayusys_gtk2.ja.po

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-audiodev=/dev/audio
.endif

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=    gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"