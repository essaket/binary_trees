#include "binary_trees.h"

int is_perfect(const binary_tree_t *tree, size_t leaf_depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL, otherwise 1
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect(tree, binary_tree_depth(get_leaf(tree)), 0));
}

/**
 * get_leaf - returns a leaf of binary tree
 *
 * @tree: A pointer to the root node of the tree to find a leaf in
 *
 * Return: a pointer to the first encountered leaf
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect - Checks if a binary tree is perfect recursively
 *
 * @tree: a pointer to the root node of the tree to check
 * @leaf_depth: the depth of one leaf in the binary tree
 * @level: level of current node
 *
 * Return: 1 if tree is perfect, otherwise 0
 */

int is_perfect(const binary_tree_t *tree, size_t leaf_depth, size_t level)
{
	if (binary_tree_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, leaf_depth, level + 1) &&
		is_perfect(tree->right, leaf_depth, level + 1));
}
