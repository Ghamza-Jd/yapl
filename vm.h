#ifndef yapl_vm_h
#define yapl_vm_h

#include "chunk.h"

typedef struct {
  chunk_t* chunk;
  uint8_t* ip;
} vm_t;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} interpret_result_t;

void init_vm();
void free_vm();
interpret_result_t interpret(chunk_t* chunk);

#endif