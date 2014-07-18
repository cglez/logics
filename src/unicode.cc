/*
 * unicode.cc
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU
 * Lesser General Public License for more details.
 */

#include "unicode.h"

namespace Unicode
{

const gunichar
fullwidth  (const char  c)
{
	if (c >= 0x21 && c <= 0x7E) {
		return 0xFF00 - 0x20 + c;
	}
	else {
		return 0;
	}
}


Glib::ustring
fullwidth  (const Glib::ustring&  str)
{
	Glib::ustring  output = "";

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it >= 0x21 && *it <= 0x7E) {
			output += (gunichar) 0xFF00 - 0x20 + *it;
		}
		else {
			return "";
		}
	}

	return output;
}


const gunichar
superscript  (const char  c)
{
	if (c >= '4' && c<= '9') {
		return 0x2074 - '4' + c;
	}
	switch (c) {
		case '0':
			return 0x2070;
		case '1':
			return 0x00B9;
		case '2':
			return 0x00B2;
		case '3':
			return 0x00B3;
		case 'i':
			return 0x2071;
		case '+':
			return 0x207A;
		case '-':
			return 0x207B;
		case '=':
			return 0x207C;
		case '(':
			return 0x207D;
		case ')':
			return 0x207E;
		case 'n':
			return 0x207F;
		default:
			return 0;
	}
}


Glib::ustring
superscript  (const Glib::ustring&  str)
{
	Glib::ustring output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += superscript(*it);
	}

	return output;
}


Glib::ustring
superscript_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l < 0) {
		is_negative = true;
		l = -l;
	}

	do {
		output.insert(output.begin(), superscript((char) ('0' + l % 10)));
	}	while (l /= 10);

	if (is_negative) {
		output.insert(output.begin(), superscript('-'));
	}

	return output;
}


const gunichar
subscript  (const char  c)
{
	if (Glib::Ascii::isdigit(c)) {
		return 0x2080 - '0' + c;
	}
	switch (c) {
		case '+':
			return 0x208A;
		case '-':
			return 0x208B;
		case '=':
			return 0x208C;
		case '(':
			return 0x208D;
		case ')':
			return 0x208E;
		case 'a':
			return 0x2090;
		case 'e':
			return 0x2091;
		case 'h':
			return 0x2095;
		case 'i':
			return 0x1D62;
		case 'j':
			return 0x2C7C;
		case 'k':
			return 0x2096;
		case 'l':
			return 0x2097;
		case 'm':
			return 0x2098;
		case 'n':
			return 0x2099;
		case 'o':
			return 0x2092;
		case 'p':
			return 0x209A;
		case 'r':
			return 0x1D63;
		case 's':
			return 0x209B;
		case 't':
			return 0x209C;
		case 'u':
			return 0x1D64;
		case 'v':
			return 0x1D65;
		default:
			return 0;
	}
}


Glib::ustring
subscript  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += subscript(*it);
	}

	return output;
}


Glib::ustring
subscript_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l < 0) {
		is_negative = true;
		l = -l;
	}

	do {
		output.insert(output.begin(), subscript((char) ('0' + l % 10)));
	}	while (l /= 10);

	if (is_negative) {
		output.insert(output.begin(), subscript('-'));
	}

	return output;
}


const gunichar
mathematical_bold  (const char  c)
{
	if (c >= '0' && c <= '9') {
		return 0x1D7CE - '0' + c;
	}
	else if (c >= 'A' && c <= 'Z') {
		return 0x1D400 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D41A - 'a' + c;
	}
	else {
		return 0;
	}
}


