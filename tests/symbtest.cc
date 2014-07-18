/*
 * test.cc
 * This file is part of logics++
 *
 * Copyright (C) 2014 - César González <ceguel@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 */

#include <iostream>
#include <glibmm.h>
#include "symbol.h"


int
main ()
{
	std::locale::global(std::locale(""));

	Logics::SymbolTable symbtable;
	std::cout << symbtable.print_table() << std::endl;

	std::cout << "Define symbol: ";
	Glib::ustring str;
	try {
		std::cin >> str;
	}
	catch (const Glib::Error& error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}

	Logics::Symbol symb(str);
	std::cout << "Symbol: " << symb.get_glyph() << std::endl;
	std::cout << "Symbol length: " << symb.lenght() << std::endl;
	std::cout << "Symbol type: ";
	switch (symb.get_type()) {
		case Logics::SYMBOL_TYPE_NONE:
			std::cout << "none";
			break;
		case Logics::SYMBOL_TYPE_TERM:
			std::cout << "term";
			break;
		case Logics::SYMBOL_TYPE_OPERATOR:
			std::cout << "operator";
			break;
		case Logics::SYMBOL_TYPE_AUXILIARY:
			std::cout << "auxiliary";
			break;
	}
	if (symb.is_custom()) {
		std::cout << " (custom)";
	}
	std::cout << "." << std::endl << std::endl;;

	Logics::Symbol symb2;
	symb2.set_glyph(str);
	std::cout << "Symbol2: " << symb2.get_glyph() << std::endl;
	std::cout << "Symbol2 length: " << symb2.lenght() << std::endl;
	std::cout << "Symbol2 type: ";
	switch (symb.get_type()) {
		case Logics::SYMBOL_TYPE_NONE:
			std::cout << "none";
			break;
		case Logics::SYMBOL_TYPE_TERM:
			std::cout << "term";
			break;
		case Logics::SYMBOL_TYPE_OPERATOR:
			std::cout << "operator";
			break;
		case Logics::SYMBOL_TYPE_AUXILIARY:
			std::cout << "auxiliary";
			break;
	}
	if (symb.is_custom()) {
		std::cout << " (custom)";
	}
	std::cout << "." << std::endl << std::endl;

	try {
		Logics::Symbol symb3(Unicode::mathematical_italic(Unicode::GREEK_CAPITAL_LETTER_ALPHA));
		std::cout << "Symbol3: " << symb3.get_glyph() << std::endl;
		std::cout << "Symbol3 length: " << symb3.lenght() << std::endl;
		std::cout << "Symbol3 type: ";
		switch (symb3.get_type()) {
			case Logics::SYMBOL_TYPE_NONE:
				std::cout << "none.";
				break;
			case Logics::SYMBOL_TYPE_TERM:
				std::cout << "term.";
				break;
			case Logics::SYMBOL_TYPE_OPERATOR:
				std::cout << "operator.";
				break;
			case Logics::SYMBOL_TYPE_AUXILIARY:
				std::cout << "auxiliary.";
				break;
		}
		std::cout << std::endl;
	}
	catch (const Glib::Error& error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}
