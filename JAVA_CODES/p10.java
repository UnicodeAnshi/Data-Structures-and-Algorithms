import java.util.*;
public class p10 { 
    public double area(double length, double width) {
        return length * width;
    }
    public double area(double base, double height, boolean isTriangle) {
        if (isTriangle) {
            return 0.5 * base * height;
        }
        return -1;
    }
    public double area(double radius) {
        return Math.PI * radius * radius;
    }

    public static void main(String[] args) {
        p10 shape = new p10();

        double rectangleArea = shape.area(18, 5);
        System.out.println("Area of the rectangle: " + rectangleArea);

        double triangleArea = shape.area(20, 5, true);
        System.out.println("Area of the triangle: " + triangleArea);

        double circleArea = shape.area(14);
        System.out.println("Area of the circle: " + circleArea);
    }
}
