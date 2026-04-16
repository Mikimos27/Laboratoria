public class Hexagon extends Figure{
    private double side;
    public Hexagon(double side){
        this.side = side;
    }
    public double Area(){
        return 3 * Math.sqrt(3) * side * side / 2;
    }
    public double Perm(){
        return 6 * side;
    }
    public String Name(){
        return "Hexagon";
    }
}
