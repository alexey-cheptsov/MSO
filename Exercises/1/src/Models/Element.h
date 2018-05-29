#ifndef ELEMENT_H_
#define ELEMENT_H_

using namespace std;
#include <string>

class Element {

        // basis parameters

        std::string id;  // identificator
        float T; // temperature (actual)
        float T_start; // temperature (at start time)


public:
        Element(string id_, float T_start_);
        Element(string id_);

        // set up of regulated parameters
        void setT(float T_);
        float getT();

        // output of values of the major parameters to a file
        void fout(fstream& output_file, float time);

};


#endif /* ELEMENT_H_ */
