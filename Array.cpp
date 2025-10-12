#include <iostream>
#include <stdlib.h>
#include <time.h>
class Array{
public:
    Array(int size = 10): mCur(0), m_capacity(size){
        m_data = new int[m_capacity];
    }
    ~Array()
    {
        delete[] m_data;
        m_data = nullptr; 
    }
private:
    int* m_data;
    int mCur;
    int m_capacity;
    void expand(int newSize)
    {
        int *p = new int[newSize];
        memcpy(p,m_data,sizeof(int) * m_capacity);
        delete []m_data;
        m_data = p;
        m_capacity = newSize;
    }
public:
    void push_back(int value)
    {
        if(mCur == m_capacity)
        {
            expand(2 * m_capacity);
        }
        m_data[mCur++] = value;
    }
    void pop_back()
    {
        if(mCur == 0)
            return;
        mCur--;
    }

    void insert(int pos, int val)
    {
        if(pos < 0 || pos >mCur)
        {
            return;
        }

        if(mCur == m_capacity)
        {
            expand(2 * m_capacity);
        }

        for(int i = mCur - 1; i >= pos; i--)
        {
            m_data[i+1] = m_data[i];
        }

        m_data[pos] = val;
        mCur++;
    }

    void erase(int pos)
    {
        if(pos >= mCur || pos < 0)
        {
            return;
        }

        for(int i = pos; i < mCur - 1; i++)
        {
            m_data[i] = m_data[i+1];
        }

        mCur--;
    }

    int find(int val)
    {
        for(int i = 0;i < mCur; i++)
        {
            if(m_data[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void show()const
    {
        for(int i = 0;i < mCur; i++)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

#if 0
int main()
{
    Array arr;
    srand(time(0));
    for(int i = 0; i< 10; i++)
    {
        arr.push_back(rand()%100);
    }
    arr.show();
    arr.pop_back();
    arr.show();
    arr.insert(0,10);
    arr.show();
    arr.insert(10,200);
    arr.show();
}
#endif

#include <string.h>
void Reverse(char* array, int size)
{
    char* p = array;
    char* q = array + size -1;
    int val;
    while(p < q)
    {
        val = *p;
        *p = *q;
        *q = val;
        p++;q--;
    }
}

void AdjustArray(int arr[], int size)
{
    int* p = arr;
    int* q = arr+size-1;
    while(p < q)
    {
        while((*p &0x1) == 1) p++;
        while((*q & 0x1) == 0 ) q--;
        if(p > q)
        return;
        int tmp = *p;
        *p = *q;
        *q = tmp;
        p++; q--;
    }
}

int main()
{
    int arr[10] = {0};
    srand(time(0));
    for(int i = 0; i< 10; i++)
    {
        arr[i] = rand()%100;
    }
    for(int v : arr)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    AdjustArray(arr,10);
    for(int v : arr)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

#if 0
int main()
{
    char arr[] = "hello world";
    
    Reverse(arr, strlen(arr));

    std::cout << arr << std::endl;
}
#endif


