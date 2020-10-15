/*
Tim Zhen
CS 235
Project 7 Implementation
*/

#include "PostfixCalculator.hpp"
#include <iostream>
using namespace std;

PostfixCalculator::PostfixCalculator()
{
}

//checks if the parenthesis are balanced
bool PostfixCalculator::unbalancedParenthesis(string str)
{
    int open = 0; int closed = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            open++;
        if (str[i] == ')')
            closed++;
    }
    if (open == closed)
        return false; //the parenthesis are balanced
    else
        return true; //the parenthesis are unbalanced
}

//checks if there is an unknown operator
bool PostfixCalculator::unknownOperator(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '(' && str[i] != ')' && str[i] != '*'
        && str[i] != '/' && str[i] != '-' && str[i] != '+' && str[i] != ' ')
        {
            return true; //there is an unknown operator
        }
    }
    return false; //there are no unknown operators
}

//looks for precedence of operators
int PostfixCalculator::precedence(char oper)
{
    int rank = 0;
    switch(oper)
    {
        case '*':
            rank = 2;
            break;
        case '/':
            rank = 2;
            break;
        case '+':
            rank = 1;
            break;
        case '-':
            rank = 1;
            break;
    }
    return rank;
}

/*
Takes a string representation of the infix expression, parses it into the
corresponding postfix expression and returns the postfix expression as a 
string. In the string representation of the postfix expression, operands 
and operators are also separated by a single space. 
*/
string PostfixCalculator::convertToPostfix(string infix_expression)
{
    string postFix;
    if (unbalancedParenthesis(infix_expression))
    {
        throw(PrecondViolatedExcep("Unbalanced parenthesis"));
    }
    else if (unknownOperator(infix_expression))
    {;
        throw(PrecondViolatedExcep("Unknown operator"));
    }
    else
    {
        for (int ch = 0; ch < infix_expression.length(); ch++)
        {
            if (isdigit(infix_expression[ch]))
            {
                postFix += infix_expression[ch];

                if (!isdigit(infix_expression[ch+1]))
                {
                    postFix += ' ';
                }
            }
            switch(infix_expression[ch])
            {
                case '(':
                    aStack.push(infix_expression[ch]);
                    break;
                case '*':
                    while(!aStack.empty() && aStack.top() != '(' && precedence(infix_expression[ch]) <= precedence(aStack.top()))
                    {
                        postFix += aStack.top();
                        postFix += ' ';
                        aStack.pop();
                    }
                    aStack.push(infix_expression[ch]);
                    break;
                case '/':
                    while(!aStack.empty() && aStack.top() != '(' && precedence(infix_expression[ch]) <= precedence(aStack.top()))
                    {
                        postFix += aStack.top();
                        postFix += ' ';
                        aStack.pop();
                    }
                    aStack.push(infix_expression[ch]);
                    break;
                case '+':
                    while(!aStack.empty() && aStack.top() != '(' && precedence(infix_expression[ch]) <= precedence(aStack.top()))
                    {
                        postFix += aStack.top();
                        postFix += ' ';
                        aStack.pop();
                    }
                    aStack.push(infix_expression[ch]);
                    break;
                case '-':
                    while(!aStack.empty() && aStack.top() != '(' && precedence(infix_expression[ch]) <= precedence(aStack.top()))
                    {
                        postFix += aStack.top();
                        postFix += ' ';
                        aStack.pop();
                    }
                    aStack.push(infix_expression[ch]);
                    break;
                case ')':
                    while (aStack.top() != '(')
                    {
                        postFix += aStack.top();
                        postFix += ' ';
                        aStack.pop();
                    }
                    aStack.pop();
                    break;
            }

        }
        while (!aStack.empty())
        {
            postFix += aStack.top();
            postFix += ' ';
            aStack.pop();
        }
    }
    return postFix;
}

/*
    takes a string representation of the postfix expression calculates the result
    and returns it.
*/
double PostfixCalculator::calculatePostfix(string postfix_expression)
{
    double op1, op2; // the two numbers we're acting on
    double result; 
    for (int i = 0; i < postfix_expression.length(); i++)
    {
        if (postfix_expression[i] == ' ')
        {
            continue; //if it encounters a space, keep going
        }
        if(isdigit(postfix_expression[i]))
        {
            double num = 0; //multidigit number to be push into stack
            while(isdigit(postfix_expression[i]))
            {
                num = num *10 + (postfix_expression[i] - '0'); //do '0' to make sure it converts to int
                i++;
            }
            i--;
            dStack.push(num); //push the multidigit number into the stack
        }
        else
        {
            op1 = dStack.top(); //grab the top double
            dStack.pop(); //remove the top of the stack
            op2 = dStack.top(); //grab the next top
            dStack.pop(); //remove the top of the stack again

            switch(postfix_expression[i])
            {
                case '*':
                    result = op1 * op2;
                    dStack.push(result);
                    break;
                case '/':
                    result = op2/op1;
                    dStack.push(result);
                    break;
                case '+':
                    result = op1 + op2;
                    dStack.push(result);
                    break;
                case '-':
                    result = op2 - op1;
                    dStack.push(result);
                    break;
            }
        }
    }
    return dStack.top();


}

/*
    Read every infix expression from the input file and:
        • Convert it to postfix (don’t forget to do this in a try-catch block,
        convertToPostfix may throw an exception!)
        • Write the corresponding postfix expression into postfix.txt, but if
        convertToPostfix throws and exception, write the error message
        instead
        • Evaluate the postfix expression if wellformed and write the result in
        results.txt, otherwise write the error message there too
*/
void PostfixCalculator::testCalculator(string input_file_name)
{
    string infix;
    ifstream fin(input_file_name.c_str());
    ofstream postFile("postfix.txt");
    ofstream resultFile("results.txt");

    while (getline(fin,infix))
    {
        try
        {
            postFile << convertToPostfix(infix) << "\n"; //adds into postfix.txt then skips line
            resultFile << calculatePostfix(convertToPostfix(infix)) << "\n"; //adds into results.txt then skips line

        }
        catch(PrecondViolatedExcep error) //throw errors
        {
            postFile << error.what() << "\n";
            resultFile << error.what() << "\n";
        }
    }

}