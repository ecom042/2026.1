/**
 * @file number.h
 * @brief Tagged union representing unsigned integers of varying widths (8, 16,
 * 32 bits).
 *
 * Provides a packed, discriminated union (struct number) that stores a value
 * alongside a tag indicating its bit-width.  Convenience macros and inline
 * constructors are supplied for each supported width, as well as a raw byte
 * accessor for serialisation purposes.
 */

#include <stdbool.h>
#include <stdint.h>

/** @brief Compound-literal initialiser for a 32-bit number. */
#define NUMBER_U32(_val) {.tag = U32, .u32 = _val}
/** @brief Compound-literal initialiser for a 16-bit number. */
#define NUMBER_U16(_val) {.tag = U16, .u16 = _val}
/** @brief Compound-literal initialiser for an 8-bit number. */
#define NUMBER_U8(_val) {.tag = U8, .u8 = _val}

#ifdef HAS_FLOAT
/** @brief Compound-literal initialiser for a 32-bit float number. */
#define NUMBER_F32(_val) {.tag = F32, .f32 = _val}
#endif
/**
 * @brief Discriminant values for struct number.
 */
enum number_tag {
  U32,
  U16,
  U8,
#ifdef HAS_FLOAT
  F32
#endif
};

/**
 * @brief A tagged union holding an unsigned integer value.
 *
 * The @c tag field indicates which union member is active.
 * The anonymous union allows direct access to the value as u32, u16, u8,
 * or as a raw byte array (@c bytes) for serialisation.
 *
 * Packed with @c __attribute__((packed)) to avoid padding between the tag
 * and the value.
 */
struct number {
  enum number_tag tag;
  union {
    uint32_t u32;
    uint16_t u16;
    uint8_t u8;
#ifdef HAS_FLOAT
    float f32;
#endif
    uint8_t bytes[4];
  };
} __attribute__((packed));

/**
 * @brief Create a struct number with the given tag and 32-bit raw value.
 *
 * @param tag  The width discriminant (U32, U16 or U8).
 * @param u32  The value to store (truncated according to @p tag on read).
 * @return A struct number initialised with @p tag and @p u32.
 */
static inline struct number number_create(enum number_tag tag, uint32_t u32) {
  return (struct number){.tag = tag, .u32 = u32};
}

/**
 * @brief Convenience constructor for a 32-bit number.
 *
 * @param u32  The 32-bit value.
 * @return A struct number tagged as U32.
 */
static inline struct number number_u32_create(uint32_t u32) {
  return number_create(U32, u32);
}
#ifdef HAS_FLOAT
static inline struct number number_f32_create(float f32) {
  return number_create(F32, f32);
}
#endif

/**
 * @brief Compute the sum of two numbers.
 *
 * @param a  First operand.
 * @param b  Second operand.
 * @return The result of adding @p a and @p b.
 */
struct number sum(struct number a, struct number b);
