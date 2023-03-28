/***************************************************
 * Constants
 ****************************************************************
 *
 * Place global constants in here: values that will be
 * used in various parts of your program. If they're
 * related, group them in an enum with a meaningful 
 * data type name like "Progress" or "GemType"
 ***************************************************/
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__
#include <string>
using namespace std;

// Add any handy constants you'll be using throughout the life of the program.


/** Example: Constants that represent the current screen/section of a collectible
 *  card database program
 */
enum Screen {
  MENU     = 0,
  LIST_CARDS   = 1,
  DISPLAY_CARD = 2,  // and so on, enum handles the rest.
  NEW_CARD,
  NEW_CARD_BY_DUPLICATE,
  EDIT_CARD
};

#endif // end of "header guard" for __CONSTANTS_H__
