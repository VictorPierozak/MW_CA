#pragma once
#include<vector>
#include<memory>
#include<array>
#include"basic_types.h"
#include"BC.hpp"

struct Neighbourhood
{
    Neighbourhood& operator=(const Neighbourhood& src);
    coor* pos;
    m_int size;
};

#define IDX(x,y,z) y*domain.dimX()*domain.dimZ() + z*domain.dimX() + x

class Domain
{
    public:

    Domain();
    Domain(const Domain&) = delete;
    Domain(Domain&&) = delete;
    ~Domain();
    Domain& operator=(const Domain&) = delete;

    Domain(m_int dimX, m_int dimY, m_int dimZ);

    static const m_int Void;

    void clone(Domain& dest) const;
    void resetBuffer();

    m_int  operator()(m_int, m_int, m_int) const;
    m_int& operator[](m_int);

    //const m_int& operator()(m_int, m_int, m_int) const;
    const m_int& operator[](m_int) const;

    bool allocated() const {return _buffer != nullptr; }

    operator bool() const { return allocated(); }
    explicit operator std::shared_ptr<m_int[]>() {return _buffer;}

    std::vector<m_int> around(m_int x, m_int y, m_int z);

    void setNeighbourhood(Neighbourhood& org) { _neighbours = org; }
    void setBC(std::shared_ptr<BC> bc) { _bc = duplicate(bc); }

    m_int dimX() const { return _dimX; }
    m_int dimY() const { return _dimY; }
    m_int dimZ() const { return _dimZ; }

    private:

    Neighbourhood _neighbours;
    m_int _dimX, _dimY, _dimZ;
    size_t _size;
    std::shared_ptr<m_int[]> _buffer;

    std::shared_ptr<BC> _bc;
};

