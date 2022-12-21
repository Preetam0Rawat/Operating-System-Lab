#include<stdio.h>
struct process
{
    int pid;
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
    int n;
    printf("Enter size : ");
    scanf("%d", &n);
    struct process p[n];
    
    for(int i =0; i< n; i++)
    {
       printf("Enter arrival time and burst time for procss %d : ", i);
       scanf("%d%d", &p[i].at, &p[i].bt);
       p[i].pid = i;
    }
    
    struct process temp;
    for(int i = 0; i< n ; i++)
     {
       for(int j = i+1; j <n; j++)
       {
          if(p[i]. at > p[j]. at)
           { temp = p[i];
             p[i] = p[j];
             p[j]  = temp;
           }
       }
     }
    
   
    for(int i = 0; i< n; i++)
    {
        if(i==0)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].st + p[i].bt; 
            p[i].rt = p[i].st - p[i].at;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        else
        if(p[i-1].ct < p[i].at)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].st + p[i].bt;
            p[i].rt = p[i].st - p[i].at;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            idle = idle + (p[i].at - p[i-1].ct); 
        }
        
        else
        {
            p[i].st = p[i-1].ct;
            p[i].ct = p[i].st + p[i].bt; 
            p[i].rt = p[i].st - p[i].at;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        
    }
    
    float cyc_len = p[n-1].ct - p[0].st;     
    float throughput = n/cyc_len;      
    float cpu = ((cyc_len - idle) / cyc_len) * 100;
    
    
        
    printf("\nProcess\t\tAt\tBt\tSt\tCt\tRt\tTt\tWt\n");
    
    for(int i = 0; i<n; i++)
    {
        printf("%d\t\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].rt, p[i].tat, p[i].wt);
    }
    
    
    printf("Throughput ; %0.2f\n", throughput);
    printf("CPU Utilization ; %0.2f\n", cpu);
}
