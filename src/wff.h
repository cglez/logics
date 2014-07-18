/*
 * wff.h
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

#ifndef WFF_H_
#define WFF_H_

#include <glibmm/ustring.h>
#include "language.h"

namespace Logics
{

/** Node types in a well formed formula */
typedef enum
{
	WFF_NODE_NONE = 0,
	WFF_NODE_VAR,       /**< Variable.          */
	WFF_NODE_CONST,     /**< Constant.          */
	WFF_NODE_PROPER,    /**< Proper symbol: a variable or a constant. */
	WFF_NODE_IMPROPER,
	WFF_NODE_UCON,      /**< Unary Connective.  */
	WFF_NODE_BCON       /**< Binary Connective. */
}	WFFType;


class WFFNode
{
	Glib::ustring label;
public:
	int node_arity();
};

} /* namespace logics */

#endif /* WFF_H_ */
