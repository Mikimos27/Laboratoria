#include "figures.hpp"
#include <cmath>

quadrangle::quadrangle(double a, double b, double c, double d, double ang){
    side1 = a;
    side2 = b;
    side3 = c;
    side4 = d;
    angle = ang;
}
double quadrangle::perm(){
    return side1 + side2 + side3 + side4;
}

square::square(double side)
    : quadrangle(side, side, side, side, 90.0) {}
double square::area() { return side1 * side1; };
const char* square::name() { return "Square"; }

rectangle::rectangle(double side1, double side2)
    : quadrangle(side1, side2, side1, side2, 90.0) {}
double rectangle::area() { return side1 * side2; }
const char* rectangle::name() { return "Rectangle"; }

diamond::diamond(double side, double angle)
    : quadrangle(side, side, side, side, angle) {}
double diamond::area() { return std::sin(angle * M_PI / 180) * side1 * side1; }
const char* diamond::name() { return "Diamond"; }

circle::circle(double radius)
    : radius(radius) {}
double circle::area() { return M_PI * radius * radius; }
double circle::perm() { return M_PI * 2 * radius; }
const char* circle::name() { return "Circle"; }

pentagon::pentagon(double side)
    : side(side) {}
double pentagon::area() { return 5 / 4 * side * side / std::tan(M_PI / 5); } 
double pentagon::perm() { return 5 * side; }
const char* pentagon::name() { return "Pentagon"; }

hexagon::hexagon(double side)
    : side(side) {}
double hexagon::area() { return 3 * std::sqrt(3) * side * side / 2; }
double hexagon::perm() { return 6 * side; };
const char* hexagon::name() { return "Hexagon"; }
