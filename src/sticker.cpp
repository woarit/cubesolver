#include "cubesolver/sticker.h"

#include <ostream>

namespace cube_solver
{

std::ostream &operator<<(std::ostream &out, const Sticker &sticker)
{
    switch(sticker)
    {
        case Sticker::ORANGE:
            return out << "O";
        case Sticker::RED:
            return out << "R";
        case Sticker::YELLOW:
            return out << "Y";
        case Sticker::WHITE:
            return out << "W";
        case Sticker::BLUE:
            return out << "B";
        case Sticker::GREEN:
            return out << "G";
        default:
            return out << "?";
    }
}

}
