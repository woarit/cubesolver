#ifndef CUBESOLVER_TILE_H
#define CUBESOLVER_TILE_H

#include "cubesolver/sticker.h"

namespace cube_solver
{

/**
 * Representing a single tile of the cube.
 */
class Tile
{
public:

    /**
     * Constructs the tile with the associated sticker.
     *
     * @param sticker the sticker of the tile
     */
    Tile(Sticker sticker);

    /**
     * Gives the sticker of this tile.
     *
     * @return the sticker of this tile
     */
    Sticker getSticker();

private:
    Sticker m_sticker;
};

using TileRef = Tile *;

}

#endif //CUBESOLVER_TILE_H
