public class Rectangle extends Quadrangle{
    public Rectangle(double a, double b){
        super(a, b, a, b, 90f);
    }
    public double Area(){
        return side1 * side2;
    }
    public String Name(){
        return "Rectangle";
    }
}
