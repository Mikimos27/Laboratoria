public class Pentagon extends Figure{
    private double side;
    public Pentagon(double side){
        this.side = side;
    }
    public double Area(){
        return 5 / 4 * side * side / Math.tan(Math.PI / 5);
    }
    public double Perm(){
        return 5 * side;
    }
    public String Name(){
        return "Pentagon";
    }
}
