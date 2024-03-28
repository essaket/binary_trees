#include "binary_trees.h"

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree
 *		after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: a pointer to the root node of the BST to remove a node from.
 * @node: a pointer to the current node in the BST.
 * @value: the value to remove from the BST.
 *
 * Return: a pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		else if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		else
			return (bst_remove_recursive(root, node->right, value));
	}

	return (NULL);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: a pointer to the root node of the BST.
 * @node: a pointer to the node to delete from the BST.
 *
 * Return: a pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (!(node->left))
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (!parent ? node->right : root);
	}

	/* Left-child only */
	if (!(node->right))
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (!parent ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: apointer to the root node of the BST to search.
 *
 * Return: the minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}
