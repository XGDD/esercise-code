class A{
    private String name = "A的私有域";
    public String getName(){
        return name;
    }
}
class B{
    private int age = 20;
    public int getAge(){
        return age;
    }
}
class Outter{
    private class InnerClassA extends A{
        public String name(){
            return super.getName();
        }
    }
    private class InnerClassB extends B{
        public int age(){
            return super.getAge();
        }
    }
    public int age(){
        return new InnerClassB().age();
    }
    public String name(){
        return new InnerClassA().name();
    }
}
public class InnerToExtends{
    public static void main(String[] args){
        Outter out = new Outter();
        System.out.println(out.name());
        System.out.println(out.age());
    }
}
