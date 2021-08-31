#include "tools/time.h"
#include "io.h"
#include "tools/string.h"

static int updating() {
	outb(0x70, 0x0a);
	return inb(0x71) & 0x80;
}

static unsigned char read(int reg) {
	while (updating())
		;

	outb(0x70, reg);
	return inb(0x71);
}

Time getTime() {
	Time time;

	unsigned char s_read = read(0);
	unsigned char s = (s_read & 0x0f) + ((s_read / 16) * 10);

	unsigned char m_read = read(0x2);
	unsigned char m = (m_read & 0x0f) + ((m_read / 16) * 10);

	unsigned char h_read = read(0x4);
	unsigned char h = (h_read & 0x0f) + ((h_read / 16) * 10);

	unsigned char day = read(0x7);
	unsigned char month = read(0x8);
	unsigned char year = read(0x9);

	time.hour = h;
	time.minute = m;
	time.second = s;

	/*strcat(time, h);
	strcat(time, ':');
	strcat(time, m);
	strcat(time, ':');
	strcat(time, s);*/

	return time;
}