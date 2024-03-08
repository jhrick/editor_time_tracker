#include <stdio.h>
#include <time.h>

void prime_nums(int starting_point) {
  int i, j;

  for (i = 2; i <= starting_point; i++) {
    for (j = 1; j < i; j++) {
      if (i % j == 0 && j != 1) {
        break;
      }

      if (j + 1 == i) {
        printf("%d is prime num\n", i);
      }
    }
  }
}

int main(void) {
  clock_t time_execution;
  double dif;

  time_execution = clock();
  prime_nums(140000);
  time_execution = clock() - time_execution;
  dif = ((double)time_execution) / CLOCKS_PER_SEC;

  printf("time: %.0fs\n", dif);

  return 0;
}
