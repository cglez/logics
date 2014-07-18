/*
 * language.h
 * This file is part of logics++
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

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <vector>
#include <set>
#include <glibmm/ustring.h>
#include "symbol.h"

namespace Logics
{

enum Notation {
	NOTATION_INFIX,                  /**< Infix Notation, Standard Notation */
	NOTATION_STD = NOTATION_INFIX,
	NOTATION_PREFIX,                 /**< Prefix Notation, Polish Notation, PN */
	NOTATION_PN = NOTATION_PREFIX,
	NOTATION_POSTFIX,                /**< Postfix Notation, Reverse Polish Notation, RPN */
	NOTATION_RPN = NOTATION_POSTFIX
};


/** Notation traditions */
enum SymbolNoationTradition {
	SYMBOL_TRADITION_PEANO,
	SYMBOL_TRADITION_POLISH,
	SYMBOL_TRADITION_AMS
};


/**
 *
 */
class Expression
{
public:
	bool is_wff (void);
private:
	std::vector<Symbol> expr;
};


/**
 *
 */
class Syntax
{
public:
private:
};


/**
 *
 */
class Language
{
public:
	Language();
	//Language(std::set<Symbol> symbols);
	Language(SymbolsDefined primitive);
	std::set<Symbol>  get_primitive_symbols() const;
	Glib::ustring     print_primitive_symbols() const;
	Glib::ustring     info() const;
private:
	std::set<Symbol>  primitive_symbols;
	std::set<Symbol>  defined_symbols;
	Syntax            syntax;
};

} /* namespace Logics */

#endif /* LANGUAGE_H_ */
