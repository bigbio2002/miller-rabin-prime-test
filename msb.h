/* source: https://stackoverflow.com/a/26598349 */

#ifndef _MSB_H_
#define _MSB_H_

unsigned msb32(unsigned x)
{
    static const unsigned bval[] =
    { 0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4 };

    unsigned base = 0;
    if (x & 0xFFFF0000) { base += 32/2; x >>= 32/2; }
    if (x & 0x0000FF00) { base += 32/4; x >>= 32/4; }
    if (x & 0x000000F0) { base += 32/8; x >>= 32/8; }

    return base + bval[x];
}

#endif
