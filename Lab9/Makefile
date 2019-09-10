build:
	mpicc send_recv.c -o send_recv
	mpicc ring.c -o ring

run_ring:
	mpirun -np 6 ring

run_send_recv:
	mpirun -np 6 send_recv

clean:
	rm send_recv ring