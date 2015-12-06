#include "cubesolver/cube.h"

#include <ostream>
#include <stdexcept>

namespace cube_solver
{

Cube::Cube(const Corner &cornerUpFrontLeft, const Corner &cornerUpBackLeft, const Corner &cornerUpBackRight,
           const Corner &cornerUpFrontRight, const Corner &cornerDownFrontLeft, const Corner &cornerDownBackLeft,
           const Corner &cornerDownBackRight, const Corner &cornerDownFrontRight, const Tile &middleFront, const Tile &middleLeft,
           const Tile &middleBack, const Tile &middleRight, const Tile &middleUp, const Tile &middleDown, const YZEdge &edgeUpFront,
           const XYEdge &edgeUpLeft, const YZEdge &edgeUpBack, const XYEdge &edgeUpRight,
           const XZEdge &edgeLeftFront, const XZEdge &edgeLeftBack, const XZEdge &edgeRightBack, const XZEdge &edgeRightFront,
           const YZEdge &edgeDownFront, const XYEdge &edgeDownLeft, const YZEdge &edgeDownBack, const XYEdge &edgeDownRight)
        : m_cornerUpFrontLeft(cornerUpFrontLeft)
        , m_cornerUpBackLeft(cornerUpBackLeft)
        , m_cornerUpBackRight(cornerUpBackRight)
        , m_cornerUpFrontRight(cornerUpFrontRight)
        , m_cornerDownFrontLeft(cornerDownFrontLeft)
        , m_cornerDownBackLeft(cornerDownBackLeft)
        , m_cornerDownBackRight(cornerDownBackRight)
        , m_cornerDownFrontRight(cornerDownFrontRight)
        , m_middleFront(middleFront)
        , m_middleLeft(middleLeft)
        , m_middleBack(middleBack)
        , m_middleRight(middleRight)
        , m_middleUp(middleUp)
        , m_middleDown(middleDown)
        , m_edgeUpFront(edgeUpFront)
        , m_edgeUpLeft(edgeUpLeft)
        , m_edgeUpBack(edgeUpBack)
        , m_edgeUpRight(edgeUpRight)
        , m_edgeLeftFront(edgeLeftFront)
        , m_edgeLeftBack(edgeLeftBack)
        , m_edgeRightBack(edgeRightBack)
        , m_edgeRightFront(edgeRightFront)
        , m_edgeDownFront(edgeDownFront)
        , m_edgeDownLeft(edgeDownLeft)
        , m_edgeDownBack(edgeDownBack)
        , m_edgeDownRight(edgeDownRight)
        , m_cornerUpFrontLeftPtr(&m_cornerUpFrontLeft)
        , m_cornerUpBackLeftPtr(&m_cornerUpBackLeft)
        , m_cornerUpBackRightPtr(&m_cornerUpBackRight)
        , m_cornerUpFrontRightPtr(&m_cornerUpFrontRight)
        , m_cornerDownFrontLeftPtr(&m_cornerDownFrontLeft)
        , m_cornerDownBackLeftPtr(&m_cornerDownBackLeft)
        , m_cornerDownBackRightPtr(&m_cornerDownBackRight)
        , m_cornerDownFrontRightPtr(&m_cornerDownFrontRight)
        , m_middleFrontPtr(&m_middleFront)
        , m_middleLeftPtr(&m_middleLeft)
        , m_middleBackPtr(&m_middleBack)
        , m_middleRightPtr(&m_middleRight)
        , m_middleUpPtr(&m_middleUp)
        , m_middleDownPtr(&m_middleDown)
        , m_edgeUpFrontPtr(&m_edgeUpFront)
        , m_edgeUpLeftPtr(&m_edgeUpLeft)
        , m_edgeUpBackPtr(&m_edgeUpBack)
        , m_edgeUpRightPtr(&m_edgeUpRight)
        , m_edgeLeftFrontPtr(&m_edgeLeftFront)
        , m_edgeLeftBackPtr(&m_edgeLeftBack)
        , m_edgeRightBackPtr(&m_edgeRightBack)
        , m_edgeRightFrontPtr(&m_edgeRightFront)
        , m_edgeDownFrontPtr(&m_edgeDownFront)
        , m_edgeDownLeftPtr(&m_edgeDownLeft)
        , m_edgeDownBackPtr(&m_edgeDownBack)
        , m_edgeDownRightPtr(&m_edgeDownRight)
        , m_front(Axis::Z,
                  &m_cornerUpFrontLeftPtr, &m_cornerUpFrontRightPtr, &m_cornerDownFrontRightPtr, &m_cornerDownFrontLeftPtr,
                  &m_middleFrontPtr,
                  &m_edgeUpFrontPtr, &m_edgeRightFrontPtr, &m_edgeDownFrontPtr, &m_edgeLeftFrontPtr)
        , m_left(Axis::X,
                 &m_cornerUpBackLeftPtr, &m_cornerUpFrontLeftPtr, &m_cornerDownFrontLeftPtr, &m_cornerDownBackLeftPtr,
                 &m_middleLeftPtr,
                 &m_edgeUpLeftPtr, &m_edgeLeftFrontPtr, &m_edgeDownLeftPtr, &m_edgeLeftBackPtr)
        , m_back(Axis::Z,
                 &m_cornerUpBackRightPtr, &m_cornerUpBackLeftPtr, &m_cornerDownBackLeftPtr, &m_cornerDownBackRightPtr,
                 &m_middleBackPtr,
                 &m_edgeUpBackPtr, &m_edgeLeftBackPtr, &m_edgeDownBackPtr, &m_edgeRightBackPtr)
        , m_right(Axis::X,&m_cornerUpFrontRightPtr, &m_cornerUpBackRightPtr, &m_cornerDownBackRightPtr, &m_cornerDownFrontRightPtr,
                  &m_middleRightPtr,
                  &m_edgeUpRightPtr, &m_edgeRightBackPtr, &m_edgeDownRightPtr, &m_edgeRightFrontPtr)
        , m_up(Axis::Y,
               &m_cornerUpBackLeftPtr, &m_cornerUpBackRightPtr, &m_cornerUpFrontRightPtr, &m_cornerUpFrontLeftPtr,
               &m_middleUpPtr,
               &m_edgeUpBackPtr, &m_edgeUpRightPtr, &m_edgeUpFrontPtr, &m_edgeUpLeftPtr)
        , m_down(Axis::Y,
                 &m_cornerDownFrontLeftPtr, &m_cornerDownFrontRightPtr, &m_cornerDownBackRightPtr, &m_cornerDownBackLeftPtr,
                 &m_middleDownPtr,
                 &m_edgeDownFrontPtr, &m_edgeDownRightPtr, &m_edgeDownBackPtr, &m_edgeDownLeftPtr)
{
}

Cube Cube::fromCategories(const std::vector<Sticker> &tiles)
{
#ifndef OPTIMIZE_REMOVE_CHECKS
    if(tiles.size() != 54)
    {
        throw std::runtime_error("There has to be exactly 54 tiles. " + tiles.size() + std::string(" provived"));
    }
#endif

    return Cube({tiles[42], tiles[35], tiles[5]},{tiles[41],tiles[32],tiles[24]},{tiles[15],tiles[33],tiles[23]},{tiles[14],tiles[34],tiles[6]},{tiles[43],tiles[50],tiles[8]},{tiles[44],tiles[53],tiles[25]},{tiles[16],tiles[52],tiles[26]},{tiles[17],tiles[51],tiles[7]},{tiles[0]},{tiles[36]},{tiles[18]},{tiles[9]},{tiles[27]},{tiles[45]},{tiles[30],tiles[1]},{tiles[37],tiles[31]},{tiles[28],tiles[19]},{tiles[10],tiles[29]},{tiles[38],tiles[4]},{tiles[40],tiles[20]},{tiles[11],tiles[22]},{tiles[13],tiles[2]},{tiles[46],tiles[3]},{tiles[39],tiles[49]},{tiles[48],tiles[21]},{tiles[12],tiles[47]});
}

std::ostream &operator<<(std::ostream &out, const Cube &cube)
{
    return out
           << "Front:" << std::endl
           << cube.m_front << std::endl
           << std::endl
           << "Right:" << std::endl
           << cube.m_right << std::endl
           << std::endl
           << "Back:" << std::endl
           << cube.m_back << std::endl
           << std::endl
           << "Up:" << std::endl
           << cube.m_up << std::endl
           << std::endl
           << "Left:" << std::endl
           << cube.m_left << std::endl
           << std::endl
           << "Down:" << std::endl
           << cube.m_down << std::endl
           << std::endl;
}

}