const gunichar
mathematical_bold  (const gunichar  uc)
{
	if (Glib::Unicode::isdefined(uc)) {
		if (Glib::Ascii::isalnum((char) uc)) {
			return mathematical_bold ((char) uc);
		}
		else if (uc >= GREEK_CAPITAL_LETTER_ALPHA && uc <= GREEK_CAPITAL_LETTER_OMEGA) {
			return 0x1D6A8 - GREEK_CAPITAL_LETTER_ALPHA + uc;
		}
		else if (uc >= GREEK_SMALL_LETTER_ALPHA && uc <= GREEK_SMALL_LETTER_OMEGA) {
			return 0x1D6C2 - GREEK_SMALL_LETTER_ALPHA + uc;
		}
		switch (uc) {
			case GREEK_CAPITAL_THETA_SYMBOL:
				return 0x1D6B9;
			case NABLA:
				return 0x1D6C1;
			case PARTIAL_DIFFERENTIAL:
				return 0x1D6DB;
			case GREEK_LUNATE_EPSILON_SYMBOL:
				return 0x1D6DC;
			case GREEK_THETA_SYMBOL:
				return 0x1D6DD;
			case GREEK_KAPPA_SYMBOL:
				return 0x1D6DE;
			case GREEK_PHI_SYMBOL:
				return 0x1D6DF;
			case GREEK_RHO_SYMBOL:
				return 0x1D6E0;
			case GREEK_PI_SYMBOL:
				return 0x1D6E1;
			case GREEK_LETTER_DIGAMMA:
				return 0x1D7CA;
			case GREEK_SMALL_LETTER_DIGAMMA:
				return 0x1D7CB;
			default:
				return 0;
		}
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_bold  (const Glib::ustring&  str)
{
	Glib::ustring  output = "";

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it)
			output += mathematical_bold(*it);
	}

	return output;
}


Glib::ustring
mathematical_bold_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l == 0) {
		output = mathematical_bold('0');
	}
	else {
		if (l < 0) {
			is_negative = true;
			l = -l;
		}
		while (l) {
			output.insert(output.begin(), mathematical_bold((char) ('0' + l % 10)));
			l /= 10;
		}
		if (is_negative) {
			output.insert(output.begin(), HEAVY_MINUS_SIGN);
		}
	}

	return output;
}


const gunichar
mathematical_italic  (const char  c)
{
	if (c >= 'A' && c <= 'Z') {
		return 0x1D434 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'g') {
		return 0x1D44E - 'a' + c;
	}
	else if (c == 'h') {
		return PLANK_CONSTANT;
	}
	else if (c >= 'i' && c <= 'z') {
		return 0x1D456 - 'i' + c;
	}
	else {
		return 0;
	}
}


const gunichar
mathematical_italic  (const gunichar  uc)
{
	if (Glib::Unicode::isdefined(uc)) {
		if (Glib::Ascii::isalnum((char) uc)) {
			return mathematical_italic ((char) uc);
		}
		else if (uc >= GREEK_CAPITAL_LETTER_ALPHA && uc <= GREEK_CAPITAL_LETTER_OMEGA) {
			return 0x1D6E2 - GREEK_CAPITAL_LETTER_ALPHA + uc;
		}
		else if (uc >= GREEK_SMALL_LETTER_ALPHA && uc <= GREEK_SMALL_LETTER_OMEGA) {
			return 0x1D6FC - GREEK_SMALL_LETTER_ALPHA + uc;
		}
		switch (uc) {
			case GREEK_CAPITAL_THETA_SYMBOL:
				return 0x1D6F3;
			case NABLA:
				return 0x1D6FB;
			case PARTIAL_DIFFERENTIAL:
				return 0x1D715;
			case GREEK_LUNATE_EPSILON_SYMBOL:
				return 0x1D716;
			case GREEK_THETA_SYMBOL:
				return 0x1D717;
			case GREEK_KAPPA_SYMBOL:
				return 0x1D718;
			case GREEK_PHI_SYMBOL:
				return 0x1D719;
			case GREEK_RHO_SYMBOL:
				return 0x1D71A;
			case GREEK_PI_SYMBOL:
				return 0x1D71B;
			default:
				return 0;
		}
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_italic  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_italic(*it);
	}

	return output;
}


const gunichar
mathematical_bold_italic  (const char  c)
{
	if (c >= 'A' && c <= 'Z') {
		return 0x1D468 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D482 - 'a' + c;
	}
	else {
		return 0;
	}
}


