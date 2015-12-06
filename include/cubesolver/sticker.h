#ifndef CUBESOLVER_STICKER_H
#define CUBESOLVER_STICKER_H

namespace cube_solver
{

/**
 * Representing the different kinds of stickers on the cube.
 * Note that indexing of the enum starts at 1 so default
 * constructed is 0 which is an invalid value.
 */
enum class Sticker
{
    // Sticker{} = 0 (invalid)
    ORANGE = 1,
    RED,
    YELLOW,
    WHITE,
    BLUE,
    GREEN,
};

}

#endif //CUBESOLVER_STICKER_H
