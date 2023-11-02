#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree recursively
 * @tree: Pointer to root node of tree
 * base case : if tree is NULL
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left), binary_tree_delete(tree->right);
	free(tree);
}
