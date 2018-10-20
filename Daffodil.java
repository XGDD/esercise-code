class A{
    private int a = 0;
    private int b = 0;
    private int c = 0;
    public int fun(int num){
        a = num / 100;
        b = (num - a * 100) / 10;
        c = num - a*100 - b*10;
        if(num == a*a*a + b*b*b + c*c*c){
            return num;
        }else{
            return 0;
        }
    }
}
public class Daffodil{
    public static void main(String[] args){
        A a = new A();
        for(int i = 100; i < 1000; i++){
            if(a.fun(i) != 0){
                System.out.println(a.fun(i));
            }
        }
    }
}