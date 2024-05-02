#include"Nucleator.hpp"

void RandomUniformNucleator::nucleation(Domain& domain) 
{
    std::uniform_int_distribution xdist(0, (int)domain.dimX());
    std::uniform_int_distribution ydist(0, (int)domain.dimY());
    std::uniform_int_distribution zdist(0, (int)domain.dimZ());
    for(m_int s = 0; s < _statesNumber; s++)
    {
        m_int x = xdist(_rand);
        m_int y = ydist(_rand);
        m_int z = zdist(_rand);
        domain[IDX(x,y,z)] = s;
    }
}