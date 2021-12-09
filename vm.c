//
// Created by Sam Kortekaas on 12/9/21.
//

#include "debug.h"
#include "chunk.h"
#include <stdlib.h>
#include <printf.h>
#include "common.h"
#include "vm.h"

VM vm;

void initVM() {

}

void freeVM() {

}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

	for (;;) {
		uint8_t instruction;
		switch (instruction = READ_BYTE()) {
			case OP_RETURN:
				return INTERPRET_OK;
			case OP_CONSTANT: {
        		Value constant = READ_CONSTANT();
        		printValue(constant);
        		printf("\n");
        		break;
      		}
		}
	}

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
	vm.chunk = chunk;
	vm.ip = vm.chunk->code;
	return run();
}