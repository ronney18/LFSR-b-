/*
 * Name: Ronney Sanchez
 * Date: October26
 * Course: COMP2040 Computing IV
 * Assignment: PS2b
 * Email: Ronney_Sanchez@student.uml.edu
 */
// Copyright 2018 Ronney Sanchez
//
#include "LFSR.hpp"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        cout << "PhotoMagic executable file [image source-file] [image encrypted-file] [seed bit string] [tap position]" << endl;
        return -1;
    }
    string inputFile = argv[1];
    string outputFile = argv[2];
    string seed = argv[3];
    int tap = atoi(argv[4]);

    // LFSR object pointer
    LFSR *binaryString = new LFSR(seed, tap);

    sf::Image image;
    if (!image.loadFromFile(inputFile)) {
        cout << "ERROR: The file " << inputFile << " does not exist!" << endl;
        return -1;
    }

    sf::Texture texture1;
    texture1.loadFromImage(image);

    // p is a pixel
    sf::Color p;
    sf::Vector2u size = image.getSize();

    for (unsigned int x = 0; x <size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            p = image.getPixel(x, y);
            p.r = p.r ^ binaryString->generate(90);
            p.g = p.g ^ binaryString->generate(70);
            p.b = p.b ^ binaryString->generate(150);
            image.setPixel(x, y, p);
         }
    }
    delete binaryString;

    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input-Image");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output-Image");
    sf::Texture texture2;
    texture2.loadFromImage(image);

    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window1.close();
            }
        }

        while (window2.pollEvent(event)) {
             if (event.type == sf::Event::Closed) {
                  window2.close();
             }
         }

         window1.clear();
         window1.draw(sprite1);
         window1.display();

         window2.clear();
         window2.draw(sprite2);
         window2.display();
    }

    if (!image.saveToFile(outputFile)) {
        cout << "ERROR: Cannot write to output file!" << endl;
        return -1;
    }
}
