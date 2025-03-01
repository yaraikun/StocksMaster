/*
    Do not forget to encode the info for GROUP NUMBER, DATA SUBMITTED, name and section.
    A deduction of 0.5 point will be applied for not complying with this instruction!
    
    GROUP NUMBER (2 digits):
    DATE SUBMITTED         :

    LASTNAME1, FIRSTNAME1:                          SECTION1:
    LASTNAME1, FIRSTNAME2:                          SECTION2:

    NOTE: encode ONLY your NAME and section if this code is for your own individual solution
          encode BOTH names and sections if this code is for your GROUP's final solution

    CCPROG2 MP Solution for Challenge #8 (C8).

	Make sure that you do the following:
	
	1. COMPILE your C source code with -Wall directive.
	
	       Example: CCPROG2> gcc -Wall 01-C8.c 
  
   	   where 01 is an example group number and C8 is the Challenge number.
  
  	   You must replace 01 with your own group number!
  
	2. RUN the a.exe file in the command line with input and output (I/O) redirection.
	
	       Example: CCPROG2> a < AC.txt > 01-C8-AC-OUTPUT.txt	   

           The text file 01-C8-AC-OUTPUT.txt will contain the actual output of your program using AC.txt as input data source.
       
        3. COMPARE your program's output your program with the accompanying C8-AC-EXPECTED.txt file using bbtest.c.
    
	       In case you do not have bbtest.exe, produce it first by compiling bbtest.c as shown below:
		
		 	Example: CCPROG2> gcc -Wall bbtest.c -o bbtest.exe
		 	
		Thereafter, run bbtest.exe with I/O redirection as shown below:
		
			Example: CCPROG2> bbtest C8-AC-EXPECTED.txt 01-C8-AC-OUTPUT.TXT > 01-C8-AC-BBTEST.txt
			
		The output redirected file 01-C8-AC-BBTEST.txt contains the results of the comparison.  If you see Differences = 0
		towards the end of the file, then it means that your program's output matches the expected output.
		Otherwise, if you see a Differences value higher than 0, then there's a strong probability that you
		either have a logical error in your program, or you did NOT follow the MP specifications (including
		the directions in this file).
		
		Debug your C source file, and redo the steps above until you get Differences = 0.
		
		Take note, however, that Differences = 0 does NOT necessarily mean that your solutions is 100% logically
		correct.  The bbtest.exe only tests if two files have the same contents.  It is not meant to test the logic
		of your C program.
	
	4. TEST your solution using the stock historical data for other companies other than AC.txt.  Note that there
	   are no expected output files provided for other companies.  You'll have to figure out how to verify the 
	   correctness of your program's output on your own. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
	TO DO: replace GROUPNUMBER in the #include below with your own group number.  For example if you are group 1,
	you should have #include "01-C6.h".  Group numbers from 1 to 9 should have a leading zero in the filename.
*/
#include "03-C6.h"

/* 
	Do NOT define any constant in this file.  

        Do NOT declare any typedef that you need below this comment.

	You should encode your own #define and typedef declarations in your GROUPNUMBER-C6.h header file.
*/

// Do NOT edit/delete the next #include directive.
#include "C8.h"   // read and understand the contents of this file

/* Do NOT include other files. */ 


/* 
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
	1. You are NOT allowed to use library functions that were NOT discussed 
	   in our online class.
	2. You must apply arrays of structures in solving Challenge #8. 
	3. Do NOT use the following yet for this particular challenge:
	    a. file processing functions such as fopen(), fclose(), etc.
	4. Apply divide-and-conquer technique by segregating your program's logic into functions.
	   A solution where all the logic are found only in the main() function 
	   will result to a 2-point deduction!
	5. Document your functions with SENSIBLE comments. Each function definition must
	   be PRECEDED by an online documentation (in the form of comments) describing
	   concisely the following:
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
    TO DO: Implement a function that will read the stock historical data via scanf().  
	   The actual data will be supplied via input redirection.
		   
    Fill in the blanks.  The first missing item is the function name, and the second one 
    is the missing portion for the data type of formal parameter ptr_stock.  
    Take note that this function has ONE structure pointer formal parameter!
*/
void
___________________ ( ______ *ptr_stock)  // do NOT change the parameter name
{
	/* Implement the body of this function.  Declare your own local variables. */
	
}