const gunichar
mathematical_bold_italic  (const gunichar  uc)
{
	if (Glib::Unicode::isdefined(uc)) {
		if (Glib::Ascii::isalnum((char) uc)) {
			return mathematical_bold ((char) uc);
		}
		else if (uc >= GREEK_CAPITAL_LETTER_ALPHA && uc <= GREEK_CAPITAL_LETTER_OMEGA) {
			return 0x1D71C - GREEK_CAPITAL_LETTER_ALPHA + uc;
		}
		else if (uc >= GREEK_SMALL_LETTER_ALPHA && uc <= GREEK_SMALL_LETTER_OMEGA) {
			return 0x1D736 - GREEK_SMALL_LETTER_ALPHA + uc;
		}
		switch (uc) {
			case GREEK_CAPITAL_THETA_SYMBOL:
				return 0x1D72D;
			case NABLA:
				return 0x1D735;
			case PARTIAL_DIFFERENTIAL:
				return 0x1D74F;
			case GREEK_LUNATE_EPSILON_SYMBOL:
				return 0x1D750;
			case GREEK_THETA_SYMBOL:
				return 0x1D751;
			case GREEK_KAPPA_SYMBOL:
				return 0x1D752;
			case GREEK_PHI_SYMBOL:
				return 0x1D753;
			case GREEK_RHO_SYMBOL:
				return 0x1D754;
			case GREEK_PI_SYMBOL:
				return 0x1D755;
			default:
				return 0;
		}
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_bold_italic  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_bold_italic(*it);
	}

	return output;
}


const gunichar
mathematical_script  (const char  c)
{
	if (c >= 'N' && c <= 'Q') {
		return 0x1D4A9 - 'N' + c;
	}
	else if (c >= 'S' && c <= 'Z') {
		return 0x1D4AE - 'S' + c;
	}
	else if (c >= 'a' && c <= 'd') {
		return 0x1D4B6 - 'a' + c;
	}
	else if (c >= 'h' && c <= 'n') {
		return 0x1D4BD - 'h' + c;
	}
	else if (c >= 'p' && c <= 'z') {
		return 0x1D4C5 - 'p' + c;
	}
	switch (c) {
		case 'A':
			return 0x1D49C;
		case 'B':
			return SCRIPT_CAPITAL_B;
		case 'C':
			return 0x1D49E;
		case 'D':
			return 0x1D49F;
		case 'E':
			return SCRIPT_CAPITAL_E;
		case 'F':
			return SCRIPT_CAPITAL_F;
		case 'G':
			return 0x1D4A2;
		case 'H':
			return SCRIPT_CAPITAL_H;
		case 'I':
			return SCRIPT_CAPITAL_I;
		case 'J':
			return 0x1D4A5;
		case 'K':
			return 0x1D4A6;
		case 'L':
			return SCRIPT_CAPITAL_L;
		case 'M':
			return SCRIPT_CAPITAL_M;
		case 'e':
			return SCRIPT_SMALL_E;
		case 'f':
			return 0x1D4BA;
		case 'g':
			return SCRIPT_SMALL_G;
		case 'o':
			return SCRIPT_SMALL_O;
		default:
			return 0;
	}
}


Glib::ustring
mathematical_script  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_script(*it);
	}

	return output;
}


const gunichar
mathematical_bold_script  (const char  c)
{
	if (c >= 'A' && c <= 'Z') {
		return 0x1D4D0 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D4EA - 'a' + c;
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_bold_script  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_bold_script(*it);
	}

	return output;
}


const gunichar
mathematical_fraktur  (const char  c)
{
	if (c >= 'D' && c <= 'G') {
		return 0x1D507 - 'D' + c;
	}
	else if (c >= 'J' && c <= 'Q') {
		return 0x1D50D - 'J' + c;
	}
	else if (c >= 'S' && c <= 'Y') {
		return 0x1D516 - 'S' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D51E - 'a' + c;
	}
	switch (c) {
		case 'A':
			return 0x1D504;
		case 'B':
			return 0x1D505;
		case 'C':
			return BLACK_LETTER_CAPITAL_C;
		case 'H':
			return BLACK_LETTER_CAPITAL_H;
		case 'I':
			return BLACK_LETTER_CAPITAL_I;
		case 'R':
			return BLACK_LETTER_CAPITAL_R;
		case 'Z':
			return BLACK_LETTER_CAPITAL_Z;
	}
}


Glib::ustring
mathematical_fraktur  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_fraktur(*it);
	}

	return output;
}


