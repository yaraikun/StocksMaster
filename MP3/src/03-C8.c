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

    CCPROG2 MP Solution for Challenge #8 (C8).

    Make sure that you do the following:

    1. COMPILE your C source code with -Wall directive.

       Example: CCPROG2> gcc -Wall 01-C8.c

       where 01 is an example group number and C8 is the Challenge number.

       You must replace 01 with your own group number!

    2. RUN the a.exe file in the command line with input and output (I/O)
       redirection.

       Example: CCPROG2> a < AC.txt > 01-C8-AC-OUTPUT.txt

       The text file 01-C8-AC-OUTPUT.txt will contain the actual output of your
       program using AC.txt as input data source.

    3. COMPARE your program's output your program with the accompanying
       C8-AC-EXPECTED.txt file using bbtest.c.

       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:

       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe

       Thereafter, run bbtest.exe with I/O redirection as shown below:

       Example: CCPROG2> bbtest C8-AC-EXPECTED.txt 01-C8-AC-OUTPUT.TXT >
                         01-C8-AC-BBTEST.txt

       The output redirected file 01-C8-AC-BBTEST.txt contains the results of
       the comparison. If you see Differences = 0 towards the end of the file,
       then it means that your program's output matches the expected output.
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

    4. TEST your solution using the stock historical data for other companies
       other than AC.txt. Note that there are no expected output files provided
       for other companies. You'll have to figure out how to verify the
       correctness of your program's output on your own.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    TO DO: replace GROUPNUMBER in the #include below with your own group
    number. For example if you are group 1, you should have #include "01-C6.h".
    Group numbers from 1 to 9 should have a leading zero in the filename.
*/
#include "03-C6.h"

/*
    Do NOT define any constant in this file.

    Do NOT declare any typedef that you need below this comment.

    You should encode your own #define and typedef declarations in your
    GROUPNUMBER-C6.h header file.
*/

// Do NOT edit/delete the next #include directive.
#include "C8.h" // read and understand the contents of this file

/* Do NOT include other files. */

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or
    CAUSE POINT DEDUCTIONS!

    1. You are NOT allowed to use library functions that were NOT discussed in
       our online class.
    2. You must apply arrays of structures in solving Challenge #8.
    3. Do NOT use the following yet for this particular challenge:
        a. file processing functions such as fopen(), fclose(), etc.
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
            return i; // this means that the key was found	

    return -1; // -1 means that the key not found
}
#endif

/*
    TO DO: Implement a function that will read the stock historical data via
    scanf(). The actual data will be supplied via input redirection.

    Fill in the blanks. The first missing item is the function name, and the
    second one is the missing portion for the data type of formal parameter
    ptr_stock. Take note that this function has ONE structure pointer formal
    parameter!
*/

/*
    Purpose: read the SHD for the stock
    Returns: void (reads and assigns values to the stock structure)
    @param : ptr_stock is a pointer to a stock of type stockType
    Pre-condition: the structure ptr_stock points to is a valid structure with
                   the necessary members
*/
void read_data(stockType *ptr_stock) // do NOT change the parameter name
{
    /*
        Implement the body of this function. Declare your own local variables.
    */

    // indexing variables
    int i;
    int j;

    // temporary variables for storing the values
    StrStock symbol;
    int num_entries;
    StrDate date;
    double ohlc[4];
    double volume;

    // read inputs then copy values to structure
    scanf("%s %d", symbol, &num_entries);

    strcpy(ptr_stock->symbol, symbol);
    ptr_stock->num_entries = num_entries;

    // read SHD for each row
    for (i = 0; i < num_entries; i++) {
        scanf("%s %lf %lf %lf %lf %lf",
               date, ohlc, ohlc+1, ohlc+2, ohlc+3, &volume);

        // copy the input data into the respective SHD row
        strcpy(ptr_stock->records[i].date, date);
        for (j = 0; j < 4; j++) ptr_stock->records[i].ohlc[j] = ohlc[j];
        ptr_stock->records[i].volume = volume;
    }
}

/*
    TO DO: Implement the function ComputeSignal(). Do not change the function
    data type, function name and parameter names.

    Fill in the blank by supplying the missing portion only for the formal
    parameter ptr_stock. Take note that this function has TWO structure pointer
    parameters!
*/

