build:
	mpicc send_recv.c -o send_recv
	mpicc ring.c -o ring
	mpicc broadcast.c -o broadcast
	mpicc scatter_gather.c -o scatter_gather

run_ring:
	mpirun -np 6 ring

run_send_recv:
	mpirun -np 6 send_recv

run_broadcast:
	mpirun -np 6 broadcast

run_scatter_gather:
	mpirun -np 6 scatter_gather

clean:
	rm send_recv ring scatter_gather broadcast