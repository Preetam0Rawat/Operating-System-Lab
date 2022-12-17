#include<stdio.h>
int findLRU(int  time[], int size)
{
  int pos = 0;
  int mn;
  
  mn = time[0];
  for(int i = 1; i<size; i++)
  {
      if(mn > time[i])
      {
          mn = time[i];
          pos = i;
      }
  }
  return pos;
}

int main()
{   
    int ref_size = 17;
    int ref[50] = {4, 7, 6, 1, 7, 6, 1, 2 ,7, 2, 2, 2, 6, 1, 3, 4, 6};
    int f_size = 4, pagefault = 0 , t = 0;
    int f_table[f_size] , flag1 , flag2 , time[10] ;
  
   
    for(int i = 0; i< f_size; i++)
         { f_table[i] = -1;}
    
     printf("REF STRING\t\tF_TABLE\t\t\t\tH/F");
    for(int i = 0 ;i< ref_size; i++)
    {
        flag1= 0; flag2 =0;
        
    // Checking hit
         for(int j = 0; j <f_size ;j++)
        {
            if(f_table[j] == ref[i])
            {
                t++;
                time[j] = t;
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        
        
    // Table empty
        if(flag1 == 0)
        {
            for(int j = 0; j< f_size; j++)
            {
                if(f_table[j] == -1)
                {
                    f_table[j] = ref[i];
                    pagefault++;
                    t++;
                    time[j] = t;
                    flag2 = 1;
                    break;
                }
                
            }
        }
        
       
        if(flag2 == 0)
        {
            int pos = findLRU(time, f_size);
            f_table[pos] = ref[i];
            pagefault++;
            t++;
            time[pos] = t;
        }
        
        printf("\n");
        printf("%d\t\t\t\t", ref[i]);
        for(int i =0 ; i<f_size; i++)
          printf("%d  ", f_table[i]);
        if(flag1 ==1 && flag2 ==1)
        printf("\t\tH");
        else
        printf("\t\tF");
        
    }
    
    printf("\nPagefault is = %d", pagefault);
}
