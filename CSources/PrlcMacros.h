//  PrlcMacros.h
//  Copyright © 2015 Alexander Maringele. All rights reserved.

#ifndef PrlcMacros_h
#define PrlcMacros_h

#define PS prlcParsingStore
#define PR prlcParsingRoot

#define NULLREF                     0

/* ********************************************* */
// #define INFO_PRINT
#ifdef INFO_PRINT

#define INFO_CNF(a) ; printf("cnf('%s')\n",a)
#define INFO_FOF(a) ; printf("fof('%s')\n",a)
#define INFO_INCLUDE(a) ; printf("include('%s')\n",a)

#else

#define INFO_CNF(a)
#define INFO_FOF(a)
#define INFO_INCLUDE(a)

#endif

/* ********************************************* */

#define DID_PARSE_FORMULA(a)        return 0
#define DID_PARSE_INCLUDE(a)        return 0

// #define CREATE_ANNOTATED(a, b, c, d, e)                 prlcLabel("annotated")

#define CREATE_FOF(name, role, fof_formula, annotations)       prlcStoreNodeAnnotated(PS, PRLC_FOF, name, role, fof_formula, annotations) INFO_FOF(name)
#define CREATE_CNF(name, role, cnf_formula, annotations)       prlcStoreNodeAnnotated(PS, PRLC_CNF, name, role, cnf_formula, annotations) INFO_CNF(name)
#define CREATE_INCLUDE(fileName, nameList)                     prlcStoreNodeInclude(PS, fileName, nameList) INFO_INCLUDE(fileName)

#define CREATE_DFOF(fof_formula)                      NULL; fprintf(stderr, "$FOF(<fof_formula>) is not supported yet.\n");
#define CREATE_DCNF(cnf_formula)                      NULL; fprintf(stderr, "$CNF(<cnf_formula>) is not supported yet.\n");
#define CREATE_DFOT(term)                             NULL; fprintf(stderr, "$FOT(<fof_term>) is not supported yet.\n");

#define TPTP_INPUT(input)                               input; prlcNodeAppendChild(PR, input)
#define TPTP_INPUT_APPEND(sequence, input)              prlcNodeAppendNode(sequence, input)

#define CREATE_Quantified(q, vars, ufrm)                prlcStoreNodeQuantified(PS, q, vars, ufrm)
#define CREATE_Functional(f, first)                     prlcStoreNodeFunctional(PS, f, first)
#define CREATE_Equational(e, first)                     prlcStoreNodeEquational(PS, e, first)
#define CREATE_Connective(c, first)                     prlcStoreNodeConnective(PS, c, first)
#define CREATE_Constant(c)                              prlcStoreNodeConstant(PS, c)
#define CREATE_Variable(v)                              prlcStoreNodeVariable(PS, v)

#define CREATE_NODES0()                                 NULL   // empty list
#define CREATE_NODES1(a)                                a           // unary list
#define CREATE_NODES2(first, next)                      prlcNodeAppendNode(first, next)

#define PREDICATE(p)                                    prlcSetPredicate(p) // xSetPredicate(mereParsingTable, tid); /* register_predicate(tid) */

#define APPEND(p, c)                                    prlcNodeAppendChild(p,c)
#define INSERT(a, b)                                    prlcLabel("INSERT")

#define CREATE_STRING(a)                                prlcStoreSymbol(PS, a) // xStoreSymbol(mereParsingTable, a)
#define CREATE_STRINGS1(a)                              prlcStoreNodeName(PS, a) // xStoreNameNode(mereParsingTable, a)

#define CREATE_DISTINCT(a)                              prlcStoreNodeConstant(PS, prlcStoreSymbol(PS, a))

#define MAKE_ROLE(a)                                    prlcStoreNodeRole(PS, a) // xStoreRole(mereParsingTable, a)

#define NODES_APPEND(member, last)                      prlcNodeAppendNode(member, last) // xNodeListAppend(mereParsingTable, member, last)
#define STRINGS_APPEND(a, b)                            prlcNodeAppendNode(a, b) // xNodeListAppend(mereParsingTable, a, b)
#define SET_PARENTHESES(a)

/* predefined symbols */
#define DIRTY(a)  (( (char*) (prlcParsingStore->symbols.memory) )  + a)

#define _NOT_       DIRTY(1) // NULL // xStoreSymbol(mereParsingTable, "~")
#define _OR_        DIRTY(3) // NULL // xStoreSymbol(mereParsingTable, "|")
#define _AND_       DIRTY(5) // NULL // xStoreSymbol(mereParsingTable, "&")
#define _GENTZEN_   DIRTY(7) // NULL // xStoreSymbol(mereParsingTable, "-->")
#define _COMMA_     DIRTY(11) // NULL // xStoreSymbol(mereParsingTable, ", ")
#define _IFF_       DIRTY(13) // NULL // xStoreSymbol(mereParsingTable, "<=>")
#define _IMPLY_     DIRTY(17) // NULL // xStoreSymbol(mereParsingTable, "=>")
#define _YLPMI_     DIRTY(20) // NULL // xStoreSymbol(mereParsingTable, "<=")
#define _NIFF_      DIRTY(23) // NULL // xStoreSymbol(mereParsingTable, "<~>")
#define _NOR_       DIRTY(27) // NULL // xStoreSymbol(mereParsingTable, "~|")
#define _NAND_      DIRTY(30) // NULL // xStoreSymbol(mereParsingTable, "~&")
#define _FORALL_    DIRTY(33) // NULL // xStoreSymbol(mereParsingTable, "!")
#define _EXISTS_    DIRTY(35) // NULL // xStoreSymbol(mereParsingTable, "?")
#define _EQUAL_     DIRTY(37) // NULL // xStoreSymbol(mereParsingTable, "=")
#define _NEQ_       DIRTY(39) // NULL // xStoreSymbol(mereParsingTable, "!=")



#endif /* PrlcMacros_h */
