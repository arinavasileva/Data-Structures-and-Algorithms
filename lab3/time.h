#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int hour = 0, int min = 0);

    // Member function to read time from the keyboard
    void read(const std::string &prompt);

    // Member function to compare two times
    bool lessThan(const Time &other) const;

    // Member function to subtract two times
    Time subtract(const Time &other) const;

    // Member function to display time in the format hh:mm
    void display() const;

    // Overloaded input stream operator
    friend std::istream &operator>>(std::istream &in, Time &time);

    // Overloaded equality operator
    bool operator==(const Time &other) const;
};

#endif // TIME_H
