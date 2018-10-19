class subClass{
    static int classPar;
    int instancePar;
    static void setclassPar(int i){
        classPar = i;
    }
    void setinstancePar(int i){
        instancePar = i;
    }
    static int getclassPar(){
        return classPar;
    }
    int getinstancePar(){
        return instancePar;
    }
}
public class ClassExample{
    public static void main(String[] args){
        subClass obj1,obj2;
        obj1 = new subClass();
        obj2 = new subClass();
        obj1.setclassPar(5);
        obj2.setclassPar(7);
        obj1.setinstancePar(3);
        obj2.setinstancePar(6);
        System.out.println("obj1.classPar: "+obj1.getclassPar());
        System.out.println("obj2.classPar: "+obj2.getclassPar());
        System.out.println("obj1.instancePar: "+obj1.getinstancePar());
        System.out.println("obj2.instancePar: "+obj2.getinstancePar());
    }
}