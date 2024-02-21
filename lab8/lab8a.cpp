#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

// Time class definition (assuming the previous implementation of Time class)
class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    friend std::istream& operator>>(std::istream& in, Time& t) {
        in >> t.hours >> t.minutes;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& t) {
        out << std::setfill('0') << std::setw(2) << t.hours << ":" << std::setw(2) << t.minutes;
        return out;
    }

    bool operator<(const Time& other) const {
        if (hours == other.hours) {
            return minutes < other.minutes;
        }
        return hours < other.hours;
    }

    Time operator-(const Time& other) const {
        int total_minutes = (hours - other.hours) * 60 + (minutes - other.minutes);
        int hours_diff = total_minutes / 60;
        int minutes_diff = total_minutes % 60;
        return Time(hours_diff, minutes_diff);
    }
};

int main() {
    std::vector<Time> times;
    std::cout << "Enter times (terminate with 0 0): ";
    Time t;
    while (std::cin >> t && !(t == Time(0, 0))) {
        times.push_back(t);
    }

    // Sort times
    std::sort(times.begin(), times.end());

    // Print sorted times
    std::cout << "Sorted times:\n";
    for (const auto& time : times) {
        std::cout << time << std::endl;
    }

    // Calculate and print time differences
    std::cout << "Time differences:\n";
    std::vector<Time> differences;
    std::adjacent_difference(times.begin(), times.end(), std::back_inserter(differences));
    for (size_t i = 1; i < differences.size(); ++i) {
        std::cout << differences[i] << std::endl;
    }

    return 0;
}

