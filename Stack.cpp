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


class LinkStack
{
private:
    struct Node
    {
        Node(int data = 0)
            : data_(data)
            , next_(nullptr)
            {}
        int data_;
        Node* next_;
    };
    Node* head_;

public:
    LinkStack()
    {   
        head_ = new Node;
    }

    ~LinkStack()
    {
        Node* p = head_;
        while(p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

public:
    void push(int val)
    {
        Node* p = new Node(val);
        p->next_ = head_->next_;
        head_->next_ = p;
    }

    void pop()
    {
        if(head_->next_ == nullptr)
        {
            throw "stack is empty";
        }
        Node* p = head_->next_;
        head_->next_ = p->next_;
        delete p;
    }

    int top() const
    {
        if(head_->next_ == nullptr)
        {
            throw "empty";
        }
        return head_->next_->data_;
    }

    bool empty() const
    {
        return head_->next_ == nullptr;
    }
};

int main()
{
    LinkStack s;
    int arr[] = {12,2,45,56,7,8,12};
    for(int v: arr)
    {
        s.push(v);
    }

    while(!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    s.top();
}
