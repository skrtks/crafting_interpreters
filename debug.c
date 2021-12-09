//
// Created by Sam Kortekaas on 12/8/21.
//

#include <printf.h>
#include "common.h"
#include "debug.h"
#include "value.h"

int simpleInstruction(const char* name, int offset);
int constantInstruction(const char* name, Chunk* chunk, int offset);
void printValue(Value value);
Line getLine(const Chunk* chunk);

void disassembleChunk(Chunk* chunk, const char* name) {
	printf("== %s ==\n", name);

	for (int offset = 0; offset < chunk->count;) {
		offset = disassembleInstruction(chunk, offset);
	}
}

int simpleInstruction(const char* name, int offset) {
	printf("%s\n", name);
	return offset + 1;
}

int constantInstruction(const char* name, Chunk* chunk, int offset) {
	uint8_t constant = chunk->code[offset + 1];
	printf("%-16s %4d '", name, constant);
	printValue(chunk->constants.values[constant]);
	printf("'\n");
	return offset + 2;
}

int disassembleInstruction(Chunk* chunk, int offset) {
	printf("%04d ", offset);

	int lineNumber = getLineNumber(&chunk->lines, offset);
	if (offset > 0 && lineNumber == getLineNumber(&chunk->lines, offset - 1)) {
		printf("   | ");
	}
	else {
		printf("%4d ", lineNumber);
	}

	uint8_t instruction = chunk->code[offset];
	switch (instruction) {
		case OP_RETURN:
			return simpleInstruction("OP_RETURN", offset);
		case OP_CONSTANT:
			return constantInstruction("OP_CONSTANT", chunk, offset);
		default:
			printf("Unknown opcode %d\n", instruction);
			return offset + 1;
	}
}
