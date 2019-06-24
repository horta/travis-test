#include <x86intrin.h>
#include <stdio.h>
#include <stdint.h>
int main(void) {
  __m256i v1 = _mm256_set1_epi32(42);
  __m256i v2 = _mm256_set1_epi32(214);
  union { __m256i v; int32_t x[8]; } v3;
  v3.v = _mm256_add_epi32(v1, v2);
  printf("%d\n", v3.x[2]);
  union { __m256i v; uint8_t x[32]; } u;
  __m256i a = u.v;
  a = _mm256_max_epu8(a, _mm256_permute2x128_si256(a, a, 0x01));
  a = _mm256_max_epu8(a, _mm256_shuffle_epi32     (a,    0x4e));    
  a = _mm256_max_epu8(a, _mm256_shuffle_epi32     (a,    0xb1));
  a = _mm256_max_epu8(a, _mm256_shufflelo_epi16   (a,    0xb1));
  a = _mm256_max_epu8(a, _mm256_srli_si256        (a,    1));
  uint8_t c = _mm256_extract_epi8(a, 0);
  printf("%d\n", (int) u.x[0]);
  printf("%d\n", (int) c);
  return 0;
}

