#include"GeneratorCA.hpp"

void GeneratorCA::iteration()
{
    for(m_int y = _subspace.y0; y < _subspace.y1; y++)
    for(m_int z = _subspace.z0; z < _subspace.z1; z++)
    for(m_int x = _subspace.x0; x < _subspace.x1; x++)
    {
        if((*_input)(x,y,z) != Domain::Void)
        {
            (*_output)(x,y,z) = (*_input)(x,y,z);
            continue;
        }
        std::vector nstates = _input->around(x,y,z);
        (*_output)(x,y,z) = _rule->state(nstates);
    }
    _itrCounter++;
    swapBuffers();
}