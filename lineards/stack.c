#include<stdio.h>
#include<stdlib.h>

int MAX;
int stack[10];
int top = -1;

void push();
int pop();
int peek();
int isempty();
int isfull();
void display();


void display()
{
  int i;
  if(top==-1)
  printf("\n stack is empty");
  else
  {
  printf("\n the status of stack is");
  for(i=top;i>=0;i--)
  {
    printf("\n |%d| \n",stack[i]);
  }
}
}
void push()
{
  int n;
  if(!isfull())
  {
    printf("\n enter element to be pushed");
    scanf("%d",&n);
    top = top+1;
    stack[top] = n;
  }
  else
  printf("\n stack overflow");
}

int pop()
{
  int n;
  if(!isempty())
  {
    n = stack[top];
    top = top -1;

    printf("\n popped number is %d",n );
    return n;
  }
  else{
  printf("\n stack underflow \n");
  return -1;
}
}

int peek()
{
  int n;
  if(!isempty())
  {
  n = stack[top];
  printf("%d\n",n );
  return n;
}
else{
printf("\n no data to peek \n");
return  -1;
}
}

int isempty()
{
  if(top==-1)
  return 1;
  else
  return 0;
}

int isfull()
{
  if(top==MAX-1)
  return 1;
  else
  return 0;
}

void main()
{
  int choice,option=1,number;
  printf("\n enter the number of elements in stack");
  scanf("%d",&number);
  MAX = number-1;
  while(option)
  {
  printf("\n stack operations \n");
  printf("\n 1.push \n 2.pop \n 3.peek \n 4.display \n");
  printf("\n enter choice");
  scanf("%d",&choice);
  switch (choice) {

    case 1:  push();
            break;
    case 2:  pop();
            break;
    case 3: peek();
            break;
    case 4: display();
            break;
  }
  printf("\n do you want to continue");
  scanf("%d",&option);
  }
}
