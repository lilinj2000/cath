AUTOMAKE_OPTIONS = foreign

SUBDIRS = mdflow

bin_PROGRAMS = cath
cath_SOURCES = \
	CathConfig.cc \
	Util.cc \
	MDServer.cc \
	Main.cc 


cath_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(CATA_CPPFLAGS) \
		$(AIR_CPPFLAGS)


cath_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(CATA_LIBADD) \
	$(AIR_LIBADD)


cath_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = CathConfig.hh \
		Util.hh \
		CathLog.hh \
		MDServer.hh


EXTRA_DIST = env.sh.example cath.cfg.example log.cfg.example

cathdir = $(bindir)
cath_DATA = $(EXTRA_DIST)
