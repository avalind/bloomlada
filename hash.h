#ifndef HASH_H_
#define HASH_H_

unsigned int hash(const void *key, int len, unsigned int seed);
unsigned int clamped_hash(const void *key, int len, unsigned int seed, int m);

#endif /* HASH_H_ */
