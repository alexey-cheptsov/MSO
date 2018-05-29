using namespace std;

#include "Connection.h"
#include <iostream>


Connection::Connection(string id_, float K_) {
	id = id_;
	K = K_;
	
	cout << "Created Connection: " << id << "; K=" << K << endl;
}


float Connection::getK() {
	return K;
}
