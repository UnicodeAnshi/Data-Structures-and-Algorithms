import java.util.*;

public class p9 {
    private int ID;
    private String Name;
    private String Branch;
    private String City;
    private String University;

    public p9(int ID, String Name, String Branch, String City, String University) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = Branch;
        this.City = City;
        this.University = University;
    }

    public p9(int ID, String Name, String Branch, String City) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = Branch;
        this.City = City;
        this.University = "";ṁ
    }

    public p9(int ID, String Name, String Branch) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = Branch;
        this.City = "";
        this.University = "";
    }

    public p9(int ID, String Name) {
        this.ID = ID;
        this.Name = Name;
        this.Branch = "";
        this.City = "";
        this.University = "";
    }

    public p9(int ID) {
        this.ID = ID;
        this.Name = "";
        this.Branch = "";
        this.City = "";
        this.University = "";
    }
    public void displayDetails() {
        System.out.println("ID: " + ID);
        System.out.println("Name: " + Name);
        System.out.println("Branch: " + Branch);
        System.out.println("City: " + City);
        System.out.println("University: " + University);
    }

    public static void main(String[] args) {
        p9 s1 = new p9(001);
        s1.displayDetails();
        System.out.println();

        p9 s2 = new p9(001, "Anshika");
        s2.displayDetails();
        System.out.println();

        p9 s3 = new p9(001, "Anshika", "CSE");
        s3.displayDetails();
        System.out.println();

        p9 s4 = new p9(001, "Anshika", "CSE", "Dehradun");
        s4.displayDetails();
        System.out.println();

        p9 s5 = new p9(001, "Anshika", "CSE", "Dehradun", "Graphic Era Hill University");
        s5.displayDetails();
    }
}

