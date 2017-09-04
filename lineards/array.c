#include<stdio.h>
int read(int);
void main()
{
  int n =[0,2,4,6,10];
  printf("\n the array elements are ");
  for(int i=0;i<5;i++)
  {
    printf("%d\n",read(i));
  }l

}
int read(int i)
{
  int val;
  while(i<5)
  {
    val = n(i);
    i++;
    return val;
  }

}
