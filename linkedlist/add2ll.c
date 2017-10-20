#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE *head = 0, *temp, *recent;




NODE* createNODE(int val)
{
    NODE* recent = (NODE*)malloc(sizeof(NODE));
    recent -> data = val;
    recent -> link = 0;
    return recent;
}


NODE * insertNODE(int val)
{
  recent = createNODE(val);
  if (head == 0)
  {
	   head = temp = recent;

  }
  else
  {
	   temp -> link = recent;
	   temp = recent;
  }
  return head;
}

void printNODE(NODE * head)
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




NODE*  addTwoLists(NODE* first, NODE* second)
{
  // Code here
  NODE *one, *two;
  int x = 0,carry = 0;
  one = first;
  two = second;
  int length1 = 0, length2 = 0, difference = 0;
  while(one != 0)
  {
      one = one -> link;
      length1++;
  }
  while(two != 0)
  {   two = two -> link;
      length2++;
  }

  NODE * head2, *head1;
  head2 = second;
  head1 = first;

  NODE * head3 = 0, *temp3;

  if(length1>length2)
  {
      difference = length1 - length2;
      for(int i = 0; i < length2 - 1; i++)
      {
          second = second -> link;
      }
      while(difference > 0)
      {

          second -> link = createNODE(0);
          second = second -> link;
          difference --;
      }
  }
  else
  {
     difference = length2 - length1;
      for(int i = 0; i < length1 - 1; i++)
      {
          first = first -> link;
      }
      while(difference > 0)
      {

          first -> link = createNODE(0);
          first = first -> link;
          difference --;
      }
  }


  one = head1;
  two = head2;
  while(one != 0 && two != 0)
  {

    int x = one -> data + two -> data + carry;
    if(x > 9)
        {
        x = x - 10;
        carry = 1;
        }
      else
        carry = 0;


     if(head3 != 0)
      {
          temp3 -> link = createNODE(x);
          temp3 = temp3 -> link;


      }
      else
      {
          head3 = temp3 = createNODE(x);
      }
     one = one -> link;
     two = two -> link;


  }
  return head3;
}

void main()
{
  insertNODE(2);
  insertNODE(3);
  insertNODE(5);
  insertNODE(4);
  NODE * first = insertNODE(4);
  head = 0;
  insertNODE(2);
  insertNODE(3);
  insertNODE(5);
  NODE * second = insertNODE(4);
  NODE *head = addTwoLists(first, second);
  printNODE(head);
}
