#include "binary_trees.h"

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
	levelorder_tree_t *head, *tail;

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

levelorder_tree_t *create_node(binary_tree_t *node)
{
	levelorder_tree_t *new_node;

	new_node = malloc(sizeof(levelorder_tree_t));
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
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 *
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

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
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
