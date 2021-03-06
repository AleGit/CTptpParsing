SRCDIR = CSources
SONAME = TptpParsing

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	SOPATH = /usr/lib
	SOFILE = lib$(SONAME).so
	FLAGS = -fPIC -shared
	INCLUDES = /usr/include
endif
ifeq ($(UNAME_S),Darwin)
	SOPATH = /usr/local/lib
	SOFILE = lib$(SONAME).dylib
	FLAGS = -dynamiclib
	INCLUDES = /usr/local/include
endif

PCSRC = PkgConfig/$(UNAME_S)/*.pc
PCDST = $(SOPATH)/pkgconfig

OPT = -Ofast

check: check.c install
	clang $(OPT) -o check$(SONAME) -l$(SONAME) check.c
	time ./check$(SONAME) PUZ001-1.p 100

install: parser
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
