
#include <iostream>

using namespace std;

enum State
{
    STATE_UNUSE,
    STATE_USING,
    STATE_DEL,
};

struct Bucket
{
    int key_;
    State state_;
    Bucket(int key = 0, State state = STATE_UNUSE)
        : key_(key)
        , state_(state)
        {}
    

};

class HashTable
{
private:
    Bucket* table_;
    int tableSize_;
    int useBucketNum_;
    double loadFactor_;
    static const int PRIME_SIZE = 10;
    static int primes_[PRIME_SIZE];
    int primeIdx_;
public:
    HashTable(int size = primes_[0],double loadFactor = 0.75)
        : loadFactor_(loadFactor)
        , useBucketNum_(0)
        , primeIdx_(0)
    {
        if(size != primes_[0])
        {
            for(; primeIdx_ < PRIME_SIZE; primeIdx_++)
            {
                if(primes_[primeIdx_] > size)
                {
                    break;
                }
            }
            if(primeIdx_ == PRIME_SIZE)
            {
                primeIdx_ --;
            }
        }
        tableSize_ = primes_[primeIdx_];
        table_ = new Bucket[tableSize_];
    }

    ~HashTable()
    {
        delete [ ] table_;
        table_ = nullptr;
    }

    bool insert(int key)
    {
        double factor = useBucketNum_ * 1.0 /tableSize_;
        std::cout << factor <<std::endl;
        if(factor > loadFactor_)
        {
            expand();
        }
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if(table_[i].state_ != STATE_USING)
            {
                table_[i].state_ = STATE_USING;
                table_[i].key_ = key;
                useBucketNum_++;
                return true;
            }
            i = (i + 1) % tableSize_;
        } while (i != idx);
        return false;
    }

    void erase(int key)
    {
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if(table_[i].state_ == STATE_USING && table_[i].key_ == key)
            {
                table_[i].state_ = STATE_DEL;
                useBucketNum_ --;
            }
            i = (i + 1) % tableSize_;
        } while (i != idx && table_[i].state_ != STATE_UNUSE);
        
    }

    void expand()
    {
        ++primeIdx_;
        if(primeIdx_ == PRIME_SIZE)
        {
            throw "HashTable is too large";
        }
        Bucket *newTable = new Bucket[primes_[primeIdx_]];
        for(int i = 0; i < tableSize_; i++)
        {
            if(table_[i].state_ == STATE_USING)
            {
                int idx = table_[i].key_ % primes_[primeIdx_];

                int k = idx;
                do
                {
                    if(newTable[k].state_ != STATE_USING)
                    {
                        newTable[k].state_ = STATE_USING;
                        newTable[k].key_ = table_[i].key_;
                        break;
                    }
                    k = (k + 1) % primes_[primeIdx_];
                } while (k != idx);
                
            }
        }
        delete[] table_;
        table_ = newTable;
        tableSize_ = primes_[primeIdx_];
    }

    int find(int key)
    {
        int count = 0;
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if(table_[i].state_ == STATE_USING && table_[i].key_ == key)
            {
                count ++;
            }
            i = (i + 1) % tableSize_;
        } while (i != idx && table_[i].state_ != STATE_UNUSE);
        return count;
    }
};

int HashTable::primes_[PRIME_SIZE] = {3,7,23,47,97,251,443};

int main()
{
    HashTable htable;
    htable.insert(32);
    htable.insert(12);
    htable.insert(22);
    htable.insert(52);
    htable.insert(222);
}

#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class LinkHashTable
{
public:
    LinkHashTable(int size = primes_[0],double loadFactor = 0.75)
        : useBucketNum_(0)
        , loadFactor_(loadFactor)
        , primeIdx_(0)
    {
        if(size != primes_[0])
        {
            for(;primeIdx_ < PRIME_SIZE; primeIdx_ ++)
            {
                if(primes_[primeIdx_] >= size)
                {
                    break;
                }
            }
            if(primeIdx_ == PRIME_SIZE)
            {
                primeIdx_ --;
            }
        }
        table_.resize(primes_[primeIdx_]);
    }

    void insert(int key)
    {
        double factor = useBucketNum_ * 1.0 / table_.size();

        if(factor > loadFactor_)
        {
            expand();
        }

        int idx = key % table_.size();
        if(table_[idx].empty())
        {
            useBucketNum_++;
            table_[idx].emplace_front(key);
        }
        else
        {
             auto it = ::find(table_[idx].begin(),table_[idx].end(),key);
             if(it == table_[idx].end())
             {
                table_[idx].emplace_front(key);
             }
        }
    }

    void erase(int key)
    {
        int idx = key % table_.size();
        auto it = ::find(table_[idx].begin(),table_[idx].end(),key);
        if(it != table_[idx].end())
        {
            table_[idx].erase(it);
            if(table_[idx].empty())
            {useBucketNum_ --;}
        }
    }

    bool find(int key)
    {
        int idx = key % table_.size();
        auto it = ::find(table_[idx].begin(),table_[idx].end(),key);
        return it != table_[idx].end();
    }
private:
    vector<list<int>> table_;
    int useBucketNum_;
    double loadFactor_;
    static const int PRIME_SIZE = 10;
    static int primes_[PRIME_SIZE];
    int primeIdx_;

    void expand()
    {
        if(primeIdx_ + 1 == PRIME_SIZE)
        {
            throw "fail";
        }
        primeIdx_ ++;
        useBucketNum_ = 0;
        vector<list<int>> oldTable;
        table_.swap(oldTable);
        table_.resize(primes_[primeIdx_]);

        for(auto list : oldTable)
        {
            for(auto key : list)
            {
                int idx = key % table_.size();
                if(table_[idx].empty())
                {
                    useBucketNum_++;
                }
                table_[idx].emplace_front(key);
            }
        }
    }

    
};
int HashTable::primes_[PRIME_SIZE] = {3,7,23,47,97,251,443};
