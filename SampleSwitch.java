public class SampleSwitch{
    public static void main(String[] args){
        for(int i = 0; i < 6; i++)
            switch(i){
                case 0:
                System.out.print("i is zero.");
                break;
                case 1:
                System.out.print("i is one.");
                break;
                case 2:
                System.out.print("i is two.");
                break;
                case 3:
                System.out.print("i is three.");
                break;
                default:
                System.out.print("i is greater than 3.");
            }
    }
}