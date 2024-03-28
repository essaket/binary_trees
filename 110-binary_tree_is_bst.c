#include "binary_trees.h"

int is_bst_check(const binary_tree_t *tree, int low, int high);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_check - Checks if a binary tree is a valid BST
 *
 * @tree: a pointer to the root node of the tree to check
 * @low: the value of the smallest node visited thus far
 * @high: the value of the largest node visited this far
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */

int is_bst_check(const binary_tree_t *tree, int low, int high)
{
	if (tree)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		return (is_bst_check(tree->left, low, tree->n - 1) &&
			is_bst_check(tree->right, tree->n + 1, high));
	}

	return (1);
}
