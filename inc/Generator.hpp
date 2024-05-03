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
    Generator(const Subdomain& subdomain, const Domain& domain, const Domain& tmpdomain, const std::shared_ptr<Rule> rule, m_int itrLimit);

    void iteration();
    void swapBuffers() { std::swap(_input, _output); }
    void reset() { _itrCounter = 0;}

    bool finish() const { return _itrCounter != _itrLimit; }
    private:

    Domain _domain;
    Domain _tmpDomain;

    Domain* _input;
    Domain* _output;

    std::shared_ptr<Rule> _rule;
    Subdomain _subdomain;
    m_int _itrLimit;
    m_int _itrCounter;
};