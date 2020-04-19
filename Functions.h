/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Arian Mohammadi Zerdeh-Del		 amohammadi-zerdeh-de@myseneca.ca
   2) Arfa Ziaardalan					 azia-ardalan@myseneca.ca
   3) Jairo Oswaldo Martinez Garnica     jomartinez-garnica@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: Funtions.h                        |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */
#include "file_helper.h"

void MenuDisplay(void);

void clearKeyboard(void);

void ContentSystem(void);

void Output(struct RiderInfo[], int[], int);

int getInt(void);

char getCat(void);

int toupper();

void BubbleSort(struct RiderInfo riders[], int size);

int Choice(struct RiderInfo riders[], int max_size, int indexes[], char category, int no_withdraw);