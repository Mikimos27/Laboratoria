import java.util.*;

public class FigureTest{
    public static void yell(String msg){
        System.out.println(msg);
    }
    public static boolean eq(double a, double b){
        return Math.abs(a - b) < 1e-6;
    }
    public static void main(String[] args){
        if(args.length < 1){
            yell("Za mało argumentów");
            return;
        }

        yell("Zrobić walidację danych:13");

        List<Figure> list = new ArrayList<>();
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
                        if(eq(angle, 90.0)) list.add(new Square(s1));
                        else list.add(new Diamond(s1, angle));
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
                                if(s1 == s2) list.add(new Square(s1));
                                else list.add(new Rectangle(s1, s2));
                            }
                            else {
                                yell("Nieobsługiwana figura");
                                continue;
                            }
                        }
                        else if(s1 == s2 && s2 == s3 && s3 == s4){
                            list.add(new Diamond(s1, angle));
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
                    list.add(new Circle(rad));
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
                    list.add(new Pentagon(rad));
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
                    list.add(new Hexagon(rad));
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
        for(Figure f : list){
            System.out.println("");
            System.out.println(f.Name());
            System.out.println(f.Area());
            System.out.println(f.Perm());

        }
    }
}
