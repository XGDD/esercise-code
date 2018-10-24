abstract class CaffeineBeverage{
    final void prepareRecipe(){
        boilwater();
        brew();
        pourInCup();
        addCondiments();
    }
    abstract void brew();
    abstract void addCondiments();
    void boilwater(){
        System.out.println("Boiling Water");
    }
    void pourInCup(){
        System.out.println("Pouring into cup");
    }
}
class Tea extends CaffeineBeverage{
    void brew(){
        System.out.println("Steepint the tea");
    }
    void addCondiments(){
        System.out.println("Adding Lemon");
    }
}
class Coffee extends CaffeineBeverage{
    void brew(){
        System.out.println("Dripping Coffee through filter");
    }
    void addCondiments(){
        System.out.println("Adding Sugar and Milk");
    }
}
public class Test{
    public static void main(String[] args){
        CaffeineBeverage coffee = new Coffee();
        coffee.prepareRecipe();
        CaffeineBeverage tea = new Tea();
        tea.prepareRecipe();
    }
}