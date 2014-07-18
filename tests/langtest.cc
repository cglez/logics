/*
 * language.cc
 * This file is part of logics
 *
 * Copyright (C) 2014 - César González <ceguel@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 */

#include <iostream>
#include "language.h"

int
main()
{
	std::locale::global(std::locale(""));

	Logics::SymbolsDefined with_primitive_symbols;
	with_primitive_symbols.set_symbol(Logics::SYMBOL_FALSE);
	with_primitive_symbols.set_symbol(Logics::SYMBOL_IMPLICATION);
	with_primitive_symbols.set_symbol(Logics::SYMBOL_BRACKET_LEFT);
	with_primitive_symbols.set_symbol(Logics::SYMBOL_BRACKET_RIGHT);

	Logics::Language language(with_primitive_symbols);
	std::cout << language.print_primitive_symbols() << std::endl;
	std::cout << language.info();

	/*
	// FIXME: Can anybody explain this?
	std::set<Logics::Symbol> primitive_symbols = language.get_primitive_symbols();
	std::set<Logics::Symbol>::iterator iter;

	for (std::set<Logics::Symbol>::iterator it = primitive_symbols.begin(); it != primitive_symbols.end(); ++it) {
		std::cout << it->get_glyph() << ", ";
	}
	std::cout << std::endl;

	for (std::set<Logics::Symbol>::iterator it = language.get_primitive_symbols().begin(); it != language.get_primitive_symbols().end(); ++it) {
		std::cout << it->get_glyph() << ", ";
	}
	std::cout << std::endl;

	for (iter = primitive_symbols.begin(); iter != primitive_symbols.end(); ++iter) {
		std::cout << iter->get_glyph() << ", ";
	}
	std::cout << std::endl;

	for (iter = language.get_primitive_symbols().begin(); iter != language.get_primitive_symbols().end(); ++iter) {
		std::cout << iter->get_glyph() << ", ";
	}
	std::cout << std::endl;
	*/
}
