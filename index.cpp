#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

struct book
{
    string bookname;
    string author;
    string genre;
};
list<book> mylist;
list<book> mylist2;


void addBook(string bookname, string author, string genre)
{
    //Adds book in the library of the app
    //Storing the name of the book,author and genre of the book
    book newBook;
    newBook.bookname = bookname;
    newBook.author   = author;
    newBook.genre    = genre;
    mylist.push_back(newBook);
}
void addBook_to_library()
{   //Adds book to the library of the app taking using input
    //By Storing the name of the book,author and genre of the book
    string bookname,author,genre;
    book newBook;
    newBook.bookname = bookname;
    newBook.author   = author;
    newBook.genre    = genre;
    cout << "Enter the book name"<<endl;
    cin >> newBook.bookname;
    cout << "Enter the author name"<<endl;
    cin >> newBook.author;
    cout << "Enter the genre"<<endl;
    cin >> newBook.genre;

    mylist.push_back(newBook);
}
void addBook_by_user()
{   // This functions allows the user to publish his own book
    // So the user's published book is added to the library of the app

    string bookname,author, genre;
    book newBook;
    newBook.bookname = bookname;
    cout << " Enter your Book Name" <<endl;
    cin>> newBook.bookname;
    newBook.author   = author;
    cout << " Enter your Name" <<endl;
    cin>> newBook.author;
    newBook.genre    = genre;
    cout << " Enter the genre of your book" <<endl;
    cin>> newBook.genre;
    mylist.push_back(newBook);

}
void addBook_by_user_to_bookmark()
{   // This functions allows the user to bookmark his favorite book
    // So the books are stored from the user input in the bookmark list
    // mylist2 was created to store all the books in the bookmark list
    string bookname;
    // Create new book entry
    book newBook;
    newBook.bookname = bookname;
    cout << " Enter the Book Name" <<endl;
    cin>> newBook.bookname;

    mylist2.push_back(newBook);

}
void display_bookmark_books()
{   // This Function displays all the books that were bookmarked by the user.
    // Output looks like this
    //-- BOOKMAKRED BOOKS------
    // 1. A 2.B 3.C etc

    cout << "\n------- BOOKMARKED BOOKS --------\n";

    int count = 0;
    for ( std::list<book>::iterator currentBook = mylist2.begin(); currentBook != mylist2.end(); ++currentBook )
    {
        cout << ++count;

        cout << ".\nBook Name: " << currentBook->bookname<<endl;
    }
}
void display_all_books()
{   // This functions displays all the books in the library that were pushed back in list<book>mylist
    // Also contains the published book of the user

    cout << "\n------- ALL AVAILABLE BOOKS --------\n";

    int count = 0;
    for ( std::list<book>::iterator currentBook = mylist.begin(); currentBook != mylist.end(); ++currentBook )
    {
        cout << ++count;

        cout << ".\nBook Name: " << currentBook->bookname<<endl;
        cout << "\nAuthor:    "  << currentBook->author<<endl;
        cout << "\nGenre:      " << currentBook->genre<<endl;
    }
}
void deleteBook()
{   // This functions simply delete books from the list of books from the Book Archive App
    //It takes input from the user to type name of the book to delete, then deletes the book.
    //For example if book A from books A,B,C was taken as input to delete, the output looks
    // looks like B,C as book A was deleted.

    string name;
    cout << "Enter Book Name to delete"<<endl;
    cin >> name;
    for ( std::list<book>::iterator currentBook = mylist.begin(); currentBook != mylist.end(); ++currentBook )
    {
        if ( currentBook->bookname == name )
        {
            mylist.erase( currentBook );
            return;
        }
    }
}
void delete_bookmark_books()
{   // This functions simply delete books from the list of books which were bookmarked as favorite
    // by the user.So the book name was taken as input and deleted accordingly from the bookmarked library
    string name;
    cout << "Enter Book Name to delete"<<endl;
    cin >> name;
    for ( std::list<book>::iterator currentBook = mylist2.begin(); currentBook != mylist2.end(); ++currentBook )
    {
        if ( currentBook->bookname == name )
        {
            mylist2.erase( currentBook );
            return;
        }
    }
}

void searchBook()
{
    // This functions allows to search books in the app taking user input, if the input matches
    // the function will return book found else it will print book not found.
    string bookname;
    cout << " Enter book to search"<<endl;
    cin>>bookname;
    for ( std::list<book>::iterator currentBook = mylist.begin(); currentBook != mylist.end(); ++currentBook )
    {
        if ( currentBook->bookname == bookname )
        {
            cout<<"Book found"<<endl;
            currentBook;
            return;
        }
        else
        {
            cout << "Book not found"<<endl;
        }
    }
}
int main()
{
    // Books added in the Library of the App as default;

    addBook ("Hamlet","William Shakespeare","Tragedy");
    addBook ("Macbeth","William Shakespeare","Tragedy");
    addBook ("Dracula","Bram Stoker","Horror");
    addBook ("Hobbit","JRR Tolkein","High Fantasy/Adventure");
    addBook ("Mayurakkhi","Humayun Ahmed","Fiction");
    addBook ("Himu","Humayun Ahmed","Fiction");

    int a,flag=1;

    cout << " Welcome to Book Archive app!" <<endl;
    cout <<endl;
    cout << " Select the Option which you want to perform" <<endl;
    cout << "1. Add Book to Library"<< endl;
    cout << "2. Add Book to publish"<< endl;
    cout << "3. Show All Books"<< endl;
    cout << "4. Search Books in Library"<< endl;
    cout << "5. Delete Book from Library"<< endl;
    cout << "6. Add Book to Bookmark"<< endl;
    cout << "7. Show Bookmarked books"<< endl;
    cout << "8. Delete Bookmarked books"<< endl;
    cout << "9. Exit" << endl;
    cout << "--- Choose any one option ---" << endl;
    cout << "Enter one option: ";
    cin  >> a;
    while( flag == 1)
    {
        cout << "Enter one option: ";
        cin  >> a;

        switch(a) // Switch case was used to perform all the operations in the app calling functions
                  // at different cases
        {
        case 1:
            addBook_to_library();
            break;
        case 2:
            addBook_by_user();
            break;
        case 3:
            display_all_books();
            break;
        case 4:
            searchBook();
            break;
        case 5:
            deleteBook();
            break;
        case 6:
            addBook_by_user_to_bookmark();
            break;
        case 7:
            display_bookmark_books();
            break;
        case 8:
            delete_bookmark_books();
            break;
        case 9:
            flag = 0;
            break;
        }
    }

    return 0;
}
