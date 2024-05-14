#pragma once
#include<vector>
#include<memory>
#include"basic_types.h"

class Rule: public Clonable<Rule>
{
    public:
    Rule() = default;
    virtual ~Rule() = default;
    virtual m_int state(const std::vector<m_int>&) const = 0;
};  

class MostNumerous: public Rule
{
    public:
    MostNumerous() = default;
    m_int state(const std::vector<m_int>&) const override;
    std::shared_ptr<Rule> clone() const override; 
};

class LeastNumerous: public Rule
{
    public:
    LeastNumerous() = default;
    m_int state(const std::vector<m_int>&) const override;
    std::shared_ptr<Rule> clone() const override; 
};


