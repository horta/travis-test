#include <x86intrin.h>
#include <stdio.h>
#include <stdint.h>
int main(void) {
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

