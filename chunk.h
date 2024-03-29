#ifndef yapl_chunk_h
#define yapl_chunk_h

#include "common.h"
#include "value.h"

typedef enum op_code_t {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_RETURN,
} op_code_t;

typedef struct chunk_t {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    value_array_t constants;
} chunk_t;

void init_chunk(chunk_t *chunk);

void free_chunk(chunk_t *chunk);

void write_chunk(chunk_t *chunk, uint8_t byte, int line);

int add_constant(chunk_t *chunk, value_t value);

#endif
