#include "binary_trees.h"

/**
* bst_remove - a function that removes a node
*
* @root: the tree's root
* @value: the value to remove when match
* Return: The root
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
	return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}

		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = minval(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
* minval - returns a node containing the minimum value
* @node: the root node
* Return: the node with minimum value
*/
bst_t *minval(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
	current = current->left;

	return (current);
}
