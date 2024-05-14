#include<stdexcept>
#include"Domain.hpp"

Domain::Domain(): _dimX(0), _dimY(0), _dimZ(0), _size(0), _buffer(nullptr), _bc(nullptr)
{
}
    

Domain::~Domain()
{
   
}

#ifdef INT_64
const m_int Domain::Void = __INT64_MAX__;
#endif

#ifdef INT_32
const m_int Domain::Void = __INT32_MAX__;
#endif

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
    _buffer[i] = Domain::Void;
}

void Domain::clone(Domain& dest) const
{
    dest._dimX = _dimX;
    dest._dimY = _dimY;
    dest._dimZ = _dimZ;
    dest._size = _size;
    dest._buffer = _buffer;
    dest._neighbours = _neighbours->clone();
    dest._bc = _bc->clone();
}

void Domain::copyBuffer(Domain& dest) const
{
    if(_size != dest._size) throw std::runtime_error("Buffers are not equal in size!");
    m_copy(dest._buffer.get(), _buffer.get(), _size);
}

void Domain::copy(Domain& dest) const
{
    dest._dimX = _dimX;
    dest._dimY = _dimY;
    dest._dimZ = _dimZ;
    dest._size = _size;
    copyBuffer(dest);
    dest._neighbours = _neighbours->clone();
    dest._bc = _bc->clone();
}

std::vector<m_int> Domain::around(m_int x, m_int y, m_int z)
{
    return _neighbours->around(x,y,z, *this);
}

void Domain::for_each(std::function<void(m_int&)> op)
{
    for(m_int idx = 0; idx < _size; idx++)
    {
        op(_buffer[idx]);
    }
}

void Domain::for_each(std::function<void(const m_int&)> op) const
{
     for(m_int idx = 0; idx < _size; idx++)
    {
        op(_buffer[idx]);
    }
}

std::vector<m_int> Moore::around(m_int x, m_int y, m_int z, Domain& domain) 
{
    coor cc = {x,y,z};
    std::vector<m_int> values;
    values.reserve(8);
    coor mov = {0,0,0};
    m_int idx = -1;

    for(m_int y = -1; y <= 1; y++)
    for(m_int x = -1; x <= 1; x++)
    {
        if(x == 0 && y == 0) continue;
        mov = {x,y,0};
        coor moved = cc + mov;
        idx = domain.bc()->operator()(moved.x, moved.y, moved.z);
        if(idx != -1) values.push_back(domain[idx]);
    }
    return values;
}

std::shared_ptr<Neighbourhood> Moore::clone() const
{
    return std::shared_ptr<Neighbourhood>(new Moore);
}

Random::Random(const vecrand_n& ns)
{
    neighbourhoods.resize(ns.size());
    std::vector<std::pair<m_int, m_float>> rnds;
    for(m_int i = 0; i < ns.size(); i++)
    {
        neighbourhoods[i].first = ns[i].first->clone();
        neighbourhoods[i].second = ns[i].second;
        rnds.emplace_back(i, neighbourhoods[i].second);
    }
    wheel.set(rnds);
}

Random::Random(const Random& obj)
{
    neighbourhoods.resize(obj.neighbourhoods.size());
    std::vector<std::pair<m_int, m_float>> rnds;
    for(m_int i = 0; i < neighbourhoods.size(); i++)
    {
        neighbourhoods[i].first = obj.neighbourhoods[i].first->clone();
        neighbourhoods[i].second = obj.neighbourhoods[i].second;
        rnds.emplace_back(i, neighbourhoods[i].second);
    }
    wheel.set(rnds);
}

std::vector<m_int> Random::around(m_int x, m_int y, m_int z, Domain& domain)
{
    return neighbourhoods[wheel.get()].first->around(x,y,z, domain);
}

std::shared_ptr<Neighbourhood> Random::clone() const
{
    return std::shared_ptr<Neighbourhood>(new Random(*this));
}

std::vector<m_int> Neumann::around(m_int x, m_int y, m_int z, Domain& domain) 
{
    coor cc = {x,y,z};
    std::vector<m_int> values;
    values.reserve(8);
    coor mov = {0,0,0};
    m_int idx = -1;

    for(m_int y = -1; y <= 1; y++)
    for(m_int x = -1; x <= 1; x++)
    {
        if(x != 0 && y != 0) continue;
        if(x == 0 && y == 0) continue;
        mov = {x,y,0};
        coor moved = cc + mov;
        idx = domain.bc()->operator()(moved.x, moved.y, moved.z);
        if(idx != -1) values.push_back(domain[idx]);
    }
    return values;
}

std::shared_ptr<Neighbourhood> Neumann::clone() const
{
    return std::shared_ptr<Neighbourhood>(new Neumann);
}
