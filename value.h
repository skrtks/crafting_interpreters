//
// Created by Sam Kortekaas on 12/9/21.
//

#ifndef VALUE_H
#define VALUE_H

#include "common.h"

typedef double Value;

typedef struct {
	int capacity;
	int count;
	Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);

#endif //VALUE_H
