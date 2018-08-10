#ifndef WEEKLY_APPT_H
#define WEEKLY_APPT_H

#include <iostream>
#include <fstream>
#include "time.h"
#include "appt.h"
using namespace std;


class WeeklyAppointment : public Appointment
{
  char series[8];
  int seriesCount; 
public:
  WeeklyAppointment();
  WeeklyAppointment(const WeeklyAppointment &wappt); 
  ~WeeklyAppointment();
  WeeklyAppointment* clone() const;
  virtual istream& read(istream &is);
  const char* getSeries() const;
  int getSeriesCount() const;
  virtual ostream& write(ostream &os) const;
  void increaseCount(int num);
}; // class WeekylyAppt

#endif