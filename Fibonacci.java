public class Fibonacci{
    public static int f(int num){
        if(num == 0){
            return 0;
        }
        if(num == 1 || num == 2){
            return 1;
        }else{
            return f(num -1) + f(num - 2);
        }
    }

    public static void main(String[] args){
        for(int i = 1; i <= 9; i++){
            System.out.print(f(i) + " ");
        }
    }
}