#ifndef _RAND_RANGE_H_
#define _RAND_RANGE_H_

// Source - https://stackoverflow.com/a/6852396
// Posted by Ryan Reich, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-26, License - CC BY-SA 3.0

#include <stdlib.h> // For random(), RAND_MAX

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long random_range(long max)
{
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long)max+1,
    num_rand = (unsigned long)RAND_MAX+1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  do
  {
   x = random();
  }
  // This is carefully written not to overflow
  while(num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}

#endif
