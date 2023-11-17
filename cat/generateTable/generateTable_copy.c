#include <stdio.h>

int main() {
  for (int i = 0; i != 256; i++) {
    if (i != 0 && !(i % 10)) {
      printf("\n");
    } else {
      printf(" ");
    }
    printf("\"");
    switch (i) {
      case '\b':
        printf("\\b");
        break;
      case '\v':
        printf("\\v");
        break;
      case '\t':
        printf("\\t");
        break;
      case '\r':
        printf("\\r");
        break;
      case '\n':
        printf("\\n");
        break;
      case '\'':
        printf("\\'");
        break;
      case '\"':
        printf("\\\"");
        break;
      case '\\':
        printf("\\");
        break;
      default:
        if (i < 32) {
          printf("\\0%o", i);
        } else if (i > '~') {
          printf("\\x%x", i);
        } else {
          printf("%c", i);
        }
    }
    printf("\",");
  }

  return 0;
}