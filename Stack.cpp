#include <iostream>

class SeqStack
{
private:
    int mcap;
    int *mpStack;
    int mtop;
public:
    SeqStack(int size = 10) 
    : mcap(size)
    , mtop(0)
    {
        mpStack = new int[10];
    }
    ~SeqStack()
    {
        delete []mpStack;
        mpStack = nullptr;
    }

public:
    void push(int val)
    {
        mpStack[mtop++] = val;
        if(mtop == mcap)
        resize(mcap*2);
    }

    int pop()
    {
        if(mtop == 0)
            throw "stack is empty";
        return mpStack[--mtop];
    }

    int top()const
    {
        if(mtop == 0)
            throw "empty";
        return mpStack[mtop-1];
    }

    bool empty()
    {
        return mtop == 0;
    }

    int size()const
    {
        return mtop;
    }
    
private:
    void resize(int newCap)
    {
        int *newStack = new int[newCap];
        memcpy(newStack,mpStack,mtop*sizeof(int));
        delete[] mpStack;
        mpStack  = newStack;
        mcap = newCap;
    }
};

int main()
{
    SeqStack s;
    int arr[] = {12,2,45,56,7,8,12};
    for(int v: arr)
    {
        s.push(v);
    }

    while(!s.empty())
    {
        std::cout << s.pop() << std::endl;
    }

    s.top();
}