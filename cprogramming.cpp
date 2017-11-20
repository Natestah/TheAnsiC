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
		printf( "%3d\t\%3d\n", fahr, celsius );
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

void exersize1_5()
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

void  exersize1_8()
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

void  exersize1_9()
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

void exersize1_10()
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




int main()
{
	//myFirstForloop();
	//anotherForLoop();
	//excersize1_5();
	//symbolic_constants();
	//getCharCountChars();
	//getCharCountLines();
	//exersize1_8();
	//exersize1_9();
	exersize1_10();
	return 0;
}

// Today I learned that printf with a number between the %d puts 3 characters to do right-justify on the list. 
//That's pretty handy! I bet that carries over to c#'s string.format stuff too.

//some other reviewy stuff like integers being truncated.  