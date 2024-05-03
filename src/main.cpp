#include<iostream>
#include"GenerationManager.hpp"
#include"postproc.hpp"

void Moore2D(Neighbourhood& n);

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
        Neighbourhood n;
        Moore2D(n);
        gen.setNeighbouthood(n);
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

void Moore2D(Neighbourhood& n)
{
    n.size = 8;
    n.pos = new coor[8];
    n.pos[0].x = -1;
    n.pos[0].y = -1;
    n.pos[0].z = 0;

    n.pos[1].x = 0;
    n.pos[1].y = -1;
    n.pos[1].z = 0;

    n.pos[2].x = 1;
    n.pos[2].y = -1;
    n.pos[2].z = 0;

    n.pos[3].x = -1;
    n.pos[3].y = 0;
    n.pos[3].z = 0;

    n.pos[4].x = 1;
    n.pos[4].y = 0;
    n.pos[4].z = 0;

    n.pos[5].x = -1;
    n.pos[5].y = 1;
    n.pos[5].z = 0;

    n.pos[6].x = 0;
    n.pos[6].y = 1;
    n.pos[6].z = 0;

    n.pos[7].x = 1;
    n.pos[7].y = 1;
    n.pos[7].z = 0;
}