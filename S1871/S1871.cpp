// S3923.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include "../_inc/allnotthesame.h"

void doOneMoreThing(int i)
{
}

int works(bool b)
{
   return b ? X : Y;
}


int main()
{

   if (b == 0) {  // Noncompliant
      doOneMoreThing(1);
   }
   else {
      doOneMoreThing(1);
   }

   if (b == 0) {  // Noncompliant?
      doOneMoreThing(X - 1);
   }
   else {
      doOneMoreThing(Y - 1);
   }

   works(true);
   works(false);

   int oh = a > b ? X : Y;  // Noncompliant?

   int oh2 = a > b ? a | X : b | Y;  // Noncompliant?

   int rc = 0;
   srand(10);
   std::string s;

   int a = rand();

   if (a == 1)
   {
      rc = A::a;
      s = str1;
      return rc;
   }
   else if (a == 2)
   {
      rc = B::b;
      s = str2;
      return rc;
   }
   else if (a == 3)
   {
      rc = X;
      s = str3;
      return rc;
   }
   else if (a == 4)
   {
      rc = Y;
      s = str4;
      return rc;
   }

   switch (a) {
      case(1):
      {
         rc = A::a;
         s = str1;
         break;
      }
      case(2):
      {
         rc = B::b;
         s = str2;
         break;
      }
      case(3):
      {
         rc = X;
         s = str3;
         break;
      }
      case(4):
      {
         rc = Y;
         s = str4;
         break;
      }
      default:
         rc = 1;     // False positive with S1871, nobody knows that one of the other defines and enums has value 1 and should rely on it
         s = str5;
         break;
   }

   switch (a) {
   case 1:
   {
      rc = A::a;
      s = str1;
      break;
   }
   case 2:
   {
      rc = B::b;
      s = str2;
      break;
   }
   case 3:
   {
      rc = X;
      s = str3;
      break;
   }
   case 4:
   {
      rc = Y;
      s = str4;
      break;
   }
   default:
      rc = 1;     // False positive with S1871, nobody knows that one of the other defines and enums has value 1 and should rely on it
      s = str5;
      break;
   }
   
   return rc;
}

