#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void main(int argc, char *argv[]) {

  if(argc != 5) {
    printf("ERROR: invalid number of command line inputs\n");
    printf("       Usage: birthday FIRSTNAME YEAR MONTH DAY\n");
    exit(1);
  }

  char name[100];

  strcpy(name, argv[1]);
  int year = atoi(argv[2]);
  int month = atoi(argv[3]);
  int day = atoi(argv[4]);

  char str[100];
  time_t now = time(NULL);
  struct tm *ptrNow;
  struct tm bday;
  bday.tm_mday = day;
  bday.tm_mon = month - 1;
  bday.tm_year = year % 100; 
  bday.tm_sec = 0;
  bday.tm_min = 0;
  bday.tm_hour = 0;
  ptrNow = localtime(&now);
  strftime(str,80,"%Y/%m/%d",ptrNow);
  printf("Today is %s\n", str);
  strftime(str,80,"%Y/%m/%d",&bday);
  printf("Your birthday was %s\n", str);

  time_t bdayT = mktime(&bday);
  double diff = difftime(now, bdayT);

  int years = (int) (diff / (double) (365.25 * 24 * 60 * 60));
  diff -= years * (365.25 * 24 * 60 * 60);
  int days = diff / (24 * 60 * 60);
  int weeks = days / 7;
  days = days % 7;

  printf("Hello, %s.  You are %d years, %d weeks, and %d days old today.\n", name, years, weeks, days);

}
