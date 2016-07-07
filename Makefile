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

# FleaTptpParsing: $(SRCDIR)/prlc.c
#	clang -shared $(SRCDIR)/prlc.c -o $(LOCALLIBPATH)
#	cp $(SHAREDLIB).so $(LOCALLIBPATH)
#	cp $(SHAREDINC).h  $(LOCALINCLUDE)	

check: check.c parser
	clang -o check$(SONAME).out -l$(SONAME) check.c
	./check$(SONAME).out

parser: $(SRCDIR)/PrlcParser.y $(SRCDIR)/PrlcLexer.l
#   bison -d -Dapi.prefix={prlc_} $(SRCDIR)/PrlcParser.y
	bison -d  $(SRCDIR)/PrlcParser.y
	flex $(SRCDIR)/PrlcLexer.l

clean: deinstall
	rm -f *.o *.out *.output *.tab.* *~ $(SRCDIR)/*.*~
	rm -f $(SOFILE)


install: deinstall parser
	clang -o $(SOFILE) -fPIC -shared -v PrlcParser.tab.c lex.prlc_.c $(SRCDIR)/*.c 
	cp $(SOFILE) $(SOPATH)/$(SOFILE)


deinstall:
	rm -f $(SOPATH)/$(SOFILE)

