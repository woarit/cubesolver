#ifndef CUBESOLVER_SIDE_H
#define CUBESOLVER_SIDE_H

#include "cubesolver/axis.h"
#include "cubesolver/corner.h"
#include "cubesolver/edge.h"
#include "cubesolver/tile.h"

#include <iosfwd>

namespace cube_solver
{

/**
 * Representing a side of a cube. This consists
 * of four corners, four edges and one middle tile.
 * That also means it doesn't only consist of 9 stickers.
 */
class Side
{
    friend std::ostream& operator<< (std::ostream &out, const Side &cPoint);

public:

    /**
     * Types of rotations the side can do
     */
    enum class Rotation
    {
        CLOCKWISE,          // 90 degrees
        COUNTER_CLOCKWISE,  // -90 degrees = 270 degrees
        DOUBLE,             // 180 degrees
    };

    /**
     * Constructs a side consisting of the elements provided.
     * The reference to the elements will be kept and thus they
     * should not be deleted before this class is destructed.
     *
     * @param axis              axis which this class represent.
     *                          Used for determine which sticker
     *                          of the pieces is "belonging"
     * @param topLeftCorner     when facing the side, top left corner
     * @param topRightCorner    when facing the side, top right corner
     * @param bottomRightCorner when facing the side, bottom right corner
     * @param bottomLeftCorner  when facing the side, bottom left corner
     * @param middle            middle of the side
     * @param topEdge           when facing the side, top edge
     * @param rightEdge         when facing the side, right edge
     * @param bottomEdge        when facing the side, bottom edge
     * @param leftEdge          when facing the side, left edge
     */
    Side(
            Axis axis,
            CornerRef *topLeftCorner, CornerRef *topRightCorner, CornerRef *bottomRightCorner, CornerRef *bottomLeftCorner,
            TileRef *middle,
            EdgeRef *topEdge, EdgeRef *rightEdge, EdgeRef *bottomEdge, EdgeRef *leftEdge
    );

    /**
     * Rotate the side by the given rotation. The rotation
     * is based on the sides current position and not its
     * original state.
     */
    void rotate(Rotation rotation);

private:
    Axis m_axisSelf, m_axisLeftRight, m_axisTopBottom;
    CornerRef *m_topLeftCorner, *m_topRightCorner, *m_bottomRightCorner, *m_bottomLeftCorner;
    TileRef *m_middle;
    EdgeRef *m_topEdge, *m_rightEdge, *m_bottomEdge, *m_leftEdge;
};

/**
 * Outputting the side to the given stream.
 * This will both be the 9 stickers of the side and
 * the 3 stickers next to on each side.
 * Each "line" of the side will be printed on separate
 * lines and spaces without a sticker will be printed
 * as a space (" ") such that the stickers align.
 *
 * @param out stream to write to
 * @param side the side to output
 *
 * @return the same stream as given, after outputting the side
 */
std::ostream& operator<<(std::ostream &out, const Side &side);

}

#endif //CUBESOLVER_SIDE_H
