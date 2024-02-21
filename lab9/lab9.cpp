#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map> // Add this for std::map

std::vector<std::string> split(const std::string& s) {
    std::istringstream iss(s);
    return {std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}}; // Fix the syntax
}

int main() {
    std::cout << "Phonebook Application\n";
    std::cout << "add <name> <number>: Add a new entry to the phonebook with the specified name and number.\n";
    std::cout << "erase <name>: Remove the entry with the specified name from the phonebook.\n";
    std::cout << "list: List all entries in the phonebook.\n";
    std::cout << "exit: Exit the program.\n";
    
    std::map<std::string, std::string> phonebook;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::vector<std::string> words = split(line);

        if (words.empty())
            continue;

        std::string command = words[0];
        if (command == "add") {
            if (words.size() >= 4) {
                std::string name = words[1] + " " + words[2];
                std::string number = words[3];
                phonebook[name] = number;
            } else {
                std::cout << "Invalid input for 'add' command\n";
            }
        } else if (command == "erase") {
            if (words.size() >= 2) {
                std::string name = words[1];
                auto it = phonebook.find(name);
                if (it != phonebook.end()) {
                    phonebook.erase(it);
                } else {
                    std::cout << "Name " << name << " not found\n";
                }
            } else {
                std::cout << "Invalid input for 'erase' command\n";
            }
        } else if (command == "list") {
            std::cout << "Content of the phone book:\n";
            for (const auto& entry : phonebook) {
                std::cout << entry.first << ": " << entry.second << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unrecognized command " << command << std::endl;
        }
    }

    return 0;
}
