#include<iostream>
#include"GenerationManager.hpp"
#include"postproc.hpp"

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

    {
        Random::vecrand_n rands;
        rands.push_back({std::shared_ptr<Neighbourhood>(new Moore), 0.2});
        rands.push_back({std::shared_ptr<Neighbourhood>(new Neumann), 0.8});
        gen.setNeighbourhood(std::shared_ptr<Neighbourhood>(new Random(rands)));
    }

    {
        std::shared_ptr<BC> bc(new Absorption(dimX, dimY, dimZ));
        gen.setBC(bc);
    }

    {
        std::shared_ptr<Rule> rule(new MostNumerous());
        gen.setRule(rule);
    }

    {
        gen.setThreadsNumber(12);
    }

    gen.setRandomUniformNucleator(statesNumber);

    try
    {
        gen.start();
        Domain& d = gen.domain();
        toBmp(d, gen.stateNumber(), "/home/wiktor/Desktop/MW/MW_CA/res");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    std::cout<< "Finish\n";
    return 0;
}
