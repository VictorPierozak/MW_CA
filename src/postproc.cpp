#include"postproc.hpp"

std::vector<color> colors(m_int stateNumber)
{
    std::vector<color> res;
    res.resize(stateNumber);
    srand(time(NULL));
    for(m_int i = 0; i < stateNumber; i++)
    {
        res[i].red = std::rand() % __UINT8_MAX__;
        res[i].blue = std::rand() % __UINT8_MAX__;
        res[i].green = std::rand() % __UINT8_MAX__;
    }

    return res;
}

void toBmp(const Domain& domain, m_int stateNumber, std::string dir)
{
    std::vector<color> stateColors = colors(stateNumber);
    for(m_int z  = 0; z < domain.dimZ(); z++)
    {
        BMP img;
        img.SetSize(domain.dimX(), domain.dimY());
        RGBApixel pixel;

        for(m_int y = 0; y < domain.dimY(); y++)
        for(m_int x = 0; x < domain.dimX(); x++)
        {
            if(domain(x,y,z) == Domain::Void)
            {
                pixel.Red = 0;
                pixel.Green = 0;
                pixel.Blue = 0;
            }
            else
            {
                pixel.Red = stateColors[domain(x,y,z)].red;
                pixel.Green = stateColors[domain(x,y,z)].green;
                pixel.Blue = stateColors[domain(x,y,z)].blue;
            }
            img.SetPixel(x,y, pixel);
        }

        std::string file = (dir + std::string("ms_") +  std::to_string(z) + std::string(".bmp"));
        img.WriteToFile(file.c_str());
    }
}