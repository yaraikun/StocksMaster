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

    CCPROG2 MP Solution for Challenge #3 (C3)

    Do the following:

    1. COMPILE your C source code with -Wall directive.

       Example: CCPROG2> gcc -Wall 01-C3.c

       where 01 is an example group number and C3 is the Challenge number.

       You must replace 01 with your own group number!

    2. RUN the corresponding a.exe file in the command line with input and
       output (I/O) redirection.

       Example: CCPROG2> a < AC.txt > 02-C3-AC-OUTPUT.txt

       The text file 01-C3-AC-OUTPUT.txt will contain the actual output of
       your program.

    3. COMPARE your program's output your program with the accompanying
       C3-AC-EXPECTED.txt file using bbtest.exe.

       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:

       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe

       Thereafter, run bbtest.exe with I/O redirection as shown below:

       Example: CCPROG2> bbtest C3-AC-EXPECTED.txt 01-C3-AC-OUTPUT.TXT >
                         01-C3-AC-BBTEST.txt

       The output file 01-C3-AC-BBTEST.txt contains the results of the
       comparison. If you see Differences = 0 towards the end of the file, then
       it means that your program's output matches the expected output.
       Otherwise, if you see a Differences value higher than 0, then there's a
       strong probability that you either have a logical error in your program,
       or you did NOT follow the MP specifications (including the directions in
       this file).

       Debug your C source file, and redo the steps above until you get
       Differences = 0.

       Take note, however, that Differences = 0 does NOT necessarily mean that
       your solution is 100% logically correct. The bbtest.exe only tests if
       two files have the same contents.  It is not meant to test the logic of
       your C program.

    4. TEST your solution using the stock historical data for other companies
       other than AC.txt. Note that there are no expected output files provided
       for other companies.  You'll have to figure out a way on how to verify
       the correctness of your program's output on your own.
*/

#include <stdio.h>
#include <string.h>

#include "C3.h" // read and understand the contents of this header file

/* Do NOT include other files. */

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
    POINT DEDUCTIONS!

    1. You are NOT allowed to use library functions that were NOT discussed in
       our online class.
    2. You must apply arrays and strings in solving Challenge #3.
    3. Do NOT use the following yet for this particular challenge:
           a. struct data type
           b. file processing functions such as fopen(), fclose(), etc.
    4. Apply divide-and-conquer technique by segregating your program's logic
       into functions. A solution where all the logic are found only in the
       main() function will result to a 2-point deduction!
    5. Document your functions with SENSIBLE comments. Each function definition
       must be PRECEDED by an online documentation (in the form comments)
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
double get_avg(double ohlc[])
{
    return (ohlc[0] + ohlc[1] + ohlc[2] + ohlc[3]) / 4;
}

int get_min_index(double ohlc[][4], int entries)
{
    int i;
    int min_index;
    double min_price;
    double price;

    min_index = 0;
    min_price = get_avg(ohlc[min_index]);

    for (i = 1; i < entries; i++) {
        price = get_avg(ohlc[i]);
        if (price <= min_price) {  // use <= to get the most recent occurrence
            min_price = price;
            min_index = i;
        }
    }

    return min_index;
}

int get_max_index(double ohlc[][4], int entries)
{
    int i;
    int max_index;
    double max_price;
    double price;

    max_index = 0;
    max_price = get_avg(ohlc[max_index]);

    for (i = 1; i < entries; i++) {
        price = get_avg(ohlc[i]);
        if (price >= max_price) {  // use <= to get the most recent occurrence
            max_price = price;
            max_index = i;
        }
    }

    return max_index;
}

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
    /*
        TO DO: Declare your own local variables AFTER this comment. You MUST
               declare and use variables for the following:
        1. a string for storing the company symbol, for example "AC"
        2. an integer for storing the actual number of rows of stock historical
           data (in the case of AC.txt this value will store 1216)
        3. 1D array of string for storing the dates (assume that the date values
           in the text file are are already formatted as "MM/DD/YYYY")
        4. 2D array of double for storing the OHLC values
        5. 1D array of double for storing the volume
    */
    StrDate stock_symbol;
    int num_entries;
    StrDate dates[MAX];
    double ohlc[MAX][4];
    double volume[MAX];

    /*
        Do NOT change the next two variable declarations.  Use min_index to
        store the index of the array with the lowest (minimum) average OHLC
        price. Similarly, use max_index to store index of the the array with the
        highest (maximum) OHLC price.
    */
    int min_index;
    int max_index;

    /*
        TO DO: CALL the function that you defined above for reading the SHD.
    */
    read_data(dates, ohlc, volume, &num_entries, stock_symbol);

    /*
        TO DO: Fill in the blanks by CALLING the functions that will compute
               the min_index and max_index values.
    */
    min_index = get_min_index(ohlc, num_entries);
    max_index = get_max_index(ohlc, num_entries);

    /*
        The next three printf() statements should produce the required output.
        Refer to the accompanying C3-AC-EXPECTED.txt to see the expected results
        using AC.txt as input file.
    */

    /* TO DO: fill up the blank to print the company symbol. */
    printf("%s\n", stock_symbol);

    /*
        TO DO: Fill in the blanks to print the
        (a) index of the most recent lowest average OHLC price,
        (b) date associated with that index,
        (c) value of the most recent lowest average OHLC price.
    */
    printf("%d %s %.2lf\n",
           min_index,
           dates[min_index],
           get_avg(ohlc[min_index]));

    /*
        TO DO: Fill in the blanks to print the
        (a) index of the most recent highest average OHLC price,
        (b) date associated with that index
        (c) value of the most recent highest average OHLC price.
    */
    printf("%d %s %.2lf\n",
           max_index,
           dates[max_index],
           get_avg(ohlc[max_index]));

    return 0;
}