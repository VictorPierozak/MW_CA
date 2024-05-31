#include<omp.h> 
#include<iostream>
#include"GenerationManager.hpp"
#include"GeneratorMC.hpp"
#include"Timer.hpp"
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

void GenerationManager::execute(std::vector<std::shared_ptr<Generator>> &generators)
{
    #pragma omp parallel num_threads(_threadsNumber)
    {
        m_int idx = omp_get_thread_num();

        while(generators[idx]->work())
        {
            #pragma omp barrier
            generators[idx]->iteration();
            #pragma omp barrier
        }
    }
}

