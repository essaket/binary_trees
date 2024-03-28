#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 *
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 *
 * Return:  a pointer to the node containing a value equals to value,
 *			otherwise NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		else if (tree->n > value)
			return (bst_search(tree->left, value));
		else
			return (bst_search(tree->right, value));
	}

	return (NULL);
}
