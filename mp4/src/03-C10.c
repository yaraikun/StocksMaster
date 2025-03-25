/*
    Do not forget to encode the info for GROUP NUMBER, DATE SUBMITTED, NAMES and
    SECTIONS.
    A deduction of 0.5 point will be applied for not complying with this
    instruction!

    GROUP NUMBER (2 digits):
    DATE SUBMITTED         :

    LASTNAME1, FIRSTNAME1:                          SECTION1:

    NOTE: encode ONLY your NAME and section if this code is for your own
          individual solution
          encode BOTH names and sections if this code is for your GROUP's final
          solution


    Make sure that you do the following:

    1. COMPILE your C source code with -Wall directive.

       Example: CCPROG2> gcc -Wall 01-C10.c

       where 01 is an example group number and C10 is the Challenge number.

       You must replace 01 with your own group number!

    2. RUN the program's exe file in the command line. Unlike the previous
       challenges you should NOT use I/O redirection.

       Example: CCPROG2> a

       Your program should produce two output text files named as:

       a. GROUPNUMBER-PORTFOLIO.txt
       b. GROUPNUMBER-MYTEST.txt

       based on the two function calls in the main() function. The output files
       should NOT be created inside the accompanying SHD folder; they should be
       in the same folder where you have your C source file.

    3. COMPARE your program's GROUPNUMBER-PORTFOLIO.txt output file with the
       accompanying C10-EXPECTED.txt file using bbtest.c.

       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:

       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe

       Thereafter, run bbtest.exe with I/O redirection as shown below:

       Example: CCPROG2> bbtest C10-EXPECTED.txt 01-PORTFOLIO.txt >
                                01-C10-BBTEST.txt

       The output redirected file 01-C10-BBTEST.txt contains the results of the
       comparison. If you see Differences = 0 towards the end of the file, then
       it means that your program's output matches the expected output.
       Otherwise, if you see a Differences value higher than 0, then there's a
       strong probability that you either have a logical error in your program,
       or you did NOT follow the MP specifications (including the directions in
       this file).

       Debug your C source file, and redo the steps above until you get
       Differences = 0.

       Take note, however, that Differences = 0 does NOT necessarily mean that
       your solutions is 100% logically correct. The bbtest.exe only tests if
       two files have the same contents. It is not meant to test the logic of
       your C program.

    4. TEST your solution using the stock historical data for other companies.
       Create your own portfolio text file and use them for testing. You'll have
       to figure out how to verify the correctness of your program's output
       using your own test portfolio file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    TO DO: replace GROUPNUMBER in the #include below with your own group number.
    For example if you are group 1, you should have #include "01-C6.h". Group
    numbers from 1 to 9 should have a leading zero in the filename.
*/
#include "03-C6.h"

// Do NOT edit/delete the next #include directive
#include "numeric_date_helpers.c" // read and understand the contents of this
                                  // file

/* Do NOT include other files. */

/*
    Do NOT define any constant in this file.
    Do NOT declare any typedef that you need below this comment.
    You should encode #define and typedef declarations in your GROUPNUMBER-C6.h
    header file.
*/

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
    POINT DEDUCTIONS!

    1. You are required to use TEXT FILE PROCESSING commands fopen(), fclose(),
       fscanf() and fprintf() on top of previous topics in solving Challenge
       #10.
    2. You are required to implement and use a binary search algorithm for
       searching using buy date as search key.
    3. You are NOT allowed to use library functions that were NOT discussed in
       our class.
    4. Apply divide-and-conquer technique by segregating your program's logic
       into functions. A solution where all the logic are found only in the
       main() function will result to a 2-point deduction!
    5. Document your functions with SENSIBLE comments. Each function definition
       must be PRECEDED by an online documentation (in the form comments)
       describing concisely the following:
       a. What is the purpose of the function?
       b. What is the nature of the functions return value (write "void" if the
          function is of type void)
       c. What is the nature of each formal parameter?
       d. Pre-condition - what are the assumptions about the formal parameters?

       Follow the online documentation style in the LinearSearch() example
       function definition given below.
*/

// DO NOT remove or edit the #if and #endif processor directives
#if 0
/*
    Purpose: determine if the search key is in the array or not using a linear
             search algorithm
    Returns: either the (a) index of the array where the key was found or
             (b) a -1 to indicate that the key was not found
    @param : key is the search key
    @param : A is the name of the array containing the universe of values
    @param : n is the number of array elements to check
    Pre-condition: the parameters contain valid values
*/
int
Search(key, int A[], int n)
{
    int i; // indexing variable

    // compare the search key with an element in the array
    for (i = 0; i < n; i++)
        if (key == A[i])
            return i; // this means that the key was found

    return -1; // -1 means that the key not found
}
#endif

/*
    TO DO: Define the functions that you need below this comment.

           Remember that you need to implement the binary search algorithm with
           date as search key.
*/

/*
     TO DO: Complete the body of the main() function.
*/
int main()
{
    char portfolio_filename[100];
    char reference_date[11];
    // Do NOT declare/use other variables

    /*
        TO DO: Fill in the TWO blanks by supplying the name of the function that
        will process the contents of the portfolio text file based on the
        specified reference date.

        DO NOT ADD/EDIT ANY OTHER CODES ASIDE FROM THOSE REQUIRED IN THE 2
        BLANKS!!!
    */

    // TEST #1: Call the function that will fullfill the C10 requirements using
    //          hardcoded actual parameters.
    __________________________("PORTFOLIO.txt", "12/27/2019");

    // TEST #2: Call the function that will fullfill the C10 requirements using
    // actual parameters specified via scanf()
    printf("Input the name of your test portfolio file: ");
    scanf("%s", portfolio_filename); // example: MYTEST.txt or other files that
                                     // you may want to use for testing
    printf("Input a reference date in MM/DD/YYYY format: ");
    scanf("%s", reference_date); // example: 12/27/2019  or other dates you may
                                 // want to use for testing
    _______________________(portfolio_filename, reference_date);

    /*
        NOTE: In case the text file corresponding to portfolio_filename does not
        exist, the called function should display an error message via

        fprintf(stderr, "ERROR: %s not found!\n", portfolio_filename);

        Don't forget the exclamation mark in the error message string.
    */

    return 0;
}
