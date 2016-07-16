//  PrlcData.h
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#ifndef PrlcData_h
#define PrlcData_h

#include "PrlcCore.h"

typedef enum {
    PRLC_UNDEFINED = 0, // n children, n in 0..<Int.max

    PRLC_FILE,        // n children

    PRLC_FOF,         //
    PRLC_CNF,         //
    PRLC_INCLUDE,     //

    PRLC_NAME,        // nil children
    PRLC_ROLE,        // nil children
    PRLC_ANNOTATION,  // n children (untested)

    PRLC_QUANTIFIER,  // n+1 children, n variables, last child is formula
    PRLC_CONNECTIVE,  // n+1 children

    PRLC_EQUATIONAL,  // 2 children
    PRLC_PREDICATE,   // n children

    PRLC_FUNCTION,    // n children
    PRLC_VARIABLE     // nil children
} PRLC_TREE_NODE_TYPE;

typedef struct prlc_tree_node {
    const char*  symbol;
    PRLC_TREE_NODE_TYPE type;

    struct prlc_tree_node *  sibling;
    struct prlc_tree_node *  lastSibling; // speedup appends
    struct prlc_tree_node *  child;
} prlc_tree_node;

typedef struct prlc_prefix_node {
    const char*  symbol;
    struct prlc_prefix_node * nexts[256];
} prlc_prefix_node;


/// A shelf holds 'size' (up to 'capacity') entries of size 'unit' in 'memory'.
/// 'memory' is a pointer to a block of 'capacity*size' bytes.
typedef struct {
    void *  memory;
    size_t capacity;
    size_t unit;
    size_t size;
} prlc_shelf;

/// A store encapsulates three shelves:
/// - symbols (char)
/// - p_nodes (prlc_prefix_node)
/// - t_nodes (prlc_tree_node)
typedef struct {
    prlc_shelf symbols;
    prlc_shelf p_nodes;
    prlc_shelf t_nodes;
} prlc_store;

#pragma mark - memory

/// Allocs memory for symbols, prefix tree and abstract syntax tree.
prlc_store*  prlcCreateStore(size_t);

/// Frees memory for symbols and syntax tree.
void prlcDestroyStore(prlc_store*);

#pragma mark - store

/// Stores every symbol just once.
const char * const prlcStoreSymbol(prlc_store *, const char* const symbol);

/// Returns stored symbol or NULL if symbol is not stored.
const char * const prlcGetSymbol(prlc_store *, const char * const symbol);

/// Returns first stored symbol or NULL if no symbol is stored.
const char * const prlcFirstSymbol(prlc_store *);

/// Returns next sequentially stored symbol or NULL if there is no next sstored symbol.
const char * const prlcNextSymbol(prlc_store *, const char * const symbol);

/// Store probelm or axiom file 'name' in tree, usually as first node, i.e. as root node.
prlc_tree_node *  prlcStoreNodeFile(prlc_store *, const char * const name);

/// Store <include> with
/// - <file_name>
/// - <formula_selection> (nullable).
prlc_tree_node *  prlcStoreNodeInclude(prlc_store *,
  const char * const file_name,
  prlc_tree_node * formula_selection);

/// Store <annotated_formula> with
/// - 'PRLC_CNF' or 'PRLC_FOF'
/// - <name>
/// - <formula_role>,
/// - <cnf_formula> or <fof_formula>,
/// - <annotations> (nullable).
prlc_tree_node * prlcStoreNodeAnnotated(prlc_store * ,
  PRLC_TREE_NODE_TYPE type,
  const char * const name,
  prlc_tree_node * role,         // mandatory first schild
  prlc_tree_node * formula,      // mandatory second child
  prlc_tree_node * annotations); // optional third child

/// Store <formula_role>
prlc_tree_node *  prlcStoreNodeRole(prlc_store *, const char * const name);
prlc_tree_node *  prlcStoreNodeConnective(prlc_store* , const char * const symbol, prlc_tree_node * firstChild);

/// Store a quantified formula.
prlc_tree_node *  prlcStoreNodeQuantified(prlc_store* , const char * const quantifier, prlc_tree_node * variables, prlc_tree_node *  formula);

prlc_tree_node *  prlcStoreNodeFunctional(prlc_store* , const char * const symbol, prlc_tree_node * firstChild);
prlc_tree_node *  prlcStoreNodeEquational(prlc_store* , const char * const symbol, prlc_tree_node * firstChild);
prlc_tree_node *  prlcStoreNodeConstant(prlc_store* , const char * const symbol);
prlc_tree_node *  prlcStoreNodeVariable(prlc_store* , const char * const symbol);

prlc_tree_node *  prlcStoreNodeName(prlc_store *, const char * const name);

prlc_tree_node *  prlcSetPredicate(prlc_tree_node * t_node);

prlc_tree_node *  prlcNodeAppendNode(prlc_tree_node * first, prlc_tree_node * last);
prlc_tree_node *  prlcNodeAppendChild(prlc_tree_node * parent, prlc_tree_node * last);

void prlcNodeSetChild(prlc_tree_node *  parent, prlc_tree_node *  child) __attribute__ ((deprecated));;

void* prlcLabel(const char * const label);

prlc_tree_node * prlcFirstTreeNode(prlc_store *);
prlc_tree_node * prlcNextTreeNode(prlc_store *, prlc_tree_node *);
prlc_tree_node * prlcTreeNodeAtIndex(prlc_store *, size_t);




#endif /* PrlcData_h */
