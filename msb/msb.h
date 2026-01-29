#ifndef _MSB3_H_
#define _MSB3_H_

unsigned msb64(uint64_t u)
{
  u |= u >> 1;
  u |= u >> 2;
  u |= u >> 4;
  u |= u >> 8;
  u |= u >> 16;
  u |= u >> 32;

  return u & ~(u >> 1);
}

unsigned msb32(uint32_t u)
{
  u |= u >> 1;
  u |= u >> 2;
  u |= u >> 4;
  u |= u >> 8;
  u |= u >> 16;

  return u & ~(u >> 1);
}

#endif
