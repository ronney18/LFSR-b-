/*
 * Name: Ronney Sanchez
 * Date: October26
 * Course: COMP2040 Computing IV
 * Assignment: PS2b
 * Email: Ronney_Sanchez@student.uml.edu
 */
// Copyright 2018 Ronney Sanchez

#include "LFSR.hpp"

LFSR::LFSR(string seed, int t) {
    for (unsigned int i = 0; i < seed.length(); i++) {
        while (seed.length() > 32) {
            cout << "Binary numbers could only go up to 32 bits long!" << endl;
            cout << "Enter a binary number: ";
            cin >> seed;
        }
        while (seed.at(i) != '0' && seed.at(i) != '1') {
            cout << "We are dealing only with binary numbers!" << endl;
            cout << "Enter a binary number: ";
            cin >> seed;
        }
    }
    this->seed = seed;
    this->tap = t;
}

int LFSR::step() {
    int target = seed.length() - tap - 1;
    char leftMostBit = seed.at(0);
    int bit = 0;

    if (seed.at(target) == leftMostBit) {
        bit = 0;
    } else {
        bit = 1;
    }
    char bitChar = '0';

    if (bit == 0) {
        bitChar = '0';
    } else {
        bitChar = '1';
    }
    seed.erase(seed.begin());
    seed.push_back(bitChar);
    return bit;
}

int LFSR::generate(int k) {
    int result = 0;
    for (int i = 0; i < k; i++) {
        int bitValue = step();
        result = (result * 2) + bitValue;
    }
    return result;
}

ostream& operator << (ostream &os, const LFSR &wr) {
    os << wr.seed;
    return os;
}
