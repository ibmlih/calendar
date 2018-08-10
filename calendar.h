#ifndef CALENDAR_H
#define	CALENDAR_H

#include "day.h"
#include "vector.h"
#include "weeklyappt.h"
#include "DayOfWeek.h"

class Calendar
{
  Vector<Day> days;
public:
  Calendar();
  ~Calendar();
  void addAppointment();
  void dateSearch() const;
  void getDate(int *day, int *month, int *year) const;
  friend istream& operator>> (istream &is, Calendar &calendar); 
  void subjectSearch() const;
  void createSeries(WeeklyAppointment weeklyappt, 
                    int day, int month, int year);
  void incDate(int *d, int *m, int *y) const;
};  // class Calendar

#endif  // CALENDAR_H 

