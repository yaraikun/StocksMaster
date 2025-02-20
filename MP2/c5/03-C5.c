/*
    Do not forget to encode the info for GROUP NUMBER, DATA SUBMITTED, name
    and section. A deduction of 0.5 point will be applied for not complying with
    this instruction!

    GROUP NUMBER (2 digits): 03
    DATE SUBMITTED         :

    LASTNAME1, FIRSTNAME1: CALUPIG, EVAN RILEY L.   SECTION1: S23A

    NOTE: encode ONLY your NAME and section if this code is for your own
          individual solution
          encode BOTH names and sections if this code is for your GROUP's final
          solution

    CCPROG2 MP Solution for Challenge #5 (C5)

    Do the following:

    1. COMPILE your C source code with -Wall directive.

       Example: CCPROG2> gcc -Wall 01-C5.c

       where 01 is an example group number and C5 is the Challenge number.

       You must replace 01 with your own group number!

    2. RUN the a.exe file in the command line with input and output (I/O)
       redirection.

       Example: CCPROG2> a < AC.txt > 01-C5-AC-OUTPUT.txt

       The text file 01-C5-AC-OUTPUT.txt will contain the actual output of your
       program.

    3. COMPARE your program's output with the accompanying C5-AC-EXPECTED.txt
       file using bbtest.exe.

       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:

       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe

       Thereafter, run bbtest.exe with I/O redirection as shown below:

       Example: CCPROG2> bbtest C5-AC-EXPECTED.txt 01-C5-AC-OUTPUT.TXT >
                         01-C5-AC-BBTEST.txt

       The output file 01-C5-AC-BBTEST.txt contains the results of the
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
       two files have the same contents.  It is not meant to test the logic of
       your C program.

    4. TEST your solution using the stock historical data for other companies
       other than AC.txt. Note that there are no expected output files provided
       for other companies.  You'll have to figure out how to verify the
       correctness of your program's output on your own.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "C5.h"                   // read and understand the contents of this
                                  // header file
#include "numeric_date_helpers.c" // read and understand the contents of this C
                                  // file

/* Do NOT include other files. */

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or
    CAUSE POINT DEDUCTIONS!

    1. You are NOT allowed to use library functions that were NOT discussed in
       our class.
    2. You must apply arrays and strings in solving Challenge #5.
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
           d. Pre-condition - what are the assumptions about the formal
              parameters?

       Follow the online documentation style in the Search() example function
       definition given below.
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
    You may #define any constant that you need below this comment.
*/

/*
    You may declare any typedef that you need below this comment.
*/

