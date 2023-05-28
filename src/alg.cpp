#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Tree;
    std::ifstream file(filename);
    std::string word = "";
    while (!file.eof()) {
        word = "";
        for (;;) {
            char symbol = file.get();
            if ((symbol > 64 && symbol < 91) || (symbol > 96 && symbol < 123))
                word += tolower(symbol);
            else
                break;
        }
        Tree.CreateNode(word);
    }
    return Tree;
}
