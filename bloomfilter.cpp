#include "bloomfilter.h"
#include "hash.h"

Bloomfilter::Bloomfilter(unsigned int m, unsigned int k)
{
  this->m = m;
  this->k = k;
  this->bitvec = Bitvector(m / 8);
};

void Bloomfilter::add(void *data_ptr, size_t len)
{
  int index;
  for(int i = 0; i < this->k; i++) {
    index = clamped_hash(data_ptr, len, i+1, this->m);
    this->bitvec.set(index);
  };
};

bool Bloomfilter::query(void *data_ptr, size_t len)
{
  int index;
  for(int i = 0; i < this->k; i++) {
    index = clamped_hash(data_ptr, len, i+1, this->m);
    if(this->bitvec.get(index) != true)
      return false;
  };
  return true;
};
