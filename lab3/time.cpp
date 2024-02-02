#include "time.h"

Time::Time(int hour, int min) : hours(hour), minutes(min) {}

void Time::read(const std::string &prompt) {
    std::cout << prompt << " (hh:mm): ";
    std::cin >> hours >> minutes;
}

bool Time::lessThan(const Time &other) const {
    return hours < other.hours || (hours == other.hours && minutes < other.minutes);
}

Time Time::subtract(const Time &other) const {
    Time result;
    int thisInMinutes = hours * 60 + minutes;
    int otherInMinutes = other.hours * 60 + other.minutes;

    int difference = thisInMinutes - otherInMinutes;

    result.hours = difference / 60;
    result.minutes = difference % 60;

    return result;
}

void Time::display() const {
    std::cout << std::setw(2) << std::setfill('0') << hours << ":"
              << std::setw(2) << std::setfill('0') << minutes;
}

std::istream &operator>>(std::istream &in, Time &time) {
    in >> time.hours >> time.minutes;
    return in;
}

bool Time::operator==(const Time &other) const {
    return hours == other.hours && minutes == other.minutes;
}
