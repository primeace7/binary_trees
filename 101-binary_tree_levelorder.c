#include "binary_trees.h"

/**
 * binary_tree_levelorder-go through a binary tree using level-order traversal
 * @tree: pointer to the root node ot the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: nothing(void)
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, j, level_count;
	size_t height, max_nodes;
	binary_tree **tree_levels, *level_nodes;

	height = binary_tree_height(tree);
	tree_levels = malloc(sizeof(level_nodes) * (height + 1));
	if (tree_levels == NULL)
		perror();

	for (i = 0; i <= height; i++)
	{
		level_count = (int)pow(2, i);
		tree_levels[i] = malloc(level_count * sizeof(level_nodes));
		for (j = 0; j < level_count; j++)
			tree_levels[i][j] = NULL;
	}

	store_level_nodes(tree, tree_levels);
}

void store_level_nodes(int value, binary_tree_t *tree, binary_tree_t **levels)
{
	

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
