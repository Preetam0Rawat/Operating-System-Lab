#include<stdio.h>
#include<stdlib.h>
# define MAX 1000

struct Process{
    int pid,at,bt,ct, tat,wt,rt,st;
    int remt; // remaining time of particular process
};

int main(){

    int n  , cont = 0; // store of remaining process
    int mn; // track the min val
    float avgrt = 0, avgWT = 0 , avgTat = 0 ;
    float sumWT = 0 , sumTat = 0 , sumrt = 0;
    printf("Enter the number of Process - ");
    scanf("%d" , &n);

    struct Process p[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        p[i].pid = i;
        printf("Enter the Arrival Time and Burst Time for Process = %d - " , p[i].pid);
        scanf("%d%d" , &p[i].at , &p[i].bt);
        p[i].st = -1;
        p[i].remt = p[i].bt;        
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


  p[0].st = p[0].at;
  p[0].ct = p[0].st + p[0].bt;
  p[0].rt = p[0].st - p[0].at;
  p[0].tat = p[0].ct - p[0].at;
  p[0].wt = p[0].tat - p[0].bt;
  cont = p[0].ct;
  
  for(int i = 1; i< n ; i++)
     {
       for(int j = i+1; j <n; j++)
       {
          if(p[i].bt < p[j].bt)
           { temp = p[i];
             p[i] = p[j];
             p[j]  = temp;
           }
       }
       
     }
 for(int i = 1; i<n; i++)
 {
  p[i].st =  cont;
  p[i].ct = p[i].st + p[i].bt;
  p[i].rt = p[i].st - p[i].at;
  p[i].tat = p[i].ct - p[i].at;
  p[i].wt = p[i].tat - p[i].bt;
  cont = p[i].ct;
 }
      printf("process\t\tat\tbt\tst\tct\trt\ttat\twt\n");

    for(int i = 0 ; i < n ; i++){
        printf("%d\t\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid , p[i].at , p[i].bt , p[i].st , p[i].ct , p[i].rt , p[i].tat , p[i].wt);
    }
    
    
    return 0;
}