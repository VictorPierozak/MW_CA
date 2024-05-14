#include<list>
#include"Generator.hpp"

class GeneratorMC: public Generator
{
    public:

    GeneratorMC() = delete;
    GeneratorMC(GeneratorMC&&) = delete;
    GeneratorMC(GeneratorMC&) = delete;
    GeneratorMC(const Subspace& subdomain, const Domain& domain_A, const Domain& domain_B, const std::shared_ptr<Rule> rule, m_int itrLimit);

    void iteration() final;
    bool work() final {return _itrCounter != _itrLimit;}

    private:

    std::list<coor> list_A;
    std::list<coor> list_B;

    std::list<coor>* list_current;
    std::list<coor>* list_next;

    std::minstd_rand _rand;
    std::uniform_real_distribution<m_float> _dist;

    coor draw();
    bool loop();
};