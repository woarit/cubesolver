#ifndef CUBESOLVER_STICKER_H
#define CUBESOLVER_STICKER_H

#include <iosfwd>

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

/**
 * Outputting the sticker to the given stream.
 * This will be as a capital letter representing
 * the sticker. An invalid sticker will be a
 * question mark.
 *
 * @param out stream to write to
 * @param sticker the sticker to output
 *
 * @return the same stream as given, after outputting the sticker
 */
std::ostream& operator<<(std::ostream &out, const Sticker &sticker);

}

#endif //CUBESOLVER_STICKER_H
