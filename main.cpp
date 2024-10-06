// Kit Pollinger
//  210 - Lab - 19 | Abstract and Automate lab 18

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // Time()
using namespace std;

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    double ratings;
    string comments;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void addNodeToTail(double ratings, string comments)
{
    Node *newNode = new Node;
    newNode->ratings = ratings;
    newNode->comments = comments;
    newNode->next = nullptr;

    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void addNodeToHead(double ratings, string comments)
{
    Node *newNode = new Node;
    newNode->ratings = ratings;
    newNode->comments = comments;
    newNode->next = head;
    head = newNode;
}

void printReview()
{
    Node *current = head;
    int count = 0;
    double totalRatings = 0.0;

    while (current != nullptr)
    {
        cout << "> Review #" << ++count << ": " << current->ratings << ": " << current->comments << endl;
        totalRatings += current->ratings;
        current = current->next;
    }
    double averageRatings = totalRatings / count;
    cout << " > Average: " << averageRatings << endl;
}

int main()
{
    int userChoice;
    double ratings;
    string comments;

    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list\n";
    cout << "[2] New nodes are added at the tail of the linked list\n";
    cin >> userChoice;

    for (char nextReview = 'y'; nextReview == 'y' || nextReview == 'Y';)
    {
        cout << "Enter review rating 0-5: ";
        cin >> ratings;
        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, comments);

        if (userChoice == 1)
        {
            addNodeToHead(ratings, comments);
        }
        else
        {
            addNodeToTail(ratings, comments);
        }

        cout << "Enter another review? Y/N: ";
        cin >> nextReview;
    }

    cout << "Outputting all reviews:" << endl;
    printReview();

    return 0;
}