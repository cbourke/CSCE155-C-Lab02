/**
 * Author: Chris Bourke
 *
 * This program outputs data on the limits of various
 * data types.
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv) {

  //character types
  printf("\nData type: character type.\n");
  printf("Minimum value for signed char: %d.\n", SCHAR_MIN);
  printf("Maximum value for signed char: %d.\n", SCHAR_MAX);
  printf("Minimum value for unsigned char: %d.\n", 0);
  printf("Maximum value for unsigned char: %d.\n", UCHAR_MAX);
  printf("Minimum value for char: %d.\n", CHAR_MIN);
  printf("Maximum value for char: %d.\n", CHAR_MAX);
  printf("Size of signed char: %ld byte.\n\n", sizeof(signed char));

  //integers
  printf("Data type: integer.\n");
  printf("Minimum value for signed short: %d.\n", SHRT_MIN);
  printf("Maximum value for signed short: %d. \n", SHRT_MAX);
  printf("Size of signed short: %ld bytes.\n\n", sizeof(signed short));
  printf("Minimum value for unsigned short: %d.\n", 0);
  printf("Maximum value for unsigned short: %d.\n", USHRT_MAX);
  printf("Size of unsigned short: %ld bytes.\n\n", sizeof(unsigned short));
  printf("Minimum value for signed int: %d\n", INT_MIN );
  printf("Maximum value for signed int: %d\n", INT_MAX );
  printf("Size of signed int: %ld bytes.\n\n", sizeof(signed int));
  printf("Minimum value for unsigned int: %u\n", 0 );
  printf("Maximum value for unsigned int: %u\n", UINT_MAX );
  printf("Size of unsigned int: %ld bytes.\n\n", sizeof(unsigned int));
  printf("Minimum value for signed long: %ld\n", LONG_MIN );
  printf("Maximum value for signed long: %ld\n", LONG_MAX );
  printf("Size of signed long: %ld bytes.\n\n", sizeof(signed long));
  printf("Minimum value for unsigned long: %d\n", 0 );
  printf("Maximum value for unsigned long: %lu\n", ULONG_MAX );
  printf("Size of unsigned long: %ld bytes.\n\n", sizeof(unsigned long));

  //floating point types
  printf("Data type: floating-point.\n");
  printf("Size of float: %ld bytes.\n", sizeof(float));
  printf("Size of double: %ld bytes.\n", sizeof(double));
  printf("Size of long double: %ld bytes.\n", sizeof(long double));

  return 0;

}
