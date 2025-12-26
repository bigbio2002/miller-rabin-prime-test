#ifndef _RAND_RANGE_H_
#define _RAND_RANGE_H_

// Source - https://stackoverflow.com/a/6852396
// Posted by Ryan Reich, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-26, License - CC BY-SA 3.0

#include <stdlib.h> // For random(), RAND_MAX

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
int random_range(int max)
{
  unsigned
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned)max+1,
    num_rand = (unsigned)RAND_MAX+1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  int x;
  do
  {
   x = random();
  }
  // This is carefully written not to overflow
  while(num_rand - defect <= (unsigned)x);

  // Truncated division is intentional
  return x/bin_size;
}

#endif
