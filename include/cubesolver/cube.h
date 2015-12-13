#ifndef CUBESOLVER_CUBE_H
#define CUBESOLVER_CUBE_H

#include "cubesolver/corner.h"
#include "cubesolver/tile.h"
#include "cubesolver/edge.h"
#include "cubesolver/side.h"

#include <vector>
#include <iosfwd>

namespace cube_solver
{

/**
 * Representing a cube.
 */
class Cube
{
    friend std::ostream& operator<<(std::ostream &out, const Cube &cube);

public:

    /**
     * Types of moves the cube can do.
     *
     * Each starting letter represents the side that origins the move:
     * F(ront), B(ack), R(ight), L(eft), U(p), D(own)
     *
     * The remaining symbols specifies how the move is done (X is the side):
     * - X (no symbols): Outer layer clockwise move
     * - X_: Outer layer counter clockwise move
     * - X2: Outer layer double rotation
    */
    enum class Move
    {
        F,
        F_,
        F2,
        R,
        R_,
        R2,
        B,
        B_,
        B2,
        L,
        L_,
        L2,
        U,
        U_,
        U2,
        D,
        D_,
        D2,
    };

    /**
     * Constructs the cube. It is recommended to use one of the static
     * helper functions to create the cube instead of using the constructor
     * directly.
     *
     * @param cornerUpFrontLeft     when facing the front, top front left corner
     * @param cornerUpBackLeft      when facing the front, top back left corner
     * @param cornerUpBackRight     when facing the front, top back right corner
     * @param cornerUpFrontRight    when facing the front, top front right corner
     * @param cornerDownFrontLeft   when facing the front, bottom front left corner
     * @param cornerDownBackLeft    when facing the front, bottom back left corner
     * @param cornerDownBackRight   when facing the front, bottom back right corner
     * @param cornerDownFrontRight  when facing the front, bottom front right corner
     * @param middleFront           when facing the front, front middle
     * @param middleLeft            when facing the front, left middle
     * @param middleBack            when facing the front, back middle
     * @param middleRight           when facing the front, right middle
     * @param middleUp              when facing the front, top middle
     * @param middleDown            when facing the front, bottom middle
     * @param edgeUpFront           when facing the front, top front edge
     * @param edgeUpLeft            when facing the front, top left edge
     * @param edgeUpBack            when facing the front, top back edge
     * @param edgeUpRight           when facing the front, top right edge
     * @param edgeLeftFront         when facing the front, left front edge
     * @param edgeLeftBack          when facing the front, left back edge
     * @param edgeRightBack         when facing the front, right back edge
     * @param edgeRightFront        when facing the front, right front edge
     * @param edgeDownFront         when facing the front, bottom front edge
     * @param edgeDownLeft          when facing the front, bottom left edge
     * @param edgeDownBack          when facing the front, bottom back edge
     * @param edgeDownRight         when facing the front, bottom right edge
     */
    Cube(const Corner &cornerUpFrontLeft, const Corner &cornerUpBackLeft, const Corner &cornerUpBackRight,
         const Corner &cornerUpFrontRight, const Corner &cornerDownFrontLeft, const Corner &cornerDownBackLeft,
         const Corner &cornerDownBackRight, const Corner &cornerDownFrontRight, const Tile &middleFront, const Tile &middleLeft,
         const Tile &middleBack, const Tile &middleRight, const Tile &middleUp, const Tile &middleDown,
         const YZEdge &edgeUpFront, const XYEdge &edgeUpLeft, const YZEdge &edgeUpBack, const XYEdge &edgeUpRight,
         const XZEdge &edgeLeftFront, const XZEdge &edgeLeftBack, const XZEdge &edgeRightBack, const XZEdge &edgeRightFront,
         const YZEdge &edgeDownFront, const XYEdge &edgeDownLeft, const YZEdge &edgeDownBack, const XYEdge &edgeDownRight);

    /**
     * Creates a cube based on the parameters given.
     * This method takes one side (9 stickers) at a time and
     * deals in turns with all pieces of category on that side.
     *
     * Each side has the following order:
     * F B G
     * E A C
     * I D H
     *
     * The sides are taken in the following order:
     * front (0-8), right (9-17), back (18-26), top (27-35, left (36-44), bottom (45-53)
     *
     * All sides (expect top and bottom) should be recorded with top side up.
     * The top side should be recorded with back side up and bottom side
     * should be recorded with front side up.
     *
     * @param tiles the stickers of the cube. See description of this method for order
     *
     * @return a cube constructed based on the tiles provided
     */
    static Cube fromCategories(const std::vector<Sticker> &tiles);

private:
    Corner m_cornerUpFrontLeft, m_cornerUpBackLeft, m_cornerUpBackRight, m_cornerUpFrontRight, m_cornerDownFrontLeft, m_cornerDownBackLeft, m_cornerDownBackRight, m_cornerDownFrontRight;
    Tile m_middleFront, m_middleLeft, m_middleBack, m_middleRight, m_middleUp, m_middleDown;
    Edge m_edgeUpFront, m_edgeUpLeft, m_edgeUpBack, m_edgeUpRight, m_edgeLeftFront, m_edgeLeftBack, m_edgeRightBack, m_edgeRightFront, m_edgeDownFront, m_edgeDownLeft, m_edgeDownBack, m_edgeDownRight;

    CornerRef m_cornerUpFrontLeftPtr, m_cornerUpBackLeftPtr, m_cornerUpBackRightPtr, m_cornerUpFrontRightPtr, m_cornerDownFrontLeftPtr, m_cornerDownBackLeftPtr, m_cornerDownBackRightPtr, m_cornerDownFrontRightPtr;
    TileRef m_middleFrontPtr, m_middleLeftPtr, m_middleBackPtr, m_middleRightPtr, m_middleUpPtr, m_middleDownPtr;
    EdgeRef m_edgeUpFrontPtr, m_edgeUpLeftPtr, m_edgeUpBackPtr, m_edgeUpRightPtr, m_edgeLeftFrontPtr, m_edgeLeftBackPtr, m_edgeRightBackPtr, m_edgeRightFrontPtr, m_edgeDownFrontPtr, m_edgeDownLeftPtr, m_edgeDownBackPtr, m_edgeDownRightPtr;

    Side m_front, m_left, m_back, m_right, m_up, m_down;
};

/**
 * Outputting the cube to the given stream.
 * Each side of the cube is printed out in separate
 * section with a title and the stickers (as they
 * are printed by Side).
 *
 * @param out stream to write to
 * @param side the cube to output
 *
 * @return the same stream as given, after outputting the cube
 */
std::ostream& operator<<(std::ostream &out, const Cube &cube);

}

#endif //CUBESOLVER_CUBE_H
