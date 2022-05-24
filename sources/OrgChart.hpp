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

        OrgChart(OrgChart& other): root(other.root), orig_root(other.root){}

        OrgChart(OrgChart&& other) noexcept: root(other.root), orig_root(other.root){}

        // Destructor
        ~OrgChart()= default;

        OrgChart& operator=(OrgChart other){
            if (this != &other){
                this->root = other.root;
                this->orig_root = other.orig_root;
            }
            return *this;
        }

        OrgChart& operator=(OrgChart&& other) noexcept{
            if (this != &other){
                this->root = other.root;
                this->orig_root = other.orig_root;
            }
            return *this;
        }

        // addition
        OrgChart& add_root(string const &item);

        OrgChart& add_sub(string const &boss_name, string const &sub_name);

        // searching using bfs algorithm
        Node* find_node(string const &item) const;

        void set_traversal();

        // Tree Scanner
        void scan_level_order();

        void scan_reverse_order(Node* node);

        void scan_preorder(Node* node);

        // Print Operator
        friend ostream& operator<<(ostream& out, OrgChart& oc);

        void clear();

        // Method
        iterator begin_level_order();

        iterator end_level_order() const;

        iterator begin_reverse_order();

        iterator reverse_order() const;

        iterator begin_preorder();

        iterator end_preorder() const;

        // Iterator
        iterator begin();

        iterator end() const;
    };
}




