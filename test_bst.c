/**
 * @file
 * <pre>COPYRIGHT(c) 2017
 * -------------------
 *
 * File Description
 *
 * Last Modified: Sun Nov  5 18:22:13 PST 2017</pre>
 * @author Adam Rizkalla
 */

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int testInsert(void);
int testMax(int num_items);
int testMin(int num_items);

/** The main function.
 * @param argc the number of tokens on the input line.
 * @param argv an array of tokens.
 * @return 0 on success, 1-255 on failure
 */
int
main(int argc, char *argv[])
{
  int num_items = 100000;

  if (testInsert() == 0) {
    printf("Insertion test FAIL\n");
    return EXIT_FAILURE;
  }

  if (testMin(num_items) == 0) {
    printf("Get minimum test FAIL\n");
    return EXIT_FAILURE;
  }

  if (testMax(num_items) == 0) {
    printf("Get maximum test FAIL\n");
    return EXIT_FAILURE;
  }

  printf("All tests passed\n");
  return EXIT_SUCCESS;
}

int testInsert(void) {
  Node_t *root = NULL;
  BST_Insert(&root, 10);
  if (root == NULL || root->val != 10) {
    return 0;
  }
  BST_Insert(&root, 5);
  if (root->left == NULL || root->left->val != 5) {
    return 0;
  }
  BST_Insert(&root, 12);
  if (root->right == NULL || root->right->val != 12) {
    return 0;
  }
  BST_Insert(&root, 4);
  if (root->left->left == NULL || root->left->left->val != 4) {
    return 0;
  }
  BST_Insert(&root, 12);
  if (root->right->right == NULL || root->right->right->val != 12) {
    return 0;
  }
  BST_Insert(&root, 6);
  if (root->left->right == NULL || root->left->right->val != 6) {
    return 0;
  }
  BST_Insert(&root, 11);
  if (root->right->left == NULL || root->right->left->val != 11) {
    return 0;
  }
  BST_Delete(root);
  return 1;
}

int testMin(int num_items) {
  Node_t *root = NULL;
  int min = num_items;
  int n, f;

  f = BST_GetMin(root);
  if (f != 0) {
    printf("Expected 0 for NULL BST\n");
    return 0;
  }

  for (int i = 0; i < num_items; i++) {
    n = rand() % num_items;
    if (n < min)
      min = n;
    BST_Insert(&root, n);
  }

  f = BST_GetMin(root);
  if (f != min) {
    printf("Expected %d, found %d\n", min, f);
    return 0;
  }

  BST_Delete(root);
  return 1;
}

int testMax(int num_items) {
  Node_t *root = NULL;
  int max = 0;
  int n, f;

  f = BST_GetMax(root);
  if (f != 0) {
    printf("Expected 0 for NULL BST\n");
    return 0;
  }

  for (int i = 0; i < num_items; i++) {
    n = rand() % num_items;
    if (n > max)
      max = n;
    BST_Insert(&root, n);
  }
  f = BST_GetMax(root);
  if (f != max) {
    printf("Expected %d, found %d\n", max, f);
    return 0;
  }

  BST_Delete(root);
  return 1;
}

