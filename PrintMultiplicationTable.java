public class PrintMultiplicationTable{
    public static void main(String[] args){
        int i = 1;
        int j = 1;
        while(j < 10){
        for(i = 1; i <= j; i++){
            int ret = i * j;
            System.out.print(i + "*" + j + "=" + ret + "     ");
        }
        System.out.println();
        j++;
      }
    }
}