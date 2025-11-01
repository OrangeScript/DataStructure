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
#if 0
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

#endif
void InsertSort(int arr[], int size);
void ShellSort(int arr[], int size);
void SelectionSort(int arr[], int size);
void BubbleSort(int arr[], int length);
void QuickSort(int arr[],int left, int right);
void MergeSort(int arr[], int left, int right);

void RadixSort(int arr[], int size);
#if 0
int main()
{
     int arr[10];
    srand(time(NULL));
    int size = sizeof(arr)/sizeof(int);
    for(int i = 0; i < size; i ++)
    {
        arr[i] = rand()%100 + 1;
    }
    Print(arr,size);
    SelectionSort(arr,size);
    Print(arr,size);
    Print(arr,size);
}
#endif

#define COUNT 30
#if 0
int main()
{
    int arr[COUNT],brr[COUNT],crr[COUNT],drr[COUNT];
    srand(time(NULL));

    for(int i = 0; i < COUNT; i++)
    {
        int val = rand() % COUNT;
        arr[i] = val;
        brr[i] = val;
        crr[i] = val;
        drr[i] = val;
    }

    clock_t begin,end;
    begin = clock();
    QuickSort(arr,0,COUNT);
    end = clock();
    std::cout << "Bubble Sort spend:" << (end - begin) * 1.0 /CLOCKS_PER_SEC 
    << "s" << std::endl;

    
    begin = clock();
    SelectionSort(brr,COUNT);
    end = clock();
    std::cout << "Selection Sort spend:" << (end - begin) * 1.0 /CLOCKS_PER_SEC 
    << "s" << std::endl;

    
    begin = clock();
    InsertSort(crr,COUNT);
    end = clock();
    std::cout << "Insert Sort spend:" << (end - begin) * 1.0 /CLOCKS_PER_SEC 
    << "s" << std::endl;

    
    begin = clock();
    ShellSort(drr,COUNT);
    end = clock();
    std::cout << "Shell Sort spend:" << (end - begin) * 1.0 /CLOCKS_PER_SEC 
    << "s" << std::endl;
}
#endif
//#if 0
int main()
{
    
    int arr[COUNT];
    srand(time(NULL));

    for(int i = 0; i < COUNT; i++)
    {
        int val = rand() ;
        arr[i] = val;
    }
    arr[10] = -23;
    arr[20] = -123;
    arr[2] = -45;
    Print(arr,COUNT);
    RadixSort(arr,COUNT);
    Print(arr,COUNT);
}
//#endif

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

void Merge(int arr[],int left,int mid,int right)
{
    int p = left;
    int q = mid + 1;
    int i = 0;
    int *brr = new int[right - left + 1];
    while(p <= mid && q <= right)
    {
        if(arr[p] <= arr[q])
        {
            brr[i++] = arr[p];
            p ++; 
        }
        else
        {
            brr[i++] = arr[q];
            q ++;
        }
    }
    while(p <= mid)
    {
        brr[i++] = arr[p++];
    }
    while(q <= right)
    {
        brr[i++] = arr[q++];
    }
    //memcpy(arr+left,brr,i * sizeof(int));
    for(int j = 0; j < i; j++)
    {
        arr[left + j] = brr[j];
    }
    delete [] brr;
}
void MergeSort(int arr[], int left, int right)
{
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    
    MergeSort(arr, left, mid);
    MergeSort(arr,mid + 1, right);
    //[left,mid]
    //[mid + 1, right]
    Merge(arr,left,mid,right);
}
int Partition(int arr[], int left, int right);
int Partition_Hoare(int a[], int left, int right);
void swap1(int arr[], int l, int r);
void QuickSort(int arr[],int left, int right)
{
    if(left >= right)
        return;

    int pivot = Partition(arr,left,right);
    QuickSort(arr,left,pivot - 1);
    QuickSort(arr,pivot + 1,right);
}

int Partition(int arr[], int left, int right)
{
    int val = arr[left];
    int p = left, q = right;
    while(q != p)
    {
        while(arr[q] >= val && q > p) q--;
        while(arr[p] <= val && q > p) p++;
        swap1(arr,p,q);
    }
    arr[left] = arr[p];
    arr[p] = val;

    return p;
}
int Partition_Hoare(int a[], int left, int right){
    int i = left;
    int j = right;
    int key = a[left];

    while(i != j){
        while(i < j && a[j] >= key)      	 //向左找到小于基准值的值的下标
            j--;
        while(i < j && a[i] <= key)      	 //向右找到大于基准值的值的下标
            i++;
	swap1(a,i,j);
	}
    /*   i等于j时跳出循环 当前基准值此时在下标为i的位置(合适的位置)   */
    swap1(a,left, i);	                 //最左边的元素变为处于当前合适位置的元素,把基准值放在合适位置                                                 
    return i;                                  //返回合适位置(i,j都可以)
}
void swap1(int arr[], int l, int r)
{
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

void SelectionSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int min_index = i;
        for(int j = i ; j < size; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap1(arr,min_index,i);
    }
}

void ShellSort(int arr[], int size)
{
    int gap = size/2;
    for(; gap > 0; gap /= 2)
    {
        
            for(int j = gap; j < size; j ++)
            {
                int val = arr[j];
                int k = j - gap;
                while(k >= 0 && arr[k] > val) {
                    arr[k + gap] = arr[k];
                    k -= gap;
                }
                arr[k + gap] = val; 
            }
    }
}

#include <vector>
#include <string>
using namespace std;
void RadixSort(int arr[], int size)
{
    int maxData = abs(arr[0]);
    for(int i = 1; i < size; i++)
    {
        if(abs(arr[i]) > maxData)
        {
            maxData = abs(arr[i]);
        }
    }
     maxData = std::to_string(maxData).size();
    vector<vector<int>> bucket;

    for(int i = 0, dev = 1, mod = 10; i< maxData; i++,dev *= 10,mod *= 10)
    {
        bucket.resize(20);

        for(int j = 0; j < size; j++)
        {
            bucket[arr[j] % mod / dev + 10].push_back(arr[j]);
        }
        int k = 0;
        for(vector<int> v : bucket)
        {
            for(int x : v)
            {
                arr[k] = x;
                k++;
            }
            
        }
        bucket.clear();
    }
}