/*
    ComputeSignal() Helper Function #1
    Note   : This function is periodically called to prevent floating-point
             precision errors from accumulating in the rolling sum updates.
    Purpose: computes the rolling sum for the short-term and long-term
             moving averages
    Returns: void (updates sst and slt directly via pointers)
    @param : ptr_stock is a pointer to a struct of type stockType
    @param : ptr_indicator is a pointer to a struct of type indicatorType
    @param : i is the current index in the dataset
    @param : sst is a pointer to store the computed short-term sum
    @param : slt is a pointer to store the computed long-term sum
    Pre-condition: the structure pointers point to valid structures with the
                   necessary members, and the members contain valid values
*/
void ComputeRollingSum(stockType *ptr_stock, indicatorType *ptr_indicator, int i, double *sst, double *slt)
{
    *sst = 0;
    *slt = 0;

    for (int j = i; j < i + ptr_indicator->mlt; j++) {
        if (j < i + ptr_indicator->mst)
            *sst += ptr_stock->records[j].ohlc[3]; // short-term sum
        *slt += ptr_stock->records[j].ohlc[3];     // long-term sum
    }
}

/*
    ComputeSignal() Helper Function #2
    Purpose: computes the short-term and long-term moving averages
    Returns: void (assigns values to ast and alt via pointers)
    @param : sst is the computed short-term rolling sum
    @param : slt is the computed long-term rolling sum
    @param : ptr_indicator is a pointer to a struct of type indicatorType
    @param : ast is a pointer to store the computed short-term moving average
    @param : alt is a pointer to store the computed long-term moving average
    Pre-condition: the rolling sums have been correctly computed.
*/
void ComputeAverages(double sst, double slt, indicatorType *ptr_indicator, double *ast, double *alt)
{
    // NOTE: casted mst and mlt to (double) helps reduce floating-point errors
    //       for some compilers.
    *ast = sst / (double) ptr_indicator->mst;
    *alt = slt / (double) ptr_indicator->mlt;
    // *ast = sst * (1.0 / ptr_indicator->mst);
    // *alt = slt * (1.0 / ptr_indicator->mlt);
}

/*
    ComputeSignal() Helper Function #3
    Purpose: copies the computed moving averages into the indicator struct
             and assigns the buy/sell signal
    Returns: void (modifies ptr_indicator->SIGNAL[count] directly)
    @param : ptr_indicator is a pointer to a struct of type indicatorType
    @param : ptr_stock is a pointer to a struct of type stockType
    @param : i is the current index in the dataset
    @param : count is the current signal count index
    @param : ast is the computed short-term moving average
    @param : alt is the computed long-term moving average
    Pre-condition: moving averages have been correctly computed
*/
void UpdateSignal(indicatorType *ptr_indicator, stockType *ptr_stock, int i, int count, double ast, double alt)
{
    strcpy(ptr_indicator->SIGNAL[count].date, ptr_stock->records[i].date);
    ptr_indicator->SIGNAL[count].short_term_MA = ast;
    ptr_indicator->SIGNAL[count].long_term_MA = alt;
    ptr_indicator->SIGNAL[count].signal = ast > alt ? 'B' : 'S';
}

/*
    ComputeSignal() Helper Function #4
    Note   : This function allows the rolling sum approach to work efficiently
             while avoiding full recalculations at each iteration.
    Purpose: updates the rolling sum by removing the oldest value and adding
             the newest value to maintain a moving sum
    Returns: void (modifies sst and slt directly via pointers)
    @param : ptr_stock is a pointer to a struct of type stockType
    @param : ptr_indicator is a pointer to a struct of type indicatorType
    @param : i is the current index in the dataset
    @param : sst is a pointer to the short-term rolling sum
    @param : slt is a pointer to the long-term rolling sum
    Pre-condition: the rolling sums have been correctly initialized
*/
void UpdateRollingSum(stockType *ptr_stock, indicatorType *ptr_indicator, int i, double *sst, double *slt)
{
    // remove old values
    *sst -= ptr_stock->records[i + ptr_indicator->mst - 1].ohlc[3];
    *slt -= ptr_stock->records[i + ptr_indicator->mlt - 1].ohlc[3];

    // add new values
    *sst += ptr_stock->records[i - 1].ohlc[3];
    *slt += ptr_stock->records[i - 1].ohlc[3];

    // NOTE: last iteration accesses out of bounds index, but value is not used
    // at the end
}

