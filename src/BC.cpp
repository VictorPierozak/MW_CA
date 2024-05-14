#include<stdexcept>
#include"BC.hpp"
#include"Domain.hpp"

m_int Periodic::operator()(m_int x, m_int y, m_int z)
{
    if(x >= _dimX) x = x - _dimX;
    else if(x < 0) x = _dimX + x;

    if(y >= _dimY) y = y - _dimY;
    else if(y < 0) y = _dimY + y;

    if(z >= _dimZ) z = z - _dimZ;
    else if(z < 0) z = _dimZ + z;
    return y*_dimX*_dimZ + z*_dimX + x;
}

m_int Absorption::operator()(m_int x, m_int y, m_int z)
{
    if(inside(x,y,z)) return y*_dimX*_dimZ + z*_dimX + x;
    else return -1;
}

