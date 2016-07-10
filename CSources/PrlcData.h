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


typedef prlc_store * _Nullable PrlcStoreRef;
typedef prlc_shelf * _Nullable PrlcShelfRef;
typedef prlc_prefix_node * _Nullable PrlcPrefixNodeRef;
typedef prlc_tree_node * _Nullable PrlcTreeNodeRef;

// typedef char* PrlcStringRef;

#pragma mark - memory

PrlcStoreRef _Nullable prlcCreateStore(size_t);
void prlcDestroyStore(PrlcStoreRef* _Nullable);

PrlcTreeNodeRef treeNode(PrlcStoreRef, size_t index);

#pragma mark - store

/// Stores every symbol just once
const char* _Nullable const prlcStoreSymbol(PrlcStoreRef, const char* _Nullable const symbol);
const char* _Nullable const prlcGetSymbol(PrlcStoreRef, const char* _Nullable const symbol);
const char* _Nullable const prlcFirstSymbol(PrlcStoreRef);
const char* _Nullable const prlcNextSymbol(PrlcStoreRef, const char* _Nullable const symbol);

PrlcTreeNodeRef prlcStoreNodeFile(PrlcStoreRef, const char* _Nullable const name, PrlcTreeNodeRef input);
PrlcTreeNodeRef prlcStoreNodeInclude(PrlcStoreRef, const char* _Nullable const file, PrlcTreeNodeRef selection);
PrlcTreeNodeRef prlcStoreNodeAnnotated(PrlcStoreRef, PRLC_TREE_NODE_TYPE type,
                                       const char* _Nullable const name, PrlcTreeNodeRef role, PrlcTreeNodeRef formula, PrlcTreeNodeRef annotations);
PrlcTreeNodeRef prlcStoreNodeRole(PrlcStoreRef, const char* _Nullable const name);
PrlcTreeNodeRef prlcStoreNodeConnective(PrlcStoreRef, const char* _Nullable const symbol, PrlcTreeNodeRef firstChild);

/// Store a quantified formula.
PrlcTreeNodeRef prlcStoreNodeQuantified(PrlcStoreRef, const char* _Nullable const quantifier, PrlcTreeNodeRef variables, PrlcTreeNodeRef formula);

PrlcTreeNodeRef prlcStoreNodeFunctional(PrlcStoreRef, const char* _Nullable const symbol, PrlcTreeNodeRef firstChild);
PrlcTreeNodeRef prlcStoreNodeEquational(PrlcStoreRef, const char* _Nullable const symbol, PrlcTreeNodeRef firstChild);
PrlcTreeNodeRef prlcStoreNodeConstant(PrlcStoreRef, const char* _Nullable const symbol);
PrlcTreeNodeRef prlcStoreNodeVariable(PrlcStoreRef, const char* _Nullable const symbol);

PrlcTreeNodeRef prlcStoreNodeName(PrlcStoreRef, const char* _Nullable const name);

PrlcTreeNodeRef  prlcSetPredicate(PrlcTreeNodeRef t_node);

PrlcTreeNodeRef prlcNodeAppendNode(PrlcTreeNodeRef first, PrlcTreeNodeRef last);
PrlcTreeNodeRef prlcNodeAppendChild(PrlcTreeNodeRef parent, PrlcTreeNodeRef last);

void prlcNodeSetChild(PrlcTreeNodeRef parent, PrlcTreeNodeRef child) __attribute__ ((deprecated));;

void* _Nullable prlcLabel(const char* _Nullable const label);

PrlcTreeNodeRef prlcFirstTreeNode(PrlcStoreRef);
PrlcTreeNodeRef prlcTreeNodeAtIndex(PrlcStoreRef, size_t);




#endif /* PrlcData_h */
