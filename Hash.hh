#pragma once
#include <stddef.h>
size_t BKDRHash(const char* str)
{
    size_t seed = 131; // 31、131、1313 都常用
    size_t hash = 0;
    while (*str)
        hash = hash * seed + static_cast<unsigned char>(*str++);
    return hash;
}

size_t DJBHash(const char* str)
{
    size_t hash = 5381;
    while (*str)
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(*str++); // hash * 33 + c
    return hash;
}

size_t SDBMHash(const char* str)
{
    size_t hash = 0;
    while (*str)
        hash = static_cast<unsigned char>(*str++) + (hash << 6) + (hash << 16) - hash;
    return hash;
}


size_t RSHash(const char* str)
{
    size_t b = 378551;
    size_t a = 63689;
    size_t hash = 0;

    while (*str)
    {
        hash = hash * a + static_cast<unsigned char>(*str++);
        a *= b;
    }
    return hash;
}


size_t APHash(const char* str)
{
    size_t hash = 0;
    for (int i = 0; *str; ++str, ++i)
    {
        if ((i & 1) == 0)
            hash ^= ((hash << 7) ^ static_cast<unsigned char>(*str) ^ (hash >> 3));
        else
            hash ^= (~((hash << 11) ^ static_cast<unsigned char>(*str) ^ (hash >> 5)));
    }
    return hash;
}
