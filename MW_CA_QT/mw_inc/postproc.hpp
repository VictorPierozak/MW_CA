#pragma once
#include<vector>
#include"Domain.hpp"
#include"BMP/EasyBMP.h" 

struct color
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct MS_Statistic
{
    std::vector<std::pair<m_int, m_float>> grainsCount;

    void measure(const Domain& domain, m_int statesNumber);

    private:
    
    void count(const Domain& domain);

    m_int statesNumber;
};


void toBmp(const Domain& domain, m_int stateNumber, std::string dir);
void removeState(Domain& domain, m_int state);