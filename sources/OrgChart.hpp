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

    enum Level {
        LEVEL_ORDER,
        REV_ORDER,
        PREORDER,
        NONE
    };

    class OrgChart {

        class iterator {
        public:
            Node* root;
            deque<Node*> tree_traversal;

            // Constructor
            iterator(Node* node): root(node) {}

            // Tree Scanner
//            void scan_level_order(Node*);
//            void scan_reverse_order(Node*);
//            void scan_preorder(Node*);

            // Operators
            string& operator*() const;
            bool operator==(const iterator&) const;
            bool operator!=(const iterator&) const;
            iterator& operator++();
            ariel::OrgChart::iterator operator++(int);
            string * operator->() const;
        };

    public:
        Node* root;

        // Constructor
        OrgChart(){
            this->root = nullptr;
        }

        // Destructor
        ~OrgChart()= default;

        // addition
        OrgChart& add_root(string const &);
        OrgChart& add_sub(string const &, string const &);

        // searching using bfs algorithm
        Node* find_node(string const &) const;

        // Print Operator
        friend ostream& operator<<(ostream &out, OrgChart &oc);

        // Method
        iterator begin_level_order() const;
        iterator end_level_order();

        iterator begin_reverse_order() const;
        iterator reverse_order();

        iterator begin_preorder() const;
        iterator end_preorder();

        // Iterator
        iterator begin() const{
            return root;
        }

        iterator end(){
            return nullptr;
        }
    };
}




