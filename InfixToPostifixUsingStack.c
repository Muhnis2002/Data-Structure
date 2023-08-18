/*
 Muhammed Muhnis T K
 C-Program to Convert an Infix Expression to Postfix Expression
 JEC21CS083
*/
#include<stdio.h>
#include<ctype.h>

// Declare arrays to hold input infix expression, stack, and output postfix expression
char in[30], s[15], p[30];
int top = -1; // Initialize stack top index

// Function to determine operator precedence
int precedence(char c);

// Function to convert infix expression to postfix expression
void in_to_po();

int main()
{
    printf("Enter the Infix Expression :");
    gets(in); // Read the input infix expression
    in_to_po(); // Convert infix to postfix
    return 0;
}

int precedence(char c)
{
    switch(c)
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
    return 0; // Default return for non-operators
}

void in_to_po()
{
    int i = 0, j = 0;
    char x, y;
    while (in[i] != '\0')
    {
        if (isalpha(in[i]) || isdigit(in[i]))
            p[j++] = in[i]; // Append operands directly to output postfix expression
        else if (in[i] == '(')
            s[++top] = in[i]; // Push '(' onto the stack
        else if (in[i] == ')')
        {
            while (s[top] != '(')
            {
                p[j++] = s[top--]; // Pop operators from the stack and append to output until '(' is encountered
            }
            top--; // Pop '(' from the stack
        }
        else // Process operators
        {
            x = in[i];
            y = s[top];
            if ((y == '(') || (top == -1) || (precedence(x) > precedence(y)))
            {
                s[++top] = x; // Push the operator onto the stack
            }
            else
            {
                while ((top != -1) && (y != '(') && (precedence(x) <= precedence(y)))
                {
                    p[j++] = s[top--]; // Pop higher or equal precedence operators from the stack and append to output
                    y = s[top];
                }
                s[++top] = x; // Push the current operator onto the stack
            }
        }
        ++i; // Move to the next character in the infix expression
    }
    while (top != -1)
    {
        p[j++] = s[top--]; // Pop any remaining operators from the stack and append to output
    }
    p[j] = '\0'; // Terminate the postfix expression string
    printf("The Postfix Expression is %s ", p); // Print the postfix expression
}
/*
OUTPUT:
Enter the Infix Expression :a+b*(c-d^e)^(f+g*h)-i
The Postfix Expression is abcde^-*fgh*+i- 
*/