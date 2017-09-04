#include<stdio.h>
int maxEle(int []);
int n;
int main()
{
  int array[20],highestnumber,i;
  printf("\n input the number of elements in array");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",array[i]);
  }
}

int maxEle(int arr[])
{
  static int highestnumber=-1,i=0;
  if(i<n)
  {
    if(array[i]>highestnumber)
    highestnumber = array[i];
    i++;
  maxEle(arr);
}
return highestnumber;
}
