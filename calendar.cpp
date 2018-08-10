#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"
#include "day.h"
#include "vector.h"

using namespace std;

Calendar::Calendar() : days(30)
{
} // create()


Calendar::~Calendar()
{
}  // ~Calendar()


void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  pos = (days += dayTemp);
  days[pos].addAppointment();
}  // addAppointment()


void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  
  for(int i = 0; i < days.getCount(); i++)
    if(days[i] ==  dayTemp)
    {
      cout << days[i];
      return;
    } // if found matching date
  
  cout << "That date was not found.\n";
}  // dateSearch()


void Calendar::getDate(int *day, int *month, int *year) const
{
  while(true)
  {
    char line[80], line2[80], *ptr;
    cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";
    
    if (! fgets(line, 80, stdin))
      cout << " is not a valid date.\nPlease try again.\n";
    else // User entered something
    {
      strtok(line, "\n");
      strcpy(line2, line);
      ptr = strtok(line, "/");
      
      if(ptr)
      {
        *month = atoi(ptr);
        ptr = strtok(NULL, "/");
        
        if(ptr)
        {
          *day = atoi(ptr);
          ptr = strtok(NULL, "\n");
          
          if(ptr)
            *year = atoi(ptr);
        } // if something before a second /
      } // if something before the first /
      
      if(*day >= 1 && *day <= 31 && *month >= 1 && *month <= 12 
         && *year >= 1000 && *year <= 2017)
         break;
      
      cout << line2 << " is not a valid date.\nPlease try again.\n";
    } // else use entered something
  } // while invalid date
}  // getDate()


istream& operator>> (istream &is, Calendar &calendar)
{
  char line[80];
  int day, month, year, pos;
  is.getline(line, 80);  // get rid of label line;
  
  while(is.getline(line, 80, '/'))
  {
    month = atoi(line);
    is.getline(line, 80, '/');
    day = atoi(line);
    is.getline(line, 80, ',');
    year = atoi(line);
    Day dayTemp(day, month, year);
    pos = calendar.days += dayTemp;

    const Appointment *appt = is >> calendar.days[pos];
    const WeeklyAppointment *weeklyappt 
    = dynamic_cast<const WeeklyAppointment*> (appt);
    
    if (weeklyappt)
      calendar.createSeries(*weeklyappt, day, month, year);
  } // while more lines in the file
  
  return is;
}  // operator>> ()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);
  
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'
  
  cout << "Date                          Start End   Subject      Location\n";
  
  for(int i = 0; i < days.getCount(); i++)
    days[i].subjectSearch(subject);
  
  cout << "\n";
}  // subjectSearch()


void Calendar::createSeries(WeeklyAppointment weeklyappt, 
                            int day, int month, int year)
{
  int count = 1, pos;
  unsigned int i = 0;
  char series[8];
  strcpy(series, weeklyappt.getSeries());
  ifstream inf("DOW.dat", ios::binary);

  while (count != weeklyappt.getSeriesCount() && i < strlen(series))
  {
    while (true)
    {
      incDate(&day, &month, &year);
      DayOfWeek dayOfWeek(month, day, year);
      inf >> dayOfWeek;

      for (i = 0; i < strlen(series); i++)
      {
        if (dayOfWeek == series[i])
          break;
      } // for

      if (dayOfWeek == series[i])
        break;      
    } // while 

    Day dayTemp(day, month, year);
    pos = (days += dayTemp);
    WeeklyAppointment *newAppt = new WeeklyAppointment(weeklyappt);
    days[pos] += *newAppt;
    delete newAppt;
    count++;
  } // while

  weeklyappt.increaseCount(weeklyappt.getSeriesCount() - 1);
  inf.close();
} // createSeries()


void Calendar::incDate (int *d, int *m, int *y) const
{
  if (*d < 31)
        *d = *d + 1;

  else // else

  if (*d == 31 && *m < 12) // else
  {
    *d = 1;
    *m = *m + 1;
  } // else if

  else // else
  {
    *d = 1;
    *m = 1;
    *y = *y + 1;
  } // if
} // incDate()











