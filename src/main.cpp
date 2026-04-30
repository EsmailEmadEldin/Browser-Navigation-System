#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// Class Node for the linked list
class Node
{
public:
    string info;   // data stored in the node
    Node* next;    // pointer to the next node
    Node(string in) : info(in), next(nullptr) {}  // constructor
};

// Stack implementation using a linked list
class Stack
{
private:
    Node* topofthestack;  // pointer to the top of the stack

public:
    Stack() { topofthestack = nullptr; }  // constructor

    // Push an item onto the stack
    void push(string item)
    {
        Node* n = new Node(item);
        if (n == nullptr)
        {
            cout << "Stack push: cannot allocate memory." << endl;
        }
        else
        {
            n->info = item;
            n->next = topofthestack;
            topofthestack = n;
        }
    }

    // Check if the stack is empty
    bool isEmpty() { return topofthestack == nullptr; }

    // Pop an item from the stack
    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return "";
        }
        else
        {
            Node* temp = topofthestack;
            string value = temp->info;
            topofthestack = topofthestack->next;
            temp->next = nullptr;
            delete temp;
            return value;
        }
    }

    // Clear all items from the stack
    void Clear()
    {
        while (!isEmpty()) { pop(); }
    }
};


int main()
{
    Stack Backward, Forward, temp;  // stacks for backward/forward navigation and temp loading
    string URLs[9];                 // array to store URLs from file
    int i = 0;

    ifstream file("URLs.txt");
    if (!file)
    {
        cout << "Error: could not open URLs.txt" << endl;
        return 1;
    }

    // Read up to 9 URLs from the file
    while (i < 9 && getline(file, URLs[i])) { i++; }

    // Push URLs into temp stack (to reverse order)
    for (int j = 0; j < 9; j++) { temp.push(URLs[j]); }

    // Transfer from temp to Backward (restores original order)
    while (!temp.isEmpty()) { Backward.push(temp.pop()); }

    // Set the first URL as the current page
    string Currentpage = Backward.pop();

    // Read the command line from the file
    string line;
    getline(file, line);
    file.close();

    // Tokenize commands by space
    char* cmd = strtok(&line[0], " ");
    string commands[10];
    int cmdcounter = 0;
    while (cmd != nullptr && cmdcounter < 10)
    {
        commands[cmdcounter++] = cmd;
        cmd = strtok(nullptr, " ");
    }

    // Process each command
    for (int j = 0; j < 10; j++)
    {
        cout << "\nChoice: " << (j + 1) << " [" << commands[j] << "]\n";

        if (commands[j] == "Backward" || commands[j] == "backward")
        {
            if (!Backward.isEmpty())
            {
                Forward.push(Currentpage);
                Currentpage = Backward.pop();
            }
        }
        else if (commands[j] == "Forward" || commands[j] == "forward")
        {
            if (!Forward.isEmpty())
            {
                Backward.push(Currentpage);
                Currentpage = Forward.pop();
            }
        }
        else
        {
            cout << "Invalid command: " << commands[j] << " — Skipping.\n";
        }

        cout << " === Current Page ===\n " << Currentpage << endl;

        // Peek at next page (Forward stack top)
        string next = "";
        if (!Forward.isEmpty())
        {
            next = Forward.pop();
            Forward.push(next);
        }
        cout << "=== Next Page ===\n" << (next.empty() ? "NONE" : next) << endl;

        // Peek at previous page (Backward stack top)
        string previous = "";
        if (!Backward.isEmpty())
        {
            previous = Backward.pop();
            Backward.push(previous);
        }
        cout << "=== Previous Page ===\n" << (previous.empty() ? "NONE" : previous) << endl;

        cout << "------------------------------------------------------------" << endl;
    }

    return 0;
}
