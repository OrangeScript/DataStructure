#include <iostream>

class Queue
{
private:
    int* pQueue_;
    int front_;
    int rear_;
    int cap_;

public:
    Queue(int data = 10)
        : cap_(data)
        , front_(0)
        , rear_(0)
    {
        pQueue_ = new int[cap_];
    } 

    ~Queue()
    {
        delete [] pQueue_;
        pQueue_ = nullptr;
    }

public:
    void push(int val)
    {
        if(front_ == (rear_ + 1) % cap_)
            expand(2*cap_);
        pQueue_[rear_] = val;
        rear_ = (rear_ + 1) % cap_;
    }
    
    void pop()
    {
        if(front_ == rear_)
        {
            throw "queue is empty";
        }
        front_ = (front_ + 1) % cap_;
    }

    int front() const
    {
        if(front_ == rear_)
            throw "empty";
        return pQueue_[front_];
    }

    int back() const
    {
        if(front_ == rear_)
            throw "empty";
        return pQueue_[(rear_ - 1 + cap_) % cap_];
    }

    bool empty() const
    {
        return front_ == rear_;
    }

    int size() const
    {
        return (rear_ - front_ + cap_) % cap_;
    }

private:
    void expand(int newSize)
    {
        int* n = new int[newSize];
        for(int i = 0; i < size(); i++)
        {
            n[i] = pQueue_[(front_ + i) % cap_];
        }
        rear_ = size();
        cap_ = newSize;
        front_ = 0;
        delete [] pQueue_;
        pQueue_ = n;
    }
};

int main()
{
    Queue que;

    int arr[] = {1,24,4,5,67,8,9,24,6,2};
    for(int v: arr)
    {
        que.push(v);
    }
    std::cout << que.front() <<std::endl;
    std::cout << que.back() <<std::endl;
    std::cout << que.size() << std::endl;

    que.push(12);
    std::cout << que.front() <<std::endl;
    std::cout << que.back() <<std::endl;
    
    std::cout << que.size() << std::endl;
}