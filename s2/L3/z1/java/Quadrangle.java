public abstract class Quadrangle extends Figure{
    protected double side1, side2, side3, side4;
    protected double angle;
    protected Quadrangle(double a, double b, double c, double d, double angle){
        side1 = a;
        side2 = b;
        side3 = c;
        side4 = d;
        this.angle = angle;
    }
    public double Perm(){
        return side1 + side2 + side3 + side4;
    }
}
