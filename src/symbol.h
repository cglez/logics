/*
 * symbol.h
 * This file is part of logics
 *
 * Copyright (C) 2014 - César González <ceguel@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <bitset>
#include <map>
#include <vector>
#include <glibmm/ustring.h>
#include <glibmm/unicode.h>
#include "unicode.h"

namespace Logics
{

/** Symbol types */
enum SymbolType {
	SYMBOL_TYPE_NONE = 0,
	SYMBOL_TYPE_TERM,
	SYMBOL_TYPE_OPERATOR,
	SYMBOL_TYPE_AUXILIARY
};


/** Symbols */
enum SymbolName {
	SYMBOL_NONE = 0,                             //< Unknown
	SYMBOL_CUSTOM,                               //< Custom symbol

	SYMBOL_VARIABLE,                             //< Variable

	SYMBOL_NEGATION,                             //< Negation, NOT
	SYMBOL_NOT = SYMBOL_NEGATION,
	SYMBOL_IMPLICATION,                          //< (Material) implication, (truth-functional) conditional
	SYMBOL_CONDITIONAL = SYMBOL_IMPLICATION,
	SYMBOL_CONJUNCTION,                          //< Conjunction, AND
	SYMBOL_AND = SYMBOL_CONJUNCTION,
	SYMBOL_DISJUNCTION,                          //< (Inclusive) disjunction, alternation, OR
	SYMBOL_ALTERNATION = SYMBOL_DISJUNCTION,
	SYMBOL_OR = SYMBOL_DISJUNCTION,
	SYMBOL_BICONDITIONAL,                        //< (Material) equivalence, (truth-functional) biconditional
	SYMBOL_EQUIVALENCE = SYMBOL_BICONDITIONAL,
	SYMBOL_EXCLUSIVE_DISJUNCTION,                //< Exclusive disjunction, EXOR, XOR, (material) non-equivalence
	SYMBOL_EXOR = SYMBOL_EXCLUSIVE_DISJUNCTION,
	SYMBOL_XOR = SYMBOL_EXCLUSIVE_DISJUNCTION,
	SYMBOL_NON_CONJUNCTION,                      //< Non-conjunction, NAND
	SYMBOL_NAND = SYMBOL_NON_CONJUNCTION,
	SYMBOL_NON_DISJUNCTION,                      //< Non-disjunction, NOR
	SYMBOL_NOR = SYMBOL_NON_DISJUNCTION,
	SYMBOL_NON_IMPLICATION,                      //< (Material) non-implication
	SYMBOL_NON_EQUIVALENCE,                      //< Non-equivalence
	SYMBOL_CONVERSE_IMPLICATION,                 //< Converse implication
	SYMBOL_CONVERSE_NON_IMPLICATION,             //< Converse non-implication

	SYMBOL_EMPTY_SET,                            //< Empty set
	SYMBOL_UNION,                                //< Union
	SYMBOL_INTERSECTION,                         //< Intersection
	SYMBOL_SUBSET,                               //< Subset of, included in
	SYMBOL_INCLUDED = SYMBOL_SUBSET,
	SYMBOL_SUPERSET,                             //< Superset of, includes in set
	SYMBOL_INCLUDES = SYMBOL_SUPERSET,
	SYMBOL_SET_COMPLEMENT,                       //< Set complement
	SYMBOL_NOT_SUBSET,                           //< Not a subset of, not included in
	SYMBOL_NOT_INCLUDED = SYMBOL_NOT_SUBSET,
	SYMBOL_NOT_SUPERSET,                         //< Not a superset of, not includes in set
	SYMBOL_NOT_INCLUDES = SYMBOL_NOT_SUPERSET,
	SYMBOL_ELEMENT_OF,                           //< Element of, in
	SYMBOL_IN = SYMBOL_ELEMENT_OF,
	SYMBOL_CONTAINS_AS_MEMBER,                   //< Contains as member
	SYMBOL_NOT_ELEMENT_OF,                       //< Not an element of, not in
	SYMBOL_NOT_IN = SYMBOL_NOT_ELEMENT_OF,
	SYMBOL_NOT_CONTAIN_AS_MEMBER,                //< Does not contain as member

