#pragma once
#include"Generator.hpp"

class GeneratorCA: public Generator
{
    public:

    GeneratorCA() = delete;
    GeneratorCA(GeneratorCA&&) = delete;
    GeneratorCA(GeneratorCA&) = delete;
    GeneratorCA(const Subspace& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit):
        Generator(subdomain, domain_A, domain_B, rule, itrLimit) {}

    void iteration() final;
    bool work() final { return _itrCounter != _itrLimit; }
};