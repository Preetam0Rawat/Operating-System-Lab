#include<stdio.h>
int main()
{
    int x =  fork();
    
    int a[5] = {4, 3, 25, 6, 21};
    if( x == 0)
    {
      printf("This is child process\n");
      printf("Child's process id is: %d\n", getpid());
      printf("Child's Parent's process id is : %d\n", getppid());
      
      
      printf("Even numbers are: \n");
      for(int i =0 ; i< 5; i++)
      {
          if(a[i]%2 == 0)
          printf("%d  ", a[i]);
      }
      printf("\n\n\n");
    }
    
    
    if(x > 0)
    {
      printf("This is Parent process\n");
      printf("Parent's process id is: %d\n", getpid());
      
       printf("Odd numbers are: \n");
      for(int i =0 ; i< 5; i++)
      {
          if(a[i]%2 != 0)
          printf("%d  ", a[i]);
      }
      printf("\n\n\n");
    }
}