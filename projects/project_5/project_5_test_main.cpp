#include <initializer_list>
#include <iostream>
#include <cassert>

#include "project_5.cpp"

  ///////////////////////////////
 /// Project 5 Testing main  ///
///////////////////////////////
/// To compile:
/// - Place project_5.cpp and project_5_test_main.cpp in the same directory 
/// - Compile using: g++ -std=c++11 roject_5_test_main.cpp -o main.exe
/// Each section contains the expected outputs in coments
/// You do not need to include this main in your submission to Marmoset 
// Finished Modifying proj 5

int main() {
  Set F{ 1,2,3,7,8,9 };
  Set G{ 3,4,5,7,9,11 };

  //F = G;

  std::cout << (F != G);

  F.merge(G);
  std::cout << F << std::endl;
    std::cout << G << std::endl;

  Set my_data_1{ 1, 3, 5, 2, 4, 8, 5, 3, 1 };
  
  Set my_data_2{ 11, 13, 20, 3, 4, 17 };
  std::cout << my_data_1 << std::endl;
    std::cout << my_data_2 << std::endl;
  std::cout << my_data_1.merge(my_data_2) << std::endl;
    std::cout << my_data_1 << std::endl;
    std::cout << my_data_2 << std::endl;
      my_data_1.merge(my_data_1);
          std::cout << my_data_1 << std::endl;
          
// This should print '6'
std::cout << my_data_1.size() << std::endl;
// This should print '0' ('false')
std::cout << my_data_1.empty() << std::endl;
assert( my_data_1.find( 0 ) == nullptr );
assert( my_data_1.find( 1 )->value() == 1 );
assert( my_data_1.find( 5 )->value() == 5 );
assert( my_data_1.find( 6 ) == nullptr );
assert( my_data_1.find( 8 )->value() );

  Set A{};
  A.insert( 1 );
  A.insert( 2 );
  A.insert( 3 );
 
  Set B{2,3,4};
  Set C{3,3,4,4,4,5,5,5,5};

  std::cout << std::endl << "--- Set initialization / insert ---" << std::endl;
  std::cout << "A: " << A << std::endl;  // {1,2,3}
  std::cout << "B: " << B << std::endl;  // {2,3,4}
  std::cout << "C: " << C << std::endl;  // {3,4,5}

  std::cout << std::endl << "--- size / empty ---" << std::endl;
  std::cout << "size of A:  " << A.size()  << std::endl; // 3
  //std::cout << "is A empty: " << A.empty() << std::endl; // 0 (false)

  assert(A.find(3) != nullptr);
  assert(A.find(4) == nullptr);

  std::cout << std::endl << "--- erase / insert ---" << std::endl;
  std::cout << "erase 3: " << A.erase(3) << std::endl; // 1
  std::cout << "erase 3: " << A.erase(3) << std::endl; // 0
  std::cout << "A:       " << A << std::endl;          // {1,2}

  int insert_values[5]{1,2,3,4,5};
  std::cout << "insert [1,2,3]: " << A.insert(insert_values, 0, 3) << std::endl; // 1
  std::cout << "A:       " << A << std::endl;   // {1,2,3}

  //std::cout << "Removed 4: " << A.erase(1) << std::endl;
    //std::cout << "A:       " << A << std::endl;   // {1,2,3}

  std::cout << std::endl << "--- Copy constructor / clear ---" << std::endl;
  Set *D { new Set {A} };
  std::cout << "A:       " <<  A << std::endl;  // {1,2,3}
  std::cout << "B:       " <<  B << std::endl;  // {2,3,4}
  std::cout << "D:       " << *D << std::endl;  // {1,2,3}
  /*
  *D = B;
  std::cout << "D = B:   " << *D << std::endl;  // {2,3,4}
  D->clear();
  std::cout << "D clear: " << *D << std::endl;  // {}
  assert(D->empty() == true);
  */
  delete D;
  D = nullptr;

  std::cout << "A: " << A << std::endl;
  std::cout << "B: " << B << std::endl;

  // Set operations
  std::cout << std::endl << "--- Set Operations ---" << std::endl;
  std::cout << "A union B: " << ( A | B ) << std::endl;
  std::cout << "A intersect B: " << ( A & B ) << std::endl;
  std::cout << "Symmetric difference of A and B: " << ( A ^ B ) << std::endl;
  std::cout << "A minus B: " << ( A - B ) << std::endl;
  std::cout << std::endl;

  std::cout << "A union C: " << ( A | C ) << std::endl;
  std::cout << "A intersect C: " << ( A & C ) << std::endl;
  std::cout << "Symmetric difference of A and C: " << ( A ^ C ) << std::endl;
  std::cout << "A minus C: " << ( A - C ) << std::endl;
  std::cout << std::endl;
 
  std::cout << "B union C: " << ( B | C ) << std::endl;
  std::cout << "B intersect C: " << ( B & C ) << std::endl;
  std::cout << "Symmetric difference of B and C: " << ( B ^ C ) << std::endl;
  std::cout << "B minus C: " << ( B - C ) << std::endl;
  std::cout << std::endl;
 
/* Expected output from set operations: 
    --- Set Operations ---
    A union B: {4, 1, 2, 3}
    A intersect B: {2, 3}
    Symmetric difference of A and B: {4, 1}
    A minus B: {1}

    A union C: {4, 5, 1, 2, 3}
    A intersect C: {3}
    Symmetric difference of A and C: {4, 5, 1, 2}
    A minus C: {1, 2}

    B union C: {5, 2, 3, 4}
    B intersect C: {3, 4}
    Symmetric difference of B and C: {5, 2}
    B minus C: {2}
*/

  return 0;
}