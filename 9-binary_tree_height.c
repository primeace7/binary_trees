#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: the height of the tree (int)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *use_tree;
	size_t max_height, current_height;

	use_tree = (binary_tree_t *)tree;

	max_height = 0;
	current_height = 0;

	traverse_tree(use_tree, &max_height, &current_height);
	return (max_height);
}

/**
 * traverse_tree - traverse every path in a tree
 * @tree: pointer to the tree to traverse
 * @max_height: the maximum height of paths traversed in the tree so far
 * @current: the height of the current path being traversed
 * Return: nothing (void)
 */

void traverse_tree(binary_tree_t *tree, size_t *max_height, size_t *current)
{
	if (tree == NULL)
	{
		(*current)--;
		return;
	}

/* for every node that isn't null, increase the height of that path by 1 */
/* that means a tree with only one node (i.e height 0) will have a */
/* current height of 1, but this will be corrected in the next line of code */

	(*current_height)++;

/* if a node is found to be a leaf node, subtract 2 to account for the 1 that*/
/* added in the previous line, and the 1 that was added in the root node */

	if (tree->left == NULL && tree->right == NULL)
	{
		(*current_height) -= 2;
		return; }

	if (*current_height > *max_height)
		*max_height = *current_height;

	traverse_tree(tree->left, max_height, current_height);
	traverse_tree(tree->right, max_height, current_height);
}
