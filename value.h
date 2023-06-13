#ifndef yapl_value_h
#define yapl_value_h

#include "common.h"

typedef enum value_type_t {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER
} value_type_t;

typedef struct value_t {
    value_type_t type;
    union container {
        bool boolean;
        double number;
    } as;
} value_t;

#define AS_BOOL(value) ((value).as.boolean)
#define AS_NUMBER(value) ((value).as.number)

#define BOOL_VAL(value) ((value_t){VAL_BOOL, {.boolean = value}})
#define NIL_VAL ((value_t){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((value_t){VAL_NUMBER, {.number = value}})

typedef struct value_array_t {
    int capacity;
    int count;
    value_t *values;
} value_array_t;

void init_value_array(value_array_t *array);

void write_value_array(value_array_t *array, value_t value);

void free_value_array(value_array_t *array);

void print_value(value_t value);

#endif
