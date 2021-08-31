#include "drivers/keyboard.h"
#include "io.h"
#include "scan.h"
#include "terminal.h"
#include "print.h"

void init_keyboard_driver() {
	outb(0x21, 0xfd);
	outb(0xa1, 0xff);
}

uint8_t KeyboardHandler() {
	uint8_t state = inb(0x64);
	while (state & 1 && (state & 0x20) == 0) {
		uint8_t scan = inb(0x60);
		uint8_t scan_code = scan & 0x7f;
		state = inb(0x64);

		if (scan < 0x3A) {
			switch (scan) {
				case 0x0e: // Backspace
					rmv_last_char();
					remove_last_char_cmd();
					break;

				case 0x1c: // Enter
					exec_cmd();
					print_newline();
					print_path();
					break;

				default:
					put(scan);
					break;
			}
		}
	}
	
	outb(0x20, 0x20);
}