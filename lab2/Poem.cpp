///**
//
// * Mega Putra
//
// * CIS 22C, Lab 2
//
// */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "List.h"
using namespace std;

void welcome();
void processFile(ifstream&, List<string>&);
string getLastLine(string&);
void promptRearrangeLine(List<string> &poemList, int& gamesPlayed);
string showSingleLine(List<string>&, int);
void arrangeLines(List<string>& poemList,string, int, int &, int &);
void playAgain(List<string>& poemList, int& );

int main()
{
    ifstream fin;
    List<string> poemList;
    int gamesPlayed = 0;
    welcome();
    processFile(fin, poemList);
    promptRearrangeLine(poemList, gamesPlayed);
    playAgain(poemList, gamesPlayed);
}

void welcome()
{
    cout << "Welcome to the poetry re-arranger!\n\n" << "Enter the name of a file containing a poem: ";
}

void processFile(ifstream &fin, List<string> &poemList)
{
    string poemFile = "";
    cin >> poemFile;
    fin.open(poemFile.c_str());
    while (!fin.is_open())
    {
        cout << "Please enter a valid file name: ";
        cin >> poemFile;
        fin.open(poemFile.c_str());
    }
    string buffer = "", author= getLastLine(poemFile), title = "", lastline = "";
    int lineNumber = 0;
    while(!fin.eof()){
        string temp;
        getline(fin,temp);
        lineNumber++;
    }
    cout << "\nThere are "<< lineNumber-4 <<" lines in your poem" <<endl;
    fin.seekg(0L,ios::beg); //reset position of getline
    for(int i=0; i < lineNumber-2; i++)
    {
        getline(fin, buffer);
        if (fin.eof()) break; //EOF check
        if (buffer[buffer.size()-1] == '\r') // A gnu compiler may store \r in the last byte.  If so, discard
            buffer.resize(buffer.size()-1);

        if (i == 0)
        {
            title = buffer;
            cout <<"The poem is:\n" << title << " " << author << "\n\n";
        }
        else if  (i == 1 && buffer.size() < 1 )
        {
            continue;
        }
        else
        {
            poemList.insertEnd(buffer);
        }
    }
    poemList.printNumberedList();
    fin.close();
}

string getLastLine(string& poemFile)
{
    ifstream fin;
    fin.open(poemFile.c_str());
    string lastLine = "";
    if(fin.is_open())
    {
        fin.seekg(-1,ios_base::end);
        bool keepLooping = true;
        while(keepLooping)
        {
            char ch;
            fin.get(ch);

            if((int)fin.tellg() <= 1)
            {
                fin.seekg(0);
                keepLooping = false;
            }
            else if(ch == '\n')
            {
                keepLooping = false;
            }
            else
            {
                fin.seekg(-2,ios_base::cur);
            }
        }
        getline(fin, lastLine);
        fin.close();
    }
    return lastLine;
}

void promptRearrangeLine(List<string> &poemList, int& gamesPlayed)
{
    int poemNum = 0, linesMoved = 0; string direction = "";
    cout << "How would you like to re-arrange this poem?\n" << endl;
    cout << "Enter the line number of the poem: ";
    cin >> poemNum;
    cout << "The line is" << showSingleLine(poemList, poemNum) << "\n\n";

    cout << "Do you want to move this line up or down: ";
    cin >> direction;
    cout << "How many lines do you want to move it: ";
    cin >> linesMoved;
    cout << "The new poem is:" << endl;
    arrangeLines(poemList, direction, linesMoved, gamesPlayed, poemNum);
}

string showSingleLine(List<string> &poemList, int lineNum)
{
    string showSingleLine = "";
    poemList.beginIterator();
    for (int i = 1; i < lineNum; i++)
    {
        poemList.advanceIterator();
    }
    showSingleLine = poemList.getIterator();
    if (showSingleLine.length() == 0)
    {
        return " blank";
    }
    else
    {
        cout << ": ";
    	return showSingleLine;
    }
}
void arrangeLines(List<string>& poemList, string direction, int linesMoved, int &gamesPlayed, int& poemNum)
{
    if (gamesPlayed != 0) //if not first arrangement, reset iterator position
    {
        poemList.beginIterator();
        for (int i = 0; i < poemNum-1; i++)
        {
            poemList.advanceIterator();
        }
    }
    string lineTemp = poemList.getIterator();
    if (direction == "Up" || direction == "up")
    {
        for (int i = 0; i < linesMoved+1; i++)
        {
            poemList.reverseIterator();
        }
        poemList.insertIterator(lineTemp);
        for (int i = 0; i < linesMoved+2; i++)
        {
            poemList.advanceIterator();
        }
        poemList.deleteIterator();
    }
    else
    {
        for (int i = 0; i < linesMoved; i++)
        {
            poemList.advanceIterator();
        }
        poemList.insertIterator(lineTemp);
        for (int i = 0; i < linesMoved; i++)
        {
            poemList.reverseIterator();
        }
        poemList.deleteIterator();
    }
    poemList.printNumberedList();
}

void playAgain(List<string>& poemList, int& gamesPlayed)
{
    string playAgain = "y";
    bool flag = true;
    while (flag == true)
    {
        cout << "Would you like to rearrange this poem further:";
        cin >> playAgain;
        if(playAgain == "yes" || playAgain == "Yes" ||playAgain == "y"||playAgain == "Y")
        {
            gamesPlayed++;
            promptRearrangeLine(poemList, gamesPlayed);
        }
        else
        {
        	cout << "Goodbye!" << endl;
            flag = false;
        }
    }
}
