using namespace std;

#include "Models/Element.h"
#include "Models/Connection.h"
#include "Numerics/Euler.h"
#include "Auxiliary/auxiliary.h"
#include <iostream>
#include <iomanip>
#include <fstream>




int main(int argc, char* argv[]) {

	int benchmark;

	cout << "Starting the simulation" << endl;

	Element T_a ("T_a", 30);
	Element T_b ("T_b", 70);
	Element T_p ("T_p", 15);
	Element T_m ("T_a", 22);

	Connection K_ma ("K_ma", 0.1);
	Connection K_mb ("K_mb", 0.05);
	Connection K_ab ("K_ab", 0.2);
	Connection K_ba ("K_ba", 0.2);
	Connection K_pb ("K_pb", 0.1);
	
	float h = 0.2;
	Euler solver(h);
	
	fstream output_T_a;
	fstream output_T_b;
        output_T_a.open("T_a.csv", ios::out);
        output_T_b.open("T_b.csv", ios::out);

	output_T_a << "t;Ta" << endl;
	output_T_b << "t;Tb" << endl;


	for (int step=0; step<40; step++) {
	
	    float dT_a = K_ma.getK() * (T_m.getT() - T_a.getT()) + K_ba.getK() * (T_b.getT() - T_a.getT());
	    float T_a_next = solver.solve(T_a.getT(), dT_a);

	    float dT_b = K_mb.getK() * (T_m.getT() - T_b.getT()) + K_ab.getK() * (T_a.getT() - T_b.getT()) + K_pb.getK() * (T_p.getT() - T_b.getT());
	    float T_b_next = solver.solve(T_b.getT(), dT_b);
	    
	    T_a.setT(T_a_next);
	    T_b.setT(T_b_next);

	
	    cout << "dT_a = " << dT_a << ", T_a_next = " << T_a_next << endl;
	    cout << "dT_b = " << dT_b << ", T_b_next = " << T_b_next << endl;
	    
	    T_a.fout(output_T_a, step);
	    T_b.fout(output_T_b, step);
	    
	    
	}
	    


	return 0;
}
