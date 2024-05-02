#include<stdexcept>
#include"Domain.hpp"

Neighbourhood& Neighbourhood::operator=(const Neighbourhood& src)
{
    if(pos != nullptr) delete[] pos;
    pos = new coor[src.size];
    copy(pos, src.pos, src.size);
    size = src.size;
    return *this;
}

Domain::Domain(): _dimX(0), _dimY(0), _dimZ(0), _size(0), _buffer(nullptr), _bc(nullptr)
{
}
    

Domain::~Domain()
{
   
}

const m_int Domain::Void = 0;

Domain::Domain(m_int dimX, m_int dimY, m_int dimZ):
    _dimX(dimX), _dimY(dimY), _dimZ(dimZ), _bc(nullptr)
{
    _size = size_t(dimX) * size_t(dimY) * size_t(dimZ);
    _buffer = std::shared_ptr<m_int[]>(new m_int[_size], std::default_delete<m_int[]>());
    resetBuffer();
}

m_int Domain::operator()(m_int x, m_int y, m_int z) const
{
    return _buffer[y*_dimX*_dimZ + z*_dimX + x];
}
    
m_int& Domain::operator[](m_int pos)
{
    if(pos >= 0 && pos < _size) return _buffer[pos];
    else throw std::runtime_error("Invalid index - " + std::to_string(pos));
}


m_int& Domain::operator()(m_int x, m_int y, m_int z)
{
    return _buffer[y*_dimX*_dimZ + z*_dimX + x];
}


const m_int& Domain::operator[](m_int pos) const
{
    if(pos >= 0 && pos < _size) return _buffer[pos];
    else throw std::runtime_error("Invalid index - " + std::to_string(pos));
}


void Domain::resetBuffer()
{
    for(size_t i = 0; i < _size; i++)
    _buffer[i] = 0;
}

void Domain::clone(Domain& dest) const
{
    dest._dimX = _dimX;
    dest._dimY = _dimY;
    dest._dimZ = _dimZ;
    dest._size = _size;
    dest._buffer = _buffer;
    dest._neighbours = _neighbours;
    dest._bc = duplicate(_bc);
}

std::vector<m_int> Domain::around(m_int x, m_int y, m_int z)
{
    coor pos = {x,y,z};
    std::vector<m_int> values;
    values.reserve(_neighbours.size);
    for(m_int n = 0; n < _neighbours.size; n++)
    {
        coor moved = pos + _neighbours.pos[n];
        values.push_back(_bc->operator()(moved.x, moved.y, moved.z, *this));
    }
    return values;
}
