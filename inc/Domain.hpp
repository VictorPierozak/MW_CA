#pragma once
#include<vector>
#include<memory>
#include<array>
#include"basic_types.h"
#include"BC.hpp"
#include"Random.hpp"

class Neighbourhood
{
    public:
    Neighbourhood() = default;
    virtual ~Neighbourhood() = default;
    virtual std::vector<m_int> around(m_int x, m_int y, m_int z, Domain& domain) = 0;
    virtual std::shared_ptr<Neighbourhood> duplicate() const = 0;
};


class Moore: public Neighbourhood
{
    public:

    Moore() = default;
    ~Moore() = default;
    std::vector<m_int> around(m_int x, m_int y, m_int z, Domain& domain) override;
    std::shared_ptr<Neighbourhood> duplicate() const override;
};

class Neumann: public Neighbourhood
{
    public:
    Neumann() = default;
    ~Neumann() = default;
    std::vector<m_int> around(m_int x, m_int y, m_int z, Domain& domain) override;
    std::shared_ptr<Neighbourhood> duplicate() const override;
};

class Random: public Neighbourhood
{
    public:

    // Vector of  pair, each pair contains neighbourhood and probability of beind drawn //
    typedef std::vector<std::pair<std::shared_ptr<Neighbourhood>, m_float>> vecrand_n;

    Random(const vecrand_n& neighbourhoods);
    Random(const Random& random);
    Random() = delete;
    ~Random() = default;
    std::vector<m_int> around(m_int x, m_int y, m_int z, Domain& domain) override;
    std::shared_ptr<Neighbourhood> duplicate() const override;

    private:
    vecrand_n neighbourhoods;
    FortuneWheel wheel;
};

#define IDX(x,y,z) y*domain.dimX()*domain.dimZ() + z*domain.dimX() + x

class Domain
{
    public:

    Domain();
    Domain(const Domain&) = delete;
    Domain(Domain&&) = delete;
    ~Domain();
    Domain& operator=(const Domain&) = delete;

    Domain(m_int dimX, m_int dimY, m_int dimZ);

    static const m_int Void;

    void clone(Domain& dest) const;
    void copy(Domain& dest) const;
    void copyBuffer(Domain& dest) const;
    void resetBuffer();

    m_int  operator()(m_int, m_int, m_int) const;
    m_int& operator[](m_int);

    m_int& operator()(m_int, m_int, m_int);
    const m_int& operator[](m_int) const;

    bool allocated() const {return _buffer != nullptr; }

    operator bool() const { return allocated(); }
    explicit operator std::shared_ptr<m_int[]>() {return _buffer;}

    std::vector<m_int> around(m_int x, m_int y, m_int z);

    void setNeighbourhood(std::shared_ptr<Neighbourhood> org) { _neighbours = org->duplicate(); }
    void setBC(std::shared_ptr<BC> bc) { _bc = duplicate(bc); }

    m_int dimX() const { return _dimX; }
    m_int dimY() const { return _dimY; }
    m_int dimZ() const { return _dimZ; }

    std::shared_ptr<BC>& bc() {return _bc;}

    private:

    std::shared_ptr<Neighbourhood> _neighbours;
    m_int _dimX, _dimY, _dimZ;
    size_t _size;
    std::shared_ptr<m_int[]> _buffer;

    std::shared_ptr<BC> _bc;
};

