build:
	mpicc send_recv.c -o send_recv
	mpicc ring.c -o ring
	mpicc broadcast.c -o broadcast
	mpicc scather_gather.c -o scather_gather

run_ring:
	mpirun -np 6 ring

run_send_recv:
	mpirun -np 6 send_recv

run_broadcast:
	mpirun -np 6 broadcast

run_scather_gather:
	mpirun -np 6 broscather_gatheradcast

clean:
	rm send_recv ring