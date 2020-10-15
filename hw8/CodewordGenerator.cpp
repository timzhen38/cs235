/*
Name: Tim Zhen
Assignment: Project 9
*/

#include "CodewordGenerator.hpp"

CodewordGenerator::CodewordGenerator()
{
}

/*
Takes a string pattern and returns the shortest string that matches the pattern
exploring the space of possible alphabet permutations in Breadth First Search
order.
The input string pattern is guaranteed to represent a valid regular expression
pattern.
*/
string CodewordGenerator::generateShortestWord(string pattern)
{
    regex re(pattern);
    string result = "";
    que.push(result); //put empty string in the queue
    while (!que.empty())
    {
        result = que.front(); //removes one from the queue
        que.pop(); //queues are first in and first out
        if (regex_match(result,re))
        {
            return result;
        }
        else
        {
            for (int ch = 0; ch < alphabet.length(); ch++)
            {
                que.push(result+alphabet[ch]);
            }
        }  
    }
    return result;
}

/*
Takes a string pattern and an integer n and returns a string of length n that
matches the pattern exploring the space of possible alphabet permutations in
Depth First Search order.
Here too, the input string pattern is guaranteed to represent a valid regular
expression pattern. 
*/
string CodewordGenerator::generateLengthWord(string pattern, int length)
{
    regex re(pattern);
    string result = "";
    stackQue.push(result); //put empty string in the stack
    while (!stackQue.empty())
    {
        result = stackQue.top(); //removes one from the stack
        stackQue.pop(); //pops the top string from the stack
        if (result.size() < length)
        {
            for (int ch = 0; ch < alphabet.length(); ch++)
            {
                stackQue.push(result+alphabet[ch]);
            }
        }
        if (regex_match(result,re) && result.length() == length)
        {
            return result;
        }
    }
    return result;
}

