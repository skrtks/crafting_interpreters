//
// Created by Sam Kortekaas on 12/9/21.
//

#include <printf.h>
#include "lines.h"
#include "memory.h"

void initLinesArray(LinesArray* array) {
	array->lines = NULL;
	array->capacity = 0;
	array->count = 0;
}

void writeLinesArray(LinesArray* array, int line) {
	for (int i = 0; i < array->count; ++i) {
		if (array->lines && line == array->lines[i].lineNumber) {
			array->lines[i].runLength++;
			return;
		}
	}
	if (array->capacity < array->count + 1) {
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->lines = GROW_ARRAY(Line, array->lines, oldCapacity, array->capacity);
	}
	array->lines[array->count].lineNumber = line;
	array->lines[array->count].runLength = 1;
	array->count++;
}

void freeLinesArray(LinesArray* array) {
	FREE_ARRAY(Line, array->lines, array->capacity);
	initLinesArray(array);
}

void printLine(int value) {
	printf("%i", value);
}

int getLineNumber(const LinesArray* array, const int chunkOffset) {
	int rangeStart;
	int rangeEnd = 0;
	for (int i = 0; i < array->count; ++i) {
		rangeStart = rangeEnd;
		rangeEnd += array->lines[i].runLength;
		if (chunkOffset >= rangeStart && chunkOffset < rangeEnd) {
			return array->lines[i].lineNumber;
		}
	}
	return -1;
}
