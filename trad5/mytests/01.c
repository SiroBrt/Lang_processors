#include <stdio.h>
int a, b = 1, c = 2;
int w[10];

main() {
  int a, b = 3, c = 4;
  int v[10];
  w[c] = b;
  v[b] = c;
  printf("%d %d %d global %d", b, c, v[b], w[c]);
}

//@(main)
