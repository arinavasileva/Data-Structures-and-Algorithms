#include <iostream>
#include "time.h"
#include "list.h"

using namespace std;

// defining and implementing class Time

class Time {
private:
    int hours;
    int minutes;

public:
    // 1. Member function to read time from the keyboard
    void read(const std::string& prompt) {
        std::cout << prompt << " (hh:mm): ";
        std::cin >> hours >> minutes;
    }

    // 2. Member function to compare two times
    bool lessThan(const Time& other) const {
        if (hours < other.hours || (hours == other.hours && minutes < other.minutes)) {
            return true;
        }
        return false;
    }

    // 3. Member function to subtract two times
    Time subtract(const Time& other) const {
        Time result;
        int thisInMinutes = hours * 60 + minutes;
        int otherInMinutes = other.hours * 60 + other.minutes;

        int difference = thisInMinutes - otherInMinutes;

        result.hours = difference / 60;
        result.minutes = difference % 60;

        return result;
    }

    // 4. Member function to display time in the format hh:mm
    void display() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes;
    }
};

// Application
int main() {
    List<Time> list;
    Time item;
    int i = 0;

    cout << "Enter items? ";
    cin >> item;
    while (!(item == Time(0, 0))) {
        list.insert_to_begin(item);
        cin >> item;
    }

    // Print the contents of the list
    for (i = 1; i <= list.size(); i++) {
        cout << "\n " << i << "th item was ";
        list[i - 1].display();
    }

    cout << "\nDelete list items ?";
    cin >> item;
    while (!(item == Time(0, 0))) {
        if (list.find_pos(item, &i)) {
            cout << "\nThe position of the item in the list is " << i;
            list.del(i);
        } else
            cout << "\nItem not found";
        cin >> item;
    }

    // Print the contents of the list
    for (i = 1; i <= list.size(); i++) {
        cout << "\n " << i << "th item was ";
        list[i - 1].display();
    }

    cout << endl;

    return 0;
}
