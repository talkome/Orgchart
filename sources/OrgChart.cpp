/**
 * Created by talko on 5/12/22.
 */

#include "OrgChart.hpp"

using namespace std;

ariel::OrgChart &ariel::OrgChart::add_root(string const &item) {
//    if (nullptr != root) {
//        Node *new_head = new Node(item);
//        new_head->sons.push_back(root);
//        root = new_head;
//    } else {
//        this->root = new Node(item);
//    }
    return *this;
}

ariel::OrgChart &ariel::OrgChart::add_sub(string const &boss_name, string const &sub_name) {
//    Node* boss = find_node(boss_name);
//    Node *sub = new Node(sub_name);
//    boss->sons.push_back(sub);
    return *this;
}

Node *ariel::OrgChart::find_node(string const &item) const {
    Node* curr;
    deque<Node*> search_queue;
    search_queue.push_back(this->root);
    while(!search_queue.empty()){
        curr = search_queue.front();
        if (!(curr->name == item)) {
            for (auto &son: curr->sons) {
                search_queue.push_back(son);
            }
            search_queue.pop_front();
        } else {
            return curr;
        }
    }

    throw invalid_argument("this item is not in the graph");
}

// print operator
ostream& ariel::operator<<(ostream& out, ariel::OrgChart& oc) {
    out << "print OrgChart" << endl;
    return out;
}

ariel::OrgChart::iterator ariel::OrgChart::begin_level_order() const {
    return nullptr;
}

ariel::OrgChart::iterator ariel::OrgChart::end_level_order() {
    return nullptr;
}

ariel::OrgChart::iterator ariel::OrgChart::begin_reverse_order() const {
    return nullptr;
}

ariel::OrgChart::iterator ariel::OrgChart::reverse_order() {
    return nullptr;
}

ariel::OrgChart::iterator ariel::OrgChart::begin_preorder() const {
    return nullptr;
}

ariel::OrgChart::iterator ariel::OrgChart::end_preorder() {
    return nullptr  ;
}

// iterator overload
string &ariel::OrgChart::iterator::operator*() const {
    return this->root->name;
}

bool ariel::OrgChart::iterator::operator==(const iterator &other) const {
    return this->root == other.root;
}

bool ariel::OrgChart::iterator::operator!=(const iterator &other) const {
    return !(*this==other);
}

ariel::OrgChart::iterator& ariel::OrgChart::iterator::operator++() {
    return *this;
}

ariel::OrgChart::iterator ariel::OrgChart::iterator::operator++(int) {
//    iterator curr = *this;
//    ++*this;
//    return curr;
    return *this;
}

string *ariel::OrgChart::iterator::operator->() const {
    return &(this->root->name);
}
