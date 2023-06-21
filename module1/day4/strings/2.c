#include <stdio.h>
#include <stdlib.h>

int string_to_integer(const char* str) {
  return atoi(str);
}

int main() {
  const char* str = "5278";
  int value = string_to_integer(str);
  printf("Input String: %s\n", str);
  printf("Integer Value: %d\n", value);

  return 0;
}