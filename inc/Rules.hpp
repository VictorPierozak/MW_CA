#pragma once
#include<vector>
#include<memory>
#include"basic_types.h"

class Rule
{
    public:
    enum class Type{MostNumerous, LeastNumerous};
    Rule() = default;
    virtual ~Rule() = default;
    virtual m_int state(const std::vector<m_int>&) const = 0;
    virtual Type type() const = 0;
};  

class MostNumerous: public Rule
{
    public:
    MostNumerous() = default;
    m_int state(const std::vector<m_int>&) const override;
    Type type() const override { return Type::MostNumerous; }
};

class LeastNumerous: public Rule
{
    public:
    LeastNumerous() = default;
    m_int state(const std::vector<m_int>&) const override;
    Type type() const override { return Type::LeastNumerous; };
};

std::shared_ptr<Rule> duplicate(const std::shared_ptr<Rule>& rule);