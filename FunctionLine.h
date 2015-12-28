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

#pragma once


#include <boost\any.hpp>
#include <boost\function.hpp>

#include <vector>


//takes the value type that is to be modified (looking at different ways to handle mutiple/varying parameters)
template <typename T>
class FunctionLine{
public:
	
	//function list initializer
	FunctionLine(std::vector<boost::function<T (T)>> functions) {
		if (functions.size() > 0) {
			func = *functions.begin();
			if (functions.size() > 1) {
				functions.erase(functions.begin());
				next = new FunctionLine(functions);
			}
		}
	};


	//executes the string of functions
	T execute(T val) {
		if (next != NULL) {
			return next->execute(func(val));
		}
		else {
			return func(val);
		}
	};

private:
	boost::function<T(T)> func; //the function to be executed
	FunctionLine* next = NULL; //the next function in the line
};