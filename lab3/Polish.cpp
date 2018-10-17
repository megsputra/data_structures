///**
//
// * Mega Putra
//
// * CIS 22C, Lab 3
//
// */
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <cstdlib>
//#include <cmath>
//#include "Stack.h"
//using namespace std;
//
//void welcome();
//void processUserInput(Stack <int>&, Stack <string>&, string&);
//int calculatePolish(Stack <int>&, Stack <string>&);
//
//int main()
//{
//    Stack <int> Numbers;
//    Stack <string> Operators;
//    string input = "";
//    welcome();
//    while (input != "q" || input != "Q")
//    {
//        processUserInput(Numbers,Operators,input);
//    }
//}
//void welcome()
//{
//    cout << "Welcome!\n\n";
//
//}
//void processUserInput(Stack<int> &Numbers,Stack <string>&Operators, string& input)
//{
//    int answer ; string Optemp; int Numtemp; int flag = 1;
//    cout << "Please enter an equation in Polish Notation "
//    "or \"q\" to quit: " << endl;
//    getline (cin, input);
//
//    if (input == "q" || input == "Q")
//    {
//        cout << "\nGoodbye!" << endl;
//        exit(1);
//    }
//    else
//    {
//        stringstream ss(input);
//        string holder="";// 2 * 7 + 9
//
//        while (ss >> holder)
//        {
//            if (holder == "*"|| holder == "/"|| holder == "+"|| holder == "-")
//            {
//                Operators.push(holder);
//
//                if(Numbers.getSize() == 1 && Operators.getSize()==2 && flag != 2) //special handling
//                {
//                    Operators.pop();
//                    Optemp = Operators.peek();
//                    Numtemp = Numbers.peek();
//                    Numbers.pop();
//                    Operators.pop();
//                    Operators.push(holder);
//
//                    while (ss>>holder )
//                    {
//                        if (holder == "*"|| holder == "/"|| holder == "+"|| holder == "-")
//                        {
//                            Operators.push(holder);
//                        }
//                        else
//                        {
//                            Numbers.push(stoi(holder));
//                        }
//                        if(Numbers.getSize() == 2 )
//                        {
//                            answer = calculatePolish(Numbers, Operators);
//                        }
//                        if(Numbers.getSize() == 1 && Operators.getSize() == 0)
//                        {
//                            if (Optemp == "/")
//                            {
//                                answer = Numtemp/ answer;
//                                Numbers.pop();
//                            }
//                            else if (Optemp == "*")
//                            {
//                                answer = Numtemp* answer;
//                                Numbers.pop();
//
//                            }
//                            else if (Optemp == "+")
//                            {
//                                answer = Numtemp+answer;
//                                Numbers.pop();
//
//                            }
//                            else if (Optemp == "-")
//                            {
//                                answer = Numtemp- answer;
//                                Numbers.pop();
//
//                            }
//                            Numbers.push(answer);
//
//                            cout << "The answer is: " << Numbers.peek() <<"\n\n";
//
//                            if (Operators.getSize() >= 1)
//                                Operators.pop();
//                            if (Numbers.getSize() >= 1)
//                            {
//                                while ( Numbers.getSize() != 0)
//                                    Numbers.pop();
//                            }
//
//                        }
//                    }
//                }
//
//            }
//            else
//            {
//                Numbers.push(stoi(holder));
//
//                if(Numbers.getSize() == 2 && !(Operators.empty()))
//                {
//                    answer = calculatePolish(Numbers, Operators);
//                    flag = 2;
//                }
//                if(Numbers.getSize() == 1 && Operators.getSize() == 0)
//                {
//                    cout << "The answer is: " << Numbers.peek() <<"\n\n";
//                    Numbers.pop();
//                }
//            }
//        }
//    }
//}
//
//int calculatePolish(Stack <int>& Numbers, Stack <string>& Operators)
//{
//    int num1 = 0, num2 = 0;
//    int answer =0;
//    num2 = Numbers.peek();
//    Numbers.pop();
//    num1 = Numbers.peek();
//    Numbers.pop();
//
//    if (Operators.peek() == "/")
//    {
//        answer = num1/ num2;
//        Operators.pop();
//
//    }
//    else if (Operators.peek() == "*")
//    {
//        answer = num1*num2;
//        Operators.pop();
//    }
//    else if (Operators.peek() == "+")
//    {
//        answer = num1+num2;
//        Operators.pop();
//    }
//    else if (Operators.peek() == "-")
//    {
//        answer = num1-num2;
//        Operators.pop();
//    }
//    else
//    {
//        cerr<<"invalid operator" << endl;
//    }
//    Numbers.push(answer);
//    return answer;
//}

