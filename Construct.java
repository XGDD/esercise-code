class Person{
    private int age;
    public Person(){
        System.out.println("Hello Constructor");
    }
    public Person(String s){
        System.out.println("Hello Constructor "+s);
    }
    public void setAge(int num){
        age = num;
    }
    public int getAge(){
        return age;
    }
    public void getPersonInfo(){
        System.out.println("年龄："+age);
    }
}
public class Construct{
    public static void main(String[] args){
        Person p = new Person("张三");
        p.setAge(20);
        p.getPersonInfo();
    }
}