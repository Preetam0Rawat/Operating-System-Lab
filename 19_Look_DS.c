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

void rev_sort( int * queue, int n)
{   int temp;
    for(int i = 0; i< n; i++)
    {
        for(int  j = i+1; j<n; j++)
        {
            if(queue[i] < queue[j])
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
    int n = 7;
    int queue[7] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50;
    int mmt = 0;
    

    sort_queue(queue, 7);
    
                                    mmt = queue[6] - head; 
    printf("%d\n", mmt);
              
          printf("%d---->", head);

    for(int i = 0; i< n; i++)
    {
        if(queue[i] > 50)
          printf("%d---->", queue[i]);
    }
    

    mmt += queue[6] - queue[0];    //2
    
    rev_sort(queue, 7);
     for(int i = 0; i< n; i++)
    {
        if(queue[i] < 50)
          printf("%d---->", queue[i]);
    }
  
    printf("\nNet movement is : %d\n", mmt);
}