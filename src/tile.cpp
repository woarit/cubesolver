#include <cubesolver/side.h>
#include "cubesolver/tile.h"

namespace cube_solver
{

Tile::Tile(Sticker sticker)
        : m_sticker(sticker)
{
}

Sticker Tile::getSticker()
{
    return m_sticker;
}

}
