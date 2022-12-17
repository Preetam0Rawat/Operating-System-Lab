#include<stdio.h>
int main()
{
    int n = 5;
    int queue[5] = {23 , 89, 132, 42, 187};
    
    int head = 100;
    int mmt = 0;
    
    for(int i = 0; i<5; i++)
    {
       printf("%d---->", queue[i]);
    }
    
    
    for(int i = 0; i<5; i++)
    {
        mmt += abs(head - queue[i]);
        head = queue[i];
    }
    
    printf("\nNet movement is : %d\n", mmt);
}