/**
 * Created by talko on 5/12/22.
 */

#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

// addition

/**
 * set the root of the orgchart
 * @param item - name of the root
 * @return
 */
OrgChart& OrgChart::add_root(string const &item){
    Node *new_head = nullptr;
    if (item.empty()){
        throw invalid_argument("Invalid Name");
    }
    if (!traversal.empty()){
        clear();
    }
    // if there is not root  - add one
    if (nullptr == root) {
        this->root = new Node(item);
    } else {
        // update to the new root
        this->root->name = item;
    }
    this->orig_root = root;
    return *this;
}

/**
 * add work above the root
 * @param boss_name - name of the boss
 * @param sub_name - name of the boss worker
 * @return
 */
OrgChart& OrgChart::add_sub(string const &boss_name, string const &sub_name){
    if (boss_name.empty() || sub_name.empty()){
        throw invalid_argument("Invalid Name");
    }
    if (root == nullptr){
        throw invalid_argument("can't add sub before root");
    }
    Node* boss = nullptr;
    Node *sub = nullptr;
    // check for the worker
    boss = find_node(boss_name);
    // add it
    sub = new Node(sub_name);
    boss->sons.push_back(sub);
    return *this;
}

// searching using bfs algorithm

/**
 * searching the worker using bfs search
 * @param item
 * @return
 */
Node* OrgChart::find_node(string const &item) const{
    deque<Node*> queue;
    Node* curr = nullptr;
    queue.push_back(this->root);
    while(!queue.empty()){
        curr = queue.front();
        if (curr->name != item) {
            for (auto &son: curr->sons) {
                queue.push_back(son);
            }
            queue.pop_front();
        } else {
            return curr;
        }
    }
    throw invalid_argument("this item is not in the graph");
}

/**
 * convert the vector result into a list
 */
void OrgChart::set_traversal() {
    size_t i = 0;
    size_t size = traversal.size();
    while (i < size-1){
        Node* back = nullptr;
        Node* curr = nullptr;
        back = traversal[i];
        curr = traversal[i+1];
        back->next = curr;
        curr->next = nullptr;
        i++;
    }
    this->root = traversal[0];
}

// Tree Scanner

/**
 * scan level order
 */
void OrgChart::scan_level_order(){
    deque<Node*> queue;
    Node* curr = nullptr;
    queue.push_front(this->root);
    while(!queue.empty()){
        curr = queue.front();
        traversal.push_back(curr);
        for (auto &son: curr->sons) {
            queue.push_back(son);
        }
        queue.pop_front();
    }
}

/**
 * scan reverse order
 * @param node - root
 */
void OrgChart::scan_reverse_order(Node* node) {
    deque<Node*> stack;
    Node* curr = nullptr;
    stack.push_back(node);
    while(!stack.empty()){
        curr = stack.front();
        traversal.push_back(curr);
        stack.pop_front();
        for (size_t i = curr->sons.size()+1; i > 1; i--) {
            stack.push_back(curr->sons[i-2]);
        }
    }
}

/**
 * scan preorder
 * @param node - root
 */
void OrgChart::scan_preorder(Node* node){
    traversal.push_back(node);
    for(auto & son : node->sons){
        scan_preorder(son);
    }
}

// Print Operator

/**
 * print orgchart unique way
 * @param out - result
 * @param oc - our orgchart
 * @return
 */
std::ostream& ariel::operator<<(std::ostream &out, ariel::OrgChart &oc){
    if (nullptr == oc.root){
        throw invalid_argument("This Tree is Empty");
    }
    oc.clear();
    deque<Node*> queue;
    Node* curr = nullptr;
    queue.push_front(oc.root);
    out << "root: "<< oc.root->name << endl;
    while(!queue.empty()){
        curr = queue.front();
        int i = 1;
        if (!curr->sons.empty()){
            out << "child of " << curr->name << endl;
            for (auto &son: curr->sons) {
                out <<" "<< i << ": "<< son->name << endl;
                i++;
                queue.push_back(son);
            }
        }
        queue.pop_front();
    }
    return out;
}

/**
 * clear the last iteration results
 */
void OrgChart::clear() {
    this->root = orig_root;
    if (!traversal.empty()){
        for (auto & i : traversal) {
            i->next = nullptr;
        }
        traversal.clear();
    }
}

// Method

/**
 * iterator to the begin of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::begin_level_order() {
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    clear();
    scan_level_order();
    set_traversal();
    return {root};
}

/**
 * iterator to the end of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::end_level_order() const{
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    return {nullptr};
}

/**
 * iterator to the begin of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::begin_reverse_order() {
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    clear();
    scan_reverse_order(root);
    std::reverse(traversal.begin(),traversal.end());
    set_traversal();
    return {root};
}

/**
 * iterator to the end of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::reverse_order() const{
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    return {nullptr};
}

/**
 * iterator to the begin of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::begin_preorder(){
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    clear();
    scan_preorder(root);
    set_traversal();
    return {root};
}

/**
 * iterator to the end of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::end_preorder() const{
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    return {nullptr};
}

// Iterator

/**
 * iterator to the begin of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::begin() {
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    return begin_level_order();
}

/**
 * iterator to the end of the orgchart
 * @return
 */
OrgChart::iterator OrgChart::end() const{
    if (nullptr == root){
        throw invalid_argument("This Tree is Empty");
    }
    return end_level_order();
}