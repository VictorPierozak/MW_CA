#include<omp.h> 
#include<iostream>
#include"GenerationManager.hpp"

GenerationManager::GenerationManager(m_int dimX, m_int dimY, m_int dimZ, m_int itrLimit):
    _domain(dimX, dimY, dimZ), _tmpdomain(dimX, dimY, dimZ), _itrLimit(itrLimit)
{
       
}

void GenerationManager::setNeighbourhood(std::shared_ptr<Neighbourhood> n)
{
    _domain.setNeighbourhood(n);
}

void GenerationManager::setBC(std::shared_ptr<BC> bc)
{
    _domain.setBC(bc);
}

void GenerationManager::setRule(std::shared_ptr<Rule> rule)
{
    _rule = rule->clone();
}

template void GenerationManager::start<GeneratorCA> ();