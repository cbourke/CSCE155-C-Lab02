/**
 * Author: Chris Bourke
 *
 * This program reads in command line arguments
 * of the user's name and birthday and computes
 * how old they are.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char **argv) {

  if (argc != 5) {
    printf("ERROR: Invalid number of command line inputs\n");
    printf("Usage: birthday FIRSTNAME YEAR MONTH DAY\n");
    exit(1);
  }

  char name[100];
  strcpy(name, argv[1]);

  int year = atoi(argv[2);
  int month = atoi(argv[3);
  int day = atoi(argv[4);

  char str[100];
  time_t now = time(NULL);
  struct tm *ptrNow;
  struct tm bday;
  bday.tm_mday = day;
  bday.tm_mon = month - 1;  // Adjust for 0-based indexing
  bday.tm_year = year - 1900; // Adjust for the year since 1900
  bday.tm_sec = 0;
  bday.tm_min = 0;
  bday.tm_hour = 0;
  bday.tm_isdst = -1; // Let the system determine DST

  ptrNow = localtime(&now);

  strftime(str, 80, "%Y/%m/%d", ptrNow);
  printf("Today is %s\n", str);
  strftime(str, 80, "%Y/%m/%d", &bday);
  printf("Your birthday was %s\n", str);

  time_t bdayT = mktime(&bday);
  double diff = difftime(now, bdayT);

  int years = (int)(diff / (365.25 * 24 * 60 * 60));
  diff -= years * (365.25 * 24 * 60 * 60);
  int days = (int)(diff / (24 * 60 * 60));
  int weeks = days / 7;
  days = days % 7;

  printf("Hello, %s. You are %d years, %d weeks, and %d days old today.\n", name, years, weeks, days);
  return 0;
}





