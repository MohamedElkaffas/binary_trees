#include "binary_trees.h"

/**
 * lt - Checks left pointers to determine insert position
 * @new: Double pointer to new
 * @current: Double pointer to pointer to tree
 * @value: to insert
 * Return: 1 on success, 0 on failure, 2 if duplicate found, 3 on malloc fail
 */

int lt(bst_t **neww, bst_t **curr, int value)
{
	if ((*curr)->left && value == (*curr)->left->n)
		return (2);

	while (*curr && value < (*curr)->n)
	{
		if (!(*(curr))->left)
		{
			(*neww) = binary_tree_node(*curr, value);
			if (!(*neww))
				return (3);
			(*curr)->left = *neww;
			return (1);
		}
		*curr = (*curr)->left;
	}
	return (0);
}

/**
 * gt - Checks left pointers to determine insert position
 * @new: Double pointer to new
 * @current: Double pointer to pointer to tree
 * @value: to insert
 * Return: 1 on success, 0 on failure, 2 if duplicate found, 3 on malloc fail
 */

int gt(bst_t **neww, bst_t **curr, int value)
{
	if ((*(curr))->right && value == (*curr)->right->n)
		return (2);

	while (*curr && value > (*curr)->n)
	{
		if (!(*(curr))->right)
		{
			*neww = binary_tree_node(*curr, value);
			if (!(*neww))
				return (3);
			*curr->right = *neww;
			return (1);
		}
		*curr = (*curr)->right;
	}
	return (0);
}

/**
 * bst_insert - Inserts a value in a BST
 * @tree: Double pointer to root node of BST to insert value
 * @value: Value to store the node being inserted
 * Return: Pointer to created node, NULL on failure
 * If tree address is NULL, created node becomes root
 * If value already present then ignore
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *neww, *curr;
	int ret;

	if (!tree)
		return (NULL);
	curr = NULL;
	if (!*tree)
	{
		neww = binary_tree_node(*tree, value);
		if (!neww)
			return (NULL);
		*tree = neww;
	}
	else
	{
		curr = *tree;
		while (1)
		{
			ret = lt(&neww, &curr, value);
			if (ret == 1)
				break;
			else if (ret == 2 || ret == 3)
				return (NULL);
			ret = gt(&neww, &curr, value);
			if (ret == 1)
				break;
			else if (ret == 2 || ret == 3)
				return (NULL);
		}
	}
	return (neww);
}
