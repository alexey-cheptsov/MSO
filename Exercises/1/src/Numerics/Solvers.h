/*
 * euler.h
 *
 *  Created on: Jul 27, 2017
 *      Author: hpcochep
 */

#ifndef NUMERICS_SOLVERS_H_
#define NUMERICS_SOLVERS_H_

class Solvers {

public:

        float h; // numeric integration step in secs.

        Solvers(float h_) :
                h(h_) {
        }

        virtual float solve(float const lvalue, float const rvalue) {
        };

};

#endif /* NUMERICS_SOLVERS_H_ */
