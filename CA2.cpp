#include <iostream>
using namespace std;

class Node {
    public:
        char data;
        Node* next;
};

class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }

        bool isEmpty() {
            return (front == NULL && rear == NULL);
        }

        void enqueue(char x) {
            Node* temp = new Node();
            temp->data = x;
            temp->next = NULL;
            if(isEmpty()) {
                front = rear = temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }

        char dequeue() {
            if(isEmpty()) {
                throw "Queue is empty.";
            }
            Node* temp = front;
            char x = temp->data;
            if(front == rear) {
                front = rear = NULL;
            } else {
                front = front->next;
            }
            delete temp;
            return x;
        }
};

int main() {
    Queue q;
    int count = 0, index = 1;
    string str;
    char choice;
    
    do {
        cout << "Enter the location of the string: ";
        cin >> index;
        cin.ignore();
        cout << "Enter the string: ";
        getline(cin, str);

        try {
            for(int i = 0; i < str.length(); i++) {
                if(str[i] != ' ' && (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
                    q.enqueue(str[i]);
                    count++;
                    cout << "Vowel " << count << " is '" << str[i] << "' at index " << i+1 << endl;
                }
            }
            if(count == 0) {
                cout << "No vowels found in the string." << endl;
            } else {
                cout << "Vowels in the string (in order): ";
                while(!q.isEmpty()) {
                    cout << q.dequeue() << " ";
                }
                cout << endl;
            }
        } catch(const char* msg) {
            cerr << "Error: " << msg << endl;
            cout << "Do you want to try again? (y/n): ";
            cin >> choice;
        }
    } while(choice == 'y' || choice == 'Y');

    return 0;
}
