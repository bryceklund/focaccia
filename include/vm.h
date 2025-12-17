#ifndef focaccia_vm_h
#define focaccia_vm_h

#include "chunk.h"

typedef struct {
  // Chunk represents a set of bytecode instructions to be executed by the VM
  Chunk *chunk;

  // `ip` means instruction pointer - this tracks the next instruction to be
  // executed. it's faster to dereference a pointer than it is to look up an
  // index in an array
  uint8_t *ip;

} VM; // as in "virtual machine"

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk *chunk);

#endif
