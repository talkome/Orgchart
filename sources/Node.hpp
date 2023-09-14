/**
 * Created by talko on 5/12/22.
 */

#include <string>

using namespace std;

struct Node {
    vector<Node*> sons;
    string name;

    // Constructor
    Node(const string& n){
        this->name = n;
    }

    // Destructor
    ~Node(){}

};