	SYMBOL_N_ARY_CONJUNCTION,                    //< N-ary conjunction, n-ary AND
	SYMBOL_N_ARY_AND = SYMBOL_N_ARY_CONJUNCTION,
	SYMBOL_N_ARY_DISJUNCTION,                    //< N-ary disjunction, n-ary OR
	SYMBOL_N_ARY_OR = SYMBOL_N_ARY_DISJUNCTION,
	SYMBOL_N_ARY_INTERSECTION,                   //< N-ary intersection
	SYMBOL_N_ARY_UNION,                          //< N-ary union

	SYMBOL_TRUE,                                 //< True
	SYMBOL_TRUTH,                                //< Truth
	SYMBOL_TAUTOLOGY,                            //< Tautology
	SYMBOL_FALSE,                                //< False
	SYMBOL_FALSITY,                              //< Falsity
	SYMBOL_CONTRADICTION,                        //< Contradiction

	SYMBOL_UNIVERSAL_QUANTIFIER,                 //< Universal quantifier, for all
	SYMBOL_FORALL = SYMBOL_UNIVERSAL_QUANTIFIER,
	SYMBOL_EXISTENTIAL_QUANTIFIER,               //< Existential quantifier, there exists
	SYMBOL_EXISTS = SYMBOL_EXISTENTIAL_QUANTIFIER,
	SYMBOL_EXISTENTIAL_QUANTIFIER_NOT,           //< Negated universal quantifier, there does not exist
	SYMBOL_EXISTS_NOT = SYMBOL_EXISTENTIAL_QUANTIFIER_NOT,
	SYMBOL_UNIQUENESS_QUANTIFIER,                //< Uniqueness quantifier, there is only one */

	SYMBOL_POSSIBILITY,                          //< Possibility operator
	SYMBOL_NECESSITY,                            //< Necessity operator

	SYMBOL_ELEMENT_SEPARATOR,                    //< Element separator
	SYMBOL_PARENTHESIS_LEFT,                     //< Left parenthesis
	SYMBOL_PARENTHESIS_RIGHT,                    //< Right parenthesis
	SYMBOL_SQUARE_BRACKET_LEFT,                  //< Left (square) bracket
	SYMBOL_BRACKET_LEFT = SYMBOL_SQUARE_BRACKET_LEFT,
	SYMBOL_SQUARE_BRACKET_RIGHT,                 //< Right (square) bracket
	SYMBOL_BRACKET_RIGHT = SYMBOL_SQUARE_BRACKET_RIGHT,
	SYMBOL_CURLY_BRACKET_LEFT,                   //< Left curly bracket, left brace
	SYMBOL_BRACE_LEFT = SYMBOL_CURLY_BRACKET_LEFT,
	SYMBOL_CURLY_BRACKET_RIGHT,                  //< Right curly bracket, right brace
	SYMBOL_BRACE_RIGHT = SYMBOL_CURLY_BRACKET_RIGHT,
	SYMBOL_ANGLE_BRACKET_LEFT,                   //< Left angle bracket
	SYMBOL_ANGLE_BRACKET_RIGHT,                  //< Right angle bracket
	SYMBOL_PRECEDENCE_DOT,                       //< Precedence point, heavy dot (Peano)
	SYMBOL_HEAVY_DOT = SYMBOL_PRECEDENCE_DOT,

