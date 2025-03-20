/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #include <iostream>
#include<vector>
#include "class.h"

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
    std::vector<double> position = {1.0, 2.0};
    std::vector<double> velocity = {3.0, 4.0};
    double mass = 5.0;

    Particle particle(mass, position, velocity);
    std::cout << "Mass: " << particle.getMass() << std::endl;
    std::cout << "Kinetic Energy: " << particle.getKineticEnergy() << std::endl;
    particle.setMass(10.0);
}