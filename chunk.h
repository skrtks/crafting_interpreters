//
// Created by Sam Kortekaas on 12/8/21.
//

#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "memory.h"
#include "value.h"
#include "lines.h"

typedef enum {
	OP_RETURN,
	OP_NEGATE,
	OP_CONSTANT,
	OP_ADD,
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE
} OpCode;

typedef struct {
	int count;
	int capacity;
	uint8_t *code;
	LinesArray lines;
	ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif //CHUNK_H
