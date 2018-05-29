using namespace std;

#include "Element.h"
#include <fstream>
#include <iostream>

#include <algorithm>

Element::Element(string id_) {
	id = id_;
	T = 0;
	T_start = 0;
	
	cout << "Created Element: " << id << "; T=" << T << endl;
}

Element::Element(string id_, float T_start_) {
	id = id_;
	T = T_start_;
	T_start = T_start_;
	
	cout << "Created Element: " << id << "; T=" << T << endl;
}


void Element::setT(float T_new) {
	T = T_new;
}

float Element::getT() {
	return T;
}

void Element::fout(fstream& output_file, float time) {
//	string s_time = to_string(time);
//	string s_T = to_string(T);
	output_file << time << ";" << T << endl;
}
