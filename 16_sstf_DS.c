#include<stdio.h>
int main()
{
    int n = 7;
    int q[7] = {82, 170, 43, 140, 24, 16, 190};
    int pos, mmt = 0;
    int min, dif; 
    int head = 50;
    
    printf("%d---->", head);
    for(int j = 0; j<n; j++)
    {
         min = 1000;
        for(int i = 0; i<n; i++)
        {
            if(q[i] != -1)
              {
                dif = abs(head - q[i]);
                if(dif < min)
                {
                    pos = i;
                    min = dif;
                }
             }
        }
        
        mmt = mmt + abs(head - q[pos]);
        head = q[pos];
        printf("%d---->", head);
        q[pos] = -1;
    }
    
    printf("\nTotal movement is = %d\n", mmt);
}