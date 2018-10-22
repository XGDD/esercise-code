abstract class PrintMechine{
    abstract public void print(int x);
}
public class AbstractTest extends PrintMechine{
    int a;
    public AbstractTest(int a){
        this.a = a;
    }
    public void print(int a){
        System.out.println(a * 2);
    }
    public static void main(String[] args){
        PrintMechine p1 = new AbstractTest(3);
        p1.print(3);
    }
}
