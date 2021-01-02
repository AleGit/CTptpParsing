SRCDIR = CSources
SONAME = TptpParsing

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

ifeq ($(UNAME_S),Linux)
	SOPATH = /usr/local/lib
	SOFILE = lib$(SONAME).so
	FLAGS = -fPIC -shared
	INCLUDES = /usr/local/include
	PCSRC = PkgConfig/$(UNAME_S)/*.pc
	PCDST = /usr/lib/pkgconfig
endif
ifeq ($(UNAME_S),Darwin)
	SOPATH = /usr/local/lib
	SOFILE = lib$(SONAME).dylib
	FLAGS = -dynamiclib
	INCLUDES = /usr/local/include
ifeq ($(UNAME_M),arm64)
	PCSRC = PkgConfig/$(UNAME_S)_$(UNAME_M)/*.pc
else
	PCSRC = PkgConfig/$(UNAME_S)/*.pc
endif
	PCDST = $(SOPATH)/pkgconfig
endif

OPT = -Ofast

info:
	echo $(PCSRC) $(PCDST)

check: check.c install
	clang $(OPT) -o check$(SONAME) -l$(SONAME) check.c
	time ./check$(SONAME) PUZ001-1.p 100

install: parser
	mkdir -p $(SOPATH)
	mkdir -p $(INCLUDES)
	mkdir -p $(PCDST)
	clang $(OPT) -o $(SOPATH)/$(SOFILE) $(FLAGS) PrlcParser.tab.c lex.prlc_.c $(SRCDIR)/*.c
	cp CSources/Prlc*.h $(INCLUDES)/
	cp $(PCSRC) $(PCDST)/

parser: $(SRCDIR)/PrlcParser.y $(SRCDIR)/PrlcLexer.l
	bison -d -p prlc_ $(SRCDIR)/PrlcParser.y
	flex $(SRCDIR)/PrlcLexer.l

clean: deinstall
	rm -f *.o *.tab.* lex.* *~ $(SRCDIR)/*.*~
	rm -f check$(SONAME) $(SOFILE)

deinstall:
	rm -f $(SOPATH)/$(SOFILE)
	rm -f $(INCLUDES)/Prlc*.h
	rm -f $(PCDST)/TptpParsing.pc
	rm -f $(PCDST)/Yices.pc
	rm -f $(PCDST)/Z3API.pc
