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

int detectloop(NODE *head)
{
    NODE *walker, *jumper;
    walker = jumper = head;
    while(walker != 0 && jumper != 0)
    {
        walker = walker -> link;
        jumper = jumper -> link -> link;

        if(walker == jumper)
        return 1;
    }
    return 0;

}

void removeloop(NODE * head)
{
    NODE *walker, *jumper;
    walker = jumper = head;
    while(walker && jumper && jumper -> next)
    {
        walker = walker -> next;
        jumper = jumper -> next -> next;

        while (walker == jumper)
        {
          jumper -> next = 0;
        }
    }
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
    int value = detectloop(head);
    if(value == 1)
    removeloop(head);
    else
    printf("\n loop not detected \n ");
}
