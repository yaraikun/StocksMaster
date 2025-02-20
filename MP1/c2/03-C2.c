/*
   GROUP NUMBER (2 digits): 03
   DATE SUBMITTED         : 16 FEBRUARY 2025

   LASTNAME1, FIRSTNAME1: CALUPIG, EVAN RILEY L        SECTION1: S23A
   LASTNAME1, FIRSTNAME1: ALCANTARA, GABRIEL ENRICO G  SECTION1: S22B

   NOTE: Encode ONLY your NAME if this code is for your own individual
         solution.
         Encode BOTH names and sections if this code is for your GROUP's final
         solution.

   CCPROG2 MP Solution for Challenge #2 (C2)

   You should compile this C source file in the command line using -Wall and -o
   as compiler options, for example:

       $ gcc -Wall -o 03-C2 03-C2.c

   You should run the executable in the command line with input and output
   redirection, for example:

       $ ./03-C2 < ACorig.txt > AC.txt

   where 03-C2 is the student's executable file,
   ACorig.txt is the source file, and AC.txt is the destination file.

   The '<' (less than symbol) is for input redirection, and the '>' (greater
   than symbol) * is for output redirection.

   Your program should:
   1. Read via scanf() the date entry as a string. It should also write via
      printf() the date as a string.
   2. Use a 1D array of strings to store the date values,
      use a 2D array of doubles for the OHLC values, and
      use a 1D array of doubles to store the volume values.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 1337    // 1216 + 10% as a buffer

/*
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT
    OR CAUSE POINT DEDUCTIONS!

    1. You are NOT allowed to use library functions that were NOT discussed in
       our class.
    2. You must apply arrays and strings in solving Challenge #2.
    3. Do NOT use the following yet for this particular challenge:
           a. struct data type
           b. file processing functions such as fopen(), fclose(), etc.
    4. Apply the divide-and-conquer technique by segregating your program's
       logic into functions. A solution where all the logic is in main() will
       result in a 2-point deduction!
    5. Document your functions with SENSIBLE comments.
       Each function definition must be PRECEDED by an online documentation
       comment describing the following:
           a. Purpose of the function
           b. Return value (write "void" if the function has no return value)
           c. Description of each parameter
           d. Pre-condition (assumptions about the parameters)

    Follow the documentation style in the LinearSearch() example below.
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
LinearSearch(key, int A[], int n)
{
	int i; // indexing variable

	// compare the search key with an element in the array
	for (i = 0; i < n; i++)
		if (key == A[i])  
			return i;  // this means that the key was found	

	return -1; // -1 means that the key not found
}
#endif

/* You may declare any typedef that you need below this comment. */

typedef char string10[11];  // for date
typedef char string2[3];    // for day, month
typedef char string4[5];    // for year

/* You may define any function that you need below this comment. */

/*
    Purpose: extracts the month, day, and year from a date string
    Returns: void (modifies month, day, and year string)
    @param : date is the input date string in "M/D/YY" or "MM/DD/YYYY" format
    @param : month is the output parameter for the extracted month
    @param : day is the output parameter for the extracted day
    @param : year is the output parameter for the extracted year
    Pre-condition: date is a valid date string containing exactly two '/'
                   characters.
*/
void parse_date(string10 date, string2 month, string2 day, string4 year)
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

/*
    Purpose: ensures a two-character format for month or day by adding a
             leading zero if necessary
    Returns: void (modifies part in place)
    @param : part is the month or day string to be formatted
    Pre-condition: part is a valid string containing one or two digits
*/
void format_part2(string2 part)
{
    string2 temp;   // temporary string for modification

    // adds a leading zeor if the part is a single digit
    if (strlen(part) == 1) {
        strcpy(temp, "0");
        strcat(temp, part);
        strcpy(part, temp);
    }
}

/*
    Purpose: ensures a four-character format for month or day by adding "20" as
             a prefix if necessary
    Returns: void (modifies part in place)
    @param : part is the year string to be formatted
    Pre-condition: part is a valid string containing one or two digits
*/
void format_part4(string4 part)
{
    string4 temp;   // temporary string for modification

    // adds "20" prefix if the year is in two-digit format
    if (strlen(part) == 2) {
        strcpy(temp, "20");
        strcat(temp, part);
        strcpy(part, temp);
    }
}

/*
    Purpose: converts a date string from various formats (e.g., "2/2/25",
             "02/02/2025") into a standardized "MM/DD/YYYY" format
    Returns: void (modifies the output string in place)
    @param : input is the date string to be formatted
    Pre-condition: input contains a valid date format and output has enough
                   space (at least 11 chars)
*/
void format_date(string10 date)
{
    string2 month, day;
    string4 year;

    // parse the input date into month, day, year parts
    parse_date(date, month, day, year);

    // ensure two-digit format for month and day
    format_part2(month);
    format_part2(day);

    // ensure four-digit format for year
    format_part4(year);

    // construct the formatted date
    strcpy(date, month);
    strcat(date, "/");
    strcat(date, day);
    strcat(date, "/");
    strcat(date, year);
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
void read_data(string10 date[], double ohlc[][4], double volume[],
               int *entries, string10 stock)
{
    string10 temp_date; // temporary buffer/holder for date
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
            format_date(temp_date); // format date before storing
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
    Purpose: prints financial data
    Returns: void (outputs data to standard output)
    @param : date contains formatted date strings
    @param : ohlc stores open, high, low, and close prices
    @param : volume stores the trading volume values
    @param : entries is the number of entries to print
    Pre-condition: arrays are properly initialized with valid data
*/
void print_data(string10 date[], double ohlc[][4], double volume[],
                int entries, string10 stock)
{
    int i;  // indexing variable

    // print stock name and number of entries
    printf("%s %d\n\n", stock, entries);

    // print data for each entry
    for (i = 0; i < entries; i++) {
        printf("%-12s %-10.2f %-10.2f %-10.2f %-10.2f %-12.2f\n",
               date[i],
               ohlc[i][0], ohlc[i][1], ohlc[i][2], ohlc[i][3],
               volume[i]);
    }
}

/*
    Purpose: handle program execution.
    Returns: 0 (successful execution).
    Pre-condition: input follows the expected format
*/
int main(void)
{
    /* Declare local variables. */
    string10 dates[MAX_ENTRIES];
    double ohlc[MAX_ENTRIES][4];
    double volume[MAX_ENTRIES];
    string10 stock_name;
    int num_entries;

    /* Call the function(s) that you defined. */
    read_data(dates, ohlc, volume, &num_entries, stock_name);
    print_data(dates, ohlc, volume, num_entries, stock_name);

    return 0;
}
