import java.util.*;

class NoMatchException extends Exception {
    public NoMatchException(String message) {
        super(message);
    }
}

public class p14 {
    public static void checkString(String str) throws NoMatchException {
        if (!str.equalsIgnoreCase("India")) {
            throw new NoMatchException("The string does not match 'India'.");
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        try {
            checkString(input);
            System.out.println("The string matches 'India'.");
        } catch (NoMatchException e) {
            System.out.println(e.getMessage());
        }

        sc.close();
    }
}
