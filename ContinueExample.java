public class ContinueExample{
    public static void main(String[] args){
        loop: for(int i = 1; i< 20; i++){
            for(int j = 2; j < i; j++){
                if((i % j) == 0)
                    continue loop;
            }
            System.out.println("i="+i);
        }
    }
}