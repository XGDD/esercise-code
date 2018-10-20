class superA{
    int i = 100;
    void fun(){
        System.out.println("This is superA");
    }
}
class subB extends superA{
    int m = 1;
    void fun(){
        System.out.println("This is subB");
    }
}
class subC extends superA{
    int n = 1;
    void fun(){
        System.out.println("This is subC");
    }
}
class Test{
    public static void main(String[] args){
        superA a;
        subB b = new subB();
        subC c = new subC();
        a = b;
        a.fun();
        a = c;
        a.fun();
    }
}