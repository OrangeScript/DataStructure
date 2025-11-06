#include <iostream>

using namespace std;
#include "Hash.hh"
#include <vector>
#include <string>
class BloomFilter
{
private:
    int bitSize_;
    vector<int> bitmap_;
public:
    BloomFilter(int size = 1471)
        : bitSize_(size)
    {
        bitmap_.resize(bitSize_ / 32 + 1);
    }

    void setBit(const char* key)
    {
        //calculate k * val
        int idx1 = BKDRHash(key) % bitSize_;
        int idx2 = RSHash(key) % bitSize_;
        int idx3 = APHash(key) % bitSize_;

        int index, offset;
        index = idx1 / 32;
        offset = idx1 % 32;
        bitmap_[index] |= (1 << offset);
        index = idx2 / 32;
        offset = idx2 % 32;
        bitmap_[index] |= (1 << offset);
        index = idx3 / 32;
        offset = idx3 % 32;
        bitmap_[index] |= (1 << offset);
    }

    bool getBit(const char* str)
    {
        int idx1 = BKDRHash(str) % bitSize_;
        int idx2 = RSHash(str) % bitSize_;
        int idx3 = APHash(str) % bitSize_;

        int index, offset;
        index = idx1 / 32;
        offset = idx1 % 32;
        if(0 == (bitmap_[index] & (1 << offset)))
        {
            return false;
        }
        index = idx2 / 32;
        offset = idx2 % 32;
        if(0 == (bitmap_[index] & (1 << offset)))
        {
            return false;
        }
        index = idx3 / 32;
        offset = idx3 % 32;
        if(0 == (bitmap_[index] & (1 << offset)))
        {
            return false;
        }
        return true;
    }
};
class BlackList
{
private:
    BloomFilter bloom_;

public:
    void add(string url)
    {
        bloom_.setBit(url.c_str());
    }

    bool query(string url)
    {
        return bloom_.getBit(url.c_str());
    }
};
int main()
{
    BlackList list;
    list.add("http://www.baidu.com");
    cout << list.query("http://www.baidu.com") <<endl;


}   