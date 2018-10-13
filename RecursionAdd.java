public class RecursionAdd{
    long Add(int num){
        if(num == 1)
            return 1;
        else
            return num * Add(num - 1);
    }
    public static void main(String[] args){
        RecursionAdd p = new RecursionAdd();
        System.out.println(p.Add(20));
    }
}
