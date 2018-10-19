class A{
    public void GetVal(){
        System.out.println("Parent");
    }
}
class B extends A{
    public void GetVal(){
        System.out.println("Child");
    }
}
public class OverrrideExample{
    public static void main(String[] args){
        B b = new B();
        A a = (A)b;
        a.GetVal();
    }
}