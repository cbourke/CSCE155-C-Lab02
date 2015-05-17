#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void main(int argc, char *argv[]) {

  char name[100];
  printf("Please Enter Your First Name (no spaces) followed by ENTER: ");
  scanf("%s", name);

  int year = 0;
  printf("Enter the year in which you were born: ");
  scanf("%d", &year);
  
  int month = 0;
  printf("Enter the month in which you were born (1-12): ");
  scanf("%d", &month);
 
  int day = 0;
  printf("Enter the day of the month in which you were born (1-31): ");
  scanf("%d", &day);
 
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
  long diff = (long) difftime(now, bdayT);

  //  printf("You are %d second old\n", diff); 
  int years = diff / (365.25 * 24 * 60 * 60);
  diff -= years * (365.25 * 24 * 60 * 60);
  int days = diff / (24 * 60 * 60);

  int weeks = days / 7;
  days = days % 7;

  printf("Hello, %s.  You are %d years, %d weeks, and %d days old today\n", name, years, weeks, days);

}
