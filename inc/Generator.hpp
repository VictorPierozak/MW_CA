#pragma once

#include"Domain.hpp"
#include"Rules.hpp"

class Generator 
{
    public:
    struct Subspace
    {
        m_int x0, x1;
        m_int y0, y1;
        m_int z0, z1;
    };

    Generator() = delete;
    Generator(Generator&&);
    Generator(const Subspace& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit);

    virtual void iteration() = 0;
    virtual bool finish() = 0;

    protected:

    Domain _domain_A;
    Domain _domain_B;

    Domain* _input;
    Domain* _output;

    std::shared_ptr<Rule> _rule;
    Subspace _subspace;


    m_int _itrLimit;
    m_int _itrCounter;

    void swapBuffers() { std::swap(_input, _output); }
};