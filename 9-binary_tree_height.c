#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: the height of the tree (int)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_tree, right_tree;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	    return (0);

	left_tree = binary_tree_height(tree->left);
	right_tree = binary_tree_height(tree->right);

	return ((left_tree > right_tree ? left_tree : right_tree) + 1);
}
