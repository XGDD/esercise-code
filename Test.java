class Father{
    private String name = "zhangjun";
    class Child{
        void introFather(){
            System.out.println(name);
        }
    }
}
public class Test{
    public static void main(String[] args){
        Father.Child in = new Father().new Child();
        in.introFather();
    }
}