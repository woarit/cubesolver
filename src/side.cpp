#include "cubesolver/side.h"

namespace
{

cube_solver::Axis getLeftRightAxis(cube_solver::Axis axis)
{
    switch(axis)
    {
        case cube_solver::Axis::X:
            return cube_solver::Axis::Z;
        case cube_solver::Axis::Y:
        case cube_solver::Axis::Z:
            return cube_solver::Axis::X;
    }

}

cube_solver::Axis getTopBottomAxis(cube_solver::Axis axis)
{
    switch(axis)
    {
        case cube_solver::Axis::X:
        case cube_solver::Axis::Z:
            return cube_solver::Axis::Y;
        case cube_solver::Axis::Y:
            return cube_solver::Axis::Z;
    }
}

}

namespace cube_solver
{

Side::Side(
        Axis axis,
        CornerRef *topLeftCorner, CornerRef *topRightCorner, CornerRef *bottomRightCorner, CornerRef *bottomLeftCorner,
        TileRef *middle,
        EdgeRef *topEdge, EdgeRef *rightEdge, EdgeRef *bottomEdge, EdgeRef *leftEdge
    )
        : m_axisSelf(axis), m_axisLeftRight(getLeftRightAxis(axis)), m_axisTopBottom(getTopBottomAxis(axis))
        , m_topLeftCorner(topLeftCorner), m_topRightCorner(topRightCorner), m_bottomRightCorner(bottomRightCorner), m_bottomLeftCorner(bottomLeftCorner)
        , m_middle(middle)
        , m_topEdge(topEdge), m_rightEdge(rightEdge), m_bottomEdge(bottomEdge), m_leftEdge(leftEdge)
{
}

}
