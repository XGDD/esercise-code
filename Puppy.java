public class Puppy{
    public int puppyAge;
    public Puppy(String name){
        System.out.println("dog's name is:"+ name);
    }
    public void setAge(int age){
        puppyAge = age;
    }
    public int getAge(){
        System.out.println("dog's age is:"+ puppyAge);
        return puppyAge;
    }
    public static void main(String[] args){
        Puppy myPuppy=new Puppy("tommy");
        myPuppy.setAge(2);
        myPuppy.getAge();
        System.out.println("变量值："+ myPuppy.puppyAge);
    }
}