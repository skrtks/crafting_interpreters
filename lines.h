//
// Created by Sam Kortekaas on 12/9/21.
//

#ifndef LINES_H
#define LINES_H

#include "common.h"

typedef struct {
	int lineNumber;
	int runLength;
} Line;

typedef struct {
	int capacity;
	int count;
	Line* lines;
} LinesArray;

void initLinesArray(LinesArray* array);
void writeLinesArray(LinesArray* array, int line);
void freeLinesArray(LinesArray* array);

int getLineNumber(const LinesArray* array, const int chunkOffset);

void printLine(int value);

#endif //LINES_H
