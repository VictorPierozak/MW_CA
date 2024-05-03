#include"Domain.hpp"
#include"BMP/EasyBMP.h" 

struct color
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

void toBmp(const Domain& domain, m_int stateNumber, std::string dir);