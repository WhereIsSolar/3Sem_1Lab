#include "Queue.h"
#include <iostream>
#include <sstream>

const string DATA_FILE = "queue.txt";
static Queue queueInstance;

void loadQueue() {
    clearQueue(queueInstance);
    initQueue(queueInstance);
    readFromFile(queueInstance, DATA_FILE);
}

void saveQueue() {
    writeToFile(queueInstance, DATA_FILE);
}

void printQueue(Queue &q) {
    for (int i = 0; i < q.size; ++i) {
        cout << q.data[(q.front + i) % q.capacity];
        if (i + 1 < q.size) cout << " ";
    }
    cout << endl;
}

void processCommand(const string &line) {
    stringstream ss(line);
    string cmd;
    ss >> cmd;

    if (cmd == "PUSH") {
        string val; ss >> val;
        Push(queueInstance, val);
        saveQueue();
        cout << "Pushed " << val << "\n";
        return;
    }

    if (cmd == "POP") {
        string val;
        if (Pop(queueInstance, val) != "") {
            saveQueue();
            cout << "Popped " << val << "\n";
        } else {
            cout << "Queue empty\n";
        }
        return;
    }

    if (cmd == "PEEK") {
        if (length(queueInstance) > 0) cout << "Front = " << peek(queueInstance) << "\n";
        else cout << "Queue empty\n";
        return;
    }

    if (cmd == "LENGTH") {
        cout << "Length = " << length(queueInstance) << "\n";
        return;
    }

    if (cmd == "CLEAR") {
        clearQueue(queueInstance);
        initQueue(queueInstance);
        saveQueue();
        cout << "Queue cleared\n";
        return;
    }

    if (cmd == "PRINT") {
        printQueue(queueInstance);
        return;
    }

    cout << "Unknown command: " << cmd << "\n";
}

int main() {
    initQueue(queueInstance);
    loadQueue();

    cout << "Queue CLI. Functions:\n"
              << "  PUSH <val>   - enqueue\n"
              << "  POP          - dequeue\n"
              << "  PEEK         - show front\n"
              << "  LENGTH       - show length\n"
              << "  PRINT        - print queue (front..back)\n"
              << "  CLEAR        - clear queue\n"
              << "  EXIT         - quit\n";

    string line;
    while (true) {
        cout << "> ";
        if (!getline(cin, line)) break;
        if (line == "EXIT") break;
        if (!line.empty()) processCommand(line);
    }

    clearQueue(queueInstance);
    return 0;
}
