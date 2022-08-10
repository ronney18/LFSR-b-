/*
 * Name: Ronney Sanchez
 * Date: October4
 * Course: COMP2040 Computing IV
 * Assignment: PS2b
 * Email: Ronney_Sanchez@student.uml.edu
 */
// Copyright 2018 Ronney Sanchez
#ifndef LFSR_INCLUDED
#define LFSR_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class LFSR {
 public:
        LFSR(string seed, int t);
        int step();
        int generate(int k);
        friend ostream& operator<<(ostream &os, const LFSR &ws);

 private:
        string seed;
        int tap;
};

#endif
