#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
int remove_type(bst_t *root);
int successor(bst_t *node);
void bal(avl_t **tree);

/**
 * avl_remove - Removes a node from an AVL tree
 *
 * @root: a pointer to the root node of the tree for removing a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing the desired value,
 *		and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_avl = (avl_t *) bst_remove((bst_t *) root, value);

	if (!root_avl)
		return (NULL);
	bal(&root_avl);

	return (root_avl);
}

/**
 * bst_remove - Remove a node from a BST tree.
 *
 * @root: root of the tree.
 * @value: node with this value to remove.
 *
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int x = 0;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		x = remove_type(root);
		if (x != 0)
			bst_remove(root->right, x);
	}
	else
		return (NULL);

	return (root);
}

/**
 * remove_type - Function that removes a node depending of its children.
 *
 * @root: node to remove.
 *
 * Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * successor - Get the next successor i mean the min node in the right subtree.
 *
 * @node: tree to check.
 *
 * Return: the min value of this tree.
 */
int successor(bst_t *node)
{
	int y = 0;

	if (!node)
		return (0);
	else
	{
		y = successor(node->left);
		if (y == 0)
		{
			return (node->n);
		}
		return (y);
	}
}

/**
 * bal - Measures balance factor of a AVL.
 *
 * @tree: tree to go through.
 *
 * Return: balanced factor.
 */
void bal(avl_t **tree)
{
	int z;

	if (!tree || !(*tree))
		return;
	if (!((*tree)->left) && !((*tree)->right))
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	z = binary_tree_balance((const binary_tree_t *)*tree);
	if (z > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (z < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
