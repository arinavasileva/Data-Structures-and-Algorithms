#include "measurement.h"
#include <iostream>
#include <fstream>

Measurements::Measurements() : values(nullptr), size(0) {}

Measurements::~Measurements() {
    delete[] values;
}

Measurements::Measurements(const Measurements& other) : values(nullptr), size(other.size) {
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = other.values[i];
    }
}

Measurements& Measurements::operator=(const Measurements& other) {
    if (this != &other) {
        delete[] values;

        size = other.size;
        values = new double[size];
        for (int i = 0; i < size; ++i) {
            values[i] = other.values[i];
        }
    }
    return *this;
}

bool Measurements::read(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file >> size;
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        file >> values[i];
    }

    file.close();
    return true;
}

void Measurements::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << values[i] << std::endl;
    }
}

double Measurements::mean() {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += values[i];
    }
    return (size > 0) ? sum / size : 0.0;
}

void Measurements::inc(double increment) {
    for (int i = 0; i < size; ++i) {
        values[i] += increment;
    }
}
