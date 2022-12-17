#include<stdio.h>
void sort_queue( int * queue, int n)
{   int temp;
    for(int i = 0; i< n; i++)
    {
        for(int  j = i+1; j<n; j++)
        {
            if(queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}
int main()
{
    int n = 7, max = 199, beg = 0, end;
    int queue[7] = {82, 170, 43, 140, 24, 16, 190};
    
    int head = 50;
    int mmt = 0;
    
    mmt = max - head;        //1
    sort_queue(queue, 7);
              
          printf("%d---->", head);

    for(int i = 0; i< n; i++)
    {
        if(queue[i] > 50)
          printf("%d---->", queue[i]);
    }
    
              printf("%d---->", max);
              printf("%d---->", beg);

    mmt += max;    //2
    
     for(int i = 0; i< n; i++)
    {
        if(queue[i] < 50)
       {   printf("%d---->", queue[i]);
           end = queue[i];    
       }
    }
    
   
    
    mmt += end;
    printf("\nNet movement is : %d\n", mmt);
}