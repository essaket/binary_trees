#include "binary_trees.h"

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_avl, int value);
int balance(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);

/**
 * avl_insert - Inserts a value in an AVL tree
 *
 * @tree: a double pointer to the root node of the AVL tree for inserting the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_avl = NULL;

	if (!tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_avl, value);

	return (new_avl);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 *
 * @tree: a double pointer to the root node of the AVL tree to insert into.
 * @parent: the parent node of the current working node.
 * @new: a double pointer to store the new node.
 * @value: the value to insert into the AVL tree.
 *
 * Return: a pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_avl, int value)
{
	int x;

	if (!(*tree))
		return (*new_avl = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new_avl, value);
		if (!((*tree)->left))
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new_avl, value);
		if (!((*tree)->right))
			return (NULL);
	}
	else
		return (*tree);

	x = balance(*tree);
	if (x > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (x < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (x > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (x < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * balance - Measures the balance factor of a binary tree.
 *
 * @tree: s pointer to the root node of the tree to measure the balance factor.
 *
 * Return: if tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree ? height(tree->left) - height(tree->right) : 0);
}

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
