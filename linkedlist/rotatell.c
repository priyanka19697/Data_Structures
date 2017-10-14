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

NODE * rotate(NODE *head, int number)
{
    NODE *temp;
    int i;
    temp = head;
    while(temp -> link != 0)
    {
        temp = temp -> link;
    }
    temp -> link = head;
    temp = head;
    for(i = 0; i < number-1; i++)
    {
      temp = temp -> link;
    }
    head = temp -> link;
    temp -> link = 0;
    return head;

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
    head = rotate(head, 4);
    printf("\n rotated list is \n" );
    printNode(head);
}
