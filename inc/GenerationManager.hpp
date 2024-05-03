#pragma once
#include"Generator.hpp"
#include"Nucleator.hpp"

class GenerationManager
{
    public:
    GenerationManager() = delete;
    GenerationManager(m_int dimX, m_int dimY, m_int dimZ, m_int itrLimit);

    void setRandomUniformNucleator(m_int statesNumber) { _nucleator = std::make_shared<RandomUniformNucleator>(statesNumber); _statesNumber=statesNumber; }
    void setNeighbouthood(Neighbourhood& n);
    void setBC(std::shared_ptr<BC> bc);
    void setRule(std::shared_ptr<Rule> rule);
    void setThreadsNumber(m_int n) {_threadsNumber = n;}

    void start();

    std::shared_ptr<m_int[]> get() {return (std::shared_ptr<m_int[]>) _domain;}

    Domain& domain() { return _domain; }
    m_int stateNumber() const { return _statesNumber; }

    private:

    Domain _domain;
    Domain _tmpdomain;

    std::vector<Generator> _generators;
    std::shared_ptr<Nucleator> _nucleator;
    std::shared_ptr<Rule> _rule;

    m_int _statesNumber;
    m_int _itrLimit;
    m_int _threadsNumber{1};
};