/**
 * @file
 * <pre>COPYRIGHT(c) 2017
 * -------------------
 *
 * Implementation of Binary Search Tree in C.
 *
 * Last Modified: Sun Nov  5 18:01:02 PST 2017</pre>
 * @author Adam Rizkalla
 */

#include <stdlib.h>
#include "bst.h"


// Insert a new node into the BST
void BST_Insert(Node_t **tree, int val) {
  Node_t *root;
  Node_t *leaf = (Node_t*)malloc(sizeof(Node_t));
  leaf->val = val;
  leaf->left = NULL;
  leaf->right = NULL;

  if (tree == NULL)
    return;

  if (*tree == NULL) {
    *tree = leaf;
    return;
  }

  root = *tree;
  while (root != NULL) {
    if (leaf->val < root->val) {
      if (root->left == NULL) {
        root->left = leaf;
        break;
      }
      root = root->left;
    } else {
      if (root->right == NULL) {
        root->right = leaf;
        break;
      }
      root = root->right;
    }
  }

}

// Find the minimum value in the BST
int BST_GetMin(Node_t *tree) {
  Node_t *node = tree;
  if (node != NULL) {
    while(node->left != NULL)
      node = node->left;
    return node->val;
  }
  return 0;
}

// Find the maximum value in the BST
int BST_GetMax(Node_t *tree) {
  Node_t *node = tree;
  if (node != NULL) {
    while(node->right != NULL)
      node = node->right;
    return node->val;
  }
  return 0;
}

// Delete the BST, freeing all memory
void BST_Delete(Node_t *tree) {
  if (tree != NULL) {
    if (tree->left != NULL) {
      BST_Delete(tree->left);
    }
    if (tree->right != NULL) {
      BST_Delete(tree->right);
    }
    free(tree);
  }
}

