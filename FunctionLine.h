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


template <typename T>
class FunctionLine{
public:
	FunctionLine() {};

	FunctionLine(std::vector<boost::function<T (T)>> functions) {
		if (functions.size() > 0) {
			func = *functions.begin();
			if (functions.size() > 1) {
				functions.erase(functions.begin());
				next = new FunctionLine(functions);
			}
		}
	};


	T execute(T val) {
		if (next != NULL) {
			return next->execute(func(val));
		}
		else {
			return func(val);
		}
	};

private:
	boost::function<T(T)> func;
	FunctionLine* next = NULL;
};