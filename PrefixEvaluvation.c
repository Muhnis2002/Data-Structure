/*
 Muhammed Muhnis T K
 C-Program to Evaluate a Prefix Expression
 JEC21CS083
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct exp
{
    char ch[8];
} po[30];

char str[10], ch[50];
int top = -1, s[15], i, k, l = 0, m;

// Function prototypes
int eval_pr();
int display();
int read();

int main()
{
    read();
    printf("\nThe Entered Prefix Expression is : ");
    display();
    printf("\n");
    eval_pr();
    return 0;
}

// Function to read and parse the prefix expression
int read()
{
    printf("Enter the Prefix Expression Separating Each Token by Single Space : ");
    gets(ch);
    i = strlen(ch);
    
    // Parsing the expression from the end
    for (; i >= 0; ++k)
    {
        if (isdigit(ch[i]))
        {
            for (m = 0; ch[i] != ' '; --i, ++m)
            {
                po[k].ch[m] = ch[i];
            }
            l = 0;
        }
        else if (ch[i] == '*' || ch[i] == '+' || ch[i] == '-' || ch[i] == '/' || ch[i] == '^')
        {
            po[k].ch[0] = ch[i];
            l = 0;
            --i;
        }
        else
        {
            ++l;
            --i;
            --k;
        }
    }
    return 0;
}

// Function to display the parsed prefix expression
int display()
{
    for (int j = k - 1; j >= 0; --j)
    {
        printf(" %s", po[j].ch);
    }
    return 0;
}

// Function to evaluate the prefix expression
int eval_pr()
{
    int p = 0, op1, op2, res;
    
    // Loop through the parsed expression
    while (p <= k)
    {
        if (isdigit(po[p].ch[0]))
        {
            // If token is a number, push it onto the stack
            s[++top] = atoi(po[p].ch);
        }
        else
        {
            // If token is an operator, pop two operands from the stack and perform the operation
            op1 = s[top--];
            op2 = s[top--];
            
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
            // Push the result of the operation back onto the stack
            s[++top] = res;
        }
        ++p;
    }
    printf("\nThe Result of Expression is : %d", s[0]);
    return 0;
}
