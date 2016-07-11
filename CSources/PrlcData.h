//  PrlcData.h
//  Copyright © 2016 Alexander Maringele. All rights reserved.

#ifndef PrlcData_h
#define PrlcData_h

#include "PrlcCore.h"

typedef enum {
    PRLC_UNDEFINED = 0,

    PRLC_FILE,

    PRLC_FOF,
    PRLC_CNF,
    PRLC_INCLUDE,

    PRLC_NAME,
    PRLC_ROLE,
    PRLC_ANNOTATION,

    PRLC_QUANTIFIER,
    PRLC_CONNECTIVE,

    PRLC_EQUATIONAL,
    PRLC_PREDICATE,

    PRLC_FUNCTION,
    PRLC_VARIABLE
} PRLC_TREE_NODE_TYPE;

typedef struct prlc_tree_node {
    const char* _Nullable symbol;
    PRLC_TREE_NODE_TYPE type;

    struct prlc_tree_node * _Nullable sibling;
    struct prlc_tree_node * _Nullable lastSibling;
    struct prlc_tree_node * _Nullable child;
} prlc_tree_node;

typedef struct prlc_prefix_node {
    const char* _Nullable symbol;
    struct prlc_prefix_node * _Nullable nexts[256];
} prlc_prefix_node;


/// A shelf holds 'size' (up to 'capacity') entries of size 'unit' in 'memory'.
/// 'memory' is a pointer to a block of 'capacity*size' bytes.
typedef struct {
    void * _Nullable memory;
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

prlc_store* _Nullable prlcCreateStore(size_t);
void prlcDestroyStore(prlc_store* _Nonnull);

prlc_tree_node * _Nullable treeNode(prlc_store* _Nonnull, size_t index);

#pragma mark - store

/// Stores every symbol just once
const char* _Nullable const prlcStoreSymbol(prlc_store* _Nonnull, const char* _Nullable const symbol);
const char* _Nullable const prlcGetSymbol(prlc_store* _Nonnull, const char* _Nullable const symbol);
const char* _Nullable const prlcFirstSymbol(prlc_store* _Nonnull);
const char* _Nullable const prlcNextSymbol(prlc_store* _Nonnull, const char* _Nullable const symbol);

prlc_tree_node * _Nullable prlcStoreNodeFile(prlc_store* _Nonnull, const char* _Nullable const name, prlc_tree_node * _Nullable input);
prlc_tree_node * _Nullable prlcStoreNodeInclude(prlc_store* _Nonnull, const char* _Nullable const file, prlc_tree_node * _Nullable selection);
prlc_tree_node * _Nullable prlcStoreNodeAnnotated(prlc_store* _Nonnull, PRLC_TREE_NODE_TYPE type,
                                       const char* _Nullable const name, prlc_tree_node * _Nullable role, prlc_tree_node * _Nullable formula, prlc_tree_node * _Nullable annotations);
prlc_tree_node * _Nullable prlcStoreNodeRole(prlc_store* _Nonnull, const char* _Nullable const name);
prlc_tree_node * _Nullable prlcStoreNodeConnective(prlc_store* _Nonnull, const char* _Nullable const symbol, prlc_tree_node * _Nullable firstChild);

/// Store a quantified formula.
prlc_tree_node * _Nullable prlcStoreNodeQuantified(prlc_store* _Nonnull, const char* _Nullable const quantifier, prlc_tree_node * _Nullable variables, prlc_tree_node * _Nullable formula);

prlc_tree_node * _Nullable prlcStoreNodeFunctional(prlc_store* _Nonnull, const char* _Nullable const symbol, prlc_tree_node * _Nullable firstChild);
prlc_tree_node * _Nullable prlcStoreNodeEquational(prlc_store* _Nonnull, const char* _Nullable const symbol, prlc_tree_node * _Nullable firstChild);
prlc_tree_node * _Nullable prlcStoreNodeConstant(prlc_store* _Nonnull, const char* _Nullable const symbol);
prlc_tree_node * _Nullable prlcStoreNodeVariable(prlc_store* _Nonnull, const char* _Nullable const symbol);

prlc_tree_node * _Nullable prlcStoreNodeName(prlc_store* _Nonnull, const char* _Nullable const name);

prlc_tree_node * _Nullable  prlcSetPredicate(prlc_tree_node * _Nullable t_node);

prlc_tree_node * _Nullable prlcNodeAppendNode(prlc_tree_node * _Nullable first, prlc_tree_node * _Nullable last);
prlc_tree_node * _Nullable prlcNodeAppendChild(prlc_tree_node * _Nullable parent, prlc_tree_node * _Nullable last);

void prlcNodeSetChild(prlc_tree_node * _Nullable parent, prlc_tree_node * _Nullable child) __attribute__ ((deprecated));;

void* _Nullable prlcLabel(const char* _Nullable const label);

prlc_tree_node * _Nullable prlcFirstTreeNode(prlc_store* _Nonnull);
prlc_tree_node * _Nullable prlcTreeNodeAtIndex(prlc_store* _Nonnull, size_t);




#endif /* PrlcData_h */
