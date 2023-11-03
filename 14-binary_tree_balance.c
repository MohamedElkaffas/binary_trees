#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of tree, -1 if NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	height_r = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	return (height_r > height_l ? height_r : height_l);
}

/**
 * binary_tree_balance - Get balance factor of binary tree
 * @tree: Pointer to root of binary tree
 * Return: Balance factor of binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l, height_r, ans;

	if (!tree)
		return (0);

	height_l = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	height_r = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	ans = height_l - height_r;
	return ans;
}
