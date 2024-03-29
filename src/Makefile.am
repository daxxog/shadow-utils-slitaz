
EXTRA_DOST = .indent.pro

ubindir = ${prefix}/bin
usbindir = ${prefix}/sbin

DEFS = -D_HAVE_CONFIG_H -DLOCALEDIR=\"$(datadir)/locale\"

INCLUDES = -I${top_srcdir} \
	-I${top_srcdir}/lib \
	-I$(top_srcdir)/libmisc

# XXX why are login and su in /bin anyway (other than for
# historical reasons)?
#
# if the system is screwed so badly that it can't mount /usr,
# you can (hopefully) boot single user, and then you're root
# so you don't need these programs for recovery.
#
# also /lib/libshadow.so.x.xx (if any) could be moved to /usr/lib
# and installation would be much simpler (just two directories,
# $prefix/bin and $prefix/sbin, no install-data hacks...)

bin_PROGRAMS = groups login su
ubin_PROGRAMS = faillog lastlog chage chfn chsh expiry gpasswd newgrp passwd
usbin_PROGRAMS = chpasswd dpasswd groupadd groupdel groupmod \
	logoutd mkpasswd newusers useradd userdel usermod grpck \
	pwck vipw grpconv grpunconv pwconv pwunconv

noinst_PROGRAMS = id sulogin

# id and groups are from gnu, sulogin from sysvinit

suidbins = su
suidubins = chage chfn chsh expiry gpasswd newgrp passwd

LDADD = $(top_builddir)/libmisc/libmisc.la \
	$(top_builddir)/lib/libshadow.la

chpasswd_LDADD = $(LDADD) $(LIBPAM)
chage_LDADD    = $(LDADD) $(LIBPAM)
chfn_LDADD     = $(LDADD) $(LIBPAM)
chsh_LDADD     = $(LDADD) $(LIBPAM)
groupadd_LDADD = $(LDADD) $(LIBPAM)
groupdel_LDADD = $(LDADD) $(LIBPAM)
groupmod_LDADD = $(LDADD) $(LIBPAM)
login_LDADD    = $(LDADD) $(LIBPAM)
newusers_LDADD = $(LDADD) $(LIBPAM)
passwd_LDADD   = $(LDADD) $(LIBPAM) $(LIBCRACK)
su_SOURCES     = su.c suauth.c
su_LDADD       = $(LDADD) $(LIBPAM)
useradd_LDADD  = $(LDADD) $(LIBPAM)
userdel_LDADD  = $(LDADD) $(LIBPAM)
usermod_LDADD  = $(LDADD) $(LIBPAM)

install-exec-hook:
	ln -sf newgrp	$(DESTDIR)$(bindir)/sg
	ln -sf vigr	$(DESTDIR)$(bindir)/vipw
	for i in $(suidbins); do \
		chmod 4755 $(DESTDIR)$(bindir)/$$i; \
	done

install-data-hook:
	for i in $(suidubins); do \
		chmod 4755 $(DESTDIR)$(ubindir)/$$i; \
	done
