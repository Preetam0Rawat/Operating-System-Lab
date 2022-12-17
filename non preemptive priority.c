#include<stdio.h>
#include<stdlib.h>
# define MIN -1

struct Process{
    int pid,at,bt,ct, tat,wt,rt,st, py, done;
};

int main(){

    int n  , cont = 0, remain = 0; // store of remaining process
    int mn; // track the min val
    float avgrt = 0, avgWT = 0 , avgTat = 0 ;
    float sumWT = 0 , sumTat = 0 , sumrt = 0;
    printf("Enter the number of Process - ");
    scanf("%d" , &n);

    struct Process p[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        p[i].pid = i;
        printf("Enter the Arrival Time and Burst Time and priority for Process = %d - " , p[i].pid);
        scanf("%d%d%d" , &p[i].at , &p[i].bt, &p[i].py);
             p[i].done = 0;
    }

    // bubble sort
    struct Process temp;

    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                temp = p[j];
                p[j]= p[j+1];
                p[j+1]= temp;
            }
        }
    }
    p[0].st = -1;
    p[n].py = MIN;
   
    for(int time = 0 ; remain != n ; time++)
    {
        mn = n;
        
        // in this loop we are finding the min of all avaliable process in the queue
        for(int i = 0 ; i < n ; i++)
        {
            if(p[i].at <= cont && p[i].py > p[mn].py && p[i].done ==0)
            {
                mn = i;
            }
        }

        if(p[mn].st == -1)
        {
            p[mn].st = time;
            p[mn].ct = p[mn].st + p[mn].bt;
            p[mn].tat = p[mn].ct - p[mn].at;
            p[mn].wt = p[mn].tat - p[mn].bt;
            p[mn].rt = p[mn].st-p[mn].at;
            p[mn].done = 1;
            remain++;
            cont  = p[mn].ct;
        }
        else
        {
            p[mn].st = cont;
            p[mn].ct = p[mn].st + p[mn].bt;
            p[mn].tat = p[mn].ct - p[mn].at;
            p[mn].wt = p[mn].tat - p[mn].bt;
            p[mn].rt = p[mn].st-p[mn].at;
            p[mn].done = 1;
            remain++; 
                        cont  = p[mn].ct;

            
        }        


    }
   
   printf("process\t\tat\tbt\tst\tct\trt\ttat\twt\n");
    
    for(int i = 0 ; i < n ; i++){
        printf("%d\t\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid , p[i].at , p[i].bt , p[i].st , p[i].ct , p[i].rt , p[i].tat , p[i].wt);
    }
    
    return 0;
}