#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"
#include "weeklyappt.h"

using namespace std;

Day::Day()
{
}  // Day()


Day::Day(int day1, int month1, int year1) : day(day1), month(month1), 
  year(year1)
{
}  // Day(int, int, int)


void Day::addAppointment()
{
  Appointment *appointment = new Appointment();
  appointment->addAppointment();
  appts += appointment;
}  // addAppointment()


bool Day::operator== (const Day &day2) const
{
  return day == day2.day && month == day2.month 
    && year == day2.year;
} // operator== ()


bool Day::operator< (const Day &day2) const
{
  return (year < day2.year)
    || (year == day2.year && month < day2.month)
    || (year == day2.year && month == day2.month 
      && day < day2.day); 
} // operator< ()



Day& Day::operator= (const Day &rhs) 
{
  if(this == &rhs)
    return *this;
  
  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
  appts = rhs.appts;
  return *this;
}  // operator= ()


ostream& operator<< (ostream &os, const Day &day)
{
  os << "Start End   Subject      Location\n";
  os << day.appts;
  os << "\n";
  return os;
} // operator<< ()


const Appointment* operator>> (istream &is, Day &day)
{
  char weeklyOrReg[5], buffer[80];

  is.getline(weeklyOrReg, 5, ',');

  if (strcmp(weeklyOrReg, "0") == 0)
  {
    Appointment *appointment = new Appointment;
    appointment->read(is);
    is.getline(buffer, 80); // read the rest of the line
    day.appts += appointment;
    return appointment;
  } // if appointment is regular

  else // else
  {
    // use series and seriesCount to make day objects
    Appointment *wklyappt = new WeeklyAppointment;
    wklyappt->read(is);
    day.appts += wklyappt;
    return wklyappt;
  } // else weeklyAppointment

} // operator>> ()


void Day::subjectSearch(const char *subject) const
{

  const Appointment *appointmentPtr;
  
  while((appointmentPtr = appts.find(subject)))
  {
    ifstream inf("DOW.dat", ios::binary);
    DayOfWeek dayOfWeek(month, day, year);
    inf >> dayOfWeek;
    cout << dayOfWeek;
    appointmentPtr->write(cout);
    cout << endl;
    inf.close();
  } // if appointment has the subject
} // subjectSearch()


Day& Day::operator+= (const WeeklyAppointment &rhs)
{
  Appointment *appointment = new WeeklyAppointment(rhs);
  appts += appointment;
  return *this;
} // operator=+ ()



