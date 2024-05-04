#include<stdexcept>
#include"BC.hpp"
#include"Domain.hpp"

m_int Periodic::operator()(m_int x, m_int y, m_int z, const Domain& domain)
{
    return 0;
}

m_int Absorption::operator()(m_int x, m_int y, m_int z, const Domain& domain)
{
    if(inside(x,y,z)) return domain(x,y,z);
    else return Domain::Void;
}

std::shared_ptr<BC> duplicate(std::shared_ptr<BC> bc)
{
    std::shared_ptr<BC> result;
    switch (bc->type())
    {
    case BC::BCType::Absorption:
        result.reset(new Absorption( *((Absorption*) bc.get())) );
        break;
    case BC::BCType::Periodic:
        result.reset(new Periodic( *((Periodic*) bc.get()) ));
        break;
    default:
        throw std::runtime_error("Unexpected BC");
    }
    return result;
}