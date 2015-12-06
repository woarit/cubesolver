#ifndef CUBESOLVER_EDGE_H
#define CUBESOLVER_EDGE_H

#include "cubesolver/piece.h"
#include "cubesolver/sticker.h"

namespace cube_solver
{

/**
 * Representing an edge of the cube. This has to have two valid
 * stickers and one invalid. Be aware that the provided sticker's
 * positions only are their initial state - they will be moved
 * around if the edge is turned. It is recommended to use the
 * derived classes: XYEdge, XZEdge, YZEdge
 */
class Edge : public Piece
{
public:

    /**
     * Constructs an edge piece. Exactly one of the stickers
     * has to be valid.
     *
     * @param x sticker of right or left side
     * @param y sticker of top or bottom side
     * @param z sticker of front or back side
     */
    Edge(Sticker x, Sticker y, Sticker z);
};

/**
 * Convenient type alias for an Edge pointer.
 */
using EdgeRef = Edge *;

/**
 * Representing an edge with the initial position
 * of left/right and top/bottom.
 */
class XYEdge : public Edge
{
public:

    /**
     * Constructs an edge piece. Both stickers
     * have to be provided. The leftover sticker (z)
     * will be invalid.
     *
     * @param x sticker of right or left side
     * @param y sticker of top or bottom side
     */
    XYEdge(Sticker x, Sticker y);
};

/**
 * Representing an edge with the initial position
 * of top/bottom and front/back.
 */
class YZEdge : public Edge
{
public:

    /**
     * Constructs an edge piece. Both stickers
     * have to be provided. The leftover sticker (x)
     * will be invalid.
     *
     * @param y sticker of top or bottom side
     * @param z sticker of front or back side
     */
    YZEdge(Sticker y, Sticker z);
};


/**
 * Representing an edge with the initial position
 * of left/right and front/back.
 */
class XZEdge : public Edge
{
public:

    /**
     * Constructs an edge piece. Both stickers
     * have to be provided. The leftover sticker (y)
     * will be invalid.
     *
     * @param x sticker of right or left side
     * @param z sticker of front or back side
     */
    XZEdge(Sticker x, Sticker z);
};

}

#endif //CUBESOLVER_EDGE_H
