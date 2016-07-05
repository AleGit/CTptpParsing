SRCDIR = CSources
SHAREDINC = FleaTptpParsing
SHAREDLIB = libFleaTptpParsing

# same paths as libyices
LOCALLIBPATH = /usr/local/lib
LOCALINCLUDE = /usr/local/include

# FleaTptpParsing: $(SRCDIR)/prlc.c
#	clang -shared $(SRCDIR)/prlc.c -o $(LOCALLIBPATH)
#	cp $(SHAREDLIB).so $(LOCALLIBPATH)
#	cp $(SHAREDINC).h  $(LOCALINCLUDE)	

check: check.c parser
	clang $(SRCDIR)/*.c *.c -o check.out
	./check.out

parser: $(SRCDIR)/PrlcParser.y $(SRCDIR)/PrlcLexer.l
#   bison -d -Dapi.prefix={prlc_} $(SRCDIR)/PrlcParser.y
	bison -d  $(SRCDIR)/PrlcParser.y
	flex $(SRCDIR)/PrlcLexer.l

clean: deinstall
	rm -f *.o *.out *.output *.tab.* *~ $(SRCDIR)/*.*~

deinstall:
	rm -f $(SHAREDLIB).so $(LOCALLIBPATH)/$(SHAREDLIB).so $(LOCALINCLUDE)/$(SHAREDINC).h

