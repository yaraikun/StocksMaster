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
    
    CCPROG2 MP Solution for Challenge #7 (C7).
    
    Make sure that you do the following:
    
    1. COMPILE your C source code with -Wall directive.
    
       Example: CCPROG2> gcc -Wall 01-C7.c
       
       where 01 is an example group number and C7 is the Challenge number.
       
       You must replace 01 with your own group number!
    
    2. RUN the a.exe file in the command line with input and output (I/O)
       redirection.
    
       Example: CCPROG2> a < AC.txt > 01-C7-AC-OUTPUT.txt	   
       
       The text file 01-C7-AC-OUTPUT.txt will contain the actual output of
       your program using AC.txt stock data.
    
    3. COMPARE your program's output with the accompanying
       C7-AC-EXPECTED.txt file using bbtest.c.
    
       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:
       
       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
       
       Thereafter, run bbtest.exe with I/O redirection as shown below:
       
       Example: CCPROG2> bbtest C7-AC-EXPECTED.txt 01-C7-AC-OUTPUT.TXT >
                         01-C7-AC-BBTEST.txt
       
       The output redirected file 01-C7-AC-BBTEST.txt contains the results of
       the comparison.  If you see Differences = 0 towards the end of the
       file, then it means that your program's output matches the expected
       output. Otherwise, if you see a Differences value higher than 0, then
       there's a strong probability that you either have a logical error in
       your program, or you did NOT follow the MP specifications (including
       the directions in this file).
       
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
    TO DO: replace GROUPNUMBER in the #include below with your own group number.
    For example if you are group 1, you should have #include "01-C6.h". Group
    numbers from 1 to 9 should have a leading zero in the filename.
*/
#include "03-C6.h"

/* 
    Do NOT define any constant in this file.  

    Do NOT declare any typedef that you need below this comment.

    You should encode your own #define and typedef declarations in your
    GROUPNUMBER-C6.h header file.
*/

// Do NOT edit/delete the next two #include directives.
#include "C7.h"                     // read and understand the contents of
                                    // this file
#include "numeric_date_helpers.c"   // read and understand the contents of
                                    // this file

/* Do NOT include other files. */ 

