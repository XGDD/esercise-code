interface InterA{
    void fun();
}
class B implements InterA{
    public void fun(){
        System.out.println("This is B");
    }
}
class C implements InterA{
    public void fun(){
        System.out.println("This is C");
    }
}
class Test{
    public static void main(String[] args){
        InterA a;
        a = new B();
        a.fun();
        a = new C();
        a.fun();
    }
}
