#include"Generator.hpp"

Generator::Generator(const Subdomain& subdomain, const Domain& domain, const std::shared_ptr<Rule> rule, m_int itrLimit)
{
    _subdomain = subdomain;
    domain.clone(_domain);
    domain.clone(_tmpDomain);
    _rule = duplicate(rule);
    _itrLimit = itrLimit;
    _itrCounter = 0;

    _input = &_domain;
    _output = &_tmpDomain;
}

Generator::Generator(Generator&& gen)
{
    gen._domain.clone(_domain);
    gen._tmpDomain.clone(_tmpDomain);
    _subdomain = gen._subdomain;
    _rule = gen._rule;
    _itrLimit = gen._itrLimit;
    _itrCounter=0;
    _input = &_domain;
    _output = &_tmpDomain;
}

void Generator::iteration()
{
    for(m_int y = _subdomain.y0; y < _subdomain.y1; y++)
    for(m_int z = _subdomain.z0; z < _subdomain.z1; z++)
    for(m_int x = _subdomain.x0; x < _subdomain.x1; x++)
    {
        std::vector nstates = _input->around(x,y,z);
        (*_output)(x,y,z) = _rule->state(nstates);
    }
    _itrCounter++;
}