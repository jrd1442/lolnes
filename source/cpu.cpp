#include "cpu.h"

#include <cassert>  // todo: make project-specific assert

//                                           pc, sp,  a,  x,  y,  p
const CPU::Registers CPU::EMPTY_REGISTERS = { 0,  0,  0,  0,  0,  0 };

CPU::CPU()
	: registers(EMPTY_REGISTERS), latency(0)
{
}

void CPU::Tick()
{
	assert(false);
}