	SYMBOL_TURNSTILE,                            //< Turnstile, proves, implies, yields
	SYMBOL_PROVES = SYMBOL_TURNSTILE,
	SYMBOL_IMPLIES = SYMBOL_TURNSTILE,
	SYMBOL_YIELDS = SYMBOL_TURNSTILE,
	SYMBOL_DOUBLE_TURNSTILE,                     //< Double turnstile, valid, satisfies
	SYMBOL_VALID = SYMBOL_DOUBLE_TURNSTILE,
	SYMBOL_SATISFIES = SYMBOL_DOUBLE_TURNSTILE,
	SYMBOL_TURNSTILE_NOT,                        //< Negated turnstile, does not prove, does not imply, does not yield
	SYMBOL_PROVES_NOT = SYMBOL_TURNSTILE_NOT,
	SYMBOL_IMPLIES_NOT = SYMBOL_TURNSTILE_NOT,
	SYMBOL_YIELDS_NOT = SYMBOL_TURNSTILE_NOT,
	SYMBOL_DOUBLE_TURNSTILE_NOT,                 //< Negated double tursntile, not valid, does not satisfy
	SYMBOL_VALID_NOT = SYMBOL_DOUBLE_TURNSTILE_NOT,
	SYMBOL_SATISFIES_NOT = SYMBOL_DOUBLE_TURNSTILE_NOT,

	//SYMBOL_META_VARIABLE,                        //< Meta-linguistic variable
	SYMBOL_META_NEGATION,                        //< Meta-linguistic negation
	SYMBOL_META_IMPLICATION,                     //< Meta-linguistic implication
	SYMBOL_META_CONJUNCTION,                     //< Meta-linguistic conjunction
	SYMBOL_META_DISJUNCTION,                     //< Meta-linguistic disjunction
	SYMBOL_META_BICONDITIONAL,                   //< Meta-linguistic biconditional

	SYMBOL_THEREFORE,                            //< Therefore
	SYMBOL_BECAUSE,                              //< Because
	SYMBOL_STRICT_IMPLICATION,                   //< Strict implication, Lewis' hook
	SYMBOL_LEWIS_HOOK = SYMBOL_STRICT_IMPLICATION,
	SYMBOL_ASTERISK_OPERATOR,                    //< Asterisk operator
	SYMBOL_ASTERISK = SYMBOL_ASTERISK_OPERATOR,
	SYMBOL_END_OF_PROOF,                         //< End of proof, Q.E.D.
	SYMBOL_QED = SYMBOL_END_OF_PROOF,
	SYMBOL_MAX
};

SymbolName  get_symbol_name  (Glib::ustring const&  glyph);
SymbolType  get_symbol_type  (SymbolName            name);
SymbolType  get_symbol_type  (Glib::ustring const&  glyph);


enum SymbolRepr {
	UNICODE = 0,
	ASCII,
	LATEX,
	XML,
	REPR_MAX
};


class SymbolTable
{
public:
	SymbolTable();
	const Glib::ustring  get_glyph    (SymbolName  name,
	                                   SymbolRepr  repr)             const;
	SymbolName           get_name     (Glib::ustring  const& glyph)  const;
	Glib::ustring        print_table  (void)                         const;
private:
	//std::map<SymbolName, std::vector<Glib::ustring> > table;
	Glib::ustring        table[SYMBOL_MAX][REPR_MAX];
};


class SymbolsDefined
{
public:
	SymbolsDefined();
	SymbolsDefined(int symbols);
	void  set_symbol    (SymbolName name);
	void  reset_symbol  (SymbolName name);
	bool  is_set        (SymbolName name)  const;
private:
	std::bitset<SYMBOL_MAX>  flags;
};


class Symbol
{
public:
	Symbol();
	Symbol(SymbolName  name);
	Symbol(const gunichar  glyph);
	Symbol(Glib::ustring const&  glyph);
	bool                 operator<   (Symbol const&         rop)     const;
	bool                 operator>   (Symbol const&         rop)     const;
	bool                 operator==  (Symbol const&         rop)     const;
	bool                 operator!=  (Symbol const&         rop)     const;
	void                 set_glyph   (Glib::ustring const&  glyph);
	const Glib::ustring  get_glyph()                                 const;
	SymbolName           get_name()                                  const;
	SymbolType           get_type()                                  const;
	bool                 is_custom()                                 const;
	int                  precedence()                                const;
	int                  lenght()                                    const;
private:
	Glib::ustring        glyph;
	SymbolName           name;
	SymbolType           type;
	void                 set_glyph();
	void                 set_name();
	void                 set_type();
};

} /* namespace Logics */

#endif /* SYMBOL_H_ */
