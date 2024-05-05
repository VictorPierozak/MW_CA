#pragma once
#include<memory>
#include"basic_types.h"

class Domain;

class BC: public virtual Clonable<BC>
{
    public:

    BC() = delete;
    BC(const BC& bc) = default;
    BC(m_int dimX, m_int dimY, m_int dimZ): _dimX(dimX), _dimY(dimY), _dimZ(dimZ) 
    {}
    virtual ~BC() = default;

    enum class BCType{Absorption, Periodic};

    virtual m_int operator()(m_int x, m_int y, m_int z, const Domain&) = 0;

    protected:

    bool inside(m_int x, m_int y, m_int z)
    {
        return (x >= 0 && x < _dimX && y >= 0 && y < _dimY && z >=  0 && z < _dimZ);
    }

    m_int _dimX, _dimY, _dimZ;
};

class Periodic: public BC
{
    public:
    Periodic() = delete;
    Periodic(const Periodic&) = default;
    Periodic(m_int dimX, m_int dimY, m_int dimZ): BC(dimX, dimY, dimZ){}
    m_int operator()(m_int x, m_int y, m_int z, const Domain&) override;
    std::shared_ptr<BC> clone() const override { return std::shared_ptr<BC>(new Periodic(_dimX, _dimY, _dimZ)); }
};

class Absorption: public BC
{
    public:
    Absorption(const Absorption&) = default;
    Absorption(m_int dimX, m_int dimY, m_int dimZ): BC(dimX, dimY, dimZ){}
    m_int operator()(m_int x, m_int y, m_int z, const Domain&) override;
    std::shared_ptr<BC> clone() const override { return std::shared_ptr<BC>(new Absorption(_dimX, _dimY, _dimZ)); }
};