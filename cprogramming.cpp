#include "stdafx.h"
#include "stdio.h"


/* print Fahrenheit-Celsius table
for fahr = 0, 20, ...., 300*/
void myFirstForloop()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while ( fahr <= upper )
	{
		celsius = 5 * (fahr - 32) / 9;
		//printf( "%3d\t\%3d\n", fahr, celsius );
		fahr = fahr + step;
	}
}

void anotherForLoop()
{
	int fahr;
	//now with a for loop.  and less variables.  we only need int fahr here!
	printf( "for loop:\n" );
	for ( fahr = 0; fahr <= 300; fahr = fahr + 20 )
	{
		printf( "%3d %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32) );
	}
}

void exercise1_5()
{
	int fahr;
	printf( "Excersize 1-5, Modify the temperature conversion program to print the table in reverse order, that is from 300 degrees to 0 1-5:\n" );
	for ( fahr = 300; fahr >= 0; fahr = fahr - 20 )
	{
		printf( "%3d %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32) );
	}
}

void controlzHint()
{
	printf( "(control-z followed by enter to end)\n" );
}

void  exercise1_8()
{
	printf( "getchar(), type chars, type some stuff and I will count tabs,spaces, and newlines \n" );
	controlzHint();
	int c, newlines, tabs, spaces;
	newlines = 0;
	tabs = 0;
	spaces = 0;
	while ( (c = getchar()) != EOF )
	{
		if ( c == '\n' )
		{
			++newlines;
		}
		else if ( c == '\t' )
		{
			++tabs;
		}
		else if ( c == ' ' )
		{
			++spaces;
		}
	}
	printf( "tabs:     %3d\n", tabs );
	printf( "spaces:   %3d\n", spaces );
	printf( "newlines: %3d\n", newlines );
}

void  exercise1_9()
{
	printf( "Write a program to copy it's input to it's output, replacing each string of one or more blanks by a single blank\n" );
	controlzHint();

	int c;
	bool inspace = false;

	while ( (c = getchar()) != EOF )
	{
		if ( c == ' ' )
		{
			if ( !inspace )
			{
				inspace = true;
				putchar( c );
			}
		}
		else
		{
			inspace = false;
			putchar( c );
		}
	}
}

void exercise1_10()
{
	printf( "Write a program to copy it's input to it's output, replacing each tab by \\t, each backspace by \\b, and each backslash by \\\\, This makes tabs and backspaces visible in an unanbiguous way.\n" );
	controlzHint();

	int c;

	while ( (c = getchar()) != EOF )
	{
		if ( c == '\t' )
		{
			putchar( '\\' );
			putchar( 't' );
		}
		else if ( c == '\b' )
		{
			//note this didn't work for me.. I failed!
			putchar( '\\' );
			putchar( 'b' );
		}
		else if ( c == '\\' )
		{
			putchar( '\\' );
			putchar( '\\' );
		}
		else
		{
			putchar( c );
		}
	}
}
#define IN  1 /* inside a word */
#define OUT 2 /* outside a word */

void word_counting_program()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);

}

// exercize 1_11  how would you test the word count program?  What kinds of input are the most likely to uncover bugs if any?

// Answer: I would run it and type things into it ( I just did ).   If that were part of a seperate function I might run differen't string through it or even generate things.  
// this isn't really counting word characters, just characters between spaces.  "asdfasd ; +" would count 3 words


void exercise1_12()
{
	printf("Write a program that prints its input one word per line.\n");
	controlzHint();

	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	// a note about this, it's kind of strange that this kind of just works.
	// like things that are printed, aren't printed untill enter is pressed is just happy coincidence.
	// I would expect to have to store those things *somehow* and then process them.  
	// This is a Console behavior that's outside of the scope of what the book is trying to teach at this point.
	
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			printf("\n%c", c);
			state = IN;
			++nw;
		}
		else
		{
			printf("%c", c);
		}
	}
}

//normally would go at top of file.. 
#define LOWER 0
#define UPPER 300
#define STEP 20

void symbolic_constants()
{
	int fahr;
	printf( "Symbolic Constants:\n" );
	for ( fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP )
	{
		printf( "%3d %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32) );
	}

}

void getCharCountChars()
{
	printf( "getchar(), type chars, control-z followed by enter to show count of characters typed\n" );
	controlzHint();
	long nc;
	nc = 0;
	while ( getchar() != EOF )
	{
		++nc;
	}
	printf( "%1d\n", nc );
}

void getCharCountLines()
{

	printf( "getchar(), type chars with enter\n" );
	controlzHint();
	int c, nl;
	nl = 0;
	while ( (c = getchar()) != EOF )
	{
		if ( c == '\n' )
		{
			++nl;
		}
	}
	printf( "%d\n", nl );
}




void array_example()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
	{
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			// took a second on this example bit, but I get it! '0' in char is a char (256) value of some thing, not 0, we need to find it's offset and subtract to put it into into the correct ndigit ( cound of each number ).
			++ndigit[c - '0'];
			// the book goes on to explain this, "chars are just small integers" 
		}
		else if (c = ' ' || c == '\n' || c == '\t')
		{
			++nwhite;
		}
		else
		{
			++nother;
		}


		// Also I'm being explained multi-way conditions (if/if else/ else). I tell you, this is an exercise in patience!
		// I'm also violating the books style throughout these examples
		/*

			if (condition)
				statement
			else if (condition)
				statement
			else
				statement

			while (condition){
				statement..
				statement..
			}

		*/
	}

	printf("digits = ");
	for (i = 0; i < 10; ++i)
	{
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);

}

#define MaxCharsInWord 45 // the longest english word according to a google search.. pneumonoultramicroscopicsilicovolcanoconiosis = 45 characters


void printbar(int count)
{
	int i;
	printf("----");
	for (i = 0; i < count; i++)
	{
		printf("-");
	}
	printf("--\n");

}

void exercise_1_13()
{
	printf("Exersize 1-13\nWrite a program to print a historagram of the lengths of words in its input.  It's easy to draw the historagram with the bars horizontal: a vertical orientation is more challenging.\n");
	printf("\n*******Type a bunch of words and I will print some historagrams\n*****\n");
	controlzHint();
	//I had to google "historagram"

	// I will start with the data, then I can present them horizontal and vertically wth the same data set.

	int largestCount = 0;

	// Question for Geoff.. I assume this is the primary benefit of using unmanaged and a habbit I'm going to have to get used to in C land.. 
	// In order from hitting re-allocate and moving memory around just have a good amount allocated to do what we want.

	int c, i, j, currentwordCount, numberOfCounts;
	c = i = j = currentwordCount = numberOfCounts = 0;
	// I'm sure there are lots of things made to simplify a more dynamic array.   It'd be a tragic function that declared an array with a length of 2000, when typically it's run with things of a length of ~10.
	// I could use some wisdom in what to look forward to on this.
	int wordCounts[MaxCharsInWord];

	for (i = 0; i < MaxCharsInWord; ++i)
	{
		wordCounts[i] = 0;
	}

	while (true)
	{
		c = getchar();
		// I'm not counting numbers in words
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			++currentwordCount;
			if (currentwordCount > largestCount)
			{
				++largestCount;
			}
		}
		else if (c == ' ' || c == '\n' || c == '\t' || c == EOF)
		{
			if (currentwordCount > 0)
			{
				++wordCounts[currentwordCount];
				if (wordCounts[currentwordCount] == 1)
				{
					++numberOfCounts;
				}

				if (wordCounts[currentwordCount] > largestCount)
				{
					largestCount = wordCounts[currentwordCount];
				}
				currentwordCount = 0;
			}
		}
		if (c == EOF)
		{
			break;
		}
	}
	
	//horizontal.
	printf("Words by count (Horizontal historagram)\n");
	printbar(largestCount);

	for (i = 0; i < MaxCharsInWord; i++)
	{
		if (wordCounts[i] == 0)
		{
			continue;
		}
		printf("%3d:", i);
		for (j = 0; j < wordCounts[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printbar(largestCount);

	printf("Words by count (Vertical historagram)\n");
	printbar(numberOfCounts);
	for (j = largestCount - 1; j >= 0; --j)
	{
		for (i = 0; i < MaxCharsInWord; i++)
		{
			if (wordCounts[i] == 0)
			{
				continue;
			}
			if (wordCounts[i] >= j)
			{
				printf(" *");
			}
			else
			{
				printf("  ");
			}
		}

		printf("\n");
	}
	printbar(numberOfCounts);
	for (i = 0; i < MaxCharsInWord; i++)
	{
		if (wordCounts[i] == 0)
		{
			continue;
		}
		printf("%2d", wordCounts[i]);
	}
	printf("\n");
	printbar(numberOfCounts);

	controlzHint();
	while ((c = getchar()) != EOF) {};
}

int main()
{
	//myFirstForloop();
	//anotherForLoop();
	//excersize1_5();
	//symbolic_constants();
	//getCharCountChars();
	//getCharCountLines();
	//exercise1_8();
	//exercise1_9();
	//exercise1_10();

	//following example. not so much exercise but making sure I don't just glance over things.
	//word_counting_program();

	//exercise1_12();

	//array_example();

	exercise_1_13();

	return 0;
}

// Today I learned that printf with a number between the %d puts 3 characters to do right-justify on the list. 
//That's pretty handy! I bet that carries over to c#'s string.format stuff too.

//some other reviewy stuff like integers being truncated.  