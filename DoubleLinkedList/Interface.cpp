#include "DoubleLinked.h"
#include <iostream>
#include <sstream>

const 
string DATA_FILE = "dlist.txt";

void loadList(DLList &list) {
    clearList(list);
    readFromFile(list, DATA_FILE);
}

void saveList(DLList &list) {
    writeToFile(list, DATA_FILE);
}

void processCommand(DLList &list, const 
string &line) {
    
stringstream ss(line);
    
string cmd;
    ss >> cmd;

    if (cmd == "PRINT") { printList(list); return; }
    if (cmd == "DCLEAR") {
      clearList(list);
      saveList(list);
      cout << "List cleared.\n";
      return;
    }

    if (cmd == "DADDH") {
      string val;
      ss >> val;
      addHead(list, val);
      saveList(list);
      cout << "Added " << val << " to head.\n";
      return;
    }
    
    if (cmd == "DADDT") {
      string val;
      ss >> val;
      addTail(list, val);
      saveList(list);
      cout << "Added " << val << " to tail.\n";
      return;
    }
    if (cmd == "DADDB") {
      string target, val;
      ss >> target >> val;
      if (addBefore(list, target, val)) {
        saveList(list);
        cout << "Inserted " << val << " before " << target << ".\n";
      } else {
        cout << "Target " << target << " not found.\n";
      }
      return;
    }
    if (cmd == "DADDA") {
      string target, val;
      ss >> target >> val;
      if (addAfter(list, target, val)) {
        saveList(list);
        cout << "Inserted " << val << " after " << target << ".\n";
      } else {
        cout << "Target " << target << " not found.\n";
      }
      return;
    }

    if (cmd == "DREMH") {
      if (removeHead(list)) {
        saveList(list);
        cout << "Head removed.\n";
      } else {
        cout << "List empty.\n";
      }
      return;
    }
    if (cmd == "DREMT") {
      if (removeTail(list)) {
        saveList(list);
        cout << "Tail removed.\n";
      } else {
        cout << "List empty.\n";
      }
      return;
    }
    if (cmd == "DREMV") {
      string val;
      ss >> val;
      if (removeValue(list, val)) {
        saveList(list);
        cout << "Removed value " << val << ".\n";
      } else {
        cout << "Value not found.\n";
      }
      return;
    }

    if (cmd == "DREMBA") {
      string target;
      ss >> target;
      if (removeBefore(list, target)) {
        saveList(list);
        cout << "Removed node before " << target << ".\n";
      } else {
        cout << "Nothing to remove before " << target << ".\n";
      }
      return;
    }
    
    if (cmd == "DREMAF") {
      string target;
      ss >> target;
      if (removeAfter(list, target)) {
        saveList(list);
        cout << "Removed node after " << target << ".\n";
      } else {
        cout << "Nothing to remove after " << target << ".\n";
      } return; }

    if (cmd == "DGET") {
      int idx;
      ss >> idx;
      DNode *n = getNode(list, idx);
      if (n)
        cout << "Node[" << idx << "] = " << n->value << "\n";
      else
        cout << "Index out of range.\n";
      return;
    }
    if (cmd == "DFIND") {
      string val;
      ss >> val;
      DNode *n = findValue(list, val);
      if (n)
        cout << "Found value: " << val << "\n";
      else
        cout << "Value not found.\n";
      return;
    }

    
    cout << "Unknown command: " << cmd << "\n";
}

int main() {
    DLList list;
    initDList(list);
    loadList(list);

    
    cout << "DoublyLinkedList CLI. Functions:\n"
              << "  DADDH <val>           - add to head\n"
              << "  DADDT <val>           - add to tail\n"
              << "  DADDB <target> <val>  - add before target\n"
              << "  DADDA <target> <val>  - add after target\n"
              << "  DREMH                 - remove head\n"
              << "  DREMT                 - remove tail\n"
              << "  DREMV <val>           - remove by value\n"
              << "  DREMBA <target>       - remove before target\n"
              << "  DREMAF <target>       - remove after target\n"
              << "  DGET <index>          - get node by index\n"
              << "  DFIND <val>           - find node by value\n"
              << "  DCLEAR                - clear list\n"
              << "  PRINT                 - print list\n"
              << "  EXIT                  - quit\n";

    
    string line;
    while (true) {
        
      cout << "> ";
      if (!
	  getline(cin, line)) break;
      if (line == "EXIT") break;
      if (!line.empty()) processCommand(list, line);
    }
    
    clearList(list);
    return 0;
}