const gunichar
mathematical_double_struck  (const char  c)
{
	if (c >= '0' && c <= '9') {
		return 0x1D7D8 - '0' + c;
	}
	else if (c >= 'D' && c <= 'G') {
		return 0x1D53B - 'D' + c;
	}
	else if (c >= 'I' && c <= 'M') {
		return 0x1D540 - 'I' + c;
	}
	else if (c >= 'S' && c <= 'Y') {
		return 0x1D54A - 'S' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D552 - 'a' + c;
	}
	switch (c) {
		case 'A':
			return 0x1D538;
		case 'B':
			return 0x1D539;
		case 'C':
			return DOUBLE_STRUCK_CAPITAL_C;
		case 'H':
			return DOUBLE_STRUCK_CAPITAL_H;
		case 'N':
			return DOUBLE_STRUCK_CAPITAL_N;
		case 'O':
			return 0x1D546;
		case 'P':
			return DOUBLE_STRUCK_CAPITAL_P;
		case 'Q':
			return DOUBLE_STRUCK_CAPITAL_Q;
		case 'R':
			return DOUBLE_STRUCK_CAPITAL_R;
		case 'Z':
			return DOUBLE_STRUCK_CAPITAL_Z;
		default:
			return 0;
	}
}


Glib::ustring
mathematical_double_struck  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_double_struck(*it);
	}

	return output;
}


Glib::ustring
mathematical_double_struck_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l == 0) {
		output = mathematical_double_struck('0');
	}
	else {
		if (l < 0) {
			is_negative = true;
			l = -l;
		}
		while (l) {
			output.insert(output.begin(), mathematical_double_struck((char) ('0' + l % 10)));
			l /= 10;
		}
		if (is_negative) {
			output.insert(output.begin(), MINUS_SIGN);
		}
	}

	return output;
}


const gunichar
mathematical_bold_fraktur  (const char  c)
{
	if (c >= 'A' && c <= 'Z') {
		return 0x1D56C - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D586 - 'a' + c;
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_bold_fraktur  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_bold_fraktur(*it);
	}

	return output;
}


const gunichar
mathematical_sans_serif  (const char  c)
{
	if (c >= '0' && c <= '9') {
		return 0x1D7E2 - '0' + c;
	}
	else if (c >= 'A' && c <= 'Z') {
		return 0x1D5A0 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D5BA - 'a' + c;
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_sans_serif  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_sans_serif(*it);
	}

	return output;
}


Glib::ustring
mathematical_sans_serif_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l == 0) {
		output = mathematical_sans_serif('0');
	}
	else {
		if (l < 0) {
			is_negative = true;
			l = -l;
		}
		while (l) {
			output.insert(output.begin(), mathematical_sans_serif((char) ('0' + l % 10)));
			l /= 10;
		}
		if (is_negative) {
			output.insert(output.begin(), MINUS_SIGN);
		}
	}

	return output;
}


const gunichar
mathematical_sans_serif_bold  (const char  c)
{
	if (c >= '0' && c <= '9') {
		return 0x1D7EC - '0' + c;
	}
	else if (c >= 'A' && c <= 'Z') {
		return 0x1D5D4 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D5EE - 'a' + c;
	}
	else {
		return 0;
	}
}


const gunichar
mathematical_sans_serif_bold  (const gunichar  uc)
{
	if (Glib::Unicode::isdefined(uc)) {
		if (Glib::Ascii::isalnum((char) uc)) {
			return mathematical_sans_serif_bold ((char) uc);
		}
		else if (uc >= GREEK_CAPITAL_LETTER_ALPHA && uc <= GREEK_CAPITAL_LETTER_OMEGA) {
			return 0x1D756 - GREEK_CAPITAL_LETTER_ALPHA + uc;
		}
		else if (uc >= GREEK_SMALL_LETTER_ALPHA && uc <= GREEK_SMALL_LETTER_OMEGA) {
			return 0x1D770 - GREEK_SMALL_LETTER_ALPHA + uc;
		}
		switch (uc) {
			case GREEK_CAPITAL_THETA_SYMBOL:
				return 0x1D767;
			case NABLA:
				return 0x1D76F;
			case PARTIAL_DIFFERENTIAL:
				return 0x1D789;
			case GREEK_LUNATE_EPSILON_SYMBOL:
				return 0x1D78A;
			case GREEK_THETA_SYMBOL:
				return 0x1D78B;
			case GREEK_KAPPA_SYMBOL:
				return 0x1D78C;
			case GREEK_PHI_SYMBOL:
				return 0x1D78D;
			case GREEK_RHO_SYMBOL:
				return 0x1D78E;
			case GREEK_PI_SYMBOL:
				return 0x1D78F;
			default:
				return 0;
		}
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_sans_serif_bold  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_sans_serif_bold(*it);
	}

	return output;
}


