#include "print.h"
#include "scan.h"
#include "terminal.h"
#include "io.h"

void kernel_main() {
    // Init drivers
    print_clear();
    init_keyboard_driver();
    log("KEYBOARD", "driver initialized");
    print_newline();
    print_newline();

    // Init screen
    enable_cursor(0, 15);

    // Entry srceen
    entry_terminal();

    // Command handler
    TerminalHandler();
}
