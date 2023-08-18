/*
 Muhammed Muhnis T K
 C-Program to Evaluate the Postfix Expression
 JEC21CS083
*/
#include<stdio.h> 
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Define a structure to hold each token in the postfix expression
struct exp
{
	char ch[8];
} po[30];

// Declare global variables
char str[10], ch[50]; // Input string and a character buffer
int top = -1, s[15], i, k, l = 0, m; // Stack, loop control variables, and counters

// Function to evaluate the postfix expression
int eval_po();

// Function to read the postfix expression and tokenize it
int read();

// Function to display the postfix expression
int display();

int main()
{
	read(); // Read the postfix expression and tokenize it
	printf("\nThe Entered Postfix Expression is : ");
	display(); // Display the tokenized postfix expression
	printf("\n");
	eval_po(); // Evaluate the postfix expression
	return 0;
}

int eval_po()
{
	int p = 0, op1, op2, res; // Loop counter and variables for operands and result
	while (p <= k)
	{
		if (isdigit(po[p].ch[0])) // Check if the token is a digit
		{
			s[++top] = atoi(po[p].ch);	// Convert the token to an integer and push onto the stack
		}
		else // Token is an operator
		{
			op2 = s[top--]; // Pop the top operand from the stack
			op1 = s[top--]; // Pop the second top operand from the stack
			switch (po[p].ch[0])
			{
				case '+':
				{
					res = op1 + op2;
					break;
				}
				case '-':
				{
					res = op1 - op2;
					break;
				}
				case '*':
				{
					res = (op1) * (op2);
					break;
				}
				case '/':
				{
					res = op1 / op2;
					break;
				}
				case '^':
				{
					res = pow(op1, op2);
					break;
				}
			}
			s[++top] = res; // Push the result of the operation onto the stack
		}
		++p; // Move to the next token
	}
	printf("\nThe Result of Expression is : %d", s[0]); // Print the final result
	return 0;
}	

int read()
{
	printf("Enter the Postfix Expression Separating Each Token by Single Space : ");
	gets(ch); // Read the input postfix expression
	for (i = 0; i < strlen(ch); ++k) // Loop through the input string
	{
		if (isdigit(ch[i])) // If the current character is a digit
		{
			for (m = 0; ch[i] != ' '; ++i, ++m) // Copy the digit token into the structure
			{
				po[k].ch[m] = ch[i];
			}
			l = 0; // Reset the letter counter
		}
		else if (ch[i] == '*' || ch[i] == '+' || ch[i] == '-' || ch[i] == '/' || ch[i] == '^') // Operator character
		{
			po[k].ch[0] = ch[i]; // Store the operator in the structure
			l = 0; // Reset the letter counter
			++i; // Move to the next character
		}
		else // Token is neither digit nor operator (could be whitespace or something else)
		{
			++l; // Increment the letter counter
			++i; // Move to the next character
			--k; // Decrement the token counter
			if (l == 2) // If two consecutive non-digit/non-operator characters are encountered, it's likely a space
			{
				break;  // Exit the loop
			}
		}
	}
	return 0;
}

int display()
{
	for (int j = 0; j <= k; ++j)
	{
		printf(" %s", po[j].ch); // Display each token in the postfix expression
	}
	return 0;
}

/*
OUTPUT:
Enter the Postfix Expression Separating Each Token by Single Space : 5 2 + 8 3 ^ -
The Entered Postfix Expression is : 5 2 + 8 3 ^ -
The Result of Expression is : 49
*/
