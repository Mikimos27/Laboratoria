public class Figure{
    public interface oneparam{
        double cArea(double r);
        double cPerm(double r);
        String getName();

    }
    public interface twoparam{
        double cArea(double a, double b);
        double cPerm(double a, double b);
        String getName();
    }

    public enum OP implements oneparam{
        CIRCLE("Circle"){
            public double cArea(double r){ return Math.PI * r * r; };
            public double cPerm(double r){ return Math.PI * 2 * r; };
        },
        SQUARE("Square"){
            public double cArea(double r){ return r * r; };
            public double cPerm(double r){ return 4 * r; };
        },
        PENTAGON("Pentagon"){
            public double cArea(double r){ return 5 / 4 * r * r / Math.tan(Math.PI / 5); };
            public double cPerm(double r){ return 5 * r; };
        },
        HEXAGON("Hexagon"){
            public double cArea(double r){ return 3 * Math.sqrt(3) * r * r / 2; };
            public double cPerm(double r){ return 6 * r; };
        };
        private final String name;
        OP(String name) { this.name = name; }
        public String getName() { return name; }

    }
    public enum TP implements twoparam{
        RECTANGLE("Rectangle") {
            public double cArea(double a, double b) { return a * b; }
            public double cPerm(double a, double b) { return 2.0 * (a + b); }
        },
        DIAMOND("Diamond") { 
            public double cArea(double a, double angle) {
                return a * a * Math.sin(Math.toRadians(angle));
            }
            public double cPerm(double a, double angle) { return 4.0 * a; }
        };

        private final String name;
        TP(String name) { this.name = name; }
        public String getName() { return name; }
    }
}
