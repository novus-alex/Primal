#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void init_keyboard_driver();
void read_k();
void init_terminal();
void remove_last_char_cmd();