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


typedef prlc_store * _Nullable NullableStoreRef;
typedef prlc_store * _Nonnull StoreRef;
typedef prlc_shelf * _Nullable NullableShelfRef;
typedef prlc_prefix_node * _Nullable NullablePrefixNodeRef;
typedef prlc_tree_node * _Nullable NullableTreeNodeRef;

// typedef char* PrlcStringRef;

#pragma mark - memory

NullableStoreRef prlcCreateStore(size_t);
void prlcDestroyStore(StoreRef);

NullableTreeNodeRef treeNode(StoreRef, size_t index);

#pragma mark - store

/// Stores every symbol just once
const char* _Nullable const prlcStoreSymbol(StoreRef, const char* _Nullable const symbol);
const char* _Nullable const prlcGetSymbol(NullableStoreRef, const char* _Nullable const symbol);
const char* _Nullable const prlcFirstSymbol(NullableStoreRef);
const char* _Nullable const prlcNextSymbol(NullableStoreRef, const char* _Nullable const symbol);

NullableTreeNodeRef prlcStoreNodeFile(NullableStoreRef, const char* _Nullable const name, NullableTreeNodeRef input);
NullableTreeNodeRef prlcStoreNodeInclude(NullableStoreRef, const char* _Nullable const file, NullableTreeNodeRef selection);
NullableTreeNodeRef prlcStoreNodeAnnotated(NullableStoreRef, PRLC_TREE_NODE_TYPE type,
                                       const char* _Nullable const name, NullableTreeNodeRef role, NullableTreeNodeRef formula, NullableTreeNodeRef annotations);
NullableTreeNodeRef prlcStoreNodeRole(NullableStoreRef, const char* _Nullable const name);
NullableTreeNodeRef prlcStoreNodeConnective(NullableStoreRef, const char* _Nullable const symbol, NullableTreeNodeRef firstChild);

/// Store a quantified formula.
NullableTreeNodeRef prlcStoreNodeQuantified(NullableStoreRef, const char* _Nullable const quantifier, NullableTreeNodeRef variables, NullableTreeNodeRef formula);

NullableTreeNodeRef prlcStoreNodeFunctional(NullableStoreRef, const char* _Nullable const symbol, NullableTreeNodeRef firstChild);
NullableTreeNodeRef prlcStoreNodeEquational(NullableStoreRef, const char* _Nullable const symbol, NullableTreeNodeRef firstChild);
NullableTreeNodeRef prlcStoreNodeConstant(NullableStoreRef, const char* _Nullable const symbol);
NullableTreeNodeRef prlcStoreNodeVariable(NullableStoreRef, const char* _Nullable const symbol);

NullableTreeNodeRef prlcStoreNodeName(NullableStoreRef, const char* _Nullable const name);

NullableTreeNodeRef  prlcSetPredicate(NullableTreeNodeRef t_node);

NullableTreeNodeRef prlcNodeAppendNode(NullableTreeNodeRef first, NullableTreeNodeRef last);
NullableTreeNodeRef prlcNodeAppendChild(NullableTreeNodeRef parent, NullableTreeNodeRef last);

void prlcNodeSetChild(NullableTreeNodeRef parent, NullableTreeNodeRef child) __attribute__ ((deprecated));;

void* _Nullable prlcLabel(const char* _Nullable const label);

NullableTreeNodeRef prlcFirstTreeNode(NullableStoreRef);
NullableTreeNodeRef prlcTreeNodeAtIndex(NullableStoreRef, size_t);




#endif /* PrlcData_h */
