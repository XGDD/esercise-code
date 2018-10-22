class Employe{
    private String name;
    private double salary;
    private int id;
    private static int nextId = 1;
    public Employe(String n, double s){
        name = n;
        salary = s;
        id = 0;
        setId();
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public double getSalary(){
        return salary;
    }
    public void setSalary(double salary){
        this.salary = salary;
    }
    public int getId(){
        return id;
    }
    public void setId(){
        id = nextId;
        nextId++;
    }
    public static int getNextId(){
        return nextId;
    }
    public static void main(String[] args){
        Employe e1 = new Employe("Harry",30000);
        System.out.println(e1.getName()+"\t"+e1.getSalary()+"\t"+e1.id+"\t"+e1.nextId);
        Employe e2 = new Employe("Tom",40000);
        System.out.println(e2.getName()+"\t"+e2.getSalary()+"\t"+e2.id+"\t"+e2.nextId);
        Employe e3 = new Employe("Kidd",500000);
        System.out.println(e3.getName()+"\t"+e3.getSalary()+"\t"+e3.id+"\t"+e3.nextId);
    }
}