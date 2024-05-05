#include<stdexcept>
#include"BC.hpp"
#include"Domain.hpp"

m_int Periodic::operator()(m_int x, m_int y, m_int z, const Domain& domain)
{
    return 0;
}

m_int Absorption::operator()(m_int x, m_int y, m_int z, const Domain& domain)
{
    if(inside(x,y,z)) return domain(x,y,z);
    else return Domain::Void;
}

