/*
	LinkedExecution is a proof of concept for a list of modification functions
	Copyright(C) 2015 Seth Creech

	This program is free software : you can redistribute it and / or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
	GNU General Public License for more details.
*/


#include "FunctionLine.h"

#include <iostream>

int add2(int val) {
	return val + 2;
}

int mult5(int val) {
	return val * 5;
}


int main(int arc, char* argv[]) {
	FunctionLine<int> line({add2, mult5});

	std::cout << line.execute(5) << std::endl;
}