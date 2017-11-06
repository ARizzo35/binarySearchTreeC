/**
 * @file
 * <pre>COPYRIGHT(c) 2017
 * -------------------
 *
 * Header file for Binary Search Tree
 *
 * Last Modified: Sun Nov  5 18:01:16 PST 2017</pre>
 * @author Adam Rizkalla
 */

#ifndef BST_H
#define BST_H


typedef struct Node_t {
  int val;
  struct Node_t *left;
  struct Node_t *right;
} Node_t;


void BST_Insert(Node_t **tree, int val);
int BST_GetMin(Node_t *tree);
int BST_GetMax(Node_t *tree);
void BST_Delete(Node_t *tree);

#endif
