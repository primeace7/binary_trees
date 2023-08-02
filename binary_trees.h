#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


/* STANDARD DATATYPES USED IN THE PROJECT */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

/* Binary tree type */
typedef struct binary_tree_s binary_tree_t;

/* Binary search tree type */
typedef struct binary_tree_s bst_t;

/*AVL tree type */
typedef struct binary_tree_s avl_t;

/* Max Binary heap type */
typedef struct binary_tree_s heap_t;

/* BINARY TREE PRINT FUNCTION FOR VISUALIZATION AND TESTING*/
void binary_tree_print(const binary_tree_t *tree);

/* FUNCTION PROTOTYPES */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
void traverse_tree(binary_tree_t *, size_t *, size_t *);
#endif /* _BINARY_TREES_H_ */
