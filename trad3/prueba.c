#include <stdio.h>

int foo(int a, int b) { return 1; }

int main() {
  foo(1, 2);
  int a = 2, i;
  for (;;) {
    printf("%d\n", i);
    i++;
    if (i <= a) {
      break;
    }
  }
  return 0;
}
