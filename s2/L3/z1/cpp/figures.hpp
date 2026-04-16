#ifndef FIGURES_H
#define FIGURES_H


class figure{
public:
    virtual double area() = 0;
    virtual double perm() = 0;
    virtual const char* name() = 0;
};

class quadrangle : public figure{
protected:
    double side1, side2, side3, side4, angle;
public:
    quadrangle(double a, double b, double c, double d, double ang);
    double perm() override;
};

class square : public quadrangle{
public:
    square(double side);
    double area() override;
    const char* name() override;
};

class rectangle : public quadrangle{
public:
    rectangle(double side1, double side2);
    double area() override;
    const char* name() override;
};

class diamond : public quadrangle{
public:
    diamond(double side, double angle);
    double area() override;
    const char* name() override;
};

class circle : public figure{
private:
    double radius;
public:
    circle(double radius);
    double area() override;
    double perm() override;
    const char* name() override;
};

class pentagon : public figure{
private:
    double side;
public:
    pentagon(double side);
    double area() override;
    double perm() override;
    const char* name() override;
};

class hexagon : public figure{
private:
    double side;
public:
    hexagon(double side);
    double area() override;
    double perm() override;
    const char* name() override;
};
#endif
