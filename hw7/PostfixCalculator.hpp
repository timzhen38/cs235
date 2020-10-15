/*
Tim Zhen
CS 235
Project 7
*/

#ifndef PostfixCalculator_HPP
#define PostfixCalculator_HPP
#include <iostream>
#include <stack>
#include <fstream>
#include "PrecondViolatedExcep.hpp"
using namespace std;

class PostfixCalculator
{
    public:
        //default constructor
        PostfixCalculator();

        /*
            Takes a string representation of the infix expression, parses it into the
            corresponding postfix expression and returns the postfix expression as a 
            string. In the string representation of the postfix expression, operands 
            and operators are also separated by a single space. 
        */
        string convertToPostfix(string infix_expression);

        /*
            takes a string representation of the postfix expression calculates the result
            and returns it.
        */
        double calculatePostfix(string postfix_expression);

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
        void testCalculator(string input_file_name); 

        /*
            Checks if there are an equal amount of open and closed parenthesis
        */
        bool unbalancedParenthesis(string str);
        
        /*
            Checks the string to see if there is an unknown operator
        */
        bool unknownOperator(string str);

        /*
            Looks for precedence of operators
        */
        int precedence(char oper);
    private:
        stack<char> aStack; //char stack for postfix conversion
        stack<double> dStack; //double stack for calculating
};

#endif