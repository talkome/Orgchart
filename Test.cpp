/**
 * Created by talko on 5/13/22.
 */

#include "doctest.h"
#include "OrgChart.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("2. Check Level Order") {
    vector<string> strVector2 = {"CEO","CTO","CFO","COO","VP_SW","VP_BI"};
    vector<int> intVector2 = {3,3,3,3,5,5};

    OrgChart org2;
    CHECK_NOTHROW(org2.add_root("CEO"));
    CHECK_NOTHROW(org2.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org2.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org2.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org2.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org2.add_sub("COO", "VP_BI"));

    unsigned long index = 0;
    for (auto i = org2.begin_level_order(); i != org2.end_level_order(); ++i) {
        CHECK_EQ(*i, strVector2[index]);
        CHECK_EQ(i->size(), intVector2[index]);
        index++;
    }
}

TEST_CASE("3. Check Reverse Level Order") {
    vector<string> strVector3 = {"VP_SW","VP_BI","CTO","CFO","COO","CEO"};
    vector<int> intVector3 = {5,5,3,3,3,3};

    OrgChart org3;
    CHECK_NOTHROW(org3.add_root("CEO"));
    CHECK_NOTHROW(org3.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org3.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org3.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org3.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org3.add_sub("COO", "VP_BI"));

    unsigned long index = 0;
    for (auto i = org3.begin_reverse_order(); i != org3.reverse_order(); ++i){
        CHECK_EQ(*i, strVector3[index]);
        CHECK_EQ(i->size(), intVector3[index]);
        index++;
    }
}

TEST_CASE("4. Check Preorder") {
    vector<string> strVector4 = {"CEO","CTO","VP_SW","CFO","COO","VP_BI"};
    vector<int> intVector4 = {3,3,5,3,3,5};

    OrgChart org4;
    CHECK_NOTHROW(org4.add_root("CEO"));
    CHECK_NOTHROW(org4.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org4.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org4.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org4.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org4.add_sub("COO", "VP_BI"));

    unsigned long index = 0;
    for (auto i=org4.begin_preorder(); i!=org4.end_preorder(); ++i) {
        CHECK_EQ(*i, strVector4[index]);
        CHECK_EQ(i->size(), intVector4[index]);
        index++;
    }
}

TEST_CASE("5. Check Iterator") {
    vector<string> strVector5 = {"CEO","CTO","CFO","COO","VP_SW","VP_BI"};

    OrgChart org5;
    CHECK_NOTHROW(org5.add_root("CEO"));
    CHECK_NOTHROW(org5.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org5.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org5.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org5.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org5.add_sub("COO", "VP_BI"));

    unsigned long index = 0;
    for (string element : org5){
        CHECK_EQ(element, strVector5[index]);
        index++;
    }
}

