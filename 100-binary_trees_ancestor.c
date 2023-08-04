#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor of @first and @second,
 *   NULL otherwise
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,\
				     const binary_tree_t *second)
{
	int i, j, node1_depth, node2_depth;
	binary_tree_t *node1, *node2;

	node1 = (binary_tree_t *)first;
	node2 = (binary_tree_t *)second;

	if (node1 == NULL || node2 == NULL || node1->parent == NULL ||\
	    node2->parent == NULL)
		return (NULL);

	node1_depth = binary_tree_depth(node1);
	node2_depth = binary_tree_depth(node2);

	binary_tree_t *node1_ancestors[node1_depth + 1];
	binary_tree_t *node2_ancestors[node2_depth + 1];

	for (i = 0; i <= node1_depth; i++)
	{
		node1_ancestors[i] = node1;
		node1 = node1->parent;
	}

	for (i = 0; i <= node2_depth; i++)
	{
		node2_ancestors[i] = node2;
		node2 = node2->parent;
	}

	for (i = 0; i <= node1_depth; i++)
	{
		for (j = 0; j <= node2_depth; j++)
		{
			if (node1_ancestors[i] == node2_ancestors[j])
				return (node1_ancestors[i]);
		}
	}
	return (NULL);
}

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 * @tree: pointer to the node whose depth will be measured
 * Return: the depth of @node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
        size_t depth;

        depth = 0;
        if (tree == NULL || tree->parent == NULL)
                return (depth);

        while (tree->parent != NULL)
        {
                depth++;
                tree = tree->parent;
        }

        return (depth);
}
