/*
 * symbol.cc
 * This file is part of logics
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

#include "symbol.h"

namespace Logics
{

SymbolType
get_symbol_type(SymbolName symb_name)
{
	switch (symb_name) {
		case SYMBOL_NEGATION:
		case SYMBOL_IMPLICATION:
		case SYMBOL_CONJUNCTION:
		case SYMBOL_DISJUNCTION:
		case SYMBOL_BICONDITIONAL:
		case SYMBOL_EXCLUSIVE_DISJUNCTION:
		case SYMBOL_NON_CONJUNCTION:
		case SYMBOL_NON_DISJUNCTION:
		case SYMBOL_NON_IMPLICATION:
		case SYMBOL_CONVERSE_IMPLICATION:
		case SYMBOL_CONVERSE_NON_IMPLICATION:
		case SYMBOL_UNIVERSAL_QUANTIFIER:
		case SYMBOL_EXISTENTIAL_QUANTIFIER:
		case SYMBOL_UNIQUENESS_QUANTIFIER:
		case SYMBOL_POSSIBILITY:
		case SYMBOL_NECESSITY:
			return SYMBOL_TYPE_OPERATOR;
		case SYMBOL_VARIABLE:
		case SYMBOL_TRUE:
		case SYMBOL_TRUTH:
		case SYMBOL_TAUTOLOGY:
		case SYMBOL_FALSE:
		case SYMBOL_FALSITY:
		case SYMBOL_CONTRADICTION:
		//case SYMBOL_META_VARIABLE:
			return SYMBOL_TYPE_TERM;
		case SYMBOL_PARENTHESIS_LEFT:
		case SYMBOL_PARENTHESIS_RIGHT:
		case SYMBOL_SQUARE_BRACKET_LEFT:
		case SYMBOL_SQUARE_BRACKET_RIGHT:
		case SYMBOL_CURLY_BRACKET_LEFT:
		case SYMBOL_CURLY_BRACKET_RIGHT:
		case SYMBOL_ANGLE_BRACKET_LEFT:
		case SYMBOL_ANGLE_BRACKET_RIGHT:
			return SYMBOL_TYPE_AUXILIARY;
		case SYMBOL_NONE:
		case SYMBOL_CUSTOM:
		default:
			return SYMBOL_TYPE_NONE;
	}
}


Symbol::Symbol()
{
	type = SYMBOL_TYPE_NONE;
	name = SYMBOL_NONE;
}


Symbol::Symbol (gunichar  glyph)
{
	if (Glib::Unicode::validate(glyph)) {
		this->glyph = (0, glyph);
		set_name();
		set_type();
	}
}


Symbol::Symbol (Glib::ustring const&  glyph)
{
	this->glyph = glyph;
	set_name();
	set_type();
}


Symbol::Symbol (SymbolName  name)
{
	this->name = name;
	set_type();
	set_glyph();
}


bool
Symbol::operator< (Symbol const&  rop) const
{
	return (name < rop.name);
}


bool
Symbol::operator> (Symbol const&  rop) const
{
	return (name > rop.name);
}


bool
Symbol::operator== (Symbol const&  rop) const
{
	return (name == rop.name);
}


bool
Symbol::operator!= (Symbol const&  rop) const
{
	return (name != rop.name);
}


void
Symbol::set_glyph()
{
	SymbolTable symbol_table;
	glyph = symbol_table.get_glyph(name, UNICODE);
}


void
Symbol::set_glyph (Glib::ustring const&  glyph)
{
	this->glyph = glyph;
	set_name();
	set_type();
}


const Glib::ustring
Symbol::get_glyph() const
{
	return glyph;
}


SymbolType
Symbol::get_type() const
{
	return type;
}


void
Symbol::set_name()
{
	SymbolTable symbol_table;
	name = symbol_table.get_name (glyph);
}


void
Symbol::set_type()
{
	type = get_symbol_type (name);
}


int
Symbol::lenght() const
{
	return glyph.length();
}


bool
Symbol::is_custom() const
{
	return name == SYMBOL_CUSTOM;
}


SymbolTable::SymbolTable()
{
	table[SYMBOL_NEGATION][UNICODE]                 = Unicode::NOT_SIGN;
	table[SYMBOL_NEGATION][ASCII]                   = "-";
	table[SYMBOL_NEGATION][LATEX]                   = "\\neg";
	table[SYMBOL_NEGATION][XML]                     = "&not;";
	table[SYMBOL_IMPLICATION][UNICODE]              = Unicode::RIGHTWARDS_ARROW;
	table[SYMBOL_IMPLICATION][ASCII]                = "->";
	table[SYMBOL_IMPLICATION][LATEX]                = "\\to";
	table[SYMBOL_IMPLICATION][XML]                  = "&rarr;";
	table[SYMBOL_CONJUNCTION][UNICODE]              = Unicode::LOGICAL_AND;
	table[SYMBOL_CONJUNCTION][ASCII]                = "&";
	table[SYMBOL_CONJUNCTION][LATEX]                = "\\wedge";
	table[SYMBOL_CONJUNCTION][XML]                  = "&and;";
	table[SYMBOL_DISJUNCTION][UNICODE]              = Unicode::LOGICAL_OR;
	table[SYMBOL_DISJUNCTION][ASCII]                = "v";
	table[SYMBOL_DISJUNCTION][LATEX]                = "\\vee";
	table[SYMBOL_DISJUNCTION][XML]                  = "&or;";
	table[SYMBOL_BICONDITIONAL][UNICODE]            = Unicode::LEFT_RIGHT_ARROW;
	table[SYMBOL_BICONDITIONAL][ASCII]              = "<->";
	table[SYMBOL_BICONDITIONAL][LATEX]              = "\\leftrightarrow";
	table[SYMBOL_BICONDITIONAL][XML]                = "&harr;";
	table[SYMBOL_EXCLUSIVE_DISJUNCTION][UNICODE]    = Unicode::XOR;
	table[SYMBOL_EXCLUSIVE_DISJUNCTION][ASCII]      = "_&";
	table[SYMBOL_EXCLUSIVE_DISJUNCTION][LATEX]      = "\\veebar";
	table[SYMBOL_EXCLUSIVE_DISJUNCTION][XML]        = "&veebar;";
	table[SYMBOL_NON_CONJUNCTION][UNICODE]          = Unicode::NAND;
	table[SYMBOL_NON_CONJUNCTION][ASCII]            = "-&";
	table[SYMBOL_NON_CONJUNCTION][LATEX]            = "\\barwedge";
	table[SYMBOL_NON_CONJUNCTION][XML]              = "";            // Not defined
	table[SYMBOL_NON_DISJUNCTION][UNICODE]          = Unicode::NOR;
	table[SYMBOL_NON_DISJUNCTION][ASCII]            = "-v";
	table[SYMBOL_NON_DISJUNCTION][LATEX]            = "\\overline{\\vee}";
	table[SYMBOL_NON_DISJUNCTION][XML]              = "&barvee;";
	table[SYMBOL_NON_IMPLICATION][UNICODE]          = Unicode::RIGHTWARDS_ARROW_WITH_STROKE;
	table[SYMBOL_NON_IMPLICATION][ASCII]            = "-/>";
	table[SYMBOL_NON_IMPLICATION][LATEX]            = "\\nrightarrow";
	table[SYMBOL_NON_IMPLICATION][XML]              = "&nrarr;";
	table[SYMBOL_NON_EQUIVALENCE][UNICODE]          = Unicode::LEFT_RIGHT_ARROW_WITH_STROKE;
	table[SYMBOL_NON_EQUIVALENCE][ASCII]            = "</->";
	table[SYMBOL_NON_EQUIVALENCE][LATEX]            = "\\nleftrightarrow";
	table[SYMBOL_NON_EQUIVALENCE][XML]              = "&nharr;";
	table[SYMBOL_CONVERSE_IMPLICATION][UNICODE]     = Unicode::LEFTWARDS_ARROW;
	table[SYMBOL_CONVERSE_IMPLICATION][ASCII]       = "<-";
	table[SYMBOL_CONVERSE_IMPLICATION][LATEX]       = "\\leftarrow";
	table[SYMBOL_CONVERSE_IMPLICATION][XML]         = "&larr;";
	table[SYMBOL_CONVERSE_NON_IMPLICATION][UNICODE] = Unicode::LEFTWARDS_ARROW_WITH_STROKE;
	table[SYMBOL_CONVERSE_NON_IMPLICATION][ASCII]   = "</-";
	table[SYMBOL_CONVERSE_NON_IMPLICATION][LATEX]   = "\\nleftarrow";
	table[SYMBOL_CONVERSE_NON_IMPLICATION][XML]     = "&nlarr;";

	table[SYMBOL_EMPTY_SET][UNICODE]                = Unicode::EMPTY_SET;
	table[SYMBOL_EMPTY_SET][ASCII]                  = "(/)";
	table[SYMBOL_EMPTY_SET][LATEX]                  = "\\varnothing";
	table[SYMBOL_EMPTY_SET][XML]                    = "&emptyset;";
	table[SYMBOL_UNION][UNICODE]                    = Unicode::UNION;
	table[SYMBOL_UNION][ASCII]                      = "(_)";
	table[SYMBOL_UNION][LATEX]                      = "\\cup";
	table[SYMBOL_UNION][XML]                        = "&cup;";
	table[SYMBOL_INTERSECTION][UNICODE]             = Unicode::INTERSECTION;
	table[SYMBOL_INTERSECTION][ASCII]               = "(^)";
	table[SYMBOL_INTERSECTION][LATEX]               = "\\cap";
	table[SYMBOL_INTERSECTION][XML]                 = "&cap;";
	table[SYMBOL_SUBSET][UNICODE]                   = Unicode::SUBSET_OF;
	table[SYMBOL_SUBSET][ASCII]                     = "(=";
	table[SYMBOL_SUBSET][LATEX]                     = "\\subset";
	table[SYMBOL_SUBSET][XML]                       = "&sub;";
	table[SYMBOL_SUPERSET][UNICODE]                 = Unicode::SUPERSET_OF;
	table[SYMBOL_SUPERSET][ASCII]                   = "=)";
	table[SYMBOL_SUPERSET][LATEX]                   = "\\supset";
	table[SYMBOL_SUPERSET][XML]                     = "&sup;";
	table[SYMBOL_SET_COMPLEMENT][UNICODE]           = Unicode::SET_MINUS;
	table[SYMBOL_SET_COMPLEMENT][ASCII]             = "\\";
	table[SYMBOL_SET_COMPLEMENT][LATEX]             = "\\backslash";
	table[SYMBOL_SET_COMPLEMENT][XML]               = "&setminus;";
	table[SYMBOL_NOT_SUBSET][UNICODE]               = Unicode::NOT_A_SUBSET_OF;
	table[SYMBOL_NOT_SUBSET][ASCII]                 = "(/=";
	table[SYMBOL_NOT_SUBSET][LATEX]                 = "\\nsubset";
	table[SYMBOL_NOT_SUBSET][XML]                   = "&nsub;";
	table[SYMBOL_NOT_SUPERSET][UNICODE]             = Unicode::NOT_A_SUPERSET_OF;
	table[SYMBOL_NOT_SUPERSET][ASCII]               = "=/)";
	table[SYMBOL_NOT_SUPERSET][LATEX]               = "\\nsupset";
	table[SYMBOL_NOT_SUPERSET][XML]                 = "&nsup;";
	table[SYMBOL_ELEMENT_OF][UNICODE]               = Unicode::ELEMENT_OF;
	table[SYMBOL_ELEMENT_OF][ASCII]                 = "(-";
	table[SYMBOL_ELEMENT_OF][LATEX]                 = "\\in";
	table[SYMBOL_ELEMENT_OF][XML]                   = "&isin;";
	table[SYMBOL_CONTAINS_AS_MEMBER][UNICODE]       = Unicode::CONTAINS_AS_MEMBER;
	table[SYMBOL_CONTAINS_AS_MEMBER][ASCII]         = "-)";
	table[SYMBOL_CONTAINS_AS_MEMBER][LATEX]         = "\\ni";
	table[SYMBOL_CONTAINS_AS_MEMBER][XML]           = "&niv;";
	table[SYMBOL_NOT_ELEMENT_OF][UNICODE]           = Unicode::NOT_AN_ELEMENT_OF;
	table[SYMBOL_NOT_ELEMENT_OF][ASCII]             = "(/-";
	table[SYMBOL_NOT_ELEMENT_OF][LATEX]             = "\\notin";
	table[SYMBOL_NOT_ELEMENT_OF][XML]               = "&notin;";
	table[SYMBOL_NOT_CONTAIN_AS_MEMBER][UNICODE]    = Unicode::DOES_NOT_CONTAIN_AS_MEMBER;
	table[SYMBOL_NOT_CONTAIN_AS_MEMBER][ASCII]      = "-/)";
	table[SYMBOL_NOT_CONTAIN_AS_MEMBER][LATEX]      = "\\notni";
	table[SYMBOL_NOT_CONTAIN_AS_MEMBER][XML]        = "&notni;";

	table[SYMBOL_TRUE][UNICODE]                     = Unicode::mathematical_bold_italic('t');
	table[SYMBOL_TRUE][ASCII]                       = "t";
	table[SYMBOL_TRUE][LATEX]                       = "\\boldsymbol{t}";
	table[SYMBOL_TRUE][XML]                         = "<em class=\"math\">t</em>";
	table[SYMBOL_TRUTH][UNICODE]                    = "T";
	table[SYMBOL_TRUTH][ASCII]                      = "T";
	table[SYMBOL_TRUTH][LATEX]                      = "T";
	table[SYMBOL_TRUTH][XML]                        = "T";
	table[SYMBOL_TAUTOLOGY][UNICODE]                = Unicode::DOWN_TACK;
	table[SYMBOL_TAUTOLOGY][ASCII]                  = "-|-";
	table[SYMBOL_TAUTOLOGY][LATEX]                  = "\\top";
	table[SYMBOL_TAUTOLOGY][XML]                    = "&top;";
	table[SYMBOL_FALSE][UNICODE]                    = Unicode::mathematical_bold_italic('f');
	table[SYMBOL_FALSE][ASCII]                      = "f";
	table[SYMBOL_FALSE][LATEX]                      = "\\boldsymbol{f}";
	table[SYMBOL_FALSE][XML]                        = "<em class=\"math\">f</em>";
	table[SYMBOL_FALSITY][UNICODE]                  = "F";
	table[SYMBOL_FALSITY][ASCII]                    = "F";
	table[SYMBOL_FALSITY][LATEX]                    = "F";
	table[SYMBOL_FALSITY][XML]                      = "F";
	table[SYMBOL_CONTRADICTION][UNICODE]            = Unicode::UP_TACK;
	table[SYMBOL_CONTRADICTION][ASCII]              = "_|_";
	table[SYMBOL_CONTRADICTION][LATEX]              = "\\bot";
	table[SYMBOL_CONTRADICTION][XML]                = "&bottom;";

	table[SYMBOL_UNIVERSAL_QUANTIFIER][UNICODE]     = Unicode::FOR_ALL;
	table[SYMBOL_UNIVERSAL_QUANTIFIER][ASCII]       = "@";
	table[SYMBOL_UNIVERSAL_QUANTIFIER][LATEX]       = "\\forall";
	table[SYMBOL_UNIVERSAL_QUANTIFIER][XML]         = "&forall;";
	table[SYMBOL_EXISTENTIAL_QUANTIFIER][UNICODE]   = Unicode::THERE_EXISTS;
	table[SYMBOL_EXISTENTIAL_QUANTIFIER][ASCII]     = "#";
	table[SYMBOL_EXISTENTIAL_QUANTIFIER][LATEX]     = "\\exists";
	table[SYMBOL_EXISTENTIAL_QUANTIFIER][XML]       = "&exist;";
	table[SYMBOL_EXISTS_NOT][UNICODE]               = Unicode::THERE_DOES_NOT_EXIST;
	table[SYMBOL_EXISTS_NOT][ASCII]                 = "/#";
	table[SYMBOL_EXISTS_NOT][LATEX]                 = "\\nexists";
	table[SYMBOL_EXISTS_NOT][XML]                   = "&nexist;";
	table[SYMBOL_UNIQUENESS_QUANTIFIER][UNICODE]    = Unicode::THERE_EXISTS;
	table[SYMBOL_UNIQUENESS_QUANTIFIER][UNICODE]   += '!';
	table[SYMBOL_UNIQUENESS_QUANTIFIER][ASCII]      = "#!";
	table[SYMBOL_UNIQUENESS_QUANTIFIER][LATEX]      = "\\exists!";
	table[SYMBOL_UNIQUENESS_QUANTIFIER][XML]        = "&exist;!";

	table[SYMBOL_N_ARY_CONJUNCTION][UNICODE]        = Unicode::N_ARY_LOGICAL_AND;
	table[SYMBOL_N_ARY_CONJUNCTION][ASCII]          = "&&";
	table[SYMBOL_N_ARY_CONJUNCTION][LATEX]          = "\\bigwedge";
	table[SYMBOL_N_ARY_CONJUNCTION][XML]            = "&Wedge;";
	table[SYMBOL_N_ARY_DISJUNCTION][UNICODE]        = Unicode::N_ARY_LOGICAL_OR;
	table[SYMBOL_N_ARY_DISJUNCTION][ASCII]          = "vv";
	table[SYMBOL_N_ARY_DISJUNCTION][LATEX]          = "\\bigvee";
	table[SYMBOL_N_ARY_DISJUNCTION][XML]            = "&Vee;";
	table[SYMBOL_N_ARY_INTERSECTION][UNICODE]       = Unicode::N_ARY_INTERSECTION;
	table[SYMBOL_N_ARY_INTERSECTION][ASCII]         = "(^^)";
	table[SYMBOL_N_ARY_INTERSECTION][LATEX]         = "\\bigcap";
	table[SYMBOL_N_ARY_INTERSECTION][XML]           = "&Intersection;";
	table[SYMBOL_N_ARY_UNION][UNICODE]              = Unicode::N_ARY_UNION;
	table[SYMBOL_N_ARY_UNION][ASCII]                = "(__)";
	table[SYMBOL_N_ARY_UNION][LATEX]                = "\\bigcup";
	table[SYMBOL_N_ARY_UNION][XML]                  = "&Union;";

	table[SYMBOL_POSSIBILITY][UNICODE]              = Unicode::DIAMOND_OPERATOR;
	table[SYMBOL_POSSIBILITY][ASCII]                = "<>";
	table[SYMBOL_POSSIBILITY][LATEX]                = "\\Diamond";
	table[SYMBOL_POSSIBILITY][XML]                  = "&diamond;";
	table[SYMBOL_NECESSITY][UNICODE]                = Unicode::ALWAYS;
	table[SYMBOL_NECESSITY][ASCII]                  = "[]";
	table[SYMBOL_NECESSITY][LATEX]                  = "\\Box";
	table[SYMBOL_NECESSITY][XML]                    = "&EmptySmallSquare;";

	table[SYMBOL_ELEMENT_SEPARATOR][UNICODE]        = ",";
	table[SYMBOL_ELEMENT_SEPARATOR][ASCII]          = ",";
	table[SYMBOL_ELEMENT_SEPARATOR][LATEX]          = ",";
	table[SYMBOL_ELEMENT_SEPARATOR][XML]            = ",";
	table[SYMBOL_PARENTHESIS_LEFT][UNICODE]         = "(";
	table[SYMBOL_PARENTHESIS_LEFT][ASCII]           = "(";
	table[SYMBOL_PARENTHESIS_LEFT][LATEX]           = "(";
	table[SYMBOL_PARENTHESIS_LEFT][XML]             = "(";
	table[SYMBOL_PARENTHESIS_RIGHT][UNICODE]        = ")";
	table[SYMBOL_PARENTHESIS_RIGHT][ASCII]          = ")";
	table[SYMBOL_PARENTHESIS_RIGHT][LATEX]          = ")";
	table[SYMBOL_PARENTHESIS_RIGHT][XML]            = ")";
	table[SYMBOL_SQUARE_BRACKET_LEFT][UNICODE]      = "[";
	table[SYMBOL_SQUARE_BRACKET_LEFT][ASCII]        = "[";
	table[SYMBOL_SQUARE_BRACKET_LEFT][LATEX]        = "[";
	table[SYMBOL_SQUARE_BRACKET_LEFT][XML]          = "[";
	table[SYMBOL_SQUARE_BRACKET_RIGHT][UNICODE]     = "]";
	table[SYMBOL_SQUARE_BRACKET_RIGHT][ASCII]       = "]";
	table[SYMBOL_SQUARE_BRACKET_RIGHT][LATEX]       = "]";
	table[SYMBOL_SQUARE_BRACKET_RIGHT][XML]         = "]";
	table[SYMBOL_CURLY_BRACKET_LEFT][UNICODE]       = "{";
	table[SYMBOL_CURLY_BRACKET_LEFT][ASCII]         = "{";
	table[SYMBOL_CURLY_BRACKET_LEFT][LATEX]         = "\\{";
	table[SYMBOL_CURLY_BRACKET_LEFT][XML]           = "{";
	table[SYMBOL_CURLY_BRACKET_RIGHT][UNICODE]      = "}";
	table[SYMBOL_CURLY_BRACKET_RIGHT][ASCII]        = "}";
	table[SYMBOL_CURLY_BRACKET_RIGHT][LATEX]        = "\\}";
	table[SYMBOL_CURLY_BRACKET_RIGHT][XML]          = "}";
	table[SYMBOL_ANGLE_BRACKET_LEFT][UNICODE]       = Unicode::MATHEMATICAL_LEFT_ANGLE_BRACKET;
	table[SYMBOL_ANGLE_BRACKET_LEFT][ASCII]         = "<";
	table[SYMBOL_ANGLE_BRACKET_LEFT][LATEX]         = "\\langle";
	table[SYMBOL_ANGLE_BRACKET_LEFT][XML]           = "&lang;";
	table[SYMBOL_ANGLE_BRACKET_RIGHT][UNICODE]      = Unicode::MATHEMATICAL_RIGHT_ANGLE_BRACKET;
	table[SYMBOL_ANGLE_BRACKET_RIGHT][ASCII]        = ">";
	table[SYMBOL_ANGLE_BRACKET_RIGHT][LATEX]        = "\\rangle";
	table[SYMBOL_ANGLE_BRACKET_RIGHT][XML]          = "&rang;";
	table[SYMBOL_PRECEDENCE_DOT][UNICODE]           = ".";
	table[SYMBOL_PRECEDENCE_DOT][ASCII]             = ".";
	table[SYMBOL_PRECEDENCE_DOT][LATEX]             = ".";
	table[SYMBOL_PRECEDENCE_DOT][XML]               = ".";

	table[SYMBOL_TURNSTILE][UNICODE]                = Unicode::RIGHT_TACK;
	table[SYMBOL_TURNSTILE][ASCII]                  = "|-";
	table[SYMBOL_TURNSTILE][LATEX]                  = "\\vdash";
	table[SYMBOL_TURNSTILE][XML]                    = "&vdash;";
	table[SYMBOL_DOUBLE_TURNSTILE][UNICODE]         = Unicode::VALID;
	table[SYMBOL_DOUBLE_TURNSTILE][ASCII]           = "|=";
	table[SYMBOL_DOUBLE_TURNSTILE][LATEX]           = "\\vDash";
	table[SYMBOL_DOUBLE_TURNSTILE][XML]             = "&vDash;";
	table[SYMBOL_TURNSTILE_NOT][UNICODE]            = Unicode::DOES_NOT_PROVE;
	table[SYMBOL_TURNSTILE_NOT][ASCII]              = "|/-";
	table[SYMBOL_TURNSTILE_NOT][LATEX]              = "\\nvdash";
	table[SYMBOL_TURNSTILE_NOT][XML]                = "&nvdash;";
	table[SYMBOL_DOUBLE_TURNSTILE_NOT][UNICODE]     = Unicode::NOT_TRUE;
	table[SYMBOL_DOUBLE_TURNSTILE_NOT][ASCII]       = "|/=";
	table[SYMBOL_DOUBLE_TURNSTILE_NOT][LATEX]       = "\\nvDash";
	table[SYMBOL_DOUBLE_TURNSTILE_NOT][XML]         = "&nvDash;";

	table[SYMBOL_META_NEGATION][UNICODE]            = Unicode::TILDE_OPERATOR;
	table[SYMBOL_META_NEGATION][ASCII]              = "~";
	table[SYMBOL_META_NEGATION][LATEX]              = "\\sim";
	table[SYMBOL_META_NEGATION][XML]                = "&sim;";
	table[SYMBOL_META_IMPLICATION][UNICODE]         = Unicode::RIGHTWARDS_DOUBLE_ARROW;
	table[SYMBOL_META_IMPLICATION][ASCII]           = "=>";
	table[SYMBOL_META_IMPLICATION][LATEX]           = "\\Rightarrow";
	table[SYMBOL_META_IMPLICATION][XML]             = "&rArr;";
	table[SYMBOL_META_CONJUNCTION][UNICODE]         = "&";
	table[SYMBOL_META_CONJUNCTION][ASCII]           = "$&";
	table[SYMBOL_META_CONJUNCTION][LATEX]           = "\\&";
	table[SYMBOL_META_CONJUNCTION][XML]             = "&amp;";
	table[SYMBOL_META_DISJUNCTION][UNICODE]         = "/";
	table[SYMBOL_META_DISJUNCTION][ASCII]           = "$v";
	table[SYMBOL_META_DISJUNCTION][LATEX]           = "/";
	table[SYMBOL_META_DISJUNCTION][XML]             = "/";
	table[SYMBOL_META_BICONDITIONAL][UNICODE]       = Unicode::LEFT_RIGHT_DOUBLE_ARROW;
	table[SYMBOL_META_BICONDITIONAL][ASCII]         = "<=>";
	table[SYMBOL_META_BICONDITIONAL][LATEX]         = "\\Leftrightarrow";
	table[SYMBOL_META_BICONDITIONAL][XML]           = "&hArr;";

	table[SYMBOL_THEREFORE][UNICODE]                = Unicode::THEREFORE;
	table[SYMBOL_THEREFORE][ASCII]                  = ":.";
	table[SYMBOL_THEREFORE][LATEX]                  = "\\therefore";
	table[SYMBOL_THEREFORE][XML]                    = "&therefore;";
	table[SYMBOL_BECAUSE][UNICODE]                  = Unicode::BECAUSE;
	table[SYMBOL_BECAUSE][ASCII]                    = ".:";
	table[SYMBOL_BECAUSE][LATEX]                    = "\\because";
	table[SYMBOL_BECAUSE][XML]                      = "&because;";
	table[SYMBOL_STRICT_IMPLICATION][UNICODE]       = Unicode::RIGHT_FISH_TAIL;
	table[SYMBOL_STRICT_IMPLICATION][ASCII]         = "-}";
	table[SYMBOL_STRICT_IMPLICATION][LATEX]         = "\\strictif";  // in packages: txfonts, pxfonts
	table[SYMBOL_STRICT_IMPLICATION][XML]           = "&rfisht;";
	table[SYMBOL_ASTERISK_OPERATOR][UNICODE]        = Unicode::ASTERISK_OPERATOR;
	table[SYMBOL_ASTERISK_OPERATOR][ASCII]          = "*";
	table[SYMBOL_ASTERISK_OPERATOR][LATEX]          = "\\ast";
	table[SYMBOL_ASTERISK_OPERATOR][XML]            = "&lowast;";
	table[SYMBOL_END_OF_PROOF][UNICODE]             = Unicode::END_OF_PROOF;
	table[SYMBOL_END_OF_PROOF][ASCII]               = ";;";
	table[SYMBOL_END_OF_PROOF][LATEX]               = "";        // automatically added in proof mode
	table[SYMBOL_END_OF_PROOF][XML]                 = "";        // not defined
}


Glib::ustring
SymbolTable::print_table() const
{
	Glib::ustring  output;

	for (int i = SYMBOL_NEGATION; i < SYMBOL_MAX; ++i) {
		for (int j = 0; j < REPR_MAX; j++) {
			output += table[i][j];
			if (j < REPR_MAX - 1) {
				output += "\t";
			}
			else {
				output += "\n";
			}
		}
	}
	return output;
}


SymbolName
SymbolTable::get_name(Glib::ustring const& glyph) const
{
	for (int name = 0; name < SYMBOL_MAX; ++name) {
		for (int repr = 0; repr < 4; ++repr) {
			if (table[name][repr] == glyph) {
				return (SymbolName) name;
			}
		}
	}

	// Check if it is a valid variable name
	if (Glib::Unicode::isalpha(glyph[0])) {
		if (!glyph[1]) {
			return SYMBOL_VARIABLE;
		}
		else if (glyph[1] == '_' && glyph[2]) {
			for (int i = 2; i < glyph.length(); i++) {
				if (!Glib::Unicode::isdigit(glyph[i])) {
					return SYMBOL_NONE;
				}
			}
			return SYMBOL_VARIABLE;
		}
		else {
			for (int i = 1; i < glyph.length(); i++) {
				if (!Glib::Unicode::isdigit(glyph[i])) {
					return SYMBOL_NONE;
				}
			}
			return SYMBOL_VARIABLE;
		}
	}
	return SYMBOL_NONE;
}


const Glib::ustring
SymbolTable::get_glyph (SymbolName name, SymbolRepr repr) const
{
	return table[name][repr];
}


SymbolsDefined::SymbolsDefined()
{
	flags = 0;
}


SymbolsDefined::SymbolsDefined (const int symbols)
{
	flags = symbols;
}


void
SymbolsDefined::set_symbol (const SymbolName name)
{
	flags.set(name);
}


void
SymbolsDefined::reset_symbol (const SymbolName name)
{
	flags.reset(name);
}


bool
SymbolsDefined::is_set (const SymbolName name) const
{
	return flags[name];
}

} /* namespace Logics */
