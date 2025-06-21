#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float sum_float_arr(const float *v, int32_t n) {
  float s = 0;
  for (int32_t i = 0; i < n; ++i) {
    s += v[i];
  }
  return s;
}

void add_one_vec(int32_t *v, int32_t n) {
  for (int32_t i = 0; i < n; ++i) {
    v[i] += 1;
  }
}

void add_one_scalar(int32_t *i) { *i += 1; }

int32_t *return_i32_array(int32_t *n) {
  int32_t *p = malloc(3 * sizeof(int32_t));
  p[0] = 100;
  p[1] = 101;
  p[2] = 102;
  printf("Return p %p\n", p);
  *n = 3;
  return p;
}
void free_i32_array(int32_t *p) {
  printf("Now p %p is: %d, %d, %d\n", p, p[0], p[1], p[2]);

  free(p);
}

int32_t my_str_len(const char *s) { return s ? strlen(s) : 0; }
void my_upper_str(char *s) {
  if (!s) {
    return;
  };
  while (s && *s) {
    if (*s >= 'a' && *s <= 'z') {
      *s -= 'a' - 'A';
    }
    s += 1;
  }
}

const char *const *my_str_array() {
  static const char *s[] = {"first", "second", NULL};
  return s;
}

typedef struct MyStruct1 {
  int32_t a;
  char b;
  float c;
  const char *s;
  double d;
} MyStruct1;

float compute_struct1_sum(const MyStruct1 *s) {
  printf("%d, %d, %.3f, %.3f, %s\n", s->a, (int32_t)s->b, s->c, s->d, s->s);
  return s->a + s->b + s->c + s->d + strlen(s->s);
}

typedef struct MyStruct2 {
  const char *s1;
  MyStruct1 s2;
  int32_t i;
} MyStruct2;

float compute_struct2_sum(const MyStruct2 *s) {
  printf("%s, %d, %d, %.3f, %.3f, %d\n", s->s1, s->s2.a, (int32_t)s->s2.b,
         s->s2.c, s->s2.d, s->i);
  if (!s->s2.s) {
    printf("empty string in s->s2.s\n");
  } else {
    printf("string in s->s2.s is: %s\n", s->s2.s);
  }
  return strlen(s->s1) + s->s2.a + s->s2.b + s->s2.c + s->s2.d + s->i;
}
