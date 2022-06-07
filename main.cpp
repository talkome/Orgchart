/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <set>
#include <random>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
    vector<string> workers = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R"};
    set<unsigned long> values_t;
    unsigned long index;
    while (values_t.size() < 7) {
        index = (unsigned long) rand() % workers.size();
        values_t.insert(index);
    }
    vector<unsigned long> values(values_t.begin(), values_t.end());
    shuffle(values.begin(), values.end(), std::mt19937(std::random_device()()));

  OrgChart oc1;
  oc1.add_root(workers[values[0]])
      .add_sub(workers[values[0]], workers[values[1]])
      .add_sub(workers[values[0]], workers[values[2]])
      .add_sub(workers[values[0]], workers[values[3]])
      .add_sub(workers[values[1]], workers[values[4]])
      .add_sub(workers[values[1]], workers[values[6]])
      .add_sub(workers[values[3]], workers[values[5]]);

  cout << oc1 << endl;

  cout <<  "Scan level order:" << endl;
  for (auto it = oc1.begin_level_order(); it != oc1.end_level_order(); ++it){
    cout << (*it) << " " ;
  }

  cout << endl <<  "------ stop -------" << endl;

  cout <<  "Scan reverse order:" << endl;
  for (auto it = oc1.begin_reverse_order(); it != oc1.reverse_order(); ++it){
    cout << (*it) << " " ;
  }

  cout << endl << "------ stop -------" << endl;

  cout <<  "Scan preorder:" << endl;
  for (auto it=oc1.begin_preorder(); it != oc1.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }

  cout << endl <<  "------ stop -------" << endl;

}
