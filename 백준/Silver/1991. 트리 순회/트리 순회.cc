#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char left;
    char right;
};

void preorder(vector<Node>& nodes, char current) {
    if (current != '.' && current >= 'A' && current <= 'Z') {
        cout << current;
        preorder(nodes, nodes[current - 'A'].left);
        preorder(nodes, nodes[current - 'A'].right);
    }
}

void inorder(vector<Node>& nodes, char current) {
    if (current != '.' && current >= 'A' && current <= 'Z') {
        if (nodes[current - 'A'].left != '.') {
            inorder(nodes, nodes[current - 'A'].left);
        }
        cout << current;
        if (nodes[current - 'A'].right != '.') {
            inorder(nodes, nodes[current - 'A'].right);
        }
    }
}

void postorder(vector<Node>& nodes, char current) {
    if (current != '.' && current >= 'A' && current <= 'Z') {
        postorder(nodes, nodes[current - 'A'].left);
        postorder(nodes, nodes[current - 'A'].right);
        cout << current;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(26);

    for (int i = 0; i < n; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        nodes[parent - 'A'].left = left;
        nodes[parent - 'A'].right = right;
    }

    preorder(nodes, 'A');
    cout << "\n";
    inorder(nodes, 'A');
    cout << "\n";
    postorder(nodes, 'A');
    return 0;
}
