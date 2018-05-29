#ifndef CONNECTION_H_
#define CONNECTION_H_

using namespace std;

#include <string>

class Connection {

        // basis parameters
        string id;
        float K;  // coefficient of temperature conduction


public:
        Connection(string id_, float K_);

        // set up of regulated parameters
        void setK(float K_);
        float getK();

};


#endif /* CONNECTION_H_ */