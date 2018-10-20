public class OverloadExample{
    int add(int a, int b){
        return (a + b);
    }
    double add(double a, double b){
        return (a + b);
    }
    double add(double a, double b, double c){
        return (a + b +c);
    }
    public static void main(String[] args){
        int a;
        double b, c;
        OverloadExample p = new OverloadExample();
        a = p.add(1, 2);
        b = p.add(1, 2);
        c = p.add(1, 2, 3);
        System.out.println("a="+a);
        System.out.println("b="+b);
        System.out.println("c="+c);
    }
}