#include<iostream>
#include"GenerationManager.hpp"

int main(int argc, const char** argv)
{
    if(argc < 6)
    {
        std::cout<< "Argc: " << argc << " - aborting\n"; 
        return -1;
    }
    m_int dimX = std::stoi(argv[1]);
    m_int dimY = std::stoi(argv[2]);
    m_int dimZ = std::stoi(argv[3]);
    m_int statesNumber = std::stoi(argv[4]);
    m_int itrLimit = std::stoi(argv[5]);

    std::cout<< "Starting\n";

    GenerationManager gen(dimX, dimY, dimZ, itrLimit);
    gen.setRandomUniformNucleator(statesNumber);
    try
    {
        gen.start();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout<< "Finish\n";
    return 0;
}