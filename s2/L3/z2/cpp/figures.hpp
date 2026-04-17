#ifndef FIGURES_H
#define FIGURES_H

#include <cmath>

class figure{
public:
    enum class OPE { CIRCLE, SQUARE, PENTAGON, HEXAGON };
    enum class TPE { RECTANGLE, DIAMOND };

    class oneparamI{
    public:
        double area(OPE en, double x);
        double perm(OPE en, double x);
        const char* name(OPE en);
    };
    class twoparamI{
    public:
        double area(TPE en, double x, double y);
        double perm(TPE en, double x, double y);
        const char* name(TPE en);
    };

    class OP: oneparamI{
    public:
        double area(OPE en, double x){
            switch(en){
                case OPE::CIRCLE:
                return M_PI * x * x;
                case OPE::SQUARE:
                return x * x;
                case OPE::PENTAGON:
                return 5 / 4 * x * x / std::tan(M_PI / 5);
                case OPE::HEXAGON:
                return 3 * std::sqrt(3) * x * x / 2;
                default:
                return -1;
            }
        }
        double perm(OPE en, double x){
            switch(en){
                case OPE::CIRCLE:
                return M_PI * 2 * x;
                case OPE::SQUARE:
                return 4 * x;
                case OPE::PENTAGON:
                return 5 * x;
                case OPE::HEXAGON:
                return 6 * x;
                default:
                return -1;
            }
        }
        const char* name(OPE en){
            switch(en){
                case OPE::CIRCLE:
                return "Circle";
                case OPE::SQUARE:
                return "Square";
                case OPE::PENTAGON:
                return "Pentagon";
                case OPE::HEXAGON:
                return "Hexagon";
                default:
                return "";
            }
        }
    };

    class TP: twoparamI{
    public:
        double area(TPE en, double x, double y){
            switch(en){
                case TPE::RECTANGLE:
                return x * y;
                case TPE::DIAMOND:
                return x * x * std::sin(y * M_PI / 180);
                default:
                return -1;
            }
        }
        double perm(TPE en, double x, double y){
            switch(en){
                case TPE::RECTANGLE:
                return 2 * (x + y);
                case TPE::DIAMOND:
                return 4 * x;
                default:
                return -1;
            }
        }
        const char* name(TPE en){
            switch(en){
                case TPE::RECTANGLE:
                return "Rectangle";
                case TPE::DIAMOND:
                return "Diamond";
                default:
                return "";
            }
        }
    };
};
#endif
