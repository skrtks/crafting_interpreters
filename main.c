#include <stdlib.h>
#include "chunk.h"
#include "debug.h"

int main(void) {
	Chunk chunk;
	initChunk(&chunk);

	int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONSTANT, 123);
	writeChunk(&chunk, constant, 123);
	writeChunk(&chunk, OP_RETURN, 123);

	constant = addConstant(&chunk, 2.1);
	writeChunk(&chunk, OP_CONSTANT, 321);
	writeChunk(&chunk, constant, 321);
	writeChunk(&chunk, OP_RETURN, 321);
	disassembleChunk(&chunk, "test chunk");

	freeChunk(&chunk);

//	system("leaks crafting_interpreters");
	return (0);
}
