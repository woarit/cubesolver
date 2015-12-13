#include "cubesolver/side.h"

#include <ostream>

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

template<typename T>
void swapAndRotate(cube_solver::Axis axis, T **a, T **b, T **c, T **d)
{
    T *temp = *d;
    *d = *c;
    *c = *b;
    *b = *a;
    *a = temp;

    (*a)->rotate(axis);
    (*b)->rotate(axis);
    (*c)->rotate(axis);
    (*d)->rotate(axis);
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

void Side::rotate(Side::Rotation rotation)
{
    switch(rotation)
    {
        case Rotation::CLOCKWISE:
            swapAndRotate(m_axisSelf, m_topLeftCorner, m_topRightCorner, m_bottomRightCorner, m_bottomLeftCorner);
            swapAndRotate(m_axisSelf, m_topEdge, m_rightEdge, m_bottomEdge, m_leftEdge);
            break;
        case Rotation::COUNTER_CLOCKWISE:
            swapAndRotate(m_axisSelf, m_topLeftCorner, m_bottomLeftCorner, m_bottomRightCorner, m_topRightCorner);
            swapAndRotate(m_axisSelf, m_topEdge, m_leftEdge, m_bottomEdge, m_rightEdge);
            break;
        case Rotation::DOUBLE: // We swap with opposite - but no need to rotate the pieces.
            std::swap(*m_rightEdge, *m_leftEdge);
            std::swap(*m_topEdge, *m_bottomEdge);
            std::swap(*m_topLeftCorner, *m_bottomRightCorner);
            std::swap(*m_bottomLeftCorner, *m_topRightCorner);
            break;
    }
}

std::ostream& operator<<(std::ostream &out, const Side &side)
{
    return out << " "
        << (*side.m_topLeftCorner)->getSticker(side.m_axisTopBottom)
        << (*side.m_topEdge)->getSticker(side.m_axisTopBottom)
        << (*side.m_topRightCorner)->getSticker(side.m_axisTopBottom)
        << " "
        << std::endl
        << (*side.m_topLeftCorner)->getSticker(side.m_axisLeftRight)
        << (*side.m_topLeftCorner)->getSticker(side.m_axisSelf)
        << (*side.m_topEdge)->getSticker(side.m_axisSelf)
        << (*side.m_topRightCorner)->getSticker(side.m_axisSelf)
        << (*side.m_topRightCorner)->getSticker(side.m_axisLeftRight)
        << std::endl
        << (*side.m_leftEdge)->getSticker(side.m_axisLeftRight)
        << (*side.m_leftEdge)->getSticker(side.m_axisSelf)
        << (*side.m_middle)->getSticker()
        << (*side.m_rightEdge)->getSticker(side.m_axisSelf)
        << (*side.m_rightEdge)->getSticker(side.m_axisLeftRight)
        << std::endl
        << (*side.m_bottomLeftCorner)->getSticker(side.m_axisLeftRight)
        << (*side.m_bottomLeftCorner)->getSticker(side.m_axisSelf)
        << (*side.m_bottomEdge)->getSticker(side.m_axisSelf)
        << (*side.m_bottomRightCorner)->getSticker(side.m_axisSelf)
        << (*side.m_bottomRightCorner)->getSticker(side.m_axisLeftRight)
        << std::endl
        << " "
        << (*side.m_bottomLeftCorner)->getSticker(side.m_axisTopBottom)
        << (*side.m_bottomEdge)->getSticker(side.m_axisTopBottom)
        << (*side.m_bottomRightCorner)->getSticker(side.m_axisTopBottom)
        << " ";
}

}
