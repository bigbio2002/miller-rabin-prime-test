/* https://equilibriumofnothing.wordpress.com/2013/09/23/algorithm-miller-rabin/ */

#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

// note: Russian peasant's algorithm is implemented as power() in <algorithm>

uint64_t mostSignificantBit(uint64_t u) {
  u |= u >> 1;
  u |= u >> 2;
  u |= u >> 4;
  u |= u >> 8;
  u |= u >> 16;
  u |= u >> 32;

  return u & ~(u >> 1);
}

// raise radix to the power u
uint64_t russianPeasantPower(uint64_t u,
                             const uint64_t radix,
                             const uint64_t modulo) {
  uint64_t a = 1,
           mask = mostSignificantBit(u);

  while (mask) {
    a = (a * a) % modulo;
    if (mask & u)
      a = (a * radix) % modulo;
    mask >>= 1;
  }

  return a;
}

// if true is returned, that means provably not prime
// if false, then not sure either way
bool witness(uint64_t radix, // random number from 1 to n-1 for test
             uint64_t n) {   // candidate number
  // candidate number must be odd (otherwise 2 is factor)
  // subtract off least significant bit
  uint64_t u = n - 1;

  // factor into mantissa and exponent
  // effectively remove and count zeros to first bit
  int t = 0;
  while (u & 0x1 == 0x0) {
    u = u >> 1;
    t++;
  }

  uint64_t x = russianPeasantPower(u, radix, n),
           w;

  for (int i = 0; i < t; i++) {
    w = x;           // last
    x = (w * w) % n; // current

    // if number is square root of unity and not trivial
    if (1 == x && w != 1 && w != n-1)
      return true;
  }

  // last check for square root of unity
  return x != 1;
}

int main(int argc, char *argv[]) {
  // input candidate prime and number of trials
  cout << "input candidate prime and number of trials" << endl;
  uint64_t n;
  int NumTrials;
  cin >> n >> NumTrials;

  // the one even prime number is 2
  if (2 == n) {
    cout << n << " is prime" << endl;
    exit(0);
  }

  // exclude even numbers
  if (n % 2 == 0) {
    cout << "even number, not prime" << endl;
    exit(2);
  }

  // trying to reject primality, looking for evidence of compositeness
  for (int i = 0; i < NumTrials; i++)
    if (witness(1 + rand() % (n - 1), n)) {
      cout << "not prime confirmed at trial " << i << endl;
      exit(1);
    }

  cout << "probably prime" << endl;

  exit(0);
}
