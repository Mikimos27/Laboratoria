public class Circle extends Figure{
    private double radius;
    public Circle(double radius){
        this.radius = radius;
    }
    public double Area(){
        return Math.PI * radius * radius;
    }
    public double Perm(){
        return Math.PI * 2 * radius;
    }
    public String Name(){
        return "Circle";
    }
}
