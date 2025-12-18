#ifndef focaccia_vm_h
#define focaccia_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  // Chunk represents a set of bytecode instructions to be executed by the VM
  Chunk *chunk;

  // `ip` means instruction pointer - this tracks the next instruction to be
  // executed. it's faster to dereference a pointer than it is to look up an
  // index in an array
  uint8_t *ip;

  Value stack[STACK_MAX];
  Value *stackTop;

} VM; // as in "virtual machine"

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk *chunk);
void push(Value value);
Value pop();

#endif
