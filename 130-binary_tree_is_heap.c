#include "binary_trees.h"

int check_parent(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	return (!binary_tree_is_complete(tree) ? 0 :
			check_parent(tree->left) && check_parent(tree->right));
}

/**
 * check_parent - Checks if parent has a greater value than its childs.
 *
 * @tree: a pointer to the node.
 *
 * Return: 1 if parent has a greater value, 0 otherwise
 */

int check_parent(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_complete - Calls to tree_is_complete function.
 *
 * @tree: tree root.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (!tree)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * tree_is_complete - Checks if tree is complete.
 *
 * @tree: pointer to the tree root.
 * @i: node index.
 * @cnodes: number of nodes.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (!tree)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: tree root.
 *
 * Return: size of the tree or 0 if tree is NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	return (!tree ? 0 : binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}