/*
    Purpose: Computes the signal value from the m-day averages.
    Returns: void (assigns values to struct)
    @param : ptr_indicator is a pointer to a struct of type indicatorType
    @param : ptr_stock is a pointer to a stock of type stockType
    Pre-condition: The structure pointers point to valid structures with the
                   necessary members, and the members contain valid values.
*/
void ComputeSignal(indicatorType *ptr_indicator, stockType *ptr_stock)
{
    /*
        Implement the body of this function. Declare your own local variables.
    */

    int i;      // indexing variable
    int count;  // accumulator variable
    double sst; // short term sum
    double ast; // short term average
    double slt; // long term sum
    double alt; // long term average

    /*
        You may define other helper functions and call them inside
        ComputeSignal().
    */

    // always initialize accumulator variables
    count = 0;
    sst = 0;
    slt = 0;

    int k = 25; // sum recalculation frequency

    // indexes from the last possible index to the first (remember the dataset
    // is in descending chronological order)
    for (i = ptr_stock->num_entries - ptr_indicator->mlt; i >= 0; i--)
    {
        // NOTE: this periodic sum reset is my "meet in the middle" solution --
        //       no need to recalculate the sum every turn, while still
        //       maintaining a degree of accuracy with the values compared to a
        //       pure rolling-sum solution
        if (count % k == 0)
            ComputeRollingSum(ptr_stock, ptr_indicator, i, &sst, &slt);

        ComputeAverages(sst, slt, ptr_indicator, &ast, &alt);
        UpdateSignal(ptr_indicator, ptr_stock, i, count++, ast, alt);
        UpdateRollingSum(ptr_stock, ptr_indicator, i, &sst, &slt);
    }

    ptr_indicator->count = count;
}

/*
    TO DO: Complete the body of the main() function.
*/
int main()
{
    /* Do NOT change the next two lines of variable declarations. */
    int i, j;
    indicatorType indicator; // NOTE: study the file C8.h file -- it contains
                             // the declaration of indicatorType alias.

    /*
        Do NOT change the next line of array definition. View the C8.h header
        file to see the values of the macros.
    */
    int test_cases[4] = {TEST_NDAYS1, TEST_NDAYS2, TEST_NDAYS3, TEST_NDAYS4};

    /*
        TO DO: Declare your own local structure variable that will the store
        the SHD for a company read from an input text file
    */
    stockType stock; // supply the structure data type alias based on your C6 
                     // header file contents the structure variable name should
                     // be stock -- don't change this!

    /*
        NOTE: The statements below should produce the required output. You are
        allowed to change or edit ONLY those lines with blanks by filling-up
        the missing information.
    */

    /*
        TO DO: Fill in the blank by CALLing the function that you defined
        above for reading the stock historical data.
    */
    read_data(&stock); // do NOT change the &stock parameter, do NOT add other
                       // parameters

    /* TO DO: Fill in the blank to print the company symbol. */
    printf("%s\n", stock.symbol);

    /*
        TO DO: Fill in the blank to print the count/number of rows of stock
        historical data.
    */
    printf("%d\n", stock.num_entries);
    printf("\n");

    /*
        except for the strcpy() below, DO NOT change any of the codes below.
    */
    for (i = 0; i < 3; i++) {
        /*
            TO DO: Fill in the blank to copy the stock symbol.
        */
        strcpy(indicator.symbol, stock.symbol);

        indicator.mst = test_cases[i];     // number of days for the short term
                                           // SMA, ex. 50-day MA
        indicator.mlt = test_cases[i + 1]; // number of days for the long term
                                           // SMA,  ex. 200-day MA

        ComputeSignal(&indicator, &stock); // call the function that you
                                           // implemented

        // print the values computed by the student's solution
        printf("**TEST-CASE-%d**\n", i + 1);
        printf("mst = %d-days, mlt = %d-days\n", indicator.mst,
                indicator.mlt);
        printf("count = %d\n", indicator.count);
        for (j = 0; j < indicator.count; j++) {
            printf("%3d   %10s %10.2lf %10.2lf   ", j + 1,
                    indicator.SIGNAL[j].date,
                    indicator.SIGNAL[j].short_term_MA,
                    indicator.SIGNAL[j].long_term_MA);
            if (indicator.SIGNAL[j].signal == 'B')
                printf("BUY\n");
            else if (indicator.SIGNAL[j].signal == 'S')
                printf("SELL\n");
            else
                printf("INCORRECT!\n"); // NOTE: there's a logical error in the
                                        // student solution if this printf() 
                                        // executes!!!!
        }
        printf("\n\n");
    }

    /*
        Refer to the accompanying C8-AC-EXPECTED.TXT to see the expected
        results using AC.TXT as input files
    */

    return 0;
}