/* 
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or
    CAUSE POINT DEDUCTIONS!

    1. You are NOT allowed to use library functions that were NOT discussed in
       our class.

    2. You must apply arrays of structures in solving Challenge #7. 

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
    TO DO: Implement a function that will read the stock historical data via
    scanf(). The actual data will be supplied via input redirection.

    Fill in the blanks.  The first missing item is the function name, and the
    second one is the missing portion for the data type of formal parameter
    ptr_stock. Take note that this function has ONE structure pointer formal
    parameter!
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
    StrStock temp_symbol;
    int temp_num_entries;
    StrDate temp_date;
    double temp_ohlc[4];
    double temp_volume;

    // pointer to the actual SHD for easier access
    shdType *stock_data = ptr_stock->records;

    // pointer to current row of SHD used in loop
    shdType *current_record;
    
    // first read the inputs onto temporary variables
    scanf("%s %d", temp_symbol, &temp_num_entries);

    // copy values to structure
    strcpy(ptr_stock->symbol, temp_symbol);
    ptr_stock->num_entries = temp_num_entries;

    // read data each row
    for (i = 0; i < temp_num_entries; i++) {
        scanf("%s %lf %lf %lf %lf %lf", // read ONE ROW of SHD data
               temp_date,
               temp_ohlc,
               temp_ohlc + 1,
               temp_ohlc + 2,
               temp_ohlc + 3,
               &temp_volume);

        // get the pointer to the current row of SHD
        current_record = stock_data + i;

        // copy the data to the SHD records in the structure
        strcpy(current_record->date, temp_date);    // copy the date

        for (j = 0; j < 4; j++)
            current_record->ohlc[j] = temp_ohlc[j]; // copy the ohlc values

        current_record->volume = temp_volume;       // copy the volume
    }
}

/*
    TO DO: Implement a binary search function.

    Fill in the blanks.  The  missing items are the return data type, the
    function name, and the formal parameters.
*/
int binary_search (StrDate key, stockType *ptr_stock)
{
    /*
        Implement the body of this function. Declare your own local variables.
    */
    int low, mid, high, found;

    int num_key;
    int num_date;

    low = 0;
    high = ptr_stock->num_entries - 1;
    found = 0;

    num_key = numeric_date(key);

    while (!found && low <= high) {
        mid = low + (high - low) / 2;
        num_date = numeric_date(ptr_stock->records[mid].date);
        if (num_key == num_date)
            found = 1;
        else if (num_key < num_date)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return found ? mid : -1;
}

/*
    TO DO: Implement the Trade() function. Do NOT change the return type, 
    function name, and formal parameter names.

    Fill in the blank by supplying the data type of the formal parameter 
    named as ptr_stock.	 

    Take note that this function has ONE structure pointer formal parameter!
*/
void Trade(StrDate buy_date, StrDate sell_date, stockType *ptrStock)
{
    /*
        Implement the body of this function. Declare your own local variables.
    */
    int buy_index;
    int sell_index;
    double buy_price;
    double sell_price;
    double PL;
    double percent_PL;

    /* 
        IMPORTANT: The Trade() function must call the binary search function,
        defined above, TWO times. The first time is to search the buy_date.
        The second time is to search the sell_date.
    */    
    buy_index = binary_search(buy_date, ptrStock);
    sell_index = binary_search(sell_date, ptrStock);

    buy_price = ptrStock->records[buy_index].ohlc[3];
    sell_price = ptrStock->records[sell_index].ohlc[3];

    PL = sell_price - buy_price;
    percent_PL = PL / buy_price * 100;

    printf("BUY DATE %s FOUND IN INDEX %d!  BUY PRICE = %.2lf\n",
            buy_date, buy_index, buy_price);
    printf("SELL DATE %s FOUND IN INDEX %d!  SELL PRICE = %.2lf\n",
            sell_date, sell_index, sell_price);
    printf("P/L = %.2lf\n", PL);
    printf("%%P/L = %.2lf\n", percent_PL);
}

/*
    TO DO: Complete the body of the main() function.
*/
int main()
{	
    /* Do NOT change the next line of variable declaration. */
    int i;	

    /*
        Do NOT change the next two lines of array definition. View the C7.h
        header file to see the values of the macros.
    */
    StrDate buy_date[5]  = {TEST_BUYDATE1, TEST_BUYDATE2, TEST_BUYDATE3,
                            TEST_BUYDATE4, TEST_BUYDATE5};
    StrDate sell_date[5] = {TEST_SELLDATE1, TEST_SELLDATE2, TEST_SELLDATE3,
                            TEST_SELLDATE4, TEST_SELLDATE5};

    /* 
        TO DO: Declare your own local structure variable that will the store
        ALL the SHD for ONE company read from an input text file.
    */
    stockType stock; // supply the structure data type alias based on your C6
                     // header file contents
                     // the structure variable name should be stock -- don't
                     // change this!  

    /*
        NOTE: The statements below should produce the required output. You are
        allowed to change or edit ONLY those lines with blanks by filling-up
        the missing information.
    */   

    /* 
        TO DO: Fill in the blank by CALLing the function that you defined above
        for reading the stock historical data.
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
        DO NOT change any of the codes below.
    */
    for (i = 0; i < 5; i++) {
        printf("**TEST-CASE-%d**\n", i + 1);      // there are 5 test cases
        Trade(buy_date[i], sell_date[i], &stock); // you'll need to implement
                                                  // the Trade() function
        printf("\n");
    }

    /*         
        Refer to the accompanying C7-AC-EXPECTED.TXT to see the expected
        results using AC.TXT as input file.
    */

    return 0;
}