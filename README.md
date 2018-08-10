# Appointment Calendar Program
This calendar program searches for user's appointments based on date or subject while also indicating
appointments that are happening at the same time and place on multiple days.

### CSV File
Users can provide an optional CSV file as a command line argument to provide information about appointments.

CSV file must follow this format: `Date,Class,Subject,Start Time,End Time,Location,Series,Count`\
Example: `8/21/2012,1,Math,10:10:00 AM,12:50:00 PM,Olson Hall,MWF,10`

If your appointment happens at the same time and place on multiple days, you can utilize `Series` and `Count`.\
In the example above, the appointment `Math` happens `10=Count` times on Monday, Wednesday, and Friday (`M,W,F=Series`) sequentially. 

If `Series` and `Count` are used for an appointment, `Class` must be set to 1, else 0.

`Series` and `Count` are optional.

### How to Run
1. `make`
2. `./calendar.out <CSV file>`

`appts.csv` file is provided as an example.

### Demo
