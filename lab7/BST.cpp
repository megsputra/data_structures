/**
 
 * Mega Putra
 
 * CIS 22C, Lab 7
 
 */

#include "Book.h"
#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void welcome();
void processFile(ifstream &fin, BST<Book>&B, Book&);
void populateTree(ifstream &fin, BST<Book>&, Book);
void showCurrentTree(BST<Book>&Books, string genre);
void write2File(BST<Book>B, Book books, string fout);

int main()
{
    BST<Book> B;
    Book books;
    ifstream fin;
    processFile(fin, B, books);
}

void welcome()
{
    cout << "Welcome to the Best Reads App!\n" << endl;
    cout << "Enter the name of the file for your book collection: ";
}

void processFile(ifstream &fin, BST<Book>&Books,Book& books)
{
    welcome();
    
    string newTitle = "", newAuthor = "", fout, fileName="", genre="", auth ="", title="";
    unsigned newISBN =0; double newPrice =0.0;  bool flag= true;
    
    cin >> fileName;
    fin.open(fileName.c_str());
    while (!fin.is_open())
    {
        cout << "Invalid file name!\n";
        cout << "\nPlease enter the name of your file: ";
        cin >> fileName;
        fin.open(fileName.c_str());
    }
    
    cout << "What genre of literature is this: ";
    cin.ignore();
    getline(cin,genre);
    populateTree(fin, Books, books);
    
    cout << "\nThe number of books in the " << genre << " book tree is: " << Books.size() << endl;
    cout << "The height of the " << genre << " book tree is: " << Books.height() << "\n\n";
    cout << "The first book in this collection is:\n" << Books.minimum();
    cout << "\nThe last book in this collection is:\n" << Books.maximum();
    
    cout << "\nEnter the information about the book you wish to remove. " <<endl;
    cout << "Title: "; cin.clear(); getline(cin, title);
    cout << "Author: "; getline(cin, auth);
    
    books.set_title(title);
    books.set_author(auth);
    
    while(flag)
    {
        if (!Books.search(books))
        {
            cout <<"Sorry, " << title << " is not in this collection!" << endl;
            cout << "\nEnter the title of a book you wish to remove: ";
            cin.clear(); getline(cin, title);
            cout << "Author: "; getline(cin, auth);
            books.set_title(title);
            books.set_author(auth);
        }
        else
        {
            Books.removeData(books);
            cout << title << " has been removed!" << endl;
            flag = false;
        }
    }
    showCurrentTree(Books,genre);
    
    cout << "Enter the title of a book you wish to insert: "; cin.clear(); getline(cin, newTitle);
    cout << "Enter the author of the book: "; getline(cin, newAuthor);
    cout << "Enter the price of the book: "; cin>>newPrice;
    cout << "Enter the isbn number of the book: "; cin>> newISBN;
    
    books.set_author(newAuthor);
    books.set_title(newTitle);
    books.set_isbn(newISBN);
    books.set_price(newPrice);
    Books.insertData(books);
    showCurrentTree(Books,genre);
    
    cout << "Would you like to write this collection to a file? (yes/no): ";
    cin >> newTitle;
    if(newTitle == "y" ||newTitle == "yes" || newTitle == "Yes" || newTitle == "Y")
    {
        cout << "Enter the file name: "; cin >> fout;
        write2File(Books, books, fout);
    }
    cout << "\nThank you! Goodbye!" << endl;
    
}
void populateTree(ifstream &fin, BST<Book>&B, Book books)
{
    string bufferT=""; string bufferA=""; string bufferE="";
    unsigned bufferI=0; double bufferD=0;
    
    while(!fin.eof())
    {
        getline(fin, bufferT);
        if (bufferT[bufferT.size()-1] == '\r') bufferT.resize(bufferT.size()-1);
        if (bufferT =="")
        {
            bufferT.clear();
            continue;
        }
        books.set_title(bufferT);
        getline(fin, bufferA);
        books.set_author(bufferA);
        fin>>bufferD;
        books.set_price(bufferD);
        fin>>bufferI;
        books.set_isbn(bufferI);
        
        B.insertData(books);
    }
    fin.close();
}

void showCurrentTree(BST<Book>&Books, string genre)
{
    cout << "\nThe number of books in the " << genre << " book tree is now: " << Books.size() << endl;
    cout << "\nThe books contained in this tree are now:\n\n";
    Books.inOrderPrint(cout);
}

void write2File(BST<Book>B, Book books, string fout)
{
    ofstream outFile(fout.c_str());
    
    if (!outFile) cerr << "Error opening the output file!" << endl;
    B.inOrderPrint(outFile);
    cout << "The data is now written to the file " << fout << endl;
    
    outFile.close();
}

