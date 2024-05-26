#pragma once
#include<vector>
#include<tuple>
#include<random>
#include"basic_types.h"

class FortuneWheel
{
    public:

    typedef std::pair<m_int, m_float> rand_pair;
    FortuneWheel(std::vector<rand_pair>&);
    FortuneWheel(): _gen(std::random_device{}()), _dist(0, 1.0) {}
    ~FortuneWheel() = default;

    void set(std::vector<rand_pair>&);
    m_int get();

    private:

    void normalize();
    std::vector<rand_pair> _pairs;
    std::vector<std::pair<m_int, m_float>> _fields;
    std::minstd_rand _gen;
    std::uniform_real_distribution<> _dist;
};
