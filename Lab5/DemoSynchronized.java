import java.io.*;
import java.util.*;

class Counter {
    public long count = 0;
    
    public synchronized void add(long value){
       this.count += value;
    }
}

class CounterThread extends Thread{

    public Counter counter = null;

    public CounterThread(Counter counter){
        this.counter = counter;
    }

    public void run() {
	    for(int i = 0; i < 10; i++){
            counter.add(i);
        }
    }
}

class CounterNoSync {
    long count = 0;
    
    public void add(long value){
       this.count += value;
    }
}

class CounterThreadNoSync extends Thread{

    public CounterNoSync counter = null;

    public CounterThreadNoSync(CounterNoSync counter){
        this.counter = counter;
    }

    public void run() {
	    for(int i = 0; i < 10; i++){
            counter.add(i);
        }
    }
}

public class DemoSynchronized {
    private static final int numberOfThreads = 20;

    public static void main (String[] args) {
        System.out.println("Synchronized");
        Counter counter = new Counter();
        Thread  threadA = new CounterThread(counter);
        Thread  threadB = new CounterThread(counter);

        threadA.start();
        threadB.start();

        try {
            System.out.println(((CounterThread)threadA).counter.count);
            System.out.println(((CounterThread)threadB).counter.count);

            threadA.join();
            threadB.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Not synchronized");
        CounterNoSync count = new CounterNoSync();
        Thread  threadC = new CounterThreadNoSync(count);
        Thread  threadD = new CounterThreadNoSync(count);

        threadC.start();
        threadD.start();

        try {
            System.out.println(((CounterThreadNoSync)threadC).counter.count);
            System.out.println(((CounterThreadNoSync)threadD).counter.count);

            threadC.join();
            threadD.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("\n\nTwo counters");

        System.out.println("Synchronized");
        Counter counterA = new Counter();
        Counter counterB = new Counter();
        threadA = new CounterThread(counterA);
        threadB = new CounterThread(counterB);

        threadA.start();
        threadB.start();

        try {
            System.out.println(((CounterThread)threadA).counter.count);
            System.out.println(((CounterThread)threadB).counter.count);

            threadA.join();
            threadB.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Not synchronized");
        CounterNoSync countC = new CounterNoSync();
        CounterNoSync countD = new CounterNoSync();
        threadC = new CounterThreadNoSync(countC);
        threadD = new CounterThreadNoSync(countD);

        threadC.start();
        threadD.start();

        try {
            System.out.println(((CounterThreadNoSync)threadC).counter.count);
            System.out.println(((CounterThreadNoSync)threadD).counter.count);

            threadC.join();
            threadD.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}