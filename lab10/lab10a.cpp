#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

// Ordinary function for generating random numbers
int randGen_1() {
    return rand() % 37 + 1; // Generating numbers in the range 1 - 37
}

// Function object for generating random numbers
class RandGen_2 {
public:
    RandGen_2(): numbers() {
        srand(time(NULL));
    }
    int operator()();
private:
    vector<int> numbers;
};

// Overloaded operator for generating random numbers without repetition
int RandGen_2::operator()() {
    int number;
    do {
        number = rand() % 37 + 1; // Generate numbers in the range 1 - 37
    } while(find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

int main(void) {
    vector<int> lottoNumbers1(7); // Vector to store first lotto numbers
    vector<int> lottoNumbers2(7); // Vector to store second lotto numbers

    // Generating first set of lotto numbers
    generate(lottoNumbers1.begin(), lottoNumbers1.end(), randGen_1);

    // Generating second set of lotto numbers
    RandGen_2 randGen_2;
    generate(lottoNumbers2.begin(), lottoNumbers2.end(), randGen_2);

    // Printing first set of lotto numbers using output stream iterator
    cout << "First lotto row: ";
    copy(lottoNumbers1.begin(), lottoNumbers1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Printing second set of lotto numbers using output stream iterator
    cout << "Second lotto row: ";
    copy(lottoNumbers2.begin(), lottoNumbers2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Finding similar numbers using set_intersection
    vector<int> intersection;
    set_intersection(lottoNumbers1.begin(), lottoNumbers1.end(), lottoNumbers2.begin(), lottoNumbers2.end(), back_inserter(intersection));

    // Printing similar numbers using for_each algorithm
    if (!intersection.empty()) {
        cout << "Same numbers:" << endl;
        int count = 1;
        for_each(intersection.begin(), intersection.end(), [&](int num) {
            cout << "#" << count++ << ": " << num << endl;
        });
    } else {
        cout << "No similar numbers found." << endl;
    }

    return 0;
}
