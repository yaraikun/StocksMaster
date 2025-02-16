/*
    Do not forget to encode the info for GROUP NUMBER, DATA SUBMITTED, name and
    section. A deduction of 0.5 point will be applied for not complying with
    this instruction!

    GROUP NUMBER (2 digits): 03
    DATE SUBMITTED         :

    LASTNAME1, FIRSTNAME1: CALUPIG, EVAN RILEY L.   SECTION1: S23A

    NOTE: encode ONLY your NAME and section if this code is for your own
          individual solution
          encode BOTH names and sections if this code is for your GROUP's final
          solution

    CCPROG2 MP Solution for Challenge #4 (C4)

    Do the following:

    1. COMPILE your C source code with -Wall directive.

       Example: CCPROG2> gcc -Wall 01-C4.c

       where 01 is an example group number and C4 is the Challenge number.

       You must replace 01 with your own group number!

    2. RUN the a.exe file in the command line with input and output (I/O)
       redirection.

       Example: CCPROG2> a < AC.txt > 01-C4-AC-OUTPUT.txt

       The text file 01-C4-AC-OUTPUT.txt will contain the actual output of your
       program.

    3. COMPARE your program's output with the accompanying C4-AC-EXPECTED.txt
       file using bbtest.exe.

       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:

       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe

       Thereafter, run bbtest.exe with I/O redirection as shown below:

       Example: CCPROG2> bbtest C4-AC-EXPECTED.txt 01-C4-AC-OUTPUT.TXT >
                         01-C4-AC-BBTEST.txt

       The output file 01-C4-AC-BBTEST.txt contains the results of the
       comparison.  If you see Differences = 0 towards the end of the file, then
       it means that your program's output matches the expected output.
       Otherwise, if you see a Differences value higher than 0, then there's a
       strong probability that you either have a logical error in your program,
       or you did NOT follow the MP specifications (including the directions in
       this file).

       Debug your C source file, and redo the steps above until you get
       Differences = 0.

       Take note, however, that Differences = 0 does NOT necessarily mean that
       your solutions is 100% logically correct. The bbtest.exe only tests if
       two files have the same contents.  It is not meant to test the logic of
       your C program.

    4. TEST your solution using the stock historical data for other companies
       other than AC.txt.  Note that there are no expected output files provided
       for other companies.  You'll have to figure out how to verify the
       correctness of your program's output on your own.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "C4.h" // read and understand the contents of this header file

/* Do NOT include other files. */

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
    POINT DEDUCTIONS!

    1. You are NOT allowed to use library functions that were NOT discussed in
       our class.
    2. You must apply arrays and strings in solving Challenge #4.
    3. Do NOT use the following yet for this particular challenge:
           a. struct data type
           b. file processing functions such as fopen(), fclose(), etc.
    4. Apply divide-and-conquer technique by segregating your program's logic
       into functions. A solution where all the logic are found only in the
       main() function will result to a 2-point deduction!
    5. Document your functions with SENSIBLE comments. Each function definition
       must be PRECEDED by an online documentation (in the form of comments)
       describing concisely the following:
           a. What is the purpose of the function?
           b. What is the nature of the functions return value (write "void" if
              the function is of type void)
           c. What is the nature of each formal parameter?
           d. Pre-condition - what are the assumptions about the formal parameters?

       Follow the online documentation style in the Search() example
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
			return i;  // this means that the key was found	

	return -1; // -1 means that the key not found
}
#endif

/*
    You may #define any constant that you need below this comment.
*/

/*
    You may declare any typedef that you need below this comment.
*/

/*
    Define the functions that you need below this comment.
*/

/*
    TO DO: Complete the body of the main() function.
*/
int main()
{
    /*
        TO DO: Declare your own local variables AFTER this comment. You MUST
               declare and use variables for the following:
        1. a string for storing company symbol, example "AC"
        2. an integer for storing the number of rows of stock historical data
           (in the case of AC.txt this value will store 1216)
        3. 1D array of string for storing the dates (assume that the date values
           in the SHD text file are are already formatted as "MM/DD/YYYY")
        4. 2D array of double values for storing the OHLC values
        5. 1D array of double for storing the volume
    */

    /* Do NOT change the next four lines of variable declarations.  */
    int i, j, m;
    int count;
    StrDate DateSMA[MAX]; // 1D array of dates with corresponding SMA values
    double SMA[MAX];      // 1D array of SMA values

    /*
        Do NOT change the next line of array definition. View the C4.h header file
        to see the values of the macros.
    */
    int test_cases[3] = {TEST_NDAYS1, TEST_NDAYS2, TEST_NDAYS3};

    /*
        TO DO: CALL the function that you defined above for reading the SHD.
    */
    _________________________________; // fill-in the blank

    /*
        NOTE: The statements below should produce the required output. You are
              allowed to change or edit ONLY those lines with blanks by
              filling-up the missing information.

        Refer to the accompanying C4-AC-EXPECTED.txt to see the expected results
        using AC.txt as input file.
    */

    /* TO DO: fill up the blank to print the company symbol. */
    printf("%s\n", _________);

    /*
        The following lines are used to test the function you defined for
        computing the m-day SMA. Three test values for m are used which
        correspond to the macros TEST_NDAYS1, TEST_NDAYS2, and TEST_NDAYS3.
    */
    for (i = 0; i < 3; i++)
    {                      // for each test case
        m = test_cases[i]; // m is the number of days
        printf("**TEST-%d-day-SMA**\n", m);

        /*
            TO DO: call the function that computes the m-day SMA. The function
            should return an integer value to be stored in count. It must also
            accept as 1st parameter the value of m, DateSMA array as 2nd
            parameter, and SMA array as 3rd parameter. Supply the function name
            and the other parameters (aside from the first 3 parameters stated
            above) that you think you'll need to accomplish the requirement.
        */
        count = _____function_name_____(m, DateSMA, SMA, _______other_parameters______);

        /*
            The following will print the count value, the dates and SMA values.
            Again, refer to the accompanying C4-AC-EXPECTED.txt to see the
            expected results using AC.txt as input file.
        */
        printf("count = %d\n", count);
        for (j = 0; j < count; j++)
            printf("%3d  %s  %.2lf\n", j + 1, DateSMA[j], SMA[j]);

        printf("\n");
    }

    return 0;
}
