#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left,*right;
};
typedef struct node NODE;
 // to create new node
NODE* newNode(int item)
{
  NODE* temp = (NODE*)malloc(sizeof(NODE));
  temp->data = item;
  temp->left = temp->right = 0;
  return temp;
}
//to insert an element
NODE* Insert(NODE *root,int key)
{
  if(root==0)
  return newNode(key);
  else if(root->data<key)
  root->right = Insert(root->right,key);
  else
  root->left= Insert(root->left,key);
  return root;
}
//to Search an element
NODE* Search(NODE* root,int key)
{
  if(root==0 || root->data = key)
  return root;
  else if(root->data < key)
  return Search(root->right,key);
  else
  return Search(root->left,key);
}
//function to print level order traversal
void printLevelOrder(NODE* root)
{
  int h = height(root);
  int i;
  for(i=1;i<=h;i++)
   printGivenLevel(root,i);
}
//funtion to print given level
void printGivenLevel(NODE* root,int level)
{
  if(root==0)
  return;
  if(level == 1)
  printf("%d",root->data);
  else if(level>1)
  {
    printGivenLevel(root->left,level-1));
    printGivenLevel(root->right,level-1)
  }
}
//function to calculate height
int height(NODE* root)
{
  if(root==0)
  return 0;
  else
  {
    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight>rheight)
    return (lheight+1);
    else
    return (rheight+1);
  }
}





void main()
{
  int choice;
  printf("\n binary tree operations \n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:Insert();
    break;
    case 2;Search();
  }
}
