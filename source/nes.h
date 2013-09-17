/* nes.h
**
** The NES console. Joins all the coomponents.
*/

#ifndef _NES_NES_H_
#define _NES_NES_H_

#include "cpu.h"

/* NES:
 *  Holds all components that make up the NES emulator.
 */
class NES
{
	static const unsigned int MEM_SIZE = 65536;  // system memory size

	CPU            cpu;  // the cpu
	byte[MEM_SIZE] mem;  // system memory

	// PPU
	// MMC
};

#endif