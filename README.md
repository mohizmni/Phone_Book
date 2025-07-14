Phone Book Application in C++

A simple console-based phone book app for managing contacts and favorites.
Features

    Edit contact names

    Automatically update favorite contacts on name changes

    Display favorite contacts list

Main Components

    Contact: structure/class holding contact info

    contacts: list of all contacts

    favorite: list of favorite contacts (Contact objects or names)

    editContact(oldname, newname): update a contact’s name

    showFavorite(): display favorite contacts

How to Use

    Compile the program:

g++ phoneBook.cpp -o phoneBook

    Run the executable:

./phoneBook

    Use editContact to change contact names

    Use showFavorite to list favorite contacts

Important Notes

    If favorite stores Contact objects, print the name member or overload the << operator for display

    For compilation errors related to operator== or operator<<, ensure comparisons and output use compatible types

Requirements

    Windows OS or Linux

    C++ compiler supporting C++11 or later