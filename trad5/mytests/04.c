#include <stdio.h>
int a, b = 1, c;
a = 1;

foo(int a, int b) {
  if (a == b) {
    puts("cosa");
  } else {
    puts("nada");
  }
}
foo1() {
  printf("%d %d %d %d %d %d %d %d %d %d", 1 || 0, 1 && 1, !1, 1 != 2, 1 == 2,
         1 < 2, 1 <= 2, 1 > 2, 1 >= 2, 1 % 2);
  printf("%s, %d%d ", "abracadabra", 8 / (2 + 5 - 3), 3 >= 5 + 1);
  a = ((((((((a)))) + 1))));
}

main() {
  int n;
  int i, j;
  while (i < n) {
    foo1();
    for (j = 0; j < i; j = j + 1) {
      a = foo(a, b);
    }
    i = i + 1;
  }
  for (int it; it < n; it = it + 1) {
    foo1();
    for (j = 0; j < it; j = j + 1) {
      a = foo(a, b);
    }
  }
}
