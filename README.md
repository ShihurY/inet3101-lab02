# INET 3101 Lab 2

## Code for INET 3101 Lab 2

### Who wrote the program (ensure all members are listed in the doc)
- Shihur Yang

### Program description paragraph
- Simple command-line menu for an Inventory Management System written in C.
- It has 6 menu options which are to show records, add/delete records, database size, and exit program
- Dynamically allocates memory to ensure records are stored continguously using malloc() and a for loop.

### Menu definition and usage
- Menu displays a list of options
- It reads user input and selects the desired menu option
- It will continue looping until the user chooses to exit

### Functions
- printRecords()
    - Input: Pointer to part struct and pointer to the number of records in the database
    - Output: Prints all records in the database or else prints "No records saved."
    - Description: Informs user about the total number of records in the database

- addRecords()
    - Input: Pointer to the database and the number of records within the database
    - Output: Adds 1 to record count and prints "Record added successfully." or else prints "Could not add new record."
    - Description: Collects user input with information about parts and adds that record to the existing database
 
- deleteRecord()
    - Input: Pointer to the database and pointer to the number of records in the database
    - Output: void
    - Description: Removes the last record added to the databse and all of its information

- main()
  - Input: User Input
  - Output: Prints menu, resulting print statement from above functions, or "Exiting Now..."
  - Description: Displays a menu, processes user input, manages dynamic memory allocation/deallocation, and calls the selected function

### Listing of files required and what type they are (.h header, .c c code, etc..)
- lab02.c (Program)
- README.txt (Design Doc)
