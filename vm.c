#include "common.h"
#include "vm.h"

vm_t vm;

void init_vm() { }

void free_vm() { }

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)

  for (;;) {
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_RETURN: {
        return INTERPRET_OK;
      }
    }
  }

#undef READ_BYTE
}

interpret_result_t interpret(chunk_t* chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;
  return run();
}
