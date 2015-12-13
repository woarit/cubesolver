#ifndef CUBESOLVER_PIECE_H
#define CUBESOLVER_PIECE_H

#include "cubesolver/sticker.h"
#include "cubesolver/axis.h"

namespace cube_solver
{

/**
 * Generic class representing a moveable piece in the cube
 */
class Piece
{
public:

    /**
     * Constructor. Stores the stickers provided. The stickers have
     * to be unique and at most one can represent an invalid sticker.
     *
     * @param x sticker of right or left side
     * @param y sticker of top or bottom side
     * @param z sticker of front or back side
     */
    Piece(Sticker x, Sticker y, Sticker z);

    /**
     * Default destructor.
     */
    virtual ~Piece() = 0;

    /**
     * Returns the sticker associated with the given axis.
     *
     * @param axis axis of the side to gain the sticker from
     *
     * @return sticker of the given axis. This can be an invalid sticker
     */
    Sticker getSticker(Axis axis) const;

    /**
     * Rotate the piece around the given axis.
     *
     * @param rotationAxis  axis that is the center of rotation. The sticker
     *                      of that axis will remain the same, the two other
     *                      will switch place.
     */
    void rotate(Axis rotationAxis);

protected:
    Sticker m_x, m_y, m_z;
};

}

#endif //CUBESOLVER_PIECE_H
