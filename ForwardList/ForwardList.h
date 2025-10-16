#pragma once
#include <string>

using namespace std;
struct Node {
    string value;
    Node* next;
};

struct ForwardList {
    Node* head;
};

void initList(ForwardList &list);

void addHead(ForwardList &list, const string &val);
void addTail(ForwardList &list, const string &val);
bool addBefore(ForwardList &list, const string &target, const string &val);
bool addAfter(ForwardList &list, const string &target, const string &val);

bool removeHead(ForwardList &list);
bool removeTail(ForwardList &list);
bool removeValue(ForwardList &list, const string &val);
bool removeBefore(ForwardList &list, const string &target);
bool removeAfter(ForwardList &list, const string &target);

Node* getNode(ForwardList &list, int index);
Node* findValue(ForwardList &list, const string &val);

void printList(ForwardList &list);

void readFromFile(ForwardList &list, const string &filename);
void writeToFile(ForwardList &list, const string &filename);

void clearList(ForwardList &list);
