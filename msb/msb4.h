#ifndef _MSB4_H_
#define _MSB4_H_

unsigned mostSignificantBit32(uint32_t val)
{
  unsigned bit = 0;

  /* 4 = log(sizeof(val) * 8) / log(2) - 1 */
  for(int r = 4; r >= 0 ; --r)
  {
    unsigned shift = 1 << r; /* 2^r */
    uint32_t sval = val >> shift;

    if(sval)
    {
        bit += shift;
        val = sval;
    }
  }

  return bit;
}

#endif
