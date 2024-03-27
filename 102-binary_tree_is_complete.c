#include "binary_trees.h"

levelorder_traversal_t *create_node(binary_tree_t *node);
void free_traversal(levelorder_traversal_t *head);
void push(binary_tree_t *node, levelorder_traversal_t *head,
		levelorder_traversal_t **tail);
void pop(levelorder_traversal_t **head);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL or not complete, otherwise 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_traversal_t *head, *tail;
	unsigned char x = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (tail == NULL)
		exit(1);

	while (head)
	{
		if (head->node->left)
		{
			if (x == 1)
			{
				free_traversal(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			x = 1;
		if (head->node->right)
		{
			if (x == 1)
			{
				free_traversal(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			x = 1;
		pop(&head);
	}

	return (1);
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
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_traversal - Frees a levelorder_traversal_t queue.
 *
 * @head: a pointer to the head of the queue.
 */

void free_traversal(levelorder_traversal_t *head)
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
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 *
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_traversal_t *head,
		levelorder_traversal_t **tail)
{
	levelorder_traversal_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_traversal(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
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
