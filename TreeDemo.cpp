/**
 * Demo program for the exercise on binary trees
 *
 * @author Erel Segal-Halevi
 * 
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;

#include "Tree.hpp"

int main() {
  try {
    // constructs an empty tree:
    ariel::Tree emptytree;
    cout << "emptytree: size=" << emptytree.size() << endl; // should print 0
    
    // constructs an ordered binary tree where:
      // 5 is in the root;
      // 3 is the root's left child;
      // 7 is the root's right child.
    ariel::Tree threetree;
    threetree.insert(5);
    threetree.insert(7);
    threetree.insert(3);
    threetree.insert(4);
    threetree.remove(4);
    cout << "threetree: size=" << threetree.size() << " root=" << threetree.root() << endl;  // size=3, root=5.
    threetree.print();
    cout << "is the number in the tree? " << threetree.contains(5) << endl;
    cout << endl;
      
    cout << "second size: " << threetree.size() << endl;     // should print 3
    cout <<"the parant of 3 is: " << threetree.parent(3) << endl;   // should print 5
    cout <<"the parant of 7 is: " <<  threetree.parent(7) << endl;   // should print 5
    cout << threetree.left(5) << endl;     // should print 3
    cout << threetree.right(5) << endl;   // should print 7
    
         
    threetree.insert(5);    // should throw an exception, since 5 already exists.
  } catch (...) {
    cout << "Caught exception!" << endl;
  }
}