Glib::ustring
mathematical_sans_serif_bold_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l == 0) {
		output = mathematical_sans_serif_bold('0');
	}
	else {
		if (l < 0) {
			is_negative = true;
			l = -l;
		}
		while (l) {
			output.insert(output.begin(), mathematical_sans_serif_bold((char) ('0' + l % 10)));
			l /= 10;
		}
		if (is_negative) {
			output.insert(output.begin(), HEAVY_MINUS_SIGN);
		}
	}

	return output;
}


const gunichar
mathematical_sans_serif_italic  (const char  c)
{
	if (c >= 'A' && c <= 'Z') {
		return 0x1D608 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D622 - 'a' + c;
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_sans_serif_italic  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_sans_serif_italic(*it);
	}

	return output;
}


const gunichar
mathematical_sans_serif_bold_italic  (const char  c)
{
	if (c >= 'A' && c <= 'Z') {
		return 0x1D63C - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D656 - 'a' + c;
	}
	else {
		return 0;
	}
}


const gunichar
mathematical_sans_serif_bold_italic  (const gunichar  uc)
{
	if (Glib::Unicode::isdefined(uc)) {
		if (Glib::Ascii::isalnum((char) uc)) {
			return mathematical_sans_serif_bold_italic ((char) uc);
		}
		else if (uc >= GREEK_CAPITAL_LETTER_ALPHA && uc <= GREEK_CAPITAL_LETTER_OMEGA) {
			return 0x1D790 - GREEK_CAPITAL_LETTER_ALPHA + uc;
		}
		else if (uc >= GREEK_SMALL_LETTER_ALPHA && uc <= GREEK_SMALL_LETTER_OMEGA) {
			return 0x1D7AA - GREEK_SMALL_LETTER_ALPHA + uc;
		}
		switch (uc) {
			case GREEK_CAPITAL_THETA_SYMBOL:
				return 0x1D7A1;
			case NABLA:
				return 0x1D7A9;
			case PARTIAL_DIFFERENTIAL:
				return 0x1D7C3;
			case GREEK_LUNATE_EPSILON_SYMBOL:
				return 0x1D7C4;
			case GREEK_THETA_SYMBOL:
				return 0x1D7C5;
			case GREEK_KAPPA_SYMBOL:
				return 0x1D7C6;
			case GREEK_PHI_SYMBOL:
				return 0x1D7C7;
			case GREEK_RHO_SYMBOL:
				return 0x1D7C8;
			case GREEK_PI_SYMBOL:
				return 0x1D7C9;
			default:
				return 0;
		}
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_sans_serif_bold_italic  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_sans_serif_bold_italic(*it);
	}

	return output;
}


const gunichar
mathematical_monospace  (const char  c)
{
	if (c >= '0' && c <= '9') {
		return 0x1D7F6 - '0' + c;
	}
	else if (c >= 'A' && c <= 'Z') {
		return 0x1D670 - 'A' + c;
	}
	else if (c >= 'a' && c <= 'z') {
		return 0x1D68A - 'a' + c;
	}
	else {
		return 0;
	}
}


Glib::ustring
mathematical_monospace  (const Glib::ustring&  str)
{
	Glib::ustring  output;

	for (Glib::ustring::const_iterator it = str.begin(); it != str.end(); ++it) {
		output += mathematical_monospace(*it);
	}

	return output;
}


Glib::ustring
mathematical_monospace_num  (long  l)
{
	Glib::ustring  output;
	bool           is_negative = false;

	if (l == 0) {
		output = mathematical_monospace('0');
	}
	else {
		if (l < 0) {
			is_negative = true;
			l = -l;
		}
		while (l) {
			output.insert(output.begin(), mathematical_monospace((char) ('0' + l % 10)));
			l /= 10;
		}
		if (is_negative) {
			output.insert(output.begin(), MINUS_SIGN);
		}
	}

	return output;
}

} /* namespace Unicode */
