import java.util.*;
public class BankAccount{
    private String depositorName;
    private String accountType;
    private String accountNo;
    private double balance;

    BankAccount(String depositorName, String accountType, String accountNumber, double initialBalance){
        this.depositorName = depositorName;
        this.accountType = accountType;
        this.accountNo = accountNumber;
        this.balance = initialBalance;
    }
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit successful. New balance: " + balance);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }
    public void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawal successful. New balance: " + balance);
        } else {
            System.out.println("Insufficient funds or invalid withdrawal amount.");
        }
    }
    public void display() {
        System.out.println("Depositor Name: " + depositorName);
        System.out.println("Balance: " + balance);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter depositor name:");
        String name = scanner.nextLine();

        System.out.println("Enter account type:");
        String type = scanner.nextLine();

        System.out.println("Enter account number:");
        String number = scanner.nextLine();

        System.out.println("Enter initial balance:");
        double initialBalance = scanner.nextDouble();

        BankAccount account = new BankAccount(name, type, number, initialBalance);

        System.out.println("Enter 'd' to deposit, 'w' to withdraw, 's' to display, or 'q' to quit:");
        char choice = scanner.next().charAt(0);
        while (choice != 'q') {
            switch (choice) {
                case 'd':
                    System.out.println("Enter deposit amount:");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 'w':
                    System.out.println("Enter withdrawal amount:");
                    double withdrawalAmount = scanner.nextDouble();
                    account.withdraw(withdrawalAmount);
                    break;
                case 's':
                    account.display();
                    break;
                default:
                    System.out.println("Invalid choice.");
                    break;
            }
            System.out.println("Enter 'd' to deposit, 'w' to withdraw, 's' to display, or 'q' to quit:");
            choice = scanner.next().charAt(0);
        }
        scanner.close();
    }
}


