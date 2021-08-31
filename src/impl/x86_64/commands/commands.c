#include "commands/commands.h"
#include "print.h"

/* Users Handlers */

void whoiam() {
	print_newline();
	print_str("User: alex");
	print_newline();
}

/* Screen Commands */

void clear() {
	print_clear();
}