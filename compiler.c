//
// Created by Sam Kortekaas on 12/15/21.
//

#include <stdio.h>

#include "common.h"
#include "compiler.h"
#include "scanner.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-extra-args"
void compile(const char* source) {
	initScanner(source);

	int line = -1;
	while (true) {
		Token token = scanToken();
		if (token.line != line) {
			printf("4d ", token.line);
			line = token.line;
		} else {
			printf("   | ");
		}
		printf("%2d '%.*s'\n", token.type, token.length, token.start);

		if (token.type == TOKEN_EOF) break;
	}
}
#pragma clang diagnostic pop