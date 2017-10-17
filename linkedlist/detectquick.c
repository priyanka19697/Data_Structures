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
int detectquick(NODE *, NODE *);
int detect(int, NODE*, NODE*);
void printNode(NODE * head)
{
   while(head != 0)
   {
      printf("|%d|\n",head -> data );
      head = head -> link;
   }

}

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

int detectquick(NODE * head1, NODE * head2)
{
  int count1 = 0, count2 = 0, difference = 0,value;
  count1 = length(head1);
  count2 = length(head2);
  if(count1 > count2)
  {
       difference = count1 - count2;
       int value = detect(difference,head1,head2);
  }
  else
  {
      difference = count2 - count1;
       value = detect(difference,head2,head1);
  }
  return value;
}

int detect(int difference, NODE* head1, NODE* head2)
{
    temp = head1;
     NODE *temp2 = head2;
    for(int i = 0; i < difference - 1; i++)
    {
            temp = temp -> link;
    }

    while(temp != temp2)
    {
        temp = temp -> link;
        temp2 = temp2 -> link;
    }
    return temp -> data;


}

void main()
{
    NODE* head1, *head2;
    head1 = createList();
    head2 = createList2();

    printNode(head1);
    printf("\n");
    printNode(head2);

    int val = detectquick(head1,head2);
    printf("\n the value at this node is %d \n",val );

}
