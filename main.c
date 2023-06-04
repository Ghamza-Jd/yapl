#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
  init_vm();

  chunk_t chunk;
  init_chunk(&chunk);

  int constant = add_constant(&chunk, 1.2);
  write_chunk(&chunk, OP_CONSTANT, 123);
  write_chunk(&chunk, constant, 123);
  write_chunk(&chunk, OP_NEGATE, 123);

  write_chunk(&chunk, OP_RETURN, 123);

  interpret(&chunk);
  free_vm();
  free_chunk(&chunk);
  return EXIT_SUCCESS;
}
