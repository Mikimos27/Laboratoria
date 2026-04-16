public class Diamond extends Quadrangle{
    public Diamond(double side, double angle){
        super(side, side, side, side, angle);
    }
    public double Area(){
        return Math.sin(Math.toRadians(angle)) * side1 * side1;
    }
    public String Name(){
        return "Diamond";
    }
}
