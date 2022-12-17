#include<stdio.h>
void print_table(int * f_table, int f_size)
{
    for(int i = 0; i< f_size; i++)
    {
        printf("%d ", f_table[i]);
    }
    printf("\n");
}

int ispresent(int x, int * f_table, int f_size)
{
    int flag = 0;
    for(int i = 0; i < f_size; i++)
    {
        if(x == f_table[i])
        {
            flag =1; break;
        }
    }
    
    if(flag == 1)
      return 1;
    else
      return 0;
}

int main()
{
    int ref[] = {4, 7, 6, 1, 7, 6, 1, 2 ,7, 2, 2, 2, 6, 1, 3, 4, 6};
    int ref_size = 17;
    int f_size = 3;
    int f_table[f_size];
    int hit = 0;
    int pagefault = 0;
    int i = 0, j = 0;

    //Entering values when frame table is empty
    
    for(i = 0; i< f_size; i++)
    {
        f_table[i] = ref[i];
        pagefault++;
    }
    
    print_table(f_table, f_size);
    
    for(i = f_size; i<ref_size; i++)
    {
        if(ispresent(ref[i],f_table, f_size))
        {
            hit++;
        }
        
        else
        {
            if(j == f_size)
            { j = 0; }
            
            f_table[j] = ref[i];
            j++;
            pagefault++;
            print_table(f_table, f_size);
        }
    }
    
    printf("Total number of hit is : %d\n", hit);
    printf("Total number of pagefault is : %d ", pagefault);
}
