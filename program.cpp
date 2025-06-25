#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include <fstream>
using namespace std;

// Structure for tree node
struct TreeNode {
    string bookName;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string book) : bookName(book), left(nullptr), right(nullptr) {}
};

// Binary Search Tree for storing book names
class BookTree {
public:
    TreeNode* root;

    BookTree() : root(nullptr) {}

    TreeNode* insert(TreeNode* node, string bookName) {
        if (!node) return new TreeNode(bookName);
        if (bookName < node->bookName)
            node->left = insert(node->left, bookName);
        else if (bookName > node->bookName)
            node->right = insert(node->right, bookName);
        return node;
    }

    void insert(string bookName) {
        root = insert(root, bookName);
    }

    bool contains(TreeNode* node, string bookName) {
        if (!node) return false;
        if (bookName == node->bookName) return true;
        if (bookName < node->bookName) return contains(node->left, bookName);
        return contains(node->right, bookName);
    }

    bool contains(string bookName) {
        return contains(root, bookName);
    }
};

// Student class
class Student {
public:
    string name;
    int id;
    string book1;
    string book2;
    int book_no;
    int issueTime1 = 0;
    int dueTime1 = 0;
    int issueTime2 = 0;
    int dueTime2 = 0;

    Student(string name = "", int id = 0)
        : name(name), id(id), book1(""), book2(""), book_no(0) {}
};

// Global Variables
BookTree tree;
int currentTime = 1000; // Simulated clock (increment manually)
unordered_map<string, int> hashmapping; // book name -> index
int arr[10][2]; // arr[i][0] = total copies, arr[i][1] = available copies
Student students[3];

void setupBooks() {
    string books[] = {"C++ Fundamentals", "Data Structures", "Operating Systems"};
    int copies[] = {5, 3, 4};

    for (int i = 0; i < 3; ++i) {
        tree.insert(books[i]);
        hashmapping[books[i]] = i;
        arr[i][0] = copies[i];
        arr[i][1] = copies[i];
    }
}

void setupStudents() {
    students[0] = Student("Alice", 101);
    students[1] = Student("Bob", 102);
    students[2] = Student("Charlie", 103);
}

void logToFile(string content) {
    ofstream logfile("library_log.txt", ios::app);
    if (logfile.is_open()) {
        logfile << content << endl;
        logfile.close();
    }
}

void issueBook() {
    int id;
    cout << "\nEnter your ID: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < 3; ++i) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Invalid ID.\n";
        return;
    }

    if (students[index].book_no >= 2) {
        cout << "You can't issue more than two books.\n";
        return;
    }

    cout << "Enter name of book: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string book;
    getline(cin, book);

    if (!tree.contains(book)) {
        cout << "Book is not available in the library.\n";
        return;
    }

    int bookIndex = hashmapping[book];
    if (arr[bookIndex][1] <= 0) {
        cout << "Book is currently out of stock. Try again later.\n";
        return;
    }

    if (students[index].book1.empty()) {
        students[index].book1 = book;
        students[index].issueTime1 = currentTime;
        students[index].dueTime1 = currentTime + 5;
    } else {
        students[index].book2 = book;
        students[index].issueTime2 = currentTime;
        students[index].dueTime2 = currentTime + 5;
    }

    students[index].book_no++;
    arr[bookIndex][1]--;

    cout << "Book issued successfully.\n";
    cout << "Issue Time: " << currentTime << "\n";
    cout << "Due Time:   " << currentTime + 5 << "\n";

    logToFile("Issued Book: " + book + " to ID: " + to_string(id) + " at time: " + to_string(currentTime));
}

void returnBook() {
    int id;
    cout << "\nEnter your ID: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < 3; ++i) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Invalid ID.\n";
        return;
    }

    cout << "Enter name of the book to return: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string book;
    getline(cin, book);

    bool hasBook = false;
    if (students[index].book1 == book) {
        hasBook = true;
    } else if (students[index].book2 == book) {
        hasBook = true;
    }

    if (!hasBook) {
        cout << "This book was not issued to you.\n";
        return;
    }

    if (hashmapping.find(book) == hashmapping.end()) {
        cout << "Book record not found in system.\n";
        return;
    }

    int bookIndex = hashmapping[book];
    arr[bookIndex][1]++;
    students[index].book_no--;

    int returnTime = currentTime;
    int dueTime = 0;

    if (students[index].book1 == book) {
        dueTime = students[index].dueTime1;
        students[index].book1 = "";
        students[index].issueTime1 = 0;
        students[index].dueTime1 = 0;
    } else {
        dueTime = students[index].dueTime2;
        students[index].book2 = "";
        students[index].issueTime2 = 0;
        students[index].dueTime2 = 0;
    }

    if (returnTime > dueTime) {
        int delay = returnTime - dueTime;
        double fine = delay * 5.0;
        cout << "Book is overdue.\n";
        cout << "Returned at: " << returnTime << ", Due at: " << dueTime << "\n";
        cout << "Delay: " << delay << " seconds\n";
        cout << "Fine: Rs. " << fine << "\n";
    } else {
        cout << "Book returned on time.\n";
    }

    cout << "Book returned successfully.\n";
    logToFile("Returned Book: " + book + " by ID: " + to_string(id) + " at time: " + to_string(currentTime));
}

void librarianMenu() {
    string user, pass;
    cout << "\nEnter Librarian Username: "; cin >> user;
    cout << "Enter Password: "; cin >> pass;

    if (user == "admin" && pass == "password") {
        int choice;
        do {
            cout << "\nLibrarian Panel:\n";
            cout << "1. View Inventory\n";
            cout << "2. View Students\n";
            cout << "3. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "\nInventory:\n";
                    for (auto& pair : hashmapping) {
                        int idx = pair.second;
                        cout << pair.first << ": " << arr[idx][1] << "/" << arr[idx][0] << " available\n";
                    }
                    break;
                case 2:
                    cout << "\nStudents:\n";
                    for (int i = 0; i < 3; ++i) {
                        cout << students[i].name << " (ID: " << students[i].id << ") - Books: "
                             << students[i].book1 << ", " << students[i].book2 << "\n";
                    }
                    break;
                case 3:
                    cout << "Logging out...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 3);
    } else {
        cout << "Authentication failed.\n";
    }
}

int main() {
    setupBooks();
    setupStudents();

    int choice;
    bool running = true;
    while (running) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Issue Book\n";
        cout << "2. Return Book\n";
        cout << "3. Librarian Panel\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                issueBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                librarianMenu();
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice.\n";
        }
        currentTime += 1; // simulate clock ticking
    }
    return 0;
}
