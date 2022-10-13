#include<stdio.h>
int main()
{
   fork();
   printf("This process' Process Id is %d\n", getpid());
   return 0;
}