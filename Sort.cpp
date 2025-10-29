#include <iostream>
#include <time.h>
#include <stdlib.h>
int BinarySearchRecurse(int arr[],int left, int right, int val)
{
    if(left > right)
    return -1;
    int mid = (left + right) / 2;
    if(arr[mid] == val)
    return mid;
    else if(arr[mid] > val)
    {
        return BinarySearchRecurse(arr,left,mid - 1,val);
    }
    else
    {
        return BinarySearchRecurse(arr,mid + 1, right, val); 
    }
}

int BinarySearch(int arr[], int size, int val)
{
    int first = 0;
    int last = size - 1;

    while(first <= last)
    {
        int mid = (first + last) / 2;
        if(arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}

void BubbleSort(int arr[], int length)
{

    for(int i = 0; i < length - 1; i++)
    {
        bool flag = false;
        for(int j = 0; j < length - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = true;
            }
        }
        if(flag == false)
        return;
    }
}

void bad_BubbleSort(int arr[], int length)
{

    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void Print(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#include <chrono>

int main()
{
    int arr[1000];
    srand(time(NULL));
    int size = sizeof(arr)/sizeof(int);
    for(int i = 0; i < size; i ++)
    {
        arr[i] = rand()%100 + 1;
    }
    int brr[1000];
    memcpy(brr,arr,size);
    
    auto start_time = std::chrono::high_resolution_clock::now();
    BubbleSort(arr,size);
    auto end_time = std::chrono::high_resolution_clock::now();
    

    std::cout << "run_time" << "  " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() 
    << "ms" << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    BubbleSort(brr,size);
    end_time = std::chrono::high_resolution_clock::now();
    
    std::cout << "run_time" << "  " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
    std::cout << BinarySearchRecurse(arr,0,size,6774) <<std::endl;
    std::cout << BinarySearchRecurse(arr,0,size,222) <<std::endl;
}
void InsertSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i]; 
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}