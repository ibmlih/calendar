#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "weeklyappt.h"
#include "time.h"

using namespace std;


WeeklyAppointment::WeeklyAppointment() : Appointment(), seriesCount(0)
{
} // WeeklyAppointment() default constructor


void WeeklyAppointment::increaseCount(int num)
{
  incCount(num);
} // increaseCount()


WeeklyAppointment::WeeklyAppointment(const WeeklyAppointment &wappt) : 
                    Appointment(wappt), seriesCount(wappt.seriesCount)
{
  strcpy(series, wappt.series);
} // WeeklyAppointment() copy constructor


WeeklyAppointment::~WeeklyAppointment()
{
} // ~WeeklyAppointment()


WeeklyAppointment* WeeklyAppointment::clone() const
{
  return new WeeklyAppointment(*this);
} // clone()


istream& WeeklyAppointment::read(istream &is)
{
  char line[10];
  int num;

  is >> *this;

  is.getline(line, 10, ',');
  strcpy(series, line);

  is.getline(line, 10);
  num = atoi(line);
  seriesCount = num;

  return is;
} // read()


const char* WeeklyAppointment::getSeries() const
{
  return series;
} // getSeries()


int WeeklyAppointment::getSeriesCount() const
{
  return seriesCount;
} // getSeriesCount()


ostream& WeeklyAppointment::write(ostream &os) const
{
  os << *this;

  os << "" << setw(7) << left << getSeries() << right 
  << " (" << getSeriesCount() << ')';

  return os;
} // write()