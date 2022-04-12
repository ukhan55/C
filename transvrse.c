#include<stdio.h>
#include<stdlib.h>
#include "headers.h"


/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(NODE* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	printf("position %d data : %d\n", node->nodePosition, node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(NODE* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node-> left);

	/* then print the data of node */
	printf("position %d data : %d\n", node->nodePosition, node->data);

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(NODE* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	printf("position %d data : %d\n",node->nodePosition, node->data);

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}
