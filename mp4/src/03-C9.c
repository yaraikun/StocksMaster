/*
    Do not forget to encode the info for GROUP NUMBER, DATE SUBMITTED, NAMES and
    SECTIONS.
    A deduction of 0.5 point will be applied for not complying with this
    instruction!

    GROUP NUMBER (2 digits):
    DATE SUBMITTED         :

    LASTNAME1, FIRSTNAME1:                          SECTION1:

    NOTE: encode ONLY your NAME and section if this code is for your own 
          individual solution encode BOTH names and sections if this code is for
          your GROUP's final solution

    Make sure that you do the following:

    1. COMPILE your C source code with -Wall directive.

           Example: CCPROG2> gcc -Wall 01-C9.c

       where 01 is an example group number and C9 is the Challenge number.

       You must replace 01 with your own group number!

    2. RUN the program's exe file in the command line. Unlike the previous
       challenges you should NOT use I/O redirection.

       Example: CCPROG2> a

       The input data should be read from the text files stored in the
       accompanying folder named as SHD.

       The output file should NOT be created inside the accompanying SHD folder;
       it should be in the same folder where you have your C source file.

       For the 1st test function call in main(), a new output text file named
       as 01-AC.txt will be produced after the program execution.

       For the 2nd test function call, an error message "XYZ data file not
       found." will be displayed on the standard error device (i.e., display
       screen) via fprintf(stderr, _____).

       Lastly, the 3rd test function call will perform the required task based
       on a symbol input by the user.

    3. COMPARE your program's output text file (using AC.txt as input data) with
       the accompanying C9-AC-EXPECTED.txt file using bbtest.c.

       In case you do not have bbtest.exe, produce it first by compiling
       bbtest.c as shown below:

       Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe

       Thereafter, run bbtest.exe with I/O redirection as shown below:

       Example: CCPROG2> bbtest C9-AC-EXPECTED.txt 01-AC.txt > 01-C9-BBTEST.txt

       The output redirected file 01-C9-BBTEST.txt contains the results of the
       comparison. If you see Differences = 0 towards the end of the file, then
       it means that your program's output matches the expected output.
       Otherwise, if you see a Differences value higher than 0, then there's a
       strong probability that you either have a logical error in your program,
       or you did NOT follow the MP specifications (including the directions in
       this file).

       Debug your C source file, and redo the steps above until you get
       Differences = 0.

       Take note, however, that Differences = 0 does NOT necessarily mean that
       your solution is 100% logically correct. The bbtest.exe only tests if two
       files have the same contents. It is not meant to test the logic of your C
       program.

    4. TEST your solution using the stock historical data for other companies
       other than AC.txt. Note that there are no expected output files provided
       for other companies. You'll have to figure out how to verify the
       correctness of your program's output on your own.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    For C9: you have the option to use or not to use the structure data type you
            declared in your C6 header file. If you decide to use it, then
            uncomment Line 80, and replace GROUPNUMBER in the #include with your
            own group number. For example if you are group 1, you should have
            #include "01-C6.h". Group numbers from 1 to 9 should have a leading
            zero in the filename.
*/
#include "03-C6.h"

// Do NOT edit/delete the next #include directive
#include "numeric_date_helpers.c" // read and understand the contents of this
                                  // file

/* Do NOT include other files. */

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE
    POINT DEDUCTIONS!

    1. You are required to use TEXT FILE PROCESSING commands fopen(), fclose(),
       fscanf() and fprintf() on top of previous topics in solving Challenge #9.
    2. You are NOT allowed to use library functions that were NOT discussed in
       our class.
    3. Apply divide-and-conquer technique by segregating your program's logic
       into functions. A solution where all the logic are found only in the
       main() function will result to a 2-point deduction!
    4. Document your functions with SENSIBLE comments. Each function definition
       must be PRECEDED by an online documentation (in the form of comments)
       describing concisely the following:
       a. What is the purpose of the function?
       b. What is the nature of the functions return value (write "void" if
          the function is of type void)
       c. What is the nature of each formal parameter?
       d. Pre-condition - what are the assumptions about the formal parameters?

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

/* TO DO: define the functions that you need below this comment. */
typedef char Str30[31];

void parse_date(StrDate date, StrDate month, StrDate day, StrDate year)
{
    int i = 0, j = 0;   // indexing variables

    // extract month
    while (date[i] != '/')
        month[j++] = date[i++]; // indexes through the date and part string
    month[j] = '\0';

    i++;                        // continues indexing through date string
    j = 0;                      // refreshes the part string index to 0

    // extract day
    while (date[i] != '/')
        day[j++] = date[i++];
    day[j] = '\0';

    i++;
    j = 0;

    // extract year
    while (date[i] != '\0')
        year[j++] = date[i++];
    year[j] = '\0';
}

void wordify_month(StrDate month)
{
   int n_month = GetMonth(month);
   
   switch(n_month) {
      case 1: strcpy(month, "JAN"); break;
      case 2: strcpy(month, "FEB"); break;
      case 3: strcpy(month, "MAR"); break;
      case 4: strcpy(month, "APR"); break;
      case 5: strcpy(month, "MAY"); break;
      case 6: strcpy(month, "JUN"); break;
      case 7: strcpy(month, "JUL"); break;
      case 8: strcpy(month, "AUG"); break;
      case 9: strcpy(month, "SEP"); break;
      case 10: strcpy(month, "OCT"); break;
      case 11: strcpy(month, "NOV"); break;
      case 12: strcpy(month, "DEC"); break;
   }
}

