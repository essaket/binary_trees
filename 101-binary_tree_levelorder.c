#include "binary_trees.h"

levelorder_traversal_t *create_node(binary_tree_t *node);
void pint_push(binary_tree_t *node, levelorder_traversal_t *head,
		levelorder_traversal_t **tail, void (*func)(int));
void free_queue(levelorder_traversal_t *head);
void pop(levelorder_traversal_t **head);
/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: a void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_traversal_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - Creates a new levelorder_tree_t node
 *
 * @node: the binary tree node
 *
 * Return: a pointer to the new node, otherwise 0
 */

levelorder_traversal_t *create_node(binary_tree_t *node)
{
	levelorder_traversal_t *new_node;

	new_node = malloc(sizeof(levelorder_traversal_t));
	if ( new_node == NULL)
		return (NULL);

	new_node->node = node;
	new->next = NULL;

	return (new_node);
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 *
 * @node: the binary tree node to print and push.
 * @head: a double pointer to the head of the queue.
 * @tail: a double pointer to the tail of the queue.
 * @func: a pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_traversal_t *head,
		levelorder_traversal_t **tail, void (*func)(int))
{
	levelorder_traversal_t *new_node;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = create_node(node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_node(node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 *
 * @head: a pointer to the head of the queue.
 */
void free_queue(levelorder_traversal_t *head)
{
	levelorder_traversal_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 *
 * @head: a double pointer to the head of the queue.
 */
void pop(levelorder_traversal_t **head)
{
	levelorder_traversal_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
