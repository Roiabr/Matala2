/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree; 
  ariel::Tree fivetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  fivetree.insert(6);
  fivetree.insert(14);
  fivetree.insert(2);
  fivetree.insert(4);
  fivetree.insert(23);


  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .CHECK_EQUAL (threetree.left(5),1)
  .CHECK_EQUAL (fivetree.size(), 5)
  .CHECK_OK    (fivetree.insert(28))
  .CHECK_EQUAL (fivetree.size(), 6)
  .CHECK_EQUAL (fivetree.root(), 6)
  .CHECK_THROWS(fivetree.parent(6))
   .CHECK_EQUAL (fivetree.contains(28), true)
   .CHECK_EQUAL (fivetree.contains(5), false)
   .CHECK_THROWS(fivetree.insert(28));
  
  
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
