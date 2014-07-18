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
#include "unicode.h"


int
main ()
{
	std::locale::global(std::locale(""));

	std::cout << Unicode::mathematical_bold_num(0) << std::endl;
	std::cout << Unicode::mathematical_bold_num(1879878000) << std::endl;
	std::cout << Unicode::mathematical_bold_num(-18798780) << std::endl;
	std::cout << Unicode::mathematical_double_struck_num(-18798780) << std::endl;
	std::cout << Unicode::mathematical_sans_serif_num(-18798780) << std::endl;
	std::cout << Unicode::mathematical_sans_serif_bold_num(-18798780) << std::endl;
	std::cout << Unicode::mathematical_monospace_num(-18798780) << std::endl;
	std::cout << Unicode::mathematical_monospace("ABCD") << std::endl;
	std::cout << Unicode::mathematical_bold("") << std::endl;
	/*
	catch (const Glib::Error& error) {
		std::cerr << error.what() << std::endl;
	}
	*/
	std::cout << "Mathematical script: " << Unicode::mathematical_script("F") << std::endl;
	std::cout << "x" << Unicode::superscript("n-3") << std::endl;
	std::cout << "x" << Unicode::superscript_num(-2325) << std::endl;
	std::cout << "p" << Unicode::subscript("3") << std::endl;
	std::cout << "p" << Unicode::subscript_num(-1) << std::endl;
	std::cout << "p" << Unicode::superscript_num(0) << std::endl;
	std::cout << "p" << Unicode::subscript_num(0) << std::endl;

	return 0;
}
