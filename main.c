#include "number.h"
#include <stdio.h>

int main() {

#ifdef HAS_FLOAT
  printf("   ***   FLOAT SUPPORT ENABLED\n");
#endif

  struct number n = number_u32_create(0xAABBCCDD);
  printf("n.u32=%#08x\n", n.u32);
  printf("n.u16=%#04x\n", n.u16);
  printf("n.u8=%#02x\n", n.u8);
  printf("n.bytes[0]=%#02x\n", n.bytes[0]);
  printf("n.bytes[1]=%#02x\n", n.bytes[1]);
  printf("n.bytes[2]=%#02x\n", n.bytes[2]);
  printf("n.bytes[3]=%#02x\n", n.bytes[3]);

  struct number a = NUMBER_U16(0x0f0a);
  struct number b = NUMBER_U32(0x00f0a00b);
  struct number s = sum(a, b);
  printf("sum = %#08x\n", s.u32);

#ifdef HAS_FLOAT
  struct number f = NUMBER_F32(3.14f);
  printf("f32 = %f\n", f.f32);
#endif

  return 0;
}
