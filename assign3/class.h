#ifndef CLASS_H
#define CLASS_H

#include <vector>

class Particle {
private:
    double mass;
    std::vector<double> position;
    std::vector<double> velocity;

    void validateMass();  // Declare the function but define it in the .cpp file

public:
    // Default constructor
    Particle();

    // Constructor with parameters
    Particle(double m, const std::vector<double>& pos, const std::vector<double>& vel);

    // Getter functions
    double getMass() const;
    double getKineticEnergy() const;

    // Setter functions
    void setMass(double m);
    void setPosition(const std::vector<double>& pos);
    void setVelocity(const std::vector<double>& vel);
};

#endif // CLASS_H

