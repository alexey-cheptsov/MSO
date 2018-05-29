/*
 * Euler.h
 *
 *  Created on: Aug 8, 2017
 *      Author: hpcochep
 */

#ifndef SRC_NUMERICS_EULER_H_
#define SRC_NUMERICS_EULER_H_

#include "Solvers.h"

class Euler: public Solvers {
public:

	Euler(float h_) :
			Solvers(h_) {
	}

	float solve(float const lvalue, float const rvalue) {

		float lvalue_next = (lvalue) + (h) * (rvalue);
		return lvalue_next;

	}

};

#endif /* SRC_NUMERICS_EULER_H_ */
