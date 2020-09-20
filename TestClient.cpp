#include <iostream>
#include "List.h"

int main(){
// INITIALIZE LIST
  List<int>* int_list = new List<int>();
  for (int i = 5; i > 0; --i)
    int_list->push_front(&i);

  for (int i = 6; i < 11; ++i)
    int_list->push_back(&i);
  int zed = 0;
/* STRIPE ZEROS FORWARD
  for (int i = 1, stop = int_list->length(); i < stop; i +=2)
    int_list->insert_at(i, &zed);
*/  
/* STRIPE ZEROS REVERSE
  for (int i = int_list->length()-1; i > 0; i--)
    int_list->insert_at(i, &zed);
*/
/* TEST REMOVALS
  int_list->erase_back();
  int_list->erase_front();
  int lose = 7;
  int_list->remove_first(&lose);
  int_list->remove_all(&zed);
*/

  std::cout << int_list->length() << std::endl;
  int_list->print();

  delete int_list;
  return 0;
}