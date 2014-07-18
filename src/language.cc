/*
 * language.cc
 * This file is part of logics
 *
 * Copyright (C) 2014 - cgg
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

#include <list>
#include "language.h"

namespace Logics
{

Language::Language(SymbolsDefined primitive_symbols)
{
	for (int n = 0; n < SYMBOL_MAX; ++n) {
		if (primitive_symbols.is_set((SymbolName) n)) {
			Symbol symb((SymbolName) n);
			this->primitive_symbols.insert(symb);
		}
	}
}


std::set<Symbol>
Language::get_primitive_symbols() const
{
	return primitive_symbols;
}


Glib::ustring
Language::print_primitive_symbols() const
{
	Glib::ustring output;
	for (std::set<Symbol>::iterator it = primitive_symbols.begin(); it != primitive_symbols.end(); ++it) {
		output += it->get_glyph();
		output += ", ";
	}
	return output;
}


Glib::ustring
Language::info() const
{
	std::list<Symbol> symbol_constants,
	                  symbol_connectives,
	                  symbol_auxiliary;
	for (std::set<Symbol>::reverse_iterator rit = primitive_symbols.rbegin(); rit != primitive_symbols.rend(); ++rit) {
		switch (rit->get_type()) {
			case SYMBOL_TYPE_TERM:
				symbol_constants.push_front(*rit);
				break;
			case SYMBOL_TYPE_OPERATOR:
				symbol_connectives.push_front(*rit);
				break;
			case SYMBOL_TYPE_AUXILIARY:
				symbol_auxiliary.push_front(*rit);
				break;
		}
	}

	Glib::ustring output;
	std::list<Symbol>::iterator it;
	int i;

	output += "Constants: ";
	for (it = symbol_constants.begin(); it != symbol_constants.end(); ++it) {
		output += it->get_glyph();
		if (it != --symbol_constants.end()) {
			output += ", ";
		}
		else {
			output += ".\n";
		}
	}

	output += "Connectives: ";
	for (it = symbol_connectives.begin(); it != symbol_connectives.end(); ++it) {
		output += it->get_glyph();
		if (it != --symbol_connectives.end()) {
			output += ", ";
		}
		else {
			output += ".\n";
		}
	}

	output += "Auxiliary symbols: ";
	for (it = symbol_auxiliary.begin(); it != symbol_auxiliary.end(); ++it) {
		output += it->get_glyph();
		if (it != --symbol_auxiliary.end()) {
			output += ", ";
		}
		else {
			output += ".\n";
		}
	}

	return output;
}


} /* namespace Logics */
