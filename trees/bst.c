#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};
typedef struct node NODE;

//to create a new bst node
NODE* newNode(int key)
{
  NODE* recent = (NODE*)malloc(sizeof(NODE));
  recent->data=key;
  recent->left = 0;
  recent->right =0;
  return recent;
}

//to insert a node
NODE* insert(NODE* root,int key)
{
  if(root==0)
  return newNode(key);
  else if(root->data < key)
  root->right = insert(root->right,key);
  else
  root->left = insert(root->left,key);
  return root;
}

//preorder traversal
void preorder(NODE* root)
{
  if(root!=0)
  {
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right;)
  }
}
