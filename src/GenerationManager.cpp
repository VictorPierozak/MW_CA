#include<omp.h> 
#include<iostream>
#include"GenerationManager.hpp"

GenerationManager::GenerationManager(m_int dimX, m_int dimY, m_int dimZ, m_int itrLimit):
    _domain(dimX, dimY, dimZ), _tmpdomain(dimX, dimY, dimZ), _itrLimit(itrLimit)
{
       
}

void GenerationManager::start()
{
    _nucleator->nucleation(_domain);
    _domain.copy(_tmpdomain);
    m_int dy = (_domain.dimY() + _threadsNumber - 1)/_threadsNumber;
    m_int y0 = 0;
    for(m_int i = 0; i < _threadsNumber; i++)
    {
        Generator::Subdomain subdomain = {0, _domain.dimX(), y0, (y0 + dy < _domain.dimY()) ? y0 + dy: _domain.dimY(), 0 , _domain.dimZ()};
        _generators.emplace_back(subdomain, _domain, _tmpdomain, _rule, _itrLimit);
        y0 += dy;
    }

   #pragma omp parallel num_threads(_threadsNumber)
    {
        m_int idx = omp_get_thread_num();
        while(_generators[idx].finish())
        {
            #pragma omp barrier
            _generators[idx].iteration();
            _generators[idx].swapBuffers();
            #pragma omp barrier
        }
    }
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