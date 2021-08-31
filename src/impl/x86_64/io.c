#include "io.h"

void outb(unsigned short port, unsigned char val) {
	asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

unsigned char inb(unsigned short port) {
	unsigned char returnVal;
	asm volatile ("inb %1, %0" : "=a"(returnVal) : "Nd"(port));
	return returnVal;
}

void mov(unsigned short register_1, unsigned short register_2) {
	asm volatile ("mov %0, %1" : : "a"(register_1), "Nd"(register_2));
}