/**
 * Author: Chris Bourke
 *
 * This program interactively prompts the user for
 * their birthday and computes how old they are.
 */

#include <stdio.h>
#include <time.h>

int main() {
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

  // Get the current time
  time_t now = time(NULL);

  // Create struct for the user's birthday
  struct tm bday;
  bday.tm_mday = day;
  bday.tm_mon = month - 1;  // Adjust for 0-based indexing
  bday.tm_year = year - 1900; // Adjust for the year since 1900
  bday.tm_sec = 0;
  bday.tm_min = 0;
  bday.tm_hour = 0;
  bday.tm_isdst = -1; // Let the system determine DST

  // Convert current time and birthday time to formatted strings
  char currentDateString[80];
  char birthdayDateString[80];
  struct tm *ptrNow = localtime(&now);

  strftime(currentDateString, 80, "%Y/%m/%d", ptrNow);
  strftime(birthdayDateString, 80, "%Y/%m/%d", &bday);

  // Print the current date and the user's birthday
  printf("Today is %s\n", currentDateString);
  printf("Your birthday was %s\n", birthdayDateString);

  // Calculate the difference in seconds between current time and birthday
  time_t bdayT = mktime(&bday);
  long diff = (long) difftime(now, bdayT);

  // Calculate the user's age in years (assuming an average year length)
  int years = diff / (365.25 * 24 * 60 * 60);

  // Print the calculated age
  printf("You are approximately %d years old.\n", years);

  return 0;
}




  
