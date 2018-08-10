#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstring>
#include "DayOfWeek.h"

using namespace std;


DayOfWeek::DayOfWeek(int month1, int day1, int year1) : month(month1), 
  day(day1), year(year1)
{
}  // DayOfWeek()


ostream& operator<< (ostream &os, const DayOfWeek &dayOfWeek)
{
  char line[80], dayStr[3], yearStr[7];
  strcpy(line, dayOfWeek.dayName);
  strcat(line, ", ");
  strcat(line, dayOfWeek.monthName);
  strcat(line, " ");
  
  if(dayOfWeek.day > 9)
  {
    dayStr[0] = dayOfWeek.day / 10 + '0';
    dayStr[1] = dayOfWeek.day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = dayOfWeek.day + '0';
    dayStr[1] = '\0';
  } // else day < 10

  strcat(line, dayStr);

  yearStr[0] = ',';
  yearStr[1] = ' ';
  yearStr[2] = dayOfWeek.year / 1000 + '0';
  yearStr[3] = dayOfWeek.year / 100 % 10 + '0';
  yearStr[4] = dayOfWeek.year / 10 % 100 % 10 + '0';
  yearStr[5] = dayOfWeek.year % 1000 % 100 % 10 + '0';
  yearStr[6] = '\0';

  strcat(line, yearStr);

  os << left << setw(30) << line << right; 
  return os;
}  // operator<<()


istream& operator>> (istream &is, DayOfWeek &day) 
{
  int dateNumber = (day.month - 1) * 31 + day.day - 1 + (day.year - 1990) * 372;
  is.seekg(dateNumber * sizeof(DayOfWeek));
  is.read((char*) &day, sizeof(DayOfWeek));
  return is;
}  // operator>>


bool DayOfWeek::operator== (char c) const
{
  switch (c)
  {
    case 'M':

      if (strcmp(dayName, "Monday") == 0)
        return true; 
      break;
      
    case 'T':

      if (strcmp(dayName, "Tuesday") == 0)
        return true; 
      break;
      
    case 'W':

      if (strcmp(dayName, "Wednesday") == 0)
        return true; 
      break;
      
    
    case 'R':

      if (strcmp(dayName, "Thursday") == 0)
        return true; 
      break;

    
    case 'F':

      if (strcmp(dayName, "Friday") == 0)
        return true; 
      break;
    
    case 'S':

      if (strcmp(dayName, "Saturday") == 0)
        return true; 
      break;

    case 'U':
    
      if (strcmp(dayName, "Sunday") == 0)
        return true; 
      break;
 
    default:
      return false;
  } // switch

  return false;
} // operator== ()

