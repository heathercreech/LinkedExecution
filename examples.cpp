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


//container for all the functions used in the examples
namespace exfunc {
	int add2(int val) {
		return val + 2;
	}

	int mult5(int val) {
		return val * 5;
	}


	std::vector<std::string>& replaceEWithJ(std::vector<std::string> &string_vector) {

		for (unsigned int i = 0; i < string_vector.size(); i++) {
			for (unsigned int j = 0; j < string_vector[i].size(); j++) {
				if (string_vector[i][j] == 'e') {
					string_vector[i][j] = 'j';
				}
				else if (string_vector[i][j] == 'E') {
					string_vector[i][j] = 'J';
				}
			}
		}
		return string_vector;
	}


	std::vector<std::string>& sortStringVector(std::vector<std::string> &string_vector) {
		std::sort(string_vector.begin(), string_vector.end());
		return string_vector;
	}
}



int main(int arc, char* argv[]) {
	//line of addition and multiplication
	FunctionLine<int> line({exfunc::add2, exfunc::mult5});
	std::cout << line.execute(5) << "\n\n";


	//Modify contents of strings in a vector, then sort
	std::vector<std::string> mod_vec({"Everyone", "Hello", "World"});
	FunctionLine<std::vector<std::string>> vec_line({exfunc::replaceEWithJ, exfunc::sortStringVector});
	mod_vec = vec_line.execute(mod_vec);

	for (unsigned int i = 0; i < mod_vec.size(); i++) {
		std::cout << mod_vec[i] << "\n";
	}
}