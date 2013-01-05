#include <iostream>
#include <cstdio>
#include "hash.h"

/* 
 * calls hash() as defined in hash.cpp (MurmurHash) but clamps the value to the
 * interval [0, m].
 * TODO: how does this affect the distribution of values from MurmurHash, is it still
 * uniform?
 */
unsigned int clamped_hash(const void *key, int len, unsigned int seed, int m)
{
  unsigned int h = hash(key, len, seed);
  return h%m;
}

void setbit(unsigned char *byte, int index) {
  *byte |= (1<<index);
};

int main(int argc,char **argv)
{
  /*unsigned int seed = 0x01;
  const char *k = "apa";
  std::cout << hash(k, 3, seed) << std::endl;
  */
  
  unsigned char a = 0;
  printf("%d\n", a);
  setbit(&a, 0);
  printf("%d\n", a);
  setbit(&a, 1);
  printf("%d\n", a);

  return 0;
};
