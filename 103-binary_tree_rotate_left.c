#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (!tree || !(tree->right))
		return (NULL);

	x = tree->right;
	y = x->left;
	x->left = tree;
	tree->right = y;
	if (!y)
		y->parent = tree;
	y = tree->parent;
	tree->parent = x;
	x->parent = y;
	if (!y)
	{
		if (y->left == tree)
			y->left = x;
		else
			y->right = x;
	}

	return (x);
}
