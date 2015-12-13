#include "cubesolver/piece.h"

#include <utility>
#include <stdexcept>
#include <sstream>

namespace cube_solver
{

Piece::Piece(Sticker x, Sticker y, Sticker z) : m_x(x), m_y(y), m_z(z)
{
#ifndef OPTIMIZE_REMOVE_CHECKS
    if(x == y || y == z || x == z)
    {
        std::stringstream stream;
        stream << "Pieces can't have equal tiles. x: " << x << "; y: " << y << "; z: " << z;
        throw std::runtime_error(stream.str());
    }
#endif
}

Piece::~Piece()
{
}

Sticker Piece::getSticker(Axis axis) const
{
    switch(axis)
    {
        case Axis::X:
            return m_x;
        case Axis::Y:
            return m_y;
        case Axis::Z:
            return m_z;
    }
}

void Piece::rotate(Axis rotationAxis)
{
    switch (rotationAxis)
    {
        case Axis::X:
            std::swap(m_y, m_z);
            break;
        case Axis::Y:
            std::swap(m_x, m_z);
            break;
        case Axis::Z:
            std::swap(m_x, m_y);
            break;
    }
}

}