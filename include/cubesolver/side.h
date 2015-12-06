#ifndef CUBESOLVER_SIDE_H
#define CUBESOLVER_SIDE_H

#include "cubesolver/axis.h"
#include "cubesolver/corner.h"
#include "cubesolver/edge.h"
#include "cubesolver/tile.h"

namespace cube_solver
{

/**
 * Representing a side of a cube. This consists
 * of four corners, four edges and one middle tile.
 * That also means it doesn't only consist of 9 stickers.
 */
class Side
{
public:

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

private:
    Axis m_axisSelf, m_axisLeftRight, m_axisTopBottom;
    CornerRef *m_topLeftCorner, *m_topRightCorner, *m_bottomRightCorner, *m_bottomLeftCorner;
    TileRef *m_middle;
    EdgeRef *m_topEdge, *m_rightEdge, *m_bottomEdge, *m_leftEdge;
};

}

#endif //CUBESOLVER_SIDE_H
