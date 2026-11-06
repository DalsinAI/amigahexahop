SUBDIRS = src data po
ACLOCAL_AMFLAGS = -I msc

EXTRA_DIST = msc/config.rpath CMakeLists.txt

MAINTAINERCLEANFILES = \
	aclocal.m4 \
	configure \
	Makefile.in \
	msc/config.sub \
	msc/config.guess \
	msc/depcomp \
	msc/install-sh \
	msc/missing \
	ABOUT-NLS \
	msc/config.rpath \
	po/Makefile.in.in \
	po/Makevars.template \
	po/Rules-quot \
	po/boldquot.sed \
	po/en@boldquot.header \
	po/en@quot.header \
	po/insert-header.sin \
	po/quot.sed \
	po/remove-potcdate.sin \
	po/*.pot \
	msc/codeset.m4 \
	msc/gettext.m4 \
	msc/glibc2.m4 \
	msc/glibc21.m4 \
	msc/iconv.m4 \
	msc/intdiv0.m4 \
	msc/intlmacosx.m4 \
	msc/intmax.m4 \
	msc/inttypes-pri.m4 \
	msc/inttypes_h.m4 \
	msc/lcmessage.m4 \
	msc/lib-ld.m4 \
	msc/lib-link.m4 \
	msc/lib-prefix.m4 \
	msc/lock.m4 \
	msc/longlong.m4 \
	msc/nls.m4 \
	msc/po.m4 \
	msc/printf-posix.m4 \
	msc/progtest.m4 \
	msc/size_max.m4 \
	msc/stdint_h.m4 \
	msc/uintmax_t.m4 \
	msc/visibility.m4 \
	msc/wchar_t.m4 \
	msc/wint_t.m4 \
	msc/xsize.m4 \
	msc/fcntl-o.m4 \
	msc/intl.m4 \
	msc/intldir.m4 \
	msc/threadlib.m4

dist-hook:
	if test -d .git -a \( ! -e $(distdir)/ChangeLog -o -w $(distdir)/ChangeLog \) ; then \
		LC_ALL=C git log --pretty --numstat --summary $(VERSION) | git2cl > $(distdir)/ChangeLog ; \
	fi
