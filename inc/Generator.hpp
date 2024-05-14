#pragma once

#include"Domain.hpp"
#include"Rules.hpp"

class Generator
{
    public:
    struct Subdomain
    {
        m_int x0, x1;
        m_int y0, y1;
        m_int z0, z1;
    };

    Generator() = delete;
    Generator(Generator&&);
    Generator(const Subdomain& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit);

    virtual void iteration();
    virtual bool finish() const { return _itrCounter != _itrLimit; }

    private:

    Domain _domain_A;
    Domain _domain_B;

    Domain* _input;
    Domain* _output;

    std::shared_ptr<Rule> _rule;
    Subdomain _subdomain;
    m_int _itrLimit;
    m_int _itrCounter;

    void swapBuffers() { std::swap(_input, _output); }
};