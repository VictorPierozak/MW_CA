#include"Generator.hpp"

Generator::Generator(const Subdomain& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit)
{
    _subdomain = subdomain;
    domain_A.clone(_domain_A);
    domain_B.clone(_domain_B);
    _rule = rule->clone();
    _itrLimit = itrLimit;
    _itrCounter = 0;

    _input = &_domain_A;
    _output = &_domain_B;
}

Generator::Generator(Generator&& gen)
{
    gen._domain_A.clone(_domain_A);
    gen._domain_B.clone(_domain_B);
    _subdomain = gen._subdomain;
    _rule = gen._rule;
    _itrLimit = gen._itrLimit;
    _itrCounter=0;
    _input = &_domain_A;
    _output = &_domain_B;
}

void Generator::iteration()
{
    for(m_int y = _subdomain.y0; y < _subdomain.y1; y++)
    for(m_int z = _subdomain.z0; z < _subdomain.z1; z++)
    for(m_int x = _subdomain.x0; x < _subdomain.x1; x++)
    {
        if((*_input)(x,y,z) != Domain::Void)
        {
            (*_output)(x,y,z) = (*_input)(x,y,z);
            continue;
        }
        std::vector nstates = _input->around(x,y,z);
        (*_output)(x,y,z) = _rule->state(nstates);
    }
    _itrCounter++;
    swapBuffers();
}