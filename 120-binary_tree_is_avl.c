#include "binary_trees.h"

int is_avl_check(const binary_tree_t *tree, int low, int high);
size_t height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (!tree ? 0 : is_avl_check(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_check - Checks if a binary tree is a valid AVL tree
 *
 * @tree: a pointer to the root node of the tree to check
 * @low: the value of the smallest node visited thus far
 * @high: the value of the largest node visited this far
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */

int is_avl_check(const binary_tree_t *tree, int low, int high)
{
	size_t l, r, d;

	if (tree)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		l = height(tree->left);
		r = height(tree->right);
		d = l > r ? l - r : r - l;
		if (d > 1)
			return (0);
		return (is_avl_check(tree->left, low, tree->n - 1) &&
			is_avl_check(tree->right, tree->n + 1, high));
	}

	return (1);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
