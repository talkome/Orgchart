/**
 * Created by talko on 5/12/22.
 */

#pragma once
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <iterator>
#include "Node.hpp"

using namespace std;

namespace ariel {

    class OrgChart {

    public:

        class iterator {
        private:
            Node* node;

        public:
            // Constructor
            iterator(Node *ptr): node(ptr) {}

            // Operators
            string& operator*() const{
                return this->node->name;
            }

            bool operator==(const iterator& other) const{
                return this->node == other.node;
            }

            bool operator!=(const iterator& other) const{
                return !(*this==other);
            }

            iterator& operator++(){
                this->node = this->node->next;
                return *this;
            }

            iterator operator++(int){
                iterator curr = *this;
                ++(*this);
                return curr;
            }

            string* operator->() const{
                return &(this->node->name);
            }
        };

        Node* root;
        Node* orig_root;
        vector<Node*> traversal;

        // Constructor
        OrgChart(): root(nullptr), orig_root(nullptr){}

        // Destructor
        ~OrgChart()= default;

        // addition
        OrgChart& add_root(string const &item){
            if (item.empty()){
                throw invalid_argument("Invalid Name");
            }
            if (nullptr != root) {
                Node *new_head = new Node(item);
                new_head->sons.push_back(root);
                root = new_head;
            } else {
                this->root = new Node(item);
            }
            this->orig_root = root;
            return *this;
        }

        OrgChart& add_sub(string const &boss_name, string const &sub_name){
            if (boss_name.empty() || sub_name.empty()){
                throw invalid_argument("Invalid Name");
            }
            Node* boss = find_node(boss_name);
            Node *sub = new Node(sub_name);
            boss->sons.push_back(sub);
            return *this;
        }

        // searching using bfs algorithm
        Node* find_node(string const &item) const{
            deque<Node*> queue;
            queue.push_back(this->root);
            while(!queue.empty()){
                Node* curr = queue.front();
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

        void set_traversal() {
            size_t i = 0;
            while (i < traversal.size()-1){
                Node* back = traversal[i];
                Node* curr = traversal[i+1];
                back->next = curr;
                curr->next = nullptr;
                i++;
            }
            this->root = traversal[0];
        }

        // Tree Scanner
        void scan_level_order(){
            deque<Node*> queue;
            queue.push_front(this->root);
            while(!queue.empty()){
                Node* curr = queue.front();
                traversal.push_back(curr);
                for (auto &son: curr->sons) {
                    queue.push_back(son);
                }
                queue.pop_front();
            }
        }

        void scan_reverse_order(Node* node) {
            deque<Node*> stack;
            stack.push_back(node);
            while(!stack.empty()){
                Node* curr = stack.front();
                traversal.push_back(curr);
                stack.pop_front();
                for (int i = curr->sons.size()+1; i > 1; i--) {
                    stack.push_back(curr->sons[i-2]);
                }
            }
        }

        void scan_preorder(Node* node){
            traversal.push_back(node);
            for(size_t i=0; i < node->sons.size();i++){
                scan_preorder(node->sons[i]);
            }
        }

        // Print Operator
        friend ostream& operator<<(ostream &out, OrgChart &oc){
            for (const auto& element : oc) {
                cout << element << " " ;
            }
            return cout;
        }

        void clear() {
            this->root = orig_root;
            if (!traversal.empty()){
                for (auto & i : traversal) {
                    i->next = nullptr;
                }
                traversal.clear();
            }
        }

        // Method
        iterator begin_level_order() {
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            clear();
            scan_level_order();
            set_traversal();
            return {root};
        }

        iterator end_level_order() const{
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            return {nullptr};
        }

        iterator begin_reverse_order() {
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            clear();
            scan_reverse_order(root);
            std::reverse(traversal.begin(),traversal.end());
            set_traversal();
            return {root};
        }

        iterator reverse_order() const{
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            return {nullptr};
        }

        iterator begin_preorder(){
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            clear();
            scan_preorder(root);
            set_traversal();
            return {root};
        }

        iterator end_preorder() const{
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            return {nullptr};
        }

        // Iterator
        iterator begin() {
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            return begin_level_order();
        }

        iterator end() const{
            if (nullptr == root){
                throw invalid_argument("This Tree is Empty");
            }
            return end_level_order();
        }
    };
}