/*
    TO DO: Implement the function ComputeSignal().  Do not change the function 
	   data type, function name and parameter names.
           
    Fill in the blank by supplying the missing portion only for the formal parameter ptr_stock.
    Take note that this function has TWO structure pointer parameters!
*/
void	
ComputeSignal(indicatorType *ptr_indicator, _________ *ptr_stock)  
{
	/* Implement the body of this function.  Declare your own local variables. */

	/* You may define other helper functions and call them inside ComputeSignal().
}



/*
	TO DO: Complete the body of the main() function.
*/
int
main()
{
	/* Do NOT change the next two lines of variable declarations. */
	int i, j;
        indicatorType indicator;  // NOTE: study the file C8.h file -- it contains 
	                          // the declaration of indicatorType alias.

	/* 
	   Do NOT change the next line of array definition. 
	   View the C8.h header file to see the values of the macros. 
	*/
	int test_cases[4] = { TEST_NDAYS1, TEST_NDAYS2, TEST_NDAYS3, TEST_NDAYS4 };  
	

	/* 
		TO DO: Declare your own local structure variable that will the store the SHD for a company read from an input text file
	*/
	__________ stock;  // supply the structure data type alias based on your C6 header file contents
	                   // the structure variable name should be stock -- don't change this!  
		
	 
	/* NOTE: The statements below should produce the required output. You are allowed to change or edit
	         ONLY those lines with blanks by filling-up the missing information.
	*/ 
	
	
	/* 
		TO DO: Fill in the blank by CALLing the function that you defined above for reading the stock historical data.
	*/
	____________________(&stock); // do NOT change the &stock parameter, do NOT add other parameters
	
	/* TO DO: Fill in the blank to print the company symbol. */
	printf("%s\n", __________); 
	
	/* TO DO: Fill in the blank to print the count/number of rows of stock historical data. */
	printf("%d\n", __________); 
	printf("\n");
	
	
	/*
		except for the strcpy() below, DO NOT change any of the codes below.
	*/
	for (i = 0; i < 3; i++) {

		/*
			TO DO: Fill in the blank to copy the stock symbol. 
		*/
		strcpy(indicator.symbol, __________);  
		
		indicator.mst = test_cases[i];   // number of days for the short term SMA, ex. 50-day MA
		indicator.mlt = test_cases[i+1]; // number of days for the long term SMA,  ex. 200-day MA
	
		ComputeSignal(&indicator, &stock);  // call the function that you implemented 
				
		// print the values computed by the student's solution
		printf("**TEST-CASE-%d**\n", i+1);
		printf("mst = %d-days, mlt = %d-days\n", indicator.mst, indicator.mlt);
   		printf("count = %d\n", indicator.count);   
   		for (j = 0; j < indicator.count; j++) {
   			printf("%3d   %10s %10.2lf %10.2lf   ", j+1, indicator.SIGNAL[j].date, 
			        indicator.SIGNAL[j].short_term_MA, indicator.SIGNAL[j].long_term_MA);
   			if (indicator.SIGNAL[j].signal == 'B') 
			   printf("BUY\n");
			else if (indicator.SIGNAL[j].signal == 'S')
					printf("SELL\n");
			else printf("INCORRECT!\n");  // NOTE: there's a logical error in the student solution if this printf() executes!!!!
		}		
	   	printf("\n\n");
	}

	/*         
	   Refer to the accompanying C8-AC-EXPECTED.TXT to see the expected results using AC.TXT as input files
	*/

   	return 0;
}
