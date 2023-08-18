/*
Muhammed Muhnis T K
C-Program to Convert Infix to Postfix Expression
JEC21CS083
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char in[30], s[15], p[30]; // Input expression, stack, and output postfix expression
int top = -1; // Top of the stack

int precedence(char c); // Function to determine operator precedence
void in_to_pr(); // Function to convert infix to postfix

int main()
{
    printf("Enter the Infix Expression: ");
    gets(in); // Input the infix expression
    in_to_pr(); // Convert infix to postfix
    return 0;
}

int precedence(char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0; // Default precedence for non-operators
}

void in_to_pr()
{
    int i = strlen(in), j = 0; // i is the index for input expression, j is the index for the postfix expression
    char x, y; // Temporary variables to hold characters

    while (i >= 0)
    {
        if ((isalpha(in[i])) || (isdigit(in[i])))
            p[j++] = in[i]; // If character is operand, add it to the postfix expression
        else if (in[i] == ')')
            s[++top] = in[i]; // Push ')' onto the stack
        else if (in[i] == '(')
        {
            while (s[top] != ')')
            {
                p[j++] = s[top--]; // Pop operators from stack to postfix expression until '(' is encountered
            }
            top--; // Pop the '(' from stack
        }
        else
        {
            x = in[i], y = s[top]; // Current operator and operator at top of stack
            if ((y == ')') || (top == -1) || (precedence(y) <= precedence(x)))
            {
                s[++top] = x; // Push operator onto stack if stack is empty or top operator has lower precedence
            }
            else
            {
                while ((top != -1) && (y != ')') && (precedence(x) < precedence(y)))
                {
                    p[j++] = s[top--]; // Pop operators from stack to postfix while precedence is higher
                    y = s[top]; // Update y to the new top operator
                }
                s[++top] = x; // Push current operator onto stack
            }
        }
        i--;
    }

    while (top != -1)
    {
        p[j++] = s[top--]; // Pop any remaining operators from stack to postfix expression
    }

    p[j] = '\0'; // Null-terminate the postfix expression
    strrev(p); // Reverse the postfix expression to get the prefix expression
    printf("The Prefix Expression is: %s", p);
}
