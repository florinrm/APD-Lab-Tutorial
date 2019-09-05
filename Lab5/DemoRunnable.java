import java.util.*;
import java.io.*;

class MyRunnable implements Runnable {
    private int threadId;

    public MyRunnable (int threadId) {
        this.threadId = threadId;
    }

    // aceasta metoda se apeleaza in mod automat
    @Override
    public void run() {
        System.out.println("Threadul nr. " + threadId + " asculta manele");
    }
}

public class DemoRunnable {
    private static final int numberOfThreads = 20;

    public static void main (String[] args) {
        Thread[] threads = new Thread[numberOfThreads];

        // cream thread-urile
        for (int i = 0; i < numberOfThreads; ++i) {
            Runnable runnable = new MyRunnable(i);
            threads[i] = new Thread(runnable);
        }

        System.out.println("Demo Runnable");
        // pornesc thread-urile in actiune
        for (int i = 0; i < numberOfThreads; ++i) {
            threads[i].start();
        }

        // am terminat cu thread-urile
        for (int i = 0; i < numberOfThreads; ++i) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}