#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE * head, *temp;

void insertNode(int val)
{
  NODE *recent;
  recent = (NODE*)malloc(sizeof(NODE));
  recent -> data = val;
  recent -> link = 0;
  if (head == 0)
  {
	   head = temp = recent;

  }
  else
  {
	   temp -> link = recent;
	   temp = recent;
  }
}

void printNode(NODE * head)
{
   while(head != 0)
   {
      printf("|%d|\n",head -> data );
      head = head -> link;
   }

}

int findlength(NODE * head)
{
  NODE *var;
  int count;
  var = head;
  while(var != 0)
  {
      count++;
      var = var -> link;
  }
  return count;
}

int getnthfromlast(NODE * head,int n)
{
      int length = findlength(head);
      int i,nl;
      nl = length - n;
      for(i = 0; i < nl; i++)
      {
        head = head -> link;
      }
      return head -> data;
}

void main()
{
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);
    insertNode(6);
    printNode(head);
    int val = getnthfromlast(head, 4);
    printf("\n the value at this node is %d",val );

}
