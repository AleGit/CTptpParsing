# C TPTP Parsing
C data structures and functions, flex and yacc files for tptp problem file parsing

- `sudo make install` builds and installs `libTptpParsing`.
- `sudo make check` builds and runs `checkTptpParsing`:
	> cp libTptpParsing.so /usr/lib/libTptpParsing.so
	> clang -o checkTptpParsing -lTptpParsing check.c
	> ./checkTptpParsing
	PUZ001-1.p
	symbols: 317.1.2909 (11 % of 2909 bytes)
	p_nodes: 241.2056.2909 (8 % of 5980904 bytes)
	t_nodes: 106.40.2909 (4 % of 116360 bytes)
	»« »~« »|« »&« »-->« »,« »<=>« »=>« »<=« »<~>« »~|« »~&« »!« »?« »=« »!=« 
	»PUZ001-1.p« »agatha« »hypothesis« »lives« »butler« »charles« »poorer_killer« »killed« »X« »Y« 
	»richer« »different_hates« »hates« »no_one_hates_everyone« »agatha_hates_agatha« 
	»agatha_hates_charles« »killer_hates_victim« »same_hates« »butler_hates_poor« 
	»prove_neither_charles_nor_butler_did_it« »negated_conjecture« ¤

