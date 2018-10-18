public class ThisExample{
    private String name;
    private int age;
    ThisExample(String name, int age){
        this.setName(name);
        this.setAge(age);
        this.print();
    }
    public void setName(String name){
        this.name = name;
    }
    public void setAge(int age){
        this.age = age;
    }
    public void print(){
        System.out.println("Name="+name+" ge="+age);
    }
    public static void main(String[] args){
        ThisExample dt = new ThisExample("Kevin",22);
    }
}