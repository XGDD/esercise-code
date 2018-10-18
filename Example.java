class car{
    public String Name;
    public char Color;
    protected int Stytle;
    public String getName(){
        return Name;
    }
    public char getColor(){
        return Color;
    }
    public int getStyle(){
        return Stytle;
    }
}

public class Example{
    public static void main(String[] args){
        car car1 = new car();
        car car2 = new car();
        car1.Name = "car1";
        car1.Color = 'R';
        car1.Stytle = 1;
        car2.Name = "car2";
        car2.Color = 'B';
        car2.Stytle = 2;
        System.out.println("Color of car1: "+car1.getColor());
        System.out.println("Color of car1: "+car2.getColor());
    }
}