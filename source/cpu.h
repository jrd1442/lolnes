#ifndef _NES_CPU_H_
#define _NES_CPU_H_

#include "datatypes.h"

class CPU
{
public:
	CPU();
	void Tick();

private:
	struct Registers
	{
		word pc;
		byte sp;
		byte a;
		byte x;
		byte y;
		
		union
		{
			struct
			{
				unsigned n : 1;
				unsigned v : 1;
				unsigned   : 1;
				unsigned b : 1;
				unsigned d : 1;
				unsigned i : 1;
				unsigned z : 1;
				unsigned c : 1;
			};
			
			byte p;
		};
	} registers;

	static const Registers EMPTY_REGISTERS;

	byte latency;

	enum Instruction
	{
		INSTRUCTION_ADC = 0, INSTRUCTION_AND, INSTRUCTION_ASL, INSTRUCTION_BCC, INSTRUCTION_BCS, INSTRUCTION_BEQ, INSTRUCTION_BIT, INSTRUCTION_BMI,
		INSTRUCTION_BNE,     INSTRUCTION_BPL, INSTRUCTION_BRK, INSTRUCTION_BVC, INSTRUCTION_BVS, INSTRUCTION_CLC, INSTRUCTION_CLD, INSTRUCTION_CLI,
		INSTRUCTION_CLV,     INSTRUCTION_CMP, INSTRUCTION_CPX, INSTRUCTION_CPY, INSTRUCTION_DEC, INSTRUCTION_DEX, INSTRUCTION_DEY, INSTRUCTION_EOR,
		INSTRUCTION_INC,     INSTRUCTION_INX, INSTRUCTION_INY, INSTRUCTION_JMP, INSTRUCTION_JSR, INSTRUCTION_LDA, INSTRUCTION_LDX, INSTRUCTION_LDY,
		INSTRUCTION_LSR,     INSTRUCTION_NOP, INSTRUCTION_ORA, INSTRUCTION_PHA, INSTRUCTION_PHP, INSTRUCTION_PLA, INSTRUCTION_PLP, INSTRUCTION_ROL,
		INSTRUCTION_ROR,     INSTRUCTION_RTI, INSTRUCTION_RTS, INSTRUCTION_SBC, INSTRUCTION_SEC, INSTRUCTION_SED, INSTRUCTION_SEI, INSTRUCTION_STA,
		INSTRUCTION_STX,     INSTRUCTION_STY, INSTRUCTION_TAX, INSTRUCTION_TAY, INSTRUCTION_TSX, INSTRUCTION_TXA, INSTRUCTION_TXS, INSTRUCTION_TYA,

		NUM_INSTRUCTION,
		INSTRUCTION_UNDEFINED
	};

	enum AddressMode
	{
		ADDRESSMODE_ACCUMULATOR = 0,
		ADDRESSMODE_ABSOLUTE,
		ADDRESSMODE_ABSOLUTE_X,
		ADDRESSMODE_ABSOLUTE_Y,
		ADDRESSMODE_IMMEDIATE,
		ADDRESSMODE_IMPLIED,
		ADDRESSMODE_INDIRECT,
		ADDRESSMODE_X_INDIRECT,
		ADDRESSMODE_INDIRECT_Y,
		ADDRESSMODE_RELATIVE,
		ADDRESSMODE_ZEROPAGE,
		ADDRESSMODE_ZEROPAGE_X,
		ADDRESSMODE_ZEROPAGE_Y,

		NUM_ADDRESSMODE,
		ADDRESSMODE_UNDEFINED
	};

	struct InstructionTableEntry
	{
		byte instruction;
		byte addressMode;
	};
	
	static const unsigned short        INSTRUCTION_TABLE_SIZE = 256;
	static const InstructionTableEntry UNDEFINED_INSTRUCTION_TABLE_ENTRY;
	static const InstructionTableEntry instructionTable[INSTRUCTION_TABLE_SIZE];

	typedef void (CPU::*PFNInstruction)(const byte &);
	static const PFNInstruction INSTRUCTIONS[NUM_INSTRUCTION];

	void ADC(const byte &addressMode);
	void AND(const byte &addressMode);
	void ASL(const byte &addressMode);
	void BCC(const byte &addressMode);
	void BCS(const byte &addressMode);
	void BEQ(const byte &addressMode);
	void BIT(const byte &addressMode);
	void BMI(const byte &addressMode);
	void BNE(const byte &addressMode);
	void BPL(const byte &addressMode);
	void BRK(const byte &addressMode);
	void BVC(const byte &addressMode);
	void BVS(const byte &addressMode);
	void CLC(const byte &addressMode);
	void CLD(const byte &addressMode);
	void CLI(const byte &addressMode);
	void CLV(const byte &addressMode);
	void CMP(const byte &addressMode);
	void CPX(const byte &addressMode);
	void CPY(const byte &addressMode);
	void DEC(const byte &addressMode);
	void DEX(const byte &addressMode);
	void DEY(const byte &addressMode);
	void EOR(const byte &addressMode);
	void INC(const byte &addressMode);
	void INX(const byte &addressMode);
	void INY(const byte &addressMode);
	void JMP(const byte &addressMode);
	void JSR(const byte &addressMode);
	void LDA(const byte &addressMode);
	void LDX(const byte &addressMode);
	void LDY(const byte &addressMode);
	void LSR(const byte &addressMode);
	void NOP(const byte &addressMode);
	void ORA(const byte &addressMode);
	void PHA(const byte &addressMode);
	void PHP(const byte &addressMode);
	void PLA(const byte &addressMode);
	void PLP(const byte &addressMode);
	void ROL(const byte &addressMode);
	void ROR(const byte &addressMode);
	void RTI(const byte &addressMode);
	void RTS(const byte &addressMode);
	void SBC(const byte &addressMode);
	void SEC(const byte &addressMode);
	void SED(const byte &addressMode);
	void SEI(const byte &addressMode);
	void STA(const byte &addressMode);
	void STX(const byte &addressMode);
	void STY(const byte &addressMode);
	void TAX(const byte &addressMode);
	void TAY(const byte &addressMode);
	void TSX(const byte &addressMode);
	void TXA(const byte &addressMode);
	void TXS(const byte &addressMode);
	void TYA(const byte &addressMode);
};

#endif