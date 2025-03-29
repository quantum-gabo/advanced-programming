#include "class.h"
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <cmath>

// Helper function to validate mass
void Particle::validateMass() {
    if (mass <= 0) {
        throw std::invalid_argument("Mass must be positive");
    }
}

// Default constructor
Particle::Particle() : mass(0), position(), velocity() {
    // Initialize with mass = 0 and empty vectors
}

// Parameterized constructor
Particle::Particle(double m, const std::vector<double>& pos, const std::vector<double>& vel) 
    : mass(m), position(pos), velocity(vel) {
    validateMass();
}

// Getter for mass
double Particle::getMass() const {
    return mass;
}

// Getter for kinetic energy
double Particle::getKineticEnergy() const {
    double sumSquaredVelocity = 0.00;
    for (const auto& v : velocity) {
        sumSquaredVelocity += v * v;
    }
    return 0.5 * mass * sumSquaredVelocity;
}

// Setter for mass
void Particle::setMass(double m) {
    mass = m;
    validateMass();
}

// Setter for position
void Particle::setPosition(const std::vector<double>& pos) {
    position = pos;
}

// Setter for velocity
void Particle::setVelocity(const std::vector<double>& vel) {
    velocity = vel;
}

