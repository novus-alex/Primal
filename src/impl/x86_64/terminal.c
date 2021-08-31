#include "terminal.h"
#include "print.h"
#include "tools/string.h"
#include "main.h"
#include "tools/time.h"
#include "commands/commands.h"

void print_path() {
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("alex@");
    print_str(OS_TERMINAL_NAME);
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(":");
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
    print_str("~");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("$ ");
}

void entry_terminal() {
	print_str(OS_NAME);
	print_char(' ');
	print_str(OS_VERSION);
	print_newline();
	print_str("Copyright (c) 2020-2021 Alexandre");
	print_newline();
	print_newline();
	print_str(" * Documentation at https://github.com/novus-alex/Primal");
	print_newline();
	print_newline();
}


void TerminalHandler() {
	while (1) {
		print_path();
		init_terminal();
	}
}

void exec_command(char *cmd) {
	if (strcmp(cmd, "whoiam") == 0) {
		whoiam();
	} else if (strcmp(cmd, "clear") == 0) {
		clear();
	}
}