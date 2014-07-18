/*
 * logics.h
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

#ifndef LOGICS_H_
#define LOGICS_H_

#include "language.h"
#include "semantic.h"
#include "wff.h"

namespace logics
{

class Logic
{
public:
	Logic();
	virtual ~Logic();
	void set_language();
};

} /* namespace logics */

#endif /* LOGICS_H_ */
