class Outer{
    private String msg = "Hello World";
    //--------------------------------
    class Inner{
        public void print(){
            System.out.println(msg);
        }
    }
    public void fun(){
        Inner in = new Inner();
        in.print();
    }
}
public class InnerClass{
    public static void main(String[] args){
        Outer out = new Outer();
        out.fun();
    }
}