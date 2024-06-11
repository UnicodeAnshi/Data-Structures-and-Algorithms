abstract class Shape {
    String color;

    abstract double area();

    public void setColor(String color) {
        this.color = color;
    }

    public String getColor() {
        return color;
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    double width, height;

    Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    double area() {
        return width * height;
    }
}

public class p17 {
    public static void main(String[] args) {
        Circle circle = new Circle(5.0);
        circle.setColor("Red");
        System.out.println("Circle:");
        System.out.println("Color: " + circle.getColor());
        System.out.println("Area: " + circle.area());

        Rectangle rectangle = new Rectangle(4.0, 6.0);
        rectangle.setColor("Blue");
        System.out.println("Rectangle:");
        System.out.println("Color: " + rectangle.getColor());
        System.out.println("Area: " + rectangle.area());
    }
}
