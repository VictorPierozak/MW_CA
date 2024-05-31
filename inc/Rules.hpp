#pragma once
#include<vector>
#include<memory>
#include"basic_types.h"

class Rule: public Clonable<Rule>
{
    public:
    Rule() = default;
    virtual ~Rule() = default;
    virtual m_int state(const std::vector<m_int>&) = 0;
    void s0(m_int s0) {_s0 = s0;}

    protected:
    m_int _s0;
};  

class MostNumerous: public Rule
{
    public:
    MostNumerous() = default;
    m_int state(const std::vector<m_int>&) override;
    std::shared_ptr<Rule> clone() const override; 
};

class LeastNumerous: public Rule
{
    public:
    LeastNumerous() = default;
    m_int state(const std::vector<m_int>&) override;
    std::shared_ptr<Rule> clone() const override; 
};

class MC: public Rule
{
    public:
    MC(m_float k = 0.1): _coeff_kt(k), _dist(0.0,1.0), _genRand(std::random_device{}()) {}
    m_int state(const std::vector<m_int>&) override;
    std::shared_ptr<Rule> clone() const override; 

    private:
    std::minstd_rand _genRand;
    std::uniform_real_distribution<> _dist;
    m_float _coeff_kt;
};
