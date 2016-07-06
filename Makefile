SRCDIR = CSources
SHAREDINC = FleaTptpParsing
SHAREDLIB = libFleaTptpParsing.so

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

install: deinstall parser
#	clang -shared -v demo.c -o demo.so
	clang -o $(SHAREDLIB) -fPIC -shared -v PrlcParser.tab.c lex.prlc_.c $(SRCDIR)/*.c 
# cp $(SHAREDLIB) $(LOCALLIBPATH)/$(SHAREDLIB)
	clang -o checkL.out -lFleaTptpParsing check.c
	./checkL.out

deinstall:
# rm -f $(SHAREDLIB) $(LOCALLIBPATH)/$(SHAREDLIB) $(LOCALINCLUDE)/$(SHAREDINC).h

