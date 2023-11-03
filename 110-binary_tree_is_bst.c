#include "binary_trees.h"

/**
 * bst_h - Checks if valid BST
 * @tree: Pointer to root node being checked
 * @mn: Int min
 * @mx: Int max
 * Return: 1 if valid BST, otherwise 0
 */

int bst_h(const binary_tree_t *tree, int mn, int mx)
{
	if (!tree)
		return (1);
	if (tree->n < mn || tree->n > mx)
		return (0);
	return (bst_h(tree->left, mn, tree->n - 1) &&
			bst_h(tree->right, tree->n + 1, mx));
}

/**
 * bst - Checks if valid BST
 * @tree: Pointer to root node of tree to check
 * Return: 1 if valid BST, othrwise 0
 */

int bst(const binary_tree_t *tree)
{
	return (bst_h(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to root node 
 * Return: 1 if valid BST, 0 if not or NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (tree ? bst(tree) : 0);
}
