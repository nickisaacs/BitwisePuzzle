/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "maci4699+niis0081", 
   /* Student name 1: Replace with the full name of first team member */
   "Matthew Cirbo",
   /* Login ID 1: Replace with the login ID of first team member */
   "maci4699",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Nicholas Isaacs",
   /* Login ID 2: Login ID of the second team member */
   "niis0081"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {

  return !x;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	
  return ~(0x01<<0x1F);

}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	
  return !(((~x & (x >> 0x1F)) + (x & ~(x >>0x1F))) >> (n + ~0));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 0x01;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  return !( ~(x >> 0x1F ^ y >> 0x1F) & (y >> 0x1F ^ ((x + y)>>0x1F)));
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {

  int first = x&0xFF;
  int second = (x>>8)&0xFF;
  int third = (x>>16)&0xFF;
  int last = (x>>24)&0xFF;
  
  return ((first<<24)|(second<<16)|(third<<8)|last);

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	
  int mask = ~(~0 << n) << (32 +(~n + 1));
  return  ~mask & ( (x >> n) | mask);

}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = ((!x)<<31)>>31;
  return (~x&y)+(x&z);
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  int mask = 1 << 31;
  int neg = (mask & x) >> 31;
  int pos = ~neg;
  int sign = mask & x;

  pos = pos & x;
  neg = neg & x;

  neg = ~(neg + ~0);

  return (neg + pos + sign);
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  x = ( x >> 0x10 ) ^ x;
  x = ( x >> 0x08 ) ^ x;
  x = ( x >> 0x04 ) ^ x;
  x = ( x >> 0x02 ) ^ x;
  x = ( x >> 0x01 ) ^ x;
  return (x & 0x01);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x) {
  int mask = ~0;
  return (!(mask ^ (~x + 1)));
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  x = ( x >> 0x10 ) | x;
  x = ( x >> 0x08 ) | x;
  x = ( x >> 0x04 ) | x;
  x = ( x >> 0x02 ) | x;
  x = ( x >> 0x01 ) | x;
  
  return ~x & 1;
}
/*
 * classLog2 - return floor(log base 2 of x), where x > 0
 *   Example: classLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int classLog2(int x) {
	
        // find out if the non-zero bit is in the first two words
        int A = !(!(x >> 16));  // should be 1 if the n >= 16
        int count = 0;
        int x_copy = x;
       
        // if A is 1 add 16 to count
        count = count + (A<<4);
       
        // if A is 1 return x >> 15, else return x. This is a
        // modified version of my conditional code
        x_copy = (((~A + 1) & (x >> 16)) + (~(~A+1) & x));
       
        // repeat the process but rather than operating on the second half,
        // we can now only worry about the second quarter of the first half.
        A = !(!(x_copy >> 8));
        count = count + (A<<3);
        x_copy = (((~A + 1) & (x_copy >> 8)) + (~(~A+1) & x_copy));
       
        // continue this process until we have covered all bits.
        A = !(!(x_copy >> 4));
        count = count + (A<<2);
        x_copy = (((~A + 1) & (x_copy >> 4)) + (~(~A+1) & x_copy));
       
        A = !(!(x_copy >> 2));
        count = count + (A<<1);
        x_copy = (((~A + 1) & (x_copy >> 2)) + (~(~A+1) & x_copy));
       
        A = !(!(x_copy >> 1));
        count = count + A;
 
        return count;


}
