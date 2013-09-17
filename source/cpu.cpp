/* cpu.cpp
**
** Implements public member functions.
*/

#include "cpu.h"

#include <cassert>  // todo: make project-specific assert

//                                           pc, sp,  a,  x,  y,  p
const CPU::Registers CPU::EMPTY_REGISTERS = { 0,  0,  0,  0,  0,  0 };

/////////////////////////////////////////////////////////////////////////////////// constructor ///
CPU::CPU()
	: registers(EMPTY_REGISTERS), latency(0)
{
}

////////////////////////////////////////////////////////////////////////////////////////// Tick ///
void CPU::Tick()
{
	assert(false);
}