// Online C compiler to run C program online
#include <stdio.h>


int main() 
{
    int p = 5;
    int r = 3;
    int alloc[5][3] = {{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}};
    int max[5][3] = {{7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3}};
    int need[p][r];
    int avail[3] = {3,3,2};
    int i,j;
    
 
        // for(i = 0; i< p; i++)
        //   { printf("Enter thea max of process %d : ", i);
        //         for(j = 0; j<r; j++)
        //           {scanf("%d",&max[i][j]);}
        //   }

        // for(i = 0; i< p; i++)
        //   { printf("Enter the allocated to process %d : ", i);
        //         for(j = 0; j<r; j++)
        //           {scanf("%d",&alloc[i][j]);}
        //   }
           
        for(i = 0; i< p; i++)
           {    for(j = 0; j<r; j++)
                  {
                      need[i][j]  =  abs(max[i][j] - alloc[i][j]);
                  }
           }
           
           
           for(i = 0; i< p; i++)
           { printf("The need of process %d is:" , i);
                for(j = 0; j<r; j++)
                  {
                      printf("%d    ",need[i][j]);
                  }    printf("\n");
           }

    
    int k = 0, flag;
    int seq[10], finish[10];
    for(i = 0; i<p; i++)
    {
        finish[i] = 0;     //Incomplete
    }
    
    for(i = 0; i<p; i++)
    {   flag = 0;
        if(finish[i] == 0)
        {
            for(j =0; j<r; j++)
            {
                if(need[i][j] > avail[j])
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
            {
                seq[k] = i+1; 
                k++;
                finish[i] = 1;
                for(j =0; j<r; j++)
                   avail[j] += alloc[i][j];
                i = -1;
            }
        }
    }
    
     flag = 0;     //Again using flag
     
     for(i = 0; i<p; i++)
     {
         if(finish[i] == 0)
         {
             flag = 1;
             break;
         }
     }
     
     if(flag == 0)
     {  printf("No deadlock\nSafe sequence is:");
          for(i = 0; i<p; i++)
              printf("%d  ", seq[i]);
     }
     else
     {
         printf("Unsafe");
     }
     
}