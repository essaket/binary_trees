#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - Converts a Binary Max Heap
 *			to a sorted array of integers
 *
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: sorted in descending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}

/**
 * tree_size - Measures the sum of heights of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: height or 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}
