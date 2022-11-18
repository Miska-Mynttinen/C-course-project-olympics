# C-course-project-olympics
Implemented a system that takes in inputs from the user to create and track olympic medals for each country given.
Basic C-project for C-course. 2021 SUMMER.

Uses structures, linked lists and other things learned during the course to function.
Asks user for inputs and prints out the current state of the olympics. Has some unneeded comments of text solutions that didn't funtion properly.

Instructions for the exercise and how it works:

Implement a system that tracks the olympic medals of different nationalities. You can enter different countries to the system, and maintain the medal counts for them. The system should support arbitrarily large number of different nations. The database will consist of names of the nations (strings), and integers that represent gold-, silver- and bronze medals for each nation. For the name of the nation arbitrarily long names should be supported.

The program has the following functions:

A nation: Add nation

Add ”nation” to the database. Initially each nation has no medals. For example: A Finland (1 p).

M nation gold silver bronze : Update medals

Adds the given amount of medals to the given country. For example M Finland 0 1 1 will add one silver and one bronze medal to Finland, in addition to existing medals. If the nation was not yet added using the A - command, an error message will be given. The medal counts are signed integers, and because of possible doping cases also negative adjustments need to be allowed, which means that the total count of the particular medal will be reduced. (1 p)

L : Output medal table

Prints the current medal table, i.e. all nations in the memory along with their medal counts: first gold, then silver, and finally bronze, each nation on a separate line. The nations should be listed in order such as first the nation with most gold medals will be output. In cases where there are equal number of gold medals, the number of silver medals counts. If also the silver counts are equal, the number of bronze medals counts. This command is worth of two points such that if you output all nations and medal counts correctly, but in wrong order, you will get one point. If, in addition, also the order is correct, you will get a second point. (max. 2 p)

W filename : Save table

Writes the medal table to a file with given filename. (1 p)


(DIDN't FINISH/DOESN'T WORK Load table
O filename : Load table

Loads the medal table from file, and replaces the existing table in memory. (1 p) )


Q : Exit program

Exits program and releases all allocated memory. This operation must be implemented so that you can find all possible memory leaks.

In addition to the above commands, there should be a working main function that repeatedly asks commands from user and acts accordingly.

The commands start with one captial letter and may be followed by some number of parameters, separated by space, depending on the command. Below is an example of possible input sequence:

A China
A Finland
M China 2 1 1
M Finland 0 0 1
M China 1 3 1
M China -1 0 0
L
W medals
Q
After this, China has 2 gold medals, 4 silver, and 2 bronze, but Finland has only one bronze. When the table is printed, China should be shown before Finland. The table will be written to file ”medals”.
