#include "cubesolver/corner.h"

#include <sstream>
#include <stdexcept>

namespace cube_solver
{

Corner::Corner(Sticker x, Sticker y, Sticker z)
        : Piece(x, y, z)
{
#ifndef OPTIMIZE_REMOVE_CHECKS
    if(x == Sticker{} || y == Sticker{} || z == Sticker{})
    {
        std::stringstream stream;
        stream << "Corners can't have invalid tiles. x: " << x << "; y: " << y << "; z: " << z;
        throw std::runtime_error(stream.str());
    }
#endif
}

}
