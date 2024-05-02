#pragma once
#include"Generator.hpp"
#include"Nucleator.hpp"

class GenerationManager
{
    public:
    GenerationManager() = delete;
    GenerationManager(m_int dimX, m_int dimY, m_int dimZ, m_int itrLimit);

    void setRandomUniformNucleator(m_int statesNumber) { _nucleator = std::make_shared<RandomUniformNucleator>(statesNumber); }

    void start();

    std::shared_ptr<m_int[]> get() {return (std::shared_ptr<m_int[]>) _domain;}

    private:

    Domain _domain;

    std::vector<Generator> _generators;
    std::shared_ptr<Nucleator> _nucleator;
    std::shared_ptr<Rule> _rule;

    m_int _statesNumber;
    m_int _itrLimit;
    m_int _threadsNumber{12};
};