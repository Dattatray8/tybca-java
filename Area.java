class Area{
    void calculate(int s){
        System.out.println("The Area of Square is: "+ s*s);
    }
    void calculate(double r){
        System.out.println("The Area of Circle is: "+ 3.14*r*r);
    }
    public static void main(String[] args) {
        Area a = new Area();
        a.calculate(2.4);
        a.calculate(2);
    }
}