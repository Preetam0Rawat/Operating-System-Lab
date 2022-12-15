#include<stdio.h>
struct process
{
    int st;
    int ct;
    int at;
    int rt;
    int bt;
    int tat;
    int wt;
};

int main()
{   int idle = 0;
    struct process p[3];
    
    for(int i =0; i< 3; i++)
    {
       printf("Enter arrival time and burst time for procss %d :\n", i);
       scanf("%d%d", &p[i].at, &p[i].bt);
    }
    
    struct process temp;
    for(int i = 0; i< 3 ; i++)
     {
       for(int j = i+1; j <3; j++)
       {
          if(p[i]. at > p[j]. at)
           { temp = p[i];
             p[i] = p[j];
             p[j]  = temp;
           }
       }
     }
    
    printf("After sorting :\n");
    
    for(int i =0; i< 3; i++)
      printf("Process %d ------->   Arrival Time = %d    Burst Time : %d\n", i, p[i].at, p[i].bt);
    
    for(int i =0; i< 3; i++)
    {
        if(i==0)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].st + p[i].bt; 
            p[i].rt = p[i].st - p[i].at;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        
        if(p[i-1].ct < p[i].at)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].st + p[i].bt;
            p[i].rt = p[i].st - p[i].at;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            idle = idle + (p[i].at - p[i-1].ct); 
        }
        
        if(p[i-1].ct > p[i].at)
        {
            p[i].st = p[i-1].ct;
            p[i].ct = p[i].st + p[i].bt; 
            p[i].rt = p[i].st - p[i].at;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        
    }
    
    float cyc_len = p[2].ct - p[0].st;     
    float throughput = 3/cyc_len;      
    float cpu = ((cyc_len - idle) / cyc_len) * 100;
    
    for(int i =0; i< 3; i++)
    {
        printf("Start time ; %d\n", p[i].st);
        printf("Completion time : %d\n", p[i].ct);
        printf("Response time : %d\n", p[i].rt);
        printf("Turn around time : %d\n", p[i].tat);
        printf("wait time : %d\n\n\n\n", p[i].wt);
        
        
    }
    
    printf("Throughput ; %0.2f\n", throughput);
    printf("CPU Utilization ; %0.2f\n", cpu);
}