/*
 * semantic.h
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

#ifndef SEMANTIC_H_
#define SEMANTIC_H_

namespace Logics
{

class Interpretation {};

class Veritative : public Interpretation
{
public:
protected:
	int truth_values;
};

class Bivalent : public Veritative
{
public:
	Bivalent();
};


class Multivaluated : public Veritative
{
public:
	Multivaluated(int truth_values);
	Multivaluated(int truth_values, int mdv);
	void set_truth_values (int truth_values);
	void set_mdv (int mdv);
protected:
	int mdv;
};



class Semantic
{
public:
	Semantic();
	virtual ~Semantic();
};

} /* namespace logics */

#endif /* SEMANTIC_H_ */
