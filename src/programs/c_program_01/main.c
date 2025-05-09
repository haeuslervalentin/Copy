#include <stdio.h>
#include <inttypes.h>

void Hanoi(size_t n, int32_t *arr_1, int32_t *arr_2, int32_t top_1, int32_t top_2)
{
  int32_t temp = arr_2[top_2];
  arr_2[top_2] = arr_1[top_1];
  arr_1[top_1] = temp;
}

int main(int argc, char **argv) {
 int32_t arrays
  return 0;
}
