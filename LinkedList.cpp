#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Node
{
    Node(int data = 0):data_(data),next_(nullptr){}
    int data_;
    Node* next_;
};

class Clink
{

private:
    Node* head_;

public:
    Clink()
    {
        head_ = new Node();
    }

    ~Clink()
    {
        //release nodes
        Node* p = head_->next_, *q = head_;
        while(p != nullptr)
        {
            q = p->next_;
            delete p;
            p = q;
        }
    }

public:
    void InsertTail(int val)
    {
        //find the last one
        Node* p = head_;

        while((*p).next_ != nullptr) p = p->next_;

        Node* n = new Node(val);

        p->next_ = n;
        //attach
    }
    
    void InsertHead(int val)
    {
        Node *n = new Node(val);
        n->next_ = head_->next_;
        head_->next_ = n;
    }
    
    void Remove(int val)
    {
        Node* p = head_->next_, *q = head_;
        while(p != nullptr)
        {
            if(p->data_ != val)
            {   
                q = p;
                p = p->next_;
                
            }
            else
            {
                q->next_ = p->next_;
                delete[] p;
                return;
            }
        }
    }

    void RemoveAll(int val)
    {
        Node* p = head_->next_, *q = head_;
        while(p != nullptr)
        {
            if(p->data_ != val)
            {   
                q = p;
                p = p->next_;
                
            }
            else
            {
                q->next_ = p->next_;
                delete p;
                p = q->next_;
            }
        }
    }

    void Show()
    {
        Node* p = head_->next_;
        while(p != nullptr)
        {
            std::cout << p->data_ << " ";
            p = p->next_;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Clink link;
    srand(time(0));
    for(int i=0 ; i< 10;i++)
    {
        int val = rand()%100;
        link.InsertTail(val);
        std::cout << val<< " ";
    }
    std::cout << std::endl;
    link.Show();
    link.InsertHead(23);
    
    link.InsertHead(23);
    
    link.InsertTail(23);
    link.Show();

    link.Remove(23);
    link.Show();
    link.RemoveAll(23);
    link.Show();
}