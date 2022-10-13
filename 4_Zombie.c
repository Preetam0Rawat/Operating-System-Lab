//Zombie State of child processs : Child becomes zombie as parent is sleeping when child is running.
#include<stdio.h>
int main()
{
    int x =  fork();
    
    if( x == 0)
    {
        
      printf("This is child process\n");
      printf("Child's process id is: %d\n", getpid());
      printf("Child's Parent's process id is : %d\n\n\n", getppid());
    }
    
    
    if(x > 0)
    {
      sleep(3);    
      printf("This is Parent process\n");
      printf("Parent's process id is: %d\n\n\n", getpid());
     
    }
}