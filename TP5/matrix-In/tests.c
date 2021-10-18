#include <stdio.h>
#include "tps_unit_test.h"
#include "matrix-In.h"

TEST_INIT_GLOBAL

void test_error_malloc_1(void)
{
  __remaining_alloc = 0;
  int ** mat = matrixI1(10);
  tps_assert(mat == NULL);
}

void test_error_malloc_2(void)
{
  __remaining_alloc = 0;
  int ** mat;
  matrixI2(10, &mat);
  tps_assert(mat == NULL);
}

void test_error_malloc_3(void)
{
  __remaining_alloc = 1;
  int ** mat = matrixI1(10);
  tps_assert(mat == NULL);
}

void test_error_malloc_4(void)
{
  __remaining_alloc = 1;
  int ** mat;
  matrixI2(10, &mat);
  tps_assert(mat == NULL);
}
void test_error_malloc_5(void)
{
  __remaining_alloc = 2;
  int ** mat = matrixI1(10);
  tps_assert(mat == NULL);
}

void test_error_malloc_6(void)
{
  __remaining_alloc = 2;
  int ** mat;
  matrixI2(10, &mat);
  tps_assert(mat == NULL);
}
void test_error_malloc_7(void)
{
  __remaining_alloc = 5;
  int ** mat = matrixI1(10);
  tps_assert(mat == NULL);
}

void test_error_malloc_8(void)
{
  __remaining_alloc = 5;
  int ** mat;
  matrixI2(10, &mat);
  tps_assert(mat == NULL);
}

void test_matrice_1(void)
{
  __remaining_alloc = -1;
  int ** mat = matrixI1(10);
  tps_assert(mat != NULL);
  tps_assert(mat[0][0] == 1);
  tps_assert(mat[1][1] == 1);
  tps_assert(mat[2][2] == 1);
  tps_assert(mat[1][0] == 0);
  tps_assert(mat[2][0] == 0);
  tps_assert(mat[0][1] == 0);
  tps_assert(mat[0][2] == 0);

  freeMatrix(10, mat);
}
void test_matrice_2(void)
{
  __remaining_alloc = -1;
  int ** mat;
  matrixI2(10, &mat);
  tps_assert(mat != NULL);
  tps_assert(mat[0][0] == 1);
  tps_assert(mat[1][1] == 1);
  tps_assert(mat[2][2] == 1);
  tps_assert(mat[1][0] == 0);
  tps_assert(mat[2][0] == 0);
  tps_assert(mat[0][1] == 0);
  tps_assert(mat[0][2] == 0);

  freeMatrix(10, mat);
}

int main(void)
{
  TEST(test_error_malloc_1);
  TEST(test_error_malloc_2);
  TEST(test_error_malloc_3);
  TEST(test_error_malloc_4);
  TEST(test_error_malloc_5);
  TEST(test_error_malloc_6);
  TEST(test_error_malloc_7);
  TEST(test_error_malloc_8);
  TEST(test_matrice_1);
  TEST(test_matrice_2);

}
