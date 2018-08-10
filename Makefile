calendar.out : appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o
	g++ -g -ansi -Wall -o calendar.out appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o

appt.o : appt.cpp appt.h time.h weeklyappt.h
	g++ -g -ansi -Wall -c appt.cpp

weeklyappt.o : weeklyappt.cpp weeklyappt.h appt.h time.h
	g++ -g -ansi -Wall -c weeklyappt.cpp

calendar.o : calendar.cpp calendar.h day.h vector.h vector.cpp weeklyappt.h appt.h DayOfWeek.h
	g++ -g -ansi -Wall -c calendar.cpp

day.o : day.cpp day.h appt.h DayOfWeek.h linkedlist.cpp linkedlist.h weeklyappt.h
	g++ -g -ansi -Wall -c day.cpp

DayOfWeek.o : DayOfWeek.cpp DayOfWeek.h 
	g++ -g -ansi -Wall -c DayOfWeek.cpp

main.o : main.cpp calendar.h appt.h 
	g++ -g -ansi -Wall -c main.cpp

time.o : time.cpp time.h 
	g++ -g -ansi -Wall -c time.cpp

clean : 
	rm -f calendar.out appt.o  calendar.o  day.o  DayOfWeek.o  main.o  time.o  weeklyappt.o
