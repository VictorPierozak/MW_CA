#include<stdexcept>
#include<algorithm>
#include"Random.hpp"


FortuneWheel::FortuneWheel(std::vector<rand_pair>& rps): _gen(std::random_device{}()), _dist(0, 1.0)
{
    std::copy(rps.begin(), rps.end(), std::back_inserter(_pairs));
    normalize();
    m_float field = 0.0;
    for(m_int idx = 0; idx < _pairs.size(); idx++)
    {
        field += _pairs[idx].second;
        _fields.emplace_back(idx, field);
    }
}


void FortuneWheel::set(std::vector<rand_pair>& rps)
{
    std::copy(rps.begin(), rps.end(), std::back_inserter(_pairs));
    normalize();
    m_float field = 0.0;
    for(m_int idx = 0; idx < _pairs.size(); idx++)
    {
        field += _pairs[idx].second;
        _fields.emplace_back(idx, field);
    }
}


void FortuneWheel::normalize()
{
    m_float sum = 0.0;
    for(const rand_pair& rp: _pairs)
    {
        if(rp.second <= 0) throw std::runtime_error("P(X) <= 0 !");
        sum += rp.second;
    }
    if(sum == 0) throw std::runtime_error("SUM(P(X)) = 0 !");
    for(rand_pair& rp: _pairs)
    {
        rp.second /= sum;
    }
}


m_int FortuneWheel::get()
{
    m_float ff = _dist(_gen);
    for(m_int idx = 0; idx < _pairs.size() - 1; idx++)
    {
        if(ff < _pairs[idx].second) return _pairs[idx].first;
    }
    return _pairs[_pairs.size()].first;
}