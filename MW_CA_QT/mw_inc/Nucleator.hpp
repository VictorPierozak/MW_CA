#pragma once
#include<random>
#include"Domain.hpp"

class Nucleator
{
    public:
    Nucleator(m_int statesNumber) : _statesNumber(statesNumber) {}
    virtual ~Nucleator() = default;

    virtual void nucleation(Domain& domain) = 0;
    m_int statesNumber() const {return _statesNumber;}

    protected:
    m_int _statesNumber;
};

class RandomUniformNucleator: public Nucleator
{
    public:
    RandomUniformNucleator(m_int statesNumber): Nucleator(statesNumber), _rand(std::random_device{}()) {}

    void nucleation(Domain& domain) override;

    private:
    std::minstd_rand _rand;
};

class UniformNucleator2D: public Nucleator
{
    public:
    UniformNucleator2D(m_int statesNumber): Nucleator(statesNumber) {}
    void nucleation(Domain& domain) override;
};