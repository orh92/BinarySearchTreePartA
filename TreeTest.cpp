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
  ariel::Tree matalaTree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
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
  .print()


.CHECK_EQUAL (matalaTree.size(), 0)//size 0 now
.CHECK_OK (matalaTree.insert(12))
 .CHECK_EQUAL (matalaTree.root(), 12)//inserted 12 and check if 12 is the root
.CHECK_OK (matalaTree.insert(13))
.CHECK_EQUAL (matalaTree.root(), 12)//inserted 13 and see if still 12 is the root
.CHECK_EQUAL (matalaTree.parent(13), 12)//check if 12 is the parent of 13
.CHECK_OK (matalaTree.insert(14))
.CHECK_EQUAL (matalaTree.root(), 12)//inserted 14 and check if 12 still the root
.CHECK_EQUAL (matalaTree.parent(14), 13)//check if 13 is the parent of 14
.CHECK_OK (matalaTree.insert(11))
.CHECK_OK (matalaTree.insert(8))
.CHECK_OK (matalaTree.insert(9))
.CHECK_EQUAL (matalaTree.parent(8), 11)//check if 11 is parent of 8
.CHECK_EQUAL (matalaTree.parent(9), 8)//check if 8 is parent of 9
.CHECK_EQUAL (matalaTree.root(), 12)//inserted 11 , 8 , 9 and check if 12 is the root;
.CHECK_EQUAL (matalaTree.size(), 6) //check the size (12 13 14 11 8 9 ) size is 6
.CHECK_EQUAL (matalaTree.contains(1), false)//check if not contains 1
.CHECK_EQUAL (matalaTree.contains(12), true)//check if contains 12
.CHECK_EQUAL (matalaTree.contains(13), true)//check if contain 13
.CHECK_EQUAL (matalaTree.right(12), 13)//check if 13 is right children of 12
.CHECK_EQUAL (matalaTree.left(12), 11)//check if 11 is left children of 12
.CHECK_EQUAL (matalaTree.left(11), 8)//check if 8 is right children of 11
  .CHECK_OK    (matalaTree.print())
  .print()
.CHECK_EQUAL (matalaTree.contains(12), true)//check if contain 13
.CHECK_EQUAL (matalaTree.contains(13), true)//check if contain 13
.CHECK_EQUAL (matalaTree.contains(14), true)//check if contain 13
.CHECK_EQUAL (matalaTree.contains(11), true)//check if contain 13
.CHECK_EQUAL (matalaTree.contains(8), true)//check if contain 13
.CHECK_EQUAL (matalaTree.contains(9), true)//check if contain 13
.CHECK_EQUAL (matalaTree.contains(5), false)//check if contain 13
.CHECK_EQUAL (matalaTree.right(12), 13)//check if 14 is right children of 13
.CHECK_EQUAL (matalaTree.left(12), 11)//check if 11 is left children of 12
.CHECK_EQUAL (matalaTree.left(11), 8)//check if 8 is left children of 11
.CHECK_OK (matalaTree.insert(7))
.CHECK_EQUAL (matalaTree.left(8), 7)//check if 8 is left children of 11
.CHECK_EQUAL (matalaTree.right(8), 9)//check if 9 is right children of 8
.CHECK_EQUAL (matalaTree.right(13), 14)//check if 14 is right children of 13

;

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
return 0;
}
