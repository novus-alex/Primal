#include "scan.h"
#include "io.h"
#include "print.h"
#include "drivers/keyboard.h"
#include "tools/string.h"
#include "terminal.h"

const char ScanCodeLookupTable[] = {
	0, 0, '1', '2',
	'3', '4','5', '6',
	'7', '8', '9', '0',
	'-', '=', 0, 0,
	'a', 'z', 'e', 'r',
	't', 'y', 'u', 'i',
	'o', 'p', '[', ']',
	0, 0, 'q', 's', 'd',
	'f', 'g', 'h', 'j',
	'k', 'l', 'm', '\'',
	'`', 0, '\\', 'w',
	'x','c', 'v', 'b',
	'n', ',', ';', ':',
	'!', 0, ' '
};

char old;
int erase = 0;
char *cmd;
bool exec = false;

char *strcat(char *dest, const char *src) {
	char *tmp = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0')
		;
	return tmp;
}

char rmvfirst(char *str) {
	for (int i=0;i<strlen(str);i++) {
		str[i] = str[i+1];
	}
}

void read_keyboard() {
	uint8_t scan = KeyboardHandler();
}

void put(uint8_t c) {
	char v = ScanCodeLookupTable[c];
	print_char(v);
	append_to_cmd(v);
}

void append_to_cmd(char c) {
	char cToStr[2];
	cToStr[1] = '\0';
	cToStr[0] = c;
	strcat(cmd, cToStr);
}

void remove_last_char_cmd() {
	cmd[strlen(cmd) - 1] = '\0';
}

void exec_cmd() {
	exec_command(cmd);
	clearstr(cmd);
}

void init_terminal() {
	clearstr(cmd);

	while (1) {
        read_keyboard();
    }
}