#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE * head, *temp;

int length(NODE * head)
{

      while(temp != 0)
      {
          count++;
          temp =  temp -> link;
      }
      return count;
}

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

int detectintersection(NODE *head1, NODE *head2)
{
    NODE *walker1, *walker2;
    int count1, count2;
    count1 = length(head1);
    count2 = length(head2);
    walker1 = head1;
    walker2 = head2;
    for(i = 0; i < count1; i++)
    {
      for (j = 0; j < count2; j++)
      {
        if(walker1 == walker2)
        return walker1 -> data;
        walker2 = walker2 -> link;

        if(walker2 == 0)
        walker2 = head;
      }
      walker1 = walker1 -> link;
    }

    return 0;

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
    int val = detectintersection(head1,head2);
    printf("\n the value at this node is %d",val );
