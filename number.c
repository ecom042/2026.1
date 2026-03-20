#include "number.h"

struct number sum(struct number a, struct number b) {
  struct number result;
  switch (a.tag) {
  case U32:
    result.u32 = a.u32 + b.u32;
    break;
  case U16:
    result.u16 = a.u16 + b.u16;
    break;
  case U8:
    result.u8 = a.u8 + b.u8;
    break;
#ifdef HAS_FLOAT
  case F32:
    result.f32 = a.f32 + b.f32;
    break;
#endif
  }
  return result;
}
