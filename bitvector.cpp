#include <cstring>
#include "bitvector.h"

Bitvector::Bitvector(size_t size_in_bits)
{
  this->size_in_bytes = (size_in_bits / 8) + 8;
  this->data = new unsigned char[this->size_in_bytes];

  if(this->data == NULL) {
    this->inited = false;
  } else {
    memset(this->data, '\0', this->size_in_bytes);
    this->inited = true;
  };
};

bool Bitvector::is_inited()
{
  return this->inited;
};

/* Stores the index of the byte in first, and the index of the bit in
 * that byte in second.
 */
std::pair<size_t, size_t> Bitvector::bit_index_to_byte(size_t bit_index)
{
  std::pair<size_t, size_t> coord;
  coord.first = bit_index / 8;
  coord.second = bit_index % 8;
  return coord;
};

void Bitvector::set(size_t bit_index)
{
  std::pair<size_t, size_t> coord = this->bit_index_to_byte(bit_index);
  unsigned char *byte_ptr = &(this->data[coord.first]);
  *byte_ptr |= (1<<coord.second);
};

bool Bitvector::get(size_t bit_index)
{
  std::pair<size_t, size_t> coord = this->bit_index_to_byte(bit_index);
  unsigned char val = this->data[coord.first];
  bool bitval = (val & (1 << coord.second)) >> coord.second;
  return bitval;
};

void Bitvector::clear(size_t bit_index)
{
  std::pair<size_t, size_t> coord = this->bit_index_to_byte(bit_index);
  unsigned char *byte_ptr = &(this->data[coord.first]);
  *byte_ptr &= ~(1 << x);
}
