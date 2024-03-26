#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: count of leaves or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_leaves = 0;

	if (tree)
	{
		count_leaves += (!tree->left && !tree->right) ? 1 : 0;
		count_leaves += binary_tree_leaves(tree->left);
		count_leaves += binary_tree_leaves(tree->right);
	}

	return (count_leaves);
}
