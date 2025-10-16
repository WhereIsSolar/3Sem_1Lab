#pragma once
#include <string>

using namespace std;

struct Queue {
    string* data;
    int size;
    int capacity;
    int front;
    int back;
};

void initQueue(Queue &q, int capacity = 100);

string Push(Queue &q, const string &val);
string Pop(Queue &q, string &val);

string peek(Queue &q);
int length(Queue &q);

void readFromFile(Queue &q, const string &filename);
void writeToFile(Queue &q, const string &filename);

void clearQueue(Queue &q);
