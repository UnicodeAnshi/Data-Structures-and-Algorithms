class Task implements Runnable {
    private String taskName;

    public Task(String taskName) {
        this.taskName = taskName;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(taskName + " -: Count: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(taskName + " : interrupted.");
            }
        }
        System.out.println(taskName + " :  completed.");
    }
}

public class p16 {
    public static void main(String[] args) {
        Task t1 = new Task("Task 1");
        Task t2 = new Task("Task 2");
        Task t3 = new Task("Task 3");
        Thread thread1 = new Thread(t1);
        Thread thread2 = new Thread(t2);
        Thread thread3 = new Thread(t3);

        thread1.start();
        thread2.start();
        thread3.start();
    }
}
