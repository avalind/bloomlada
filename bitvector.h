#ifndef BITVECTOR_H_
#define BITVECTOR_H_

/* Only Assumption is that 1 byte = 8 bits */
class Bitvector
{
  private:
    unsigned char *data;
    size_t size_in_bytes;
  
  public:
    Bitvector(size_t size_in_bits);

    void set(size_t bit_index, bool value);
    bool get(size_t bit_index);
}
#endif /* BITVECTOR_H_ */
