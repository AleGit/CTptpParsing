SRCDIR = CSources
SONAME = TptpParsing
INCLUDES = /usr/local/include

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SOPATH = /usr/lib
	SOFILE = lib$(SONAME).so
	FLAGS = -fPIC -shared
endif
ifeq ($(UNAME_S),Darwin)
	SOPATH = /usr/local/lib
	SOFILE = lib$(SONAME).dylib
	FLAGS = -dynamiclib
endif



check: check.c install
	clang -o check$(SONAME) -L$(SOPATH) -l$(SONAME) check.c
	./check$(SONAME) PUZ001-1.p 100

install: parser
	clang -o $(SOFILE) $(FLAGS) PrlcParser.tab.c lex.prlc_.c $(SRCDIR)/*.c
	cp $(SOFILE) $(SOPATH)/$(SOFILE)
	cp CSources/Prlc*.h $(INCLUDES)/

parser: $(SRCDIR)/PrlcParser.y $(SRCDIR)/PrlcLexer.l
	# bison -d -Dapi.prefix={prlc_} $(SRCDIR)/PrlcParser.y
	bison -d -p prlc_ $(SRCDIR)/PrlcParser.y
	flex $(SRCDIR)/PrlcLexer.l

clean: deinstall
	rm -f *.o *.tab.* lex.* *~ $(SRCDIR)/*.*~
	rm -f check$(SONAME) $(SOFILE)

deinstall:
	rm -f $(SOPATH)/$(SOFILE)
	rm -f $(INCLUDES)/Prlc*.h
