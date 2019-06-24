#include <x86intrin.h>
#include <stdio.h>
#include <stdint.h>
int main(void) {
  __m256i v1 = _mm256_set1_epi32(42);
  __m256i v2 = _mm256_set1_epi32(214);
  union { __m256i v; int32_t x[8]; } v3;
  v3.v = _mm256_add_epi32(v1, v2);
  printf("%d\n", v3.x[2]);
  return 0;
}

