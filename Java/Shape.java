package JavaBasic;

public abstract class Shape{
    abstract void draw();
    void message(){
        System.out.println("Shape");
    }
}

class Circle extends Shape{
    void draw(){
        System.out.println("Circle drown");
    }

}

class Cone extends Shape{
    void draw(){
        System.out.println("Cone drown");
    }
}

public class runShape{
    public static void main(String[] args){
        Circle circle = new Circle();
        Cone cone = new Cone();
        circle.draw();
        cone.draw();
        cone.message();
    }
}
