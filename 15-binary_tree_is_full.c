#include "binary_trees.h"

/**
 * binary_tree_is_full - Check if binary tree is full
 * @tree: Pointer to root of binary tree
 * Return: 1 if tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? binary_tree_is_full(tree->left) + 1 : 0;
	height_r = tree->right ? binary_tree_is_full(tree->right) + 1 : 0;
	return (height_l == height_r);
}
