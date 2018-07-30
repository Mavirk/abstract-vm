#include "avm.hpp"

AVM::AVM(){
	memory.reserve(1000000);
}

i32 AVM::getType(i32 instruction){
	i32 type = 0xc0000000;
	type = (type & instruction ) >> 30;
	return type;
}

i32 AVM::getData(i32 instruction){
	i32 data = 0x3fffffff;
	data = data & instruction;
	return data;
}

void AVM::fetch(){
	pc++;
}

void AVM::decode(){
	typ = getType(memory[pc]);
	dat = getData(memory[pc]);
}

void AVM::execute(){
	if (typ == 0 || typ == 2){
		sp++;
		memory[sp] = dat;
	} else {
		doPrimative();
	} 
}

void AVM::doPrimative(){
	switch (dat){
		case 0: //halt
			std::cout << "halt" << std::endl;
			running = 0;
			break;
		case 1: //add
			std::cout << "add " << memory[sp] << " " << memory[sp - 1] << std::endl;
			memory[sp - 1] = memory[sp] + memory[sp - 1];
			sp--;
			break;
		case 2: //sub
			std::cout << "sub " << memory[sp] << " " << memory[sp - 1] << std::endl;
			memory[sp - 1] = memory[sp] - memory[sp - 1];
			sp--;
			break;
		case 3: //mul
			std::cout << "mul " << memory[sp] << " " << memory[sp - 1] << std::endl;
			memory[sp - 1] = memory[sp] * memory[sp - 1];
			sp--;
			break;
		case 4: //div
			std::cout << "div " << memory[sp] << " " << memory[sp - 1] << std::endl;
			memory[sp - 1] = memory[sp] / memory[sp - 1];
			sp--;
			break;
	}
}
void AVM::run(){
	pc -= 1;
	while (running == 1){
		fetch();
		decode();
		execute();
		std::cout << "tos: " << memory[sp] << std::endl;
	}	
}
void AVM::loadProgram(std::vector<i32> prog) {
	for (i32 i = 0; i < prog.size(); i++){
		memory[pc + i] = prog[i];
	}	
}
