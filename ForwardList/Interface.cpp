#include <iostream>
#include <sstream>
#include <string>
#include "ForwardList.h"

const string DATA_FILE = "list.txt";

void loadList(ForwardList &list) {
    clearList(list);
    readFromFile(list, DATA_FILE);
}

void saveList(ForwardList &list) {
    writeToFile(list, DATA_FILE);
}

void processCommand(ForwardList &list, const string &commandLine) {
    stringstream ss(commandLine);
    string cmd;
    ss >> cmd;

    if (cmd == "PRINT") {
        printList(list);
        return;
    }

    if (cmd == "LCLEAR") {
        clearList(list);
        saveList(list);
        cout << "List cleared.\n";
        return;
    }

    if (cmd == "LADDH") {
        string val; ss >> val;
        addHead(list, val);
        saveList(list);
        cout << "Added " << val << " to head.\n";
        return;
    }

    if (cmd == "LADDT") {
        string val; ss >> val;
        addTail(list, val);
        saveList(list);
        cout << "Added " << val << " to tail.\n";
        return;
    }

    if (cmd == "LADDB") {
        string target, val; ss >> target >> val;
        if (addBefore(list, target, val)) {
            saveList(list);
            cout << "Inserted " << val << " before " << target << ".\n";
        } else {
            cout << "Target " << target << " not found.\n";
        }
        return;
    }

    if (cmd == "LADDA") {
        string target, val; ss >> target >> val;
        if (addAfter(list, target, val)) {
            saveList(list);
            cout << "Inserted " << val << " after " << target << ".\n";
        } else {
            cout << "Target " << target << " not found.\n";
        }
        return;
    }

    if (cmd == "LREMH") {
        if (removeHead(list)) {
            saveList(list);
            cout << "Head removed.\n";
        } else {
            cout << "List empty.\n";
        }
        return;
    }

    if (cmd == "LREMT") {
        if (removeTail(list)) {
            saveList(list);
            cout << "Tail removed.\n";
        } else {
            cout << "List empty.\n";
        }
        return;
    }

    if (cmd == "LREMV") {
        string val; ss >> val;
        if (removeValue(list, val)) {
            saveList(list);
            cout << "Removed value " << val << ".\n";
        } else {
            cout << "Value not found.\n";
        }
        return;
    }

    if (cmd == "LREMBEFORE") {
        string target; ss >> target;
        if (removeBefore(list, target)) {
            saveList(list);
            cout << "Removed node before " << target << ".\n";
        } else {
            cout << "Nothing to remove before " << target << ".\n";
        }
        return;
    }

    if (cmd == "LREMAFTER") {
        string target; ss >> target;
        if (removeAfter(list, target)) {
            saveList(list);
            cout << "Removed node after " << target << ".\n";
        } else {
            cout << "Nothing to remove after " << target << ".\n";
        }
        return;
    }

    if (cmd == "LGET") {
        int idx; ss >> idx;
        Node* n = getNode(list, idx);
        if (n) cout << "Node[" << idx << "] = " << n->value << "\n";
        else cout << "Index out of range.\n";
        return;
    }

    if (cmd == "LFIND") {
        string val; ss >> val;
        Node* n = findValue(list, val);
        if (n) cout << "Found value: " << val << "\n";
        else cout << "Value not found.\n";
        return;
    }

    cout << "Unknown command: " << cmd << "\n";
}

int main() {
    ForwardList list;
    initList(list);
    loadList(list);

    cout << "ForwardList CLI. Functions:\n"
              << "  LADDH <val>               - add to head\n"
              << "  LADDT <val>               - add to tail\n"
              << "  LADDB <target> <val>      - add before target\n"
              << "  LADDA <target> <val>      - add after target\n"
              << "  LREMH                     - remove head\n"
              << "  LREMT                     - remove tail\n"
              << "  LREMV <val>               - remove by value\n"
              << "  LREMBEFORE <target>       - remove node before target\n"
              << "  LREMAFTER <target>        - remove node after target\n"
              << "  LGET <index>              - get node by index\n"
              << "  LFIND <val>               - find node by value\n"
              << "  LCLEAR                    - clear list\n"
              << "  PRINT                     - print list\n"
              << "  EXIT                      - quit\n";

    string line;
    while (true) {
        cout << "> ";
        if (!getline(cin, line)) break;
        if (line == "EXIT") break;
        if (!line.empty()) processCommand(list, line);
    }

    clearList(list);
    return 0;
}
