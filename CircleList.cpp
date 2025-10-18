#include <iostream>
#include <stdlib.h>
#include <time.h>


class CircleLink
{
private:
    struct Node
    {
        Node(int data = 0) : data_(data),next_(nullptr) {}
        int data_;
        Node* next_;
    };

    Node* head_;
    Node* tail_;

public:
    CircleLink()
    {
        head_ = new Node();
        tail_ = head_;
        head_->next_ = head_;
    }


    ~CircleLink()
    {
        Node* p = head_->next_;
        while(p != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
    }

public:
    void InsertTail(int val)
    {
        Node* n = new Node(val);
        tail_->next_ = n;
        n->next_ = head_;
        tail_ = n;
    }

    void InsertHead(int val)
    {
        Node* n = new Node(val);
        if(head_->next_ == nullptr)
        {
            tail_ = n;
        }
        n->next_ = head_->next_;
        head_->next_ = n;
    }

    void Remove(int val)
    {
        Node* q = head_;
        Node* p = head_->next_;

        while(p != head_)
        {
            if(p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                if(q->next_ == head_)
                {
                    tail_ = q;
                }
                return;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }

    bool Find(int val)const
    {
        Node* p = head_->next_;
        while(p != head_)
        {
            if(p->data_ == val)
            {
                return true;
            }
        }
        return false;
    }

    void Show()const
    {
        Node* p = head_->next_;
        while(p != head_)
        {
            std::cout << p->data_ << " ";
            p = p->next_;
        }
        std::cout << std::endl;
    }
};

int main()
{
    CircleLink* c = new CircleLink();
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        c->InsertTail(rand()% 100);
    }
    c->Show();
    c->InsertHead(100);
    c->InsertTail(200);
    c->Remove(200);
    c->Show();
}