void format_date(StrDate date)
{
   StrDate month, day, year, temp;

   parse_date(date, month, day, year);

   wordify_month(month);

   strcpy(temp, year);
   strcat(temp, "-");
   strcat(temp, month);
   strcat(temp, "-");
   strcat(temp, day);

   strcpy(date, temp);
}

int read_stock_data(stockType *stock, char *symbol)
{
   int i;
   FILE *fp;
   Str30 file_name;

   strcpy(file_name, symbol);
   strcat(file_name, ".txt");

   fp = fopen(file_name, "r");

   if (fp == NULL) {
      fprintf(stderr, "ERROR: %s.TXT not found!\n", symbol);
      return 1;
   }

   fscanf(fp, "%s %d", stock->symbol, &stock->num_entries);

   for (i = 0; i < stock->num_entries; i++) {
      fscanf(fp, "%s %lf %lf %lf %lf %lf",
             stock->records[i].date,
             &stock->records[i].ohlc[0],
             &stock->records[i].ohlc[1],
             &stock->records[i].ohlc[2],
             &stock->records[i].ohlc[3],
             &stock->records[i].volume);
   }

   fclose(fp);

   return 0;
}

void swap_record(shdType *A, shdType *B)
{
   shdType temp;
   temp = *A;
   *A = *B;
   *B = temp;
}

void sort_stock_data(stockType *stock)
{
   int i, j, min;

   long int date_min, date_j;

   for (i = 0; i < stock->num_entries - 1; i++) {
      min = i;

      date_min = numeric_date(stock->records[min].date);

      for (j = i + 1; j < stock->num_entries; j++) {
         date_j = numeric_date(stock->records[j].date);
         if (date_min > date_j)
            min = j;
      }

      if (i != min) {
         swap_record(&stock->records[i], &stock->records[min]);
      }
   }
}

void write_stock_data(stockType *stock)
{
   int i;
   FILE *fp;

   Str30 file_name;

   strcpy(file_name, "03-");
   strcat(file_name, stock->symbol);
   strcat(file_name, ".txt");

   fp = fopen(file_name, "w");

   fprintf(fp, "%s %d\n\n", stock->symbol, stock->num_entries);

   for (i = 0; i < stock->num_entries; i++) {
      format_date(stock->records[i].date);
      fprintf(fp, "%s  %.2lf  %.2lf  %.2lf  %.2lf  %.2lf\n",
              stock->records[i].date,
              stock->records[i].ohlc[0],
              stock->records[i].ohlc[1],
              stock->records[i].ohlc[2],
              stock->records[i].ohlc[3],
              stock->records[i].volume);
   }

   fclose(fp);
}

void process_stock(char *symbol)
{
    stockType stock;

    if (read_stock_data(&stock, symbol) == 0) {
        sort_stock_data(&stock);
        write_stock_data(&stock);
    }
}

/*
   main() function for testing student's solution.
*/
int main()
{
    char symbol[8];
    // Do NOT declare/use other local variables.

    /*
        Fill in the blank by supplying the missing name of the function that
        will accomplish the following:

        1. Read the contents of the input text file containing the stock
           historical data for the company corresponding to the symbol specified
           as actual parameter. For example, if the actual parameter is "AC",
           then the function should read ALL the contents of the file "AC.txt"
           stored in the SHD folder.

        2. Write the contents of the output text file which contains basically
           the same set of values as the input text file but with TWO
           differences:
           a. the date values are formatted as "YYYY-AA-DD" (for example,
              "2021-OCT-27") where "AAA" represents the first 3 characters of
              the month in word (in capital letters), i.e., "JAN", "FEB", ...,
              "NOV", "DEC".
           b. the rows of data are in listed in CHRONOLOGICAL order starting
              from the oldest date to the most recent date.

        The name of the output text file should be GROUPNUMBER-SYMBOL.txt where
        SYMBOL is the stock's symbol. For example, if your group number is 1,
        and the stock symbol is AC, then the output file should be named as
        01-AC.txt.

        DO NOT ADD/EDIT ANY OTHER CODES ASIDE FROM THOSE REQUIRED IN THE 3
        BLANKS!!!
    */

    // #1: Call the function that will do fullfill the C9 requirements.
    //     Fill in the missing function name with "AC" as actual parameter
    //     value.
    process_stock("AC"); // TEST #1: AC -- test the solution for an existing
                         // stock symbol AC.txt. Your program should produce the
                         // output text file named GROUPNUMBER-AC.txt located in
                         // the same folder as your C source file.

    // #2. Do a second function call, this time with "XYZ" as the actual
    //     parameter value.
    process_stock("XYZ"); // TEST #2: XYZ -- test the solution for a
                          // NON-existent stock symbol. Since there's no company
                          // with XYZ as stock symbol, your solution should
                          // display an error message on the standard error
                          // device. The EXACT error message should be:
                          //     "ERROR: XYZ.TXT not found!" (don't forget the
                          //     exclamation mark)
                          // NOTE: You must use fprintf(stderr, ____) to display
                          // the error message.

    // #3. Do a third function call, this time with a company symbol input by
    //     the user.
    printf("Input the stock symbol: ");
    fflush(stdout);
    scanf("%s", symbol);   // symbol may or may not exist (ex. "MPI", "GTCAP",
                           // "ZZZ", etc...)
    process_stock(symbol); // TEST #3: -- test using a symbol input by the user

    return 0;
}
