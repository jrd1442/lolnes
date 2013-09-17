#ifndef _NES_NES_H_
#define _NES_NES_H_

#include "cpu.h"

class NES
{
	static const unsigned int MEM_SIZE = 65536;

	CPU            cpu;
	byte[MEM_SIZE] mem;

	// PPU
	// MMC
};

#endif