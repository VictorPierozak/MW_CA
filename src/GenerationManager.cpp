#include<omp.h> 
#include<iostream>
#include"GenerationManager.hpp"
#include"GeneratorMC.hpp"
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

void GenerationManager::startCA()
    {
        _domain.copy(_tmpdomain);
        m_int dy = (_domain.dimY() + _threadsNumber - 1)/_threadsNumber;
        m_int y0 = 0;
        std::vector<std::shared_ptr<Generator>> generators;
        for(m_int i = 0; i < _threadsNumber; i++)
        {
            Generator::Subspace subdomain = {0, _domain.dimX(), y0, (y0 + dy < _domain.dimY()) ? y0 + dy: _domain.dimY(), 0 , _domain.dimZ()};
            generators.emplace_back(new GeneratorCA(subdomain, _domain, _tmpdomain, _rule, _itrLimit));
            y0 += dy;
        }

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

void GenerationManager::startMC()
{
    _domain.copy(_tmpdomain);
    m_int dy = (_domain.dimY() + _threadsNumber - 1)/_threadsNumber;
    m_int y0 = 0;
    std::vector<std::shared_ptr<Generator>> generators;
    for(m_int i = 0; i < _threadsNumber; i++)
    {
        Generator::Subspace subdomain = {0, _domain.dimX(), y0, (y0 + dy < _domain.dimY()) ? y0 + dy: _domain.dimY(), 0 , _domain.dimZ()};
        generators.emplace_back(new GeneratorMC(subdomain, _domain, _tmpdomain, _rule, _itrLimit));
        y0 += dy;
    }

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