/*
    Define the functions that you need below this comment.
*/
/*
    Purpose: reads stock market data (dates, OHLC values, and volume) from
             input
    Returns: void (modifies the provided arrays and sets the number of entries)
    @param : date is an array to store formatted dates
    @param : ohlc is a 2D array storing Open, High, Low, and Close prices
    @param : volume is an array storing volume values
    @param : entries is a pointer to an integer that stores the number of
             entries read
    Pre-condition: input data follows the expected format and contains
                   valid values
*/
int binary_search(StrDate key, StrDate date[], int n)
{
    int low, high, mid;
    int found;
    int i;

    found = 0;

    low = 0;
    high = n - 1;

    while (!found && low <= high) {
        mid = low + (high - low) / 2;
        if (strcmp(key, date[mid]) == 0)
            found = 0;
        else if (strcmp(key, date[mid]) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}

/*
    Purpose: reads stock market data (dates, OHLC values, and volume) from
             input
    Returns: void (modifies the provided arrays and sets the number of entries)
    @param : date is an array to store formatted dates
    @param : ohlc is a 2D array storing Open, High, Low, and Close prices
    @param : volume is an array storing volume values
    @param : entries is a pointer to an integer that stores the number of
             entries read
    Pre-condition: input data follows the expected format and contains
                   valid values
*/
int linear_search(StrDate key, StrDate date[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (strcmp(key, date[i]) == 0)
            return i;

    return -1;
}

/*
    Purpose: reads stock market data (dates, OHLC values, and volume) from
             input
    Returns: void (modifies the provided arrays and sets the number of entries)
    @param : date is an array to store formatted dates
    @param : ohlc is a 2D array storing Open, High, Low, and Close prices
    @param : volume is an array storing volume values
    @param : entries is a pointer to an integer that stores the number of
             entries read
    Pre-condition: input data follows the expected format and contains
                   valid values
*/
void read_data(StrDate date[], double ohlc[][4], double volume[], int *entries,
               StrDate stock)
{
    StrDate temp_date; // temporary buffer/holder for date
    double open, high, low, close, vol;
    int i, read_count;
    
    // read stock symbol and number of entries
    scanf("%s %d", stock, entries);

    // read each transaction
    for (i = 0; i < *entries; i++) {
        read_count = scanf("%s %lf %lf %lf %lf %lf",
                           temp_date,
                           &open, &high, &low, &close,
                           &vol);

        // ensure correct number of values were read
        if (read_count == 6) {
            strcpy(date[i], temp_date);
            ohlc[i][0] = open;
            ohlc[i][1] = high;
            ohlc[i][2] = low;
            ohlc[i][3] = close;
            volume[i] = vol;
        } else {
            // assign default values for incomplete lines
            strcpy(date[i], "00/00/0000");
            ohlc[i][0] = 0.0;
            ohlc[i][1] = 0.0;
            ohlc[i][2] = 0.0;
            ohlc[i][3] = 0.0;
            volume[i] = 0.0;
        }
    }
}

/*
    TO DO: Complete the body of the main() function.
*/
int main()
{
    /* TO DO: Declare your own local variables AFTER this comment. You MUST
              declare and use variables for the following:
       1. a string for storing company symbol, example "AC"
       2. an integer for storing the number of rows of stock historical data
          (in the case of AC.txt this value will store 1216)
       3. 1D array of string for storing the dates (assume that the date values
          in the SHD text file are are already formatted as "MM/DD/YYYY")
       4. 2D array of double values for storing the OHLC values
       5. 1D array of double for storing the volume
    */
    StrDate stock;
    int num_entries;
    StrDate dates[MAX];
    double ohlc[MAX][4];
    double volume[MAX];

    /* Do NOT change the next three lines of variable declarations. */
    int i;
    int index;
    StrDate key;

    /*
        Do NOT change the next line of array definition. View the C5.h header
        file to see the values of the macros.
    */
    StrDate test_cases[7] = {TEST_DATE1, TEST_DATE2, TEST_DATE3, TEST_DATE4,
                             TEST_DATE5, TEST_DATE6, TEST_DATE7};

    /*
        TO DO: CALL the function that you defined above for reading the stock
               historical data.
    */
    read_data(dates, ohlc, volume, &num_entries, stock);

    /*
        NOTE: The statements below should produce the required output. You are
              allowed to change or edit ONLY those lines with blanks by
              filling-up the missing information.

        Refer to the accompanying C5-AC-EXPECTED.txt to see the expected
        results using AC.txt as input file.
    */

    /* TO DO: fill up the blank to print the company symbol. */
    printf("%s\n\n", stock);

    /*
        The following lines are used to test your Linear Search algorithm
        implementation. Seven test values for the search key are used which
        correspond to macros TEST_DATE1 to TEST_DATE7.
    */
    printf("** TEST-01-LINEAR-SEARCH**\n");
    for (i = 0; i < 7; i++) {
        strcpy(key, test_cases[i]);

        /*
            TO DO: call your own Linear Search function. The function should
                   return an integer value to be stored in index. It the search
                   key is found, it should correspond to the array index where
                   the search key was found; otherwise, the value is -1. It
                   must accept the search key as the 1st parameter. Supply the
                   function name and the other parameters that you think you'll
                   need to accomplish the requirement.
        */
        index = linear_search(key, dates, num_entries);
        printf("%4d  %12s %4d ", i + 1, key, index);

        if (index != -1) { // key was found
            /*
                TO DO: Fill in the blank to print the closing price and the
                       volume corresponding to the array index.
            */
            printf(" %8.2lf  %12.2lf", ohlc[index][3], volume[index]);
        }
        printf("\n");
    }
    printf("\n");

    /*
        The following lines are used to test your Binary Search algorithm
        implementation.
    */
    printf("** TEST-02-BINARY-SEARCH**\n");
    for (i = 0; i < 7; i++) {
        strcpy(key, test_cases[i]);

        /*
            TO DO: call your own Binary Search function.  The function should
                   return an integer value to be stored in index. It the search
                   key is found, it should correspond to the array index where
                   the search key was found; otherwise, the value is -1. It
                   must accept the search key as the 1st parameter. Supply the
                   function name and the other parameters that you think you'll
                   need to accomplish the requirement.
        */
        index = binary_search(key, dates, num_entries);
        printf("%4d  %12s %4d ", i + 1, key, index);

        if (index != -1) { // key was found
            /*
                TO DO: Fill in the blank to print the closing price and the
                       volume corresponding to the array index.
            */
            printf(" %8.2lf  %12.2lf", ohlc[index][3], volume[index]);
        }

        printf("\n");
    }

    return 0;
}
