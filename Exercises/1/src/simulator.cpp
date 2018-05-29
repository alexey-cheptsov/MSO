using namespace std;

#include "Models/Element.h"
#include "Models/Connection.h"
#include "Numerics/Euler.h"
#include <iostream>
#include <iomanip>
#include <fstream>




int main(int argc, char* argv[]) {

        cout << "Starting the simulation" << endl;

        Element T_a ("T_a", 30);
        /*
         * TO FILL
         */

        Connection K_ma ("K_ma", 0.1);
        /*
         * TO FILL
         */


        float h = 0.2;
        Euler solver(h);


        for (int step=0; step<40; step++) {

            float dT_a = 0;
            float T_a_next = solver.solve(T_a.getT(), dT_a);
            T_a.setT(T_a_next);

            /*
             * TO FILL
             */



            cout << "dT_a = " << dT_a << ", T_a_next = " << T_a_next << endl;

            /*
             * TO FILL
             */


        }


        return 0;
}
