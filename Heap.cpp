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

    void Print()
    {
        for(int i = 0; i < size_ ; i ++)
        {
            std::cout << que_[i] << ' ';
        }
        std::cout << std::endl;
    }

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
        int child;
        while((child = loc * 2 + 1) < size_)
        {
            if(child + 1 < size_ && comp_(que_[child + 1], que_[child]))
            {
                child ++;
            }

            if (!comp_(que_[child], val))
            break;

            que_[loc] = que_[child];
            loc = child;
        }
        que_[loc] = val;
    }
};

int main()
{
    PriorityQueue q;
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(4);
    q.push(9);
    q.push(10);
    q.push(22);
    q.push(4);
    q.push(7);
    q.Print();
    q.pop();
    q.Print();
    q.pop();
    q.Print();
    q.pop();
    q.Print();
    q.pop();
    q.Print();
}