#pragma once
#include"Generator.hpp"
#include"GeneratorCA.hpp"
#include"Nucleator.hpp"
#include<omp.h>

class GenerationManager
{
    public:
    GenerationManager() = delete;
    GenerationManager(m_int dimX, m_int dimY, m_int dimZ, m_int itrLimit);

    void setNucleator(std::shared_ptr<Nucleator> ptr) { _nucleator = ptr; _statesNumber = ptr->statesNumber(); }
    void setNeighbourhood(std::shared_ptr<Neighbourhood> n);
    void setBC(std::shared_ptr<BC> bc);
    void setRule(std::shared_ptr<Rule> rule);
    void setThreadsNumber(m_int n) {_threadsNumber = n;}

    template<typename GeneratorType>
    void start()
    {
        _nucleator->nucleation(_domain);
        _domain.copy(_tmpdomain);
        m_int dy = (_domain.dimY() + _threadsNumber - 1)/_threadsNumber;
        m_int y0 = 0;
        std::vector<std::shared_ptr<Generator>> generators;
        for(m_int i = 0; i < _threadsNumber; i++)
        {
            Generator::Subspace subdomain = {0, _domain.dimX(), y0, (y0 + dy < _domain.dimY()) ? y0 + dy: _domain.dimY(), 0 , _domain.dimZ()};
            generators.emplace_back(new GeneratorType(subdomain, _domain, _tmpdomain, _rule, _itrLimit));
            y0 += dy;
        }

        #pragma omp parallel num_threads(_threadsNumber)
        {
            m_int idx = omp_get_thread_num();
            #pragma omp single
            {
                std::cout << idx << '\t';
            }
            while(generators[idx]->work())
            {
                #pragma omp barrier
                generators[idx]->iteration();
                #pragma omp barrier
            }
        }
    }

    void startCA();
    void startMC();

    std::shared_ptr<m_int[]> get() {return (std::shared_ptr<m_int[]>) _domain;}

    Domain& domain() { return _domain; }
    m_int stateNumber() const { return _statesNumber; }

    private:

    Domain _domain;
    Domain _tmpdomain;

    std::shared_ptr<Nucleator> _nucleator;
    std::shared_ptr<Rule> _rule;

    m_int _statesNumber;
    m_int _itrLimit;
    m_int _threadsNumber{1};
};