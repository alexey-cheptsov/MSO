#ifndef NUMERICS_EULER_H_
#define NUMERICS_EULER_H_

#include "Solvers.h"

class Euler: public Solvers {
public:

	Euler(float h_) :
			Solvers(h_) {
	}

	float solve(float const lvalue, float const rvalue) {

		float lvalue_next = 0;
		return lvalue_next;

	}

};

#endif /* NUMERICS_EULER_H_ */
