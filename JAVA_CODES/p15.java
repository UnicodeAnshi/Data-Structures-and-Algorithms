class LowBalanceException extends Exception {
    public LowBalanceException(String message) {
        super(message);
    }
}
public class p15 {
    private int balance;

    public p15(int initialBalance) {
        this.balance = initialBalance;
    }
    public void withdrawal(int amount) throws LowBalanceException {
        if (amount > balance) {
            throw new LowBalanceException("Insufficient balance. Your current balance is " + balance + ", but you tried to withdraw " + amount + ".");
        }
        balance -= amount;
    }

    public int showBalance() {
        return balance;
    }

    public static void main(String[] args) {
        p15 account = new p15(100);

        try {
            account.withdrawal(1500);
            System.out.println("Successfully withdrawn. Current balance is : " + account.showBalance());
        } catch (LowBalanceException e) {
            System.out.println(e.getMessage());
        }

        try {
            account.withdrawal(15);
            System.out.println("Successfully withdrawn. Current balance is : " + account.showBalance());
        } catch (LowBalanceException e) {
            System.out.println(e.getMessage());
        
        }
    }
}