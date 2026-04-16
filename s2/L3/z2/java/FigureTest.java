import java.util.*;

public class FigureTest{
    public static void yell(String msg){
        System.out.println(msg);
    }
    public static boolean eq(double a, double b){
        return Math.abs(a - b) < 1e-6;
    }
    private static class Shape{
        Shape(String name, double area, double perim){
            this.name = name;
            this.area = area;
            this.perim = perim;
        }
        String name;
        double area, perim;
    }

    public static void main(String[] args){
        if(args.length < 1){
            yell("Za mało argumentów");
            return;
        }

        yell("Zrobić walidację danych:13");

        List<Shape> list = new ArrayList<>();
        int count = 0;
        for(String v : args){
            count++;
            String[] arr = v.split(" ");
            switch(arr[0]){
                case "q":
                if(arr.length == 3){
                    double s1, angle;
                    try{
                        s1 = Double.parseDouble(arr[1]);
                        angle = Double.parseDouble(arr[2]);
                        if(s1 < 0 || angle < 0){
                            yell("Tylko nienegatywne dane : " + String.valueOf(count));
                            continue;
                        }
                        if(eq(angle, 90.0)){
                            Figure.OP f = Figure.OP.SQUARE;
                            list.add(new Shape(f.getName(), f.cArea(s1), f.cPerm(s1)));
                        }
                        else {
                            Figure.TP f = Figure.TP.DIAMOND;
                            list.add(new Shape(f.getName(), f.cArea(s1, angle), f.cPerm(s1, angle)));
                        }
                    }
                    catch(Exception e){
                        yell("Parse error : " + String.valueOf(count));
                        continue;
                    }
                }
                else if(arr.length == 6){
                    double s1, s2, s3, s4, angle;
                    try{
                        s1 = Double.parseDouble(arr[1]);
                        s2 = Double.parseDouble(arr[2]);
                        s3 = Double.parseDouble(arr[3]);
                        s4 = Double.parseDouble(arr[4]);
                        angle = Double.parseDouble(arr[5]);

                        if(s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0 || angle < 0){
                            yell("Tylko nienegatywne dane : " + String.valueOf(count));
                            continue;
                        }

                        if(eq(angle, 90.0)){
                            if(s1 == s3 && s2 == s4){
                                if(s1 == s2){
                                    Figure.OP f = Figure.OP.SQUARE;
                                    list.add(new Shape(f.getName(), f.cArea(s1), f.cPerm(s1)));
                                }
                                else {
                                    Figure.TP f = Figure.TP.RECTANGLE;
                                    list.add(new Shape(f.getName(), f.cArea(s1, s2), f.cPerm(s1, s2)));
                                }
                            }
                            else {
                                yell("Nieobsługiwana figura");
                                continue;
                            }
                        }
                        else if(s1 == s2 && s2 == s3 && s3 == s4){
                            Figure.TP f = Figure.TP.DIAMOND;
                            list.add(new Shape(f.getName(), f.cArea(s1, angle), f.cPerm(s1, angle)));
                        }
                        else {
                            yell("Nieobsługiwana figura");
                            continue;
                        }
                    }
                    catch(Exception e){
                        yell("Parse error : " + String.valueOf(count));
                        continue;
                    }
                }
                else{
                    yell("Zła liczba argumentów : " + String.valueOf(count));
                    continue;
                }
                break;

                case "c":
                if(arr.length != 2){
                    yell("Zła liczba argumentów : " + String.valueOf(count));
                    continue;
                }
                double rad;
                try{
                    rad = Double.parseDouble(arr[1]);
                    if(rad < 0){
                        yell("Tylko nienegatywne dane : " + String.valueOf(count));
                        continue;
                    }
                    Figure.OP f = Figure.OP.CIRCLE;
                    list.add(new Shape(f.getName(), f.cArea(rad), f.cPerm(rad)));
                }
                catch(Exception e){
                    yell("Parse error : " + String.valueOf(count));
                    continue;
                }
                break;
                case "p":
                if(arr.length != 2){
                    yell("Zła liczba argumentów : " + String.valueOf(count));
                    continue;
                }
                try{
                    rad = Double.parseDouble(arr[1]);
                    if(rad < 0){
                        yell("Tylko nienegatywne dane : " + String.valueOf(count));
                        continue;
                    }
                    Figure.OP f = Figure.OP.PENTAGON;
                    list.add(new Shape(f.getName(), f.cArea(rad), f.cPerm(rad)));
                }
                catch(Exception e){
                    yell("Parse error : " + String.valueOf(count));
                    continue;
                }
                break;
                case "h":
                if(arr.length != 2){
                    yell("Zła liczba argumentów : " + String.valueOf(count));
                    continue;
                }
                try{
                    rad = Double.parseDouble(arr[1]);
                    if(rad < 0){
                        yell("Tylko nienegatywne dane : " + String.valueOf(count));
                        continue;
                    }
                    Figure.OP f = Figure.OP.HEXAGON;
                    list.add(new Shape(f.getName(), f.cArea(rad), f.cPerm(rad)));
                }
                catch(Exception e){
                    yell("Parse error : " + String.valueOf(count));
                    continue;
                }
                break;
                default:
                yell("Figura nie jest obsługowana");
                break;
            }

        }
        for(Shape f : list){
            System.out.println("");
            System.out.println(f.name);
            System.out.println(f.area);
            System.out.println(f.perim);

        }
    }
}
