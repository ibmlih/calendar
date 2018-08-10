#ifndef APPT_H
#define	APPT_H

#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;


class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
  static int count;
public:
  Appointment();
  Appointment(const Appointment &appt);
  virtual ~Appointment();
  void addAppointment();
  bool operator== (const char *subject) const;
  static int getCount();
  bool operator< (const Appointment &appointment2) const;
  friend ostream& operator<< (ostream &os, const Appointment &appointment);
  friend istream& operator>> (istream &is, Appointment &appointment);
  virtual Appointment* clone() const; 
  virtual istream& read(istream &is);
  virtual ostream& write(ostream &os) const;
  void incCount(int num);
}; // class Appointment
#endif  // APPT_H 

