#include "binary_trees.h"

/**
 * complete - Recursive binary tree complete check
 * @tree: Pointer to root node of tree to check
 * @sz: Size of binary tree
 * @idx: Counter
 * Return: 1 if complete, otherwise 0
 */

int complete(const binary_tree_t *tree, int sz, int idx)
{
	if (!tree)
		return (1);
	if (index >= sz)
		return (0);
	return (complete(tree->left, sz, 2 * idx + 1) &&
			complete(tree->right, sz, 2 * idx + 2));
}

/**
 * _binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to root node of tree to measure size
 * Return: Size of binary tree, 0 if tree is NULL
 */

int _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_size(tree->left) + _binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to root node of tree to check
 *
 * Return: 1, 0 if NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int sz, idx;

	if (tree)
	{
		size = _binary_tree_size(tree);
		idx = 0;

		return (complete(tree, size, index));
	}
	return (0);
}
