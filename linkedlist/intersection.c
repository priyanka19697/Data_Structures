#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE * head, *temp;


NODE* createList();
NODE* createList2();

int length(NODE * temp)
{

      int count = 0;
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
    printf("%d",count1);
    count2 = length(head2);
    walker1 = head1;
    walker2 = head2;

    int i, j;
    for(i = 0; i < count1; i++)
    {
      for (j = 0; j < count2; j++)
      {
        if(walker1 == walker2)
          return walker1 -> data;

        walker2 = walker2 -> link;

        if(walker2 == 0)
          walker2 = head2;
      }
      walker1 = walker1 -> link;
    }

    return 0;



}


void main()
{
    NODE* head1, *head2;
    head1 = createList();
    head2 = createList2();

    printNode(head1);
    printf("\n");
    printNode(head2);

    int val = detectintersection(head1,head2);
    printf("\n the value at this node is %d",val );

}





NODE* createNode(int data)
{
   NODE* recent;
   recent = (NODE*)malloc(sizeof(NODE));
   recent->data = data;
   recent->link = NULL;

   return recent;
}


NODE* intersection;

NODE* createList()
{

    NODE* head, *temp;

    temp = head = createNode(5);

    temp->link = createNode(6);
    temp = temp -> link;

    temp ->link = createNode(7);
    temp = temp -> link;

    intersection = createNode(8);
    temp -> link = intersection;
    temp = temp -> link;

    temp -> link = createNode(9);
    temp = temp -> link;

    temp -> link = createNode(10);
    temp = temp-> link;

    return head;

}



NODE* createList2()
{

    NODE* head, *temp;
    temp = head = createNode(1);

    temp->link = createNode(2);
    temp = temp -> link;

    temp ->link = createNode(3);
    temp = temp -> link;

    temp -> link = intersection;
    temp = temp -> link;



    return head;

}
