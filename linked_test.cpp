
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "linked_list_collection.h"

using namespace std;


// Test 1
TEST(BasicListTest, CorrectSize) {
  LinkedListCollection<string,double> c;
  ASSERT_EQ(0, c.size());
  c.add("b", 10.0);
  ASSERT_EQ(1, c.size());
  c.add("a", 20.0);
  ASSERT_EQ(2, c.size());
  c.add("c", 20.0);
  ASSERT_EQ(3, c.size());

}


// Test 2
TEST(BasicListTest, SimpleFind) {
  LinkedListCollection<string,double> c;
  double v;
  ASSERT_EQ(false, c.find("b", v));
  c.add("b", 10.0);
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(10.0, v);
  ASSERT_EQ(false, c.find("a", v));
  c.add("a", 20.0);
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(20.0, v);
}


// Test 3
TEST(BasicListTest, SimpleRemoveElems) {
  LinkedListCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("d", 30);
  c.add("c", 30);
  ASSERT_EQ(4, c.size());
  int v;
  c.remove("d");
  ASSERT_EQ(3, c.size());
  ASSERT_EQ(false, c.find("d", v));
  c.remove("b");
  ASSERT_EQ(2, c.size());
  ASSERT_EQ(false, c.find("b", v));  
  c.remove("c");
  ASSERT_EQ(1, c.size());
  ASSERT_EQ(false, c.find("c", v));  
  c.remove("a");
  ASSERT_EQ(false, c.find("a", v)); 
  ASSERT_EQ(0, c.size());
  ASSERT_EQ(false, c.find("c", v));  
}


// Test 4
TEST(BasicListTest, SimpleRange) {
  LinkedListCollection<int,string> c;
  c.add(50, "e");
  c.add(10, "a");
  c.add(30, "c");
  c.add(40, "d");
  c.add(60, "f");
  c.add(20, "b");
  vector<string> vs;
  c.find(20, 40, vs);
  ASSERT_EQ(3, vs.size());
  // note that the following "find" is a C++ built-in function
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "a"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "b"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "c"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "d"));
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "e"));  
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "f"));  
}


// Test 5
TEST(BasicListTest, SimpleSort) {
  LinkedListCollection<string,int> c;
  c.add("a", 10);
  c.add("e", 50);
  c.add("c", 30);
  c.add("b", 20);
  c.add("d", 40);
  vector<string> sorted_ks;
  c.sort(sorted_ks);
  ASSERT_EQ(5, sorted_ks.size());
  // check if in sorted order
  for (int i = 0; i < int(sorted_ks.size()) -1; ++i)
    ASSERT_LE(sorted_ks[i], sorted_ks[i+1]);
}


//Test 6
TEST(BasicListTest, Check) {
  LinkedListCollection<string,int> c;
  c.add("a", 10);
  c.add("e", 50);
  LinkedListCollection<string,int> d;
  d = c; //check equal operator with empty list
  ASSERT_EQ(2, d.size());
  int v;
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(true, d.find("e", v));
  c.add("p",40);
  c.add("s",2);
  d = c; //check equal op again with elements already there
  ASSERT_EQ(true, c.find("p", v));
  ASSERT_EQ(true, d.find("s", v));
  ASSERT_EQ(4, d.size());
  ASSERT_EQ(4, c.size());
}





int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

