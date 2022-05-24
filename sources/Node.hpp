/**
 * Created by talko on 5/12/22.
 */

#include <vector>
#include <string>
#include <utility>

using namespace std;

struct Node {
    string name;
    Node* next;
    vector<Node*> sons;

    // Constructor
    Node(string n): name(move(n)), next(nullptr){}

    Node(Node& other): name(other.name), next(nullptr){}

    Node(Node&& other) noexcept: name(move(other.name)), next(nullptr){}

    // Destructor
    ~Node(){}

    Node& operator=(Node other){
        if (this != &other){
            this->name = other.name;
            this->next = other.next;
        }
        return *this;
    }

    Node& operator=(Node&& other) noexcept{
        if (this != &other){
            this->name = other.name;
            this->next = other.next;
        }
        return *this;
    }
};
