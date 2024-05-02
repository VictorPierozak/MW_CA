#pragma once
#include<memory>
#include"basic_types.h"

class Domain;

class BC
{
    public:

    BC() = delete;
    BC(m_int dimX, m_int dimY, m_int dimZ): _dimX(dimX), _dimY(dimY), _dimZ(dimZ) 
    {}
    virtual ~BC() = default;

    enum class BCType{Absorption, Periodic};

    virtual m_int operator()(m_int x, m_int y, m_int z, const Domain&) = 0;
    virtual BCType type() const = 0;

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
    Periodic(m_int dimX, m_int dimY, m_int dimZ): BC(dimX, dimY, dimZ){}
    virtual m_int operator()(m_int x, m_int y, m_int z, const Domain&) override;
    virtual BCType type() const override { return BC::BCType::Periodic; }
};

class Absorption: public BC
{
    public:
    Absorption(m_int dimX, m_int dimY, m_int dimZ): BC(dimX, dimY, dimZ){}
    virtual m_int operator()(m_int x, m_int y, m_int z, const Domain&) override;
    virtual BCType type() const override { return BC::BCType::Absorption; }
};

std::shared_ptr<BC> duplicate(std::shared_ptr<BC> bc);