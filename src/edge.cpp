#include <stdexcept>
#include "cubesolver/edge.h"

namespace cube_solver
{

Edge::Edge(Sticker x, Sticker y, Sticker z)
        : Piece(x, y, z)
{
#ifndef OPTIMIZE_REMOVE_CHECKS
    int count = 0;
    if(x != Sticker{})
    {
        ++count;
    }
    if(y != Sticker{})
    {
        ++count;
    }
    if(z != Sticker{})
    {
        ++count;
    }
    if(count != 2)
    {
        throw std::runtime_error("Exactly two of x, y and z have to be set for edges. " + count + std::string(" found"));
    }
#endif
}

XYEdge::XYEdge(Sticker x, Sticker y)
        : Edge(x, y, {})
{
}

YZEdge::YZEdge(Sticker y, Sticker z)
        : Edge({}, y, z)
{
}

XZEdge::XZEdge(Sticker x, Sticker z)
        : Edge(x, {}, z)
{
}

}
