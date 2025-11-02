#include <iostream>
#include <functional>

class PriorityQueue
{
private:
    using Comp = std::function<bool(int,int)>;
    int cap_;
    int size_;
    int* que_;
    Comp comp_;
public:
    PriorityQueue(Comp comp = std::greater<int>())
        : cap_(20)
        , size_(0)
        , comp_(comp)
    {
        que_ = new int[cap_];
    }

    ~PriorityQueue()
    {
        delete []que_;
    }

    void push(int val)
    {
        if(size_ == cap_)
        {
            int* p = new int[cap_ * 2];
            memcpy(p,que_,size_*sizeof(int));
            cap_ = cap_ * 2;
            delete[] que_;
            que_ = p;
            //p = nullptr;//is it needed?
        }
        SiftUp(size_,val);
        size_ ++;
    }

    void pop()
    {
        if(size_ == 0)
            throw "queue is empty";
        size_--;
        que_[0] = que_[size_]; 
        SiftDown(0,que_[0]);
    }

    int top()
    {
        return que_[0];
    }
    void Print()
    {
        for(int i = 0; i < size_ ; i ++)
        {
            std::cout << que_[i] << ' ';
        }
        std::cout << std::endl;
    }
    
    friend void HeapSort(int arr[],int size);
private:
    void SiftUp(int loc, int val)
    {
        if(loc == 0)
        {
            que_[loc] = val;
            return;
        }
        int father = (loc - 1) / 2;
        if(comp_(val,que_[father]))
        {
            que_[loc] = que_[father];
            loc = father;
            SiftUp(loc, val);
        }
        else
        {
            que_[loc] = val;
        }

    }

    void SiftDown(int loc, int val)
    {
        int child = loc * 2 + 1;
        if(child < size_)
        {
            if(child + 1 < size_ && comp_(que_[child + 1],que_[child]))
            {
                child = child + 1;
            }
            if(comp_(que_[child],val))
            {
                que_[loc] = que_[child];
                loc = child;
                SiftDown(loc,val);

            }
            else
            {
                que_[loc] = val;
            }
        }
        else
        {
            que_[loc] = val;
        }
        
    }
};

void siftdown(int arr[], int loc, int size)
{
    int child;
    int val = arr[loc];
    while((child = loc * 2 + 1) < size)
    {
        if(child + 1 < size && arr[child + 1] > arr[child])
            child = child + 1;
        if(arr[child] > val)
        {
            arr[loc] = arr[child];
            loc = child;
        }
        else
        {
            break;
        }
    }
    arr[loc] = val;
    
}

void swap1(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void HeapSort(int arr[], int size)
{
    
    for(int i = (size - 1 - 1) / 2 ; i >= 0; i --)
    {
        siftdown(arr, i, size);
    }
    int index = size - 1;
    for(int i = 0; i < size; i++)
    {
        swap1(arr,0,index);
        siftdown(arr,0,index);
        index --;
    }
}


void HeapSort_rubbish(int arr[],int size)
{
    PriorityQueue q = PriorityQueue([](int a,int b){return a<b;});
    for(int i = 0; i < size; i++)
    {
        q.push(arr[i]);
    }
    for(int i = 0; i < size; i++)
    {
        arr[i] = q.top();
        q.pop();
    }
}
#include <time.h>
#include <stdlib.h>
#if 0
int main()
{
    srand(time(NULL));
    int arr[10];
    for(int i = 0; i< 10; i++)
    {
        arr[i] = rand()%100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    HeapSort(arr,10);

    for(int i = 0; i< 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
#endif