#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include "bitvector.h"

class Bloomfilter
{
  private:
    unsigned int m;
    unsigned int k;
    Bitvector bitvec;

  public:
    Bloomfilter(unsigned int m, unsigned int k);

    void add(void *data, size_t len);
    bool query(void *data, size_t len);
};

#endif /* BLOOMFILTER_H_ */
