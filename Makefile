SRCDIR = CSources
SONAME = TptpParsing
SOFILE = lib$(SONAME).so

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SOPATH = /usr/lib
endif
ifeq ($(UNAME_S),Darwin)
	SOPATH = /usr/local/lib
endif

check: check.c install
	clang -o check$(SONAME) -l$(SONAME) check.c
	./check$(SONAME) PUZ001-1.p 100

install: parser
	clang -o $(SOFILE) -fPIC -shared -v PrlcParser.tab.c lex.prlc_.c $(SRCDIR)/*.c
	cp $(SOFILE) $(SOPATH)/$(SOFILE)
	cp CSources/Prlc*.h /usr/local/include/

parser: $(SRCDIR)/PrlcParser.y $(SRCDIR)/PrlcLexer.l
#   bison -d -Dapi.prefix={prlc_} $(SRCDIR)/PrlcParser.y
	bison -d -p prlc_ $(SRCDIR)/PrlcParser.y
	flex $(SRCDIR)/PrlcLexer.l

clean: deinstall
	rm -f *.o *.tab.* lex.* *~ $(SRCDIR)/*.*~
	rm -f check$(SONAME) $(SOFILE)

deinstall:
	rm -f $(SOPATH)/$(SOFILE)
	rm -f /usr/local/incldue/prlc
