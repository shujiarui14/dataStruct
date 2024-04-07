#include <stdio.h>

void print_array(int arr[],int n)
{
    int i=0;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}



void insert_sort(int arr[],int n)
{
    printf("排序前的数组：");
    print_array(arr,n);
    int i=1;
    for (; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>-1&&arr[j]>key)
        {
            /* code */
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printf("排序过程时数组：");
        print_array(arr,n);
    }
    
}

int main()
{
    int arr[10]={34,56,78,99,7,6,556,77,44,23};
    insert_sort(arr,10);
    return 0;
}
