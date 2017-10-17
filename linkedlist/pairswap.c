#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;




void insertNode(int num)

{

   recent = (NODE*)malloc(sizeof(NODE));
   recent -> data = num;
   recent -> link = 0;


 if(head!=0)
  {
      temp -> link = recent;
      temp = recent;

  }
  else
  {
      temp = head = recent;
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

NODE * pairswap(NODE * head)
{
  int var;
  NODE * first;

  while (first != 0 && first -> link != 0)
  {
         var = first -> link -> data ;
         first -> link -> data = first -> data;
         first -> data = var;
         first = first -> link -> link;

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
    pairswap(head);
    printf("\n after pairswap " );
    printNode(head);

}
