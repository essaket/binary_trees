#include "binary_trees.h"

avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree,
 *		or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (!array || size == 0 ? NULL : aux_sort(NULL, array, 0,
					((int)(size)) - 1));
}

/**
 * aux_sort - Create the tree using the half element of the array.
 *
 * @parent: parent of the node to create.
 * @array: sorted array.
 * @begin: position where the array starts.
 * @last: position where the array ends.
 *
 * Return: tree created.
 */

avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (!aux)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
