#ifndef _MOSTSIGNIFICANTBIT_H_
#define _MOSTSIGNIFICANTBIT_H_

uint64_t mostSignificantBit_64(uint64_t u)
{
  u |= u >> 1;
  u |= u >> 2;
  u |= u >> 4;
  u |= u >> 8;
  u |= u >> 16;
  u |= u >> 32;

  return u & ~(u >> 1);
}

#endif
