compile: main.c mutex.c barrier.c
	gcc -o main main.c -lm -O3 -lpthread
	gcc -o mutex mutex.c -lm -O3 -lpthread
	gcc -o barrier barrier.c -lm -O3 -lpthread

clean:
	rm main mutex barrier
