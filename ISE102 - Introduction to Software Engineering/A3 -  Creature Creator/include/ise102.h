#ifndef __ISE102_H__
#define __ISE102_H__

//#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
//#include "scn/all.h"
#include "fmt/core.h"
#include "fmt/format.h"
#include "fmt/color.h"
// Detect target's platform and set some macros in order to wrap platform
// specific code this library depends on.
// Platform check borrowed from termcolor.hpp, github.com/ikalnytskyi
#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#   define TARGET_POSIX
#elif defined(_WIN32) || defined(_WIN64)
#   define TARGET_WINDOWS
#endif

#if defined(TARGET_POSIX)
// Use conio_linux.h on LINUX (including replit)
#   include "conio_linux.h"
#elif defined(TARGET_WINDOWS)
//Use conio.h on WINDOWS (Visual Studio Community, open the sln file)
# include <conio.h>
#endif
//using namespace std;
using fmt::print;
using fmt::format;
using fmt::emphasis;
using fmt::fg;
using fmt::bg;
//using scn::input;
//using scn::prompt;
using fmt::color;
using namespace std::literals::chrono_literals;

// Stop/hold program execution for the given number of milliseconds (duration_ms)
// e.g. delay(1000); // stops for one second
void delay(int duration_ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}

// Takes in a minimum number (int) and a maximum number (int), returns a random
// number between the min and max (inclusive)
// e.g. int rolled = randomInRange(1,6);  // stores 1, 2, 3, 4, 5 or 6 in `rolled` (dice roll).
int randomInRange(int min, int max)
{
  int difference = max - min;
  int rand_in_range = min + (rand() % (difference+1));
  // send back the result.
  return rand_in_range;
}

// Erase all existing text from the console and return cursor to the first line.
void clearScreen()
{
#ifdef WINDOWS
  std::system("cls");
  //print("\n windows clearscreen \n");
#else
  // Assume POSIX
  std::system("clear");
  //print("\n linux clearscreen \n");
#endif
}

// Create a text style compatible with the frm print statement. 
// @foreground: a colour for the text character (see include/fmt/color.h)
// @background: the colour the pixels surrounding the character (tall rectangle)
// @emphasis: bold, italic, underline, strikethrough (see include/fmt/color.h)
// e.g. auto troll_style = makeStyle(color::black, color::red, emphasis::underline);
fmt::text_style makeStyle(fmt::color foreground, fmt::color background,fmt::emphasis emph = fmt::emphasis(0))
{
  return emph | fg(foreground) | bg (background);
}

#endif  // ISE102_H