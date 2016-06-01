AUTOMAKE_OPTIONS = foreign

SUBDIRS = mdflow

bin_PROGRAMS = cath
cath_SOURCES = \
	Util.cc \
	CathConfig.cc \
	MDServer.cc \
	Main.cc 


cath_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(CATA_CPPFLAGS) \
		$(AIR_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(JSON_CPPFLAGS)


cath_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(CATA_LIBADD) \
	$(AIR_LIBADD) \
	$(JSON_LIBADD)


cath_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = CathConfig.hh \
		Util.hh \
		CathLog.hh \
		MDServer.hh


EXTRA_DIST = env.sh cath.cfg log.cfg

cathdir = $(bindir)
cath_DATA = $(EXTRA_DIST)
