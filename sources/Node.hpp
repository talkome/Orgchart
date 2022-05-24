/**
 * Created by talko on 5/12/22.
 */

#include <string>
#include <utility>

using namespace std;

struct Node {
    string name;
    Node* next;
    vector<Node*> sons;

    // Constructor
    Node(string n): name(std::move(n)), next(nullptr){}

    // Destructor
    ~Node(){}

};

