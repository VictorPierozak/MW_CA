#include"Generator.hpp"

Generator::Generator(const Subspace& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit)
{
    _subspace = subdomain;
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
    _subspace = gen._subspace;
    _rule = gen._rule;
    _itrLimit = gen._itrLimit;
    _itrCounter=0;
    _input = &_domain_A;
    _output = &_domain_B;
}
