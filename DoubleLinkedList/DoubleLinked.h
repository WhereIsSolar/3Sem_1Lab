#pragma once
#include <string>

using namespace std;

struct DNode {
    string value;
    DNode* prev;
    DNode* next;
};

struct DLList {
    DNode* head;
    DNode* tail;
};

void initDList(DLList &list);

void addHead(DLList &list, const string &val);
void addTail(DLList &list, const string &val);
bool addBefore(DLList &list, const string &target, const string &val);
bool addAfter(DLList &list, const string &target, const string &val);

bool removeHead(DLList &list);
bool removeTail(DLList &list);
bool removeValue(DLList &list, const string &val);
bool removeBefore(DLList &list, const string &target);
bool removeAfter(DLList &list, const string &target);

DNode* getNode(DLList &list, int index);
DNode* findValue(DLList &list, const string &val);

void printList(DLList &list);

void readFromFile(DLList &list, const string &filename);
void writeToFile(DLList &list, const string &filename);

void clearList(DLList &list);
