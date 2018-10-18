class Person{
    public static void prt(String s){
        System.out.println(s);
    }
    Person(){
        prt("A Person.");
    }
    Person(String name){
        prt("A Person name is: "+name);
    }
}
public class MoreExample extends Person{
    MoreExample(){
        super();
        prt("A chinese.");
    }
    MoreExample(String name){
        super(name);
        prt("his name is: "+name);
    }
    MoreExample(String name,int age){
        this(name);
        prt("his age is: "+age);
    }
    public static void main(String[] args){
        MoreExample cn = new MoreExample();
        cn = new MoreExample("Kevin");
        cn = new MoreExample("Kevin", 22);
    }
}