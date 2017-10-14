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

NODE* reverse(NODE* head)
{
    NODE *current, *previous, *next;
    previous = 0;
    current = head;
    while (current != 0)
    {
        next = current -> link;
        current -> link = previous;
        previous = current;
        current = next;
    }
    head = previous;

    return head;

}

void printNode(NODE * head)
{
   while(head != 0)
   {
      printf("|%d|\n",head -> data );
      head = head -> link;
   }

}

void main()
{
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);
    printNode(head);
    head = reverse(head);
    printf("\n reversed list is" );
    printNode(head);
}
