#ifndef CUBESOLVER_CORNER_H
#define CUBESOLVER_CORNER_H

#include "cubesolver/sticker.h"
#include "cubesolver/piece.h"

namespace cube_solver
{

/**
 * Representing a corner of the cube. This has three valid stickers.
 * Be aware that the provided sticker's positions only are their
 * initial state - they will be moved around if the corner is turned.
 */
class Corner : public Piece
{
public:

    /**
     * Constructs a corner piece. The stickers have to be valid.
     *
     * @param x sticker of right or left side
     * @param y sticker of top or bottom side
     * @param z sticker of front or back side
     */
    Corner(Sticker x, Sticker y, Sticker z);
};

/**
 * Convenient type alias for a Corner pointer.
 */
using CornerRef = Corner *;

}

#endif //CUBESOLVER_CORNER_H
