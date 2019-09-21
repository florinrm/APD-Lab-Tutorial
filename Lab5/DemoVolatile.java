import java.io.*;
import java.util.*;

class MyThreadWithVolatile extends Thread {
    public static volatile int volatileInt = 0;
    private int threadId;

    public MyThreadWithVolatile (int threadId) {
        this.threadId = threadId;
    }

    @Override
    public void run() {
        volatileInt++;
        System.out.println("Thread no. " + threadId + " with volatile value " + volatileInt);
    }
}

class MyThreadWithNoVolatile extends Thread {
    public static int noVolatileInt = 0;
    private int threadId;

    public MyThreadWithNoVolatile (int threadId) {
        this.threadId = threadId;
    }

    @Override
    public void run() {
        noVolatileInt++;
        System.out.println("Thread no. " + threadId + " with non-volatile value " + noVolatileInt);
    }
}

public class DemoVolatile {
    private static final int numberOfThreads = 20;

    public static void main (String[] args) {
        Thread[] threadsVolatile = new Thread[numberOfThreads];
        Thread[] threadsNoVolatile = new Thread[numberOfThreads];

        System.out.println("Volatile");
        // cream thread-urile
        for (int i = 0; i < numberOfThreads; ++i) {
            threadsVolatile[i] = new MyThreadWithVolatile(i);
        }

        // pornesc thread-urile in actiune
        for (int i = 0; i < numberOfThreads; ++i) {
            threadsVolatile[i].start();
        }

        // am terminat cu thread-urile
        for (int i = 0; i < numberOfThreads; ++i) {
            try {
                threadsVolatile[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("No Volatile");
        // cream thread-urile
        for (int i = 0; i < numberOfThreads; ++i) {
            threadsNoVolatile[i] = new MyThreadWithNoVolatile(i);
        }

        // pornesc thread-urile in actiune
        for (int i = 0; i < numberOfThreads; ++i) {
            threadsNoVolatile[i].start();
        }

        // am terminat cu thread-urile
        for (int i = 0; i < numberOfThreads; ++i) {
            try {
                threadsNoVolatile[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}