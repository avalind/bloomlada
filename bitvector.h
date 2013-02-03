#ifndef BITVECTOR_H_
#define BITVECTOR_H_

#include <utility>

/* Only Assumption is that 1 byte = 8 bits */
class Bitvector
{
  private:
    bool inited;
    unsigned char *data;
    size_t size_in_bytes;
 
    std::pair<size_t, size_t> bit_index_to_byte(size_t bit_index);

  public:
    Bitvector(size_t size_in_bits);
    Bitvector() {};

    bool is_inited();

    void set(size_t bit_index);
    void clear(size_t bit_index);
    bool get(size_t bit_index);

};
#endif /* BITVECTOR_H_ */
