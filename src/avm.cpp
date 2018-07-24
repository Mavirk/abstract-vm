#include "avm.hpp"

AVM::AVM(){
	memory.reserve(1000000);
}

i32 StackkVM::getType(i32 instruction){
	i32 type = 0xc0000000;
	type = (type & instuction ) >> 30;
	return type;
}

i32 StackkVM::getData(i32 instruction){
	i32 data = 0x3fffffff;a
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
	if (type == 0 || type = 2){
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
			std::cout << "add" << memory[sp - 1] << " " << memory[sp] << std::endl;
			memory[sp - 1] = memory[sp - 1] + memory[sp];
			break;
	}
}
void AVM::run(){
	pc -= 1;
	while (running == 1){
		fetch();
		decode();
		execute();
		std::cout << "tos: " << memory[sp]; << std::endl;
	}	
}
void loadProgram(std::vector<i32>) prog {
	for (i32 i = 0; i < prog.size(); i++){
		memory[pc + i] = prog[i];
	}	
}
