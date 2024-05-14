#include"GeneratorMC.hpp"

GeneratorMC::GeneratorMC(const Subspace& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit):
Generator(subdomain, domain_A, domain_B, rule, itrLimit)
{

    for(m_int y = _subspace.y0; y < _subspace.y1; y++)
    for(m_int z = _subspace.z0; z < _subspace.z1; z++)
    for(m_int x = _subspace.x0; x < _subspace.x1; x++)
    {
        list_A.emplace(std::next(list_A.begin(), (m_int)_dist(_rand)*list_A.size()), coor{x,y,z});   
    }
    list_current = &list_A;
    list_next = &list_B;
}

void GeneratorMC::iteration()
{
    while(loop())
    {
        coor pos = draw();
    }
    std::swap(list_current, list_next);
    _itrCounter++;
}

coor GeneratorMC::draw()
{
    coor result = list_current->front();
    list_current->pop_front();
    list_next->emplace(std::next(list_next->begin(), (m_int)_dist(_rand)*list_next->size()), result);
    return result;
}

bool GeneratorMC::loop()
{
    return list_current->size() != 0;
}