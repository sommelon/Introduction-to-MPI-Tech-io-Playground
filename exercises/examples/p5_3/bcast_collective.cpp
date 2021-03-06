#include <iostream>
#include <mpi.h>

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // Initialising the data
  constexpr int buffer_size = 1024;
  int buffer[buffer_size];

  if (rank==0) {
    // Storing some values in the buffer
    for (int i=0; i < buffer_size; ++i)
      buffer[i] = i*i;
  }

  MPI_Bcast(buffer, 1000, MPI_INT, 0, MPI_COMM_WORLD);

  std::cout << "Process #" << rank << "; Buffer = (";
  for (int i=0; i < size; ++i)
    std::cout << buffer[i] << (i < 4 ? " " : "");
  std::cout << ")" << std::endl;
  
  MPI_Finalize();
}
