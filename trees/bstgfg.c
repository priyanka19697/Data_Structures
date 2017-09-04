#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};
typedef struct node NODE;

//to create new BST node

NODE* newNode(int item)
{
  NODE *temp = (NODE*)malloc(sizeof(NODE));
  temp ->data = item;
  temp ->left = 0;
  temp ->right = 0;
  return temp;

}

//to insert new node with the given key

NODE* insert(NODE* root,int key)
{
  if(root == 0)
  return newNode(key);
  else if(root->data <key)
  root->right = insert(root->right,key);
  else
  root -> left = insert(root->left,key);
  return root;
}

//to search for a key in BST

NODE* search(NODE* root,int key)
{
  if(root==0||root->data == key)
  return root;
  else if(root->data < key)
  return search(root->right,key);
  else
  return search(root->left,key);
}

//to delete a key node in BST

/*NODE* delete(NODE* root,int key)
{
  if(root == NULL)
  return root;
  if(key<root->data)
  root->left = delete(root->left,key);
  else if(key>root->data)
  root->right = delete(root->right,key);
  else//if key is same as root data
  {


  }
} */

 //inorder traversal
 void inorder(NODE* root)
 {
   if(root!=o)
   {
     inorder(root->left);
     printf("%d",root);
     inorder(root->right);
   }
 }
