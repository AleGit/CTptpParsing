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
	clang -o check$(SONAME).out -l$(SONAME) check.c
	./check$(SONAME).out

install: parser
	clang -o $(SOFILE) -fPIC -shared -v PrlcParser.tab.c lex.prlc_.c $(SRCDIR)/*.c 
	cp $(SOFILE) $(SOPATH)/$(SOFILE)

parser: $(SRCDIR)/PrlcParser.y $(SRCDIR)/PrlcLexer.l
#   bison -d -Dapi.prefix={prlc_} $(SRCDIR)/PrlcParser.y
	bison -d -p prlc_ $(SRCDIR)/PrlcParser.y
	flex $(SRCDIR)/PrlcLexer.l

clean: deinstall
	rm -f *.o *.out *.output *.tab.* *~ lex.* $(SRCDIR)/*.*~
	rm -f $(SOFILE)

deinstall:
	rm -f $(SOPATH)/$(SOFILE)

