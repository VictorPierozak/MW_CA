#pragma once
#include<cstdint>

#ifndef NOT_DEFAULT
#define INT_64
#define FLOAT_64
#define UINT_16
#endif

#ifdef INT_64
typedef int64_t m_int;
#define M_INT_MAX __INT64_MAX__
#endif

#ifdef INT_32
typedef int32_t
#define M_INT_MAX __INT32_MAX__
#endif

#ifdef FLOAT_64
typedef double m_float;
#endif

#ifdef FLOAT_32
typedef float m_float;
#endif

#ifdef UINT_16
typedef uint16_t m_uint;
#define M_UINT_MAX __UINT16_MAX__
#endif

#define VOID 0

struct coor
{
    coor& operator=(const coor& src)
    {
        x = src.x; y = src.y; z = src.z;
        return *this;
    }
    coor operator+(const coor& add)
    {
        return {add.x+x, add.y+y, add.z+z};
    }
    m_int x,y,z;
};

template<typename T>
void copy(T* dest, const T* src, size_t size)
{
    for(m_int i = 0; i < size; i++) dest[i] = src[i];
}

template<typename T>
void reset(T* array, size_t size, T value)
{
    for(m_int i = 0; i < size; i++) array[i] = value;
}

