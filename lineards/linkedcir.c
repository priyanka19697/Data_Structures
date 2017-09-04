#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


void print();
int counter();
void delete();

struct node{
  int data;
  struct node *link;
};
typedef struct node NODE;

NODE *recent=0,*temp=0,*head;

void main()
{


  int count=0,choice=1;
  head = 0;
  while(choice)
  {
      recent = (NODE*)malloc(sizeof(NODE));
      printf("\n enter the data \n");
      scanf("\t %d",&recent->data);
      if(head!=0)
      {
        temp->link = recent;
        temp = recent;
      }
      else{
        temp=head= recent;
      }


    printf("\n do you want to insert a node? \n");
    scanf("\n %d",&choice);
  }

  temp->link = head;

  print();
}

void print()
{
  int x;
  temp = head;
  printf("the status of linked list is");
  while(temp->link!=head)
  {
    printf("%d=>",temp->data);
    temp = temp->link;
  }
  printf("%d",temp->data);
  x = counter(0);
  printf("\n The number of nodes in cll are%d\n",x);

}

int counter(int value)
{
  temp = head;
  while(temp->link!=head)
  {
    value = value + 1;
    temp = temp->link;
  }
  value = value + 1;
  return value;
}

void delete()
{
  printf("\n which node do you want to delete \n");
  scanf("%d",&n);
  temp = head;
  for(i=1;i<=n;i++)
  {
    temp = temp->link;
  }
  del = temp;
  newadd = del->link;


}
