#include "binary_trees.h"

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: pointer to the tree to check for completeness
 * Return 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_complete(tree->left);
	right = binary_tree_is_complete(tree->right);

	if (left + right < 2)
		return (0);
	else
		return (1);
}
