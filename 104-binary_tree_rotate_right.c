#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (!tree || !(tree->left))
		return (NULL);

	x = tree->left;
	y = x->right;
	x->right = tree;
	tree->left = y;
	if (y)
		y->parent = tree;
	y = tree->parent;
	tree->parent = x;
	x->parent = y;
	if (y)
	{
		if (y->left == tree)
			y->left = x;
		else
			y->right = x;
	}

	return (x);
}
