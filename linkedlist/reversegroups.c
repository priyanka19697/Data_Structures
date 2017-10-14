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

NODE* reversegrps(NODE* head, int number)
{
    int x = number;
    NODE * next = 0,*current, *previous = 0;
    current = head;

    while (current != 0 && x > 0)
    {
        next = current -> link;
        current -> link = previous;
        previous = current;
        current = next;
        x--;
    }

    if(next != 0)
    {
        head -> link = reversegrps(next, number);
    }

    return previous;
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
    head = reversegrps(head, 3);
    printf("\n reversed list is \n" );
    printNode(head);
}
