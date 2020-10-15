/*
Name: Tim Zhen
Assignment: Project 9 
*/

#ifndef CodewordGenerator_HPP_
#define CodewordGenerator_HPP_
#include <iostream>
#include <regex>
#include <queue>

using namespace std;

class CodewordGenerator
{
    public:

        //default constructor
        CodewordGenerator();

        /*
            Takes a string pattern and returns the shortest string that matches the pattern
            exploring the space of possible alphabet permutations in Breadth First Search
            order.
            The input string pattern is guaranteed to represent a valid regular expression
            pattern
        */
        string generateShortestWord(string pattern);

        /*
            Takes a string pattern and an integer n and returns a string of length n that
            matches the pattern exploring the space of possible alphabet permutations in
            Depth First Search order.
            Here too, the input string pattern is guaranteed to represent a valid regular
            expression pattern. 
        */
        string generateLengthWord(string pattern, int length);
    
    private:
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //every character in the alphabet
        queue<string> que; //queue of possible alphabet permutations and for BFS
        stack<string> stackQue; //stack of possible alphabet permutations and for DFS
};

#endif
