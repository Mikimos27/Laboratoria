public class Square extends Quadrangle{
    public Square(double side){
        super(side, side, side, side, 90f);
    }
    public double Area(){
        return side1 * side1;
    }
    public String Name(){
        return "Square";
    }
}
