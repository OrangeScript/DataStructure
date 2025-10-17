#include <iostream>

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
    }

};