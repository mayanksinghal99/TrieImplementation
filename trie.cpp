#include <bits./stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // Constructor to initialize a TrieNode with the given character 'ch'
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    // Constructor to initialize the Trie with an empty root node
    Trie()
    {
        root = new TrieNode('\0');
    }

    // Recursive function to insert a string 'str' into the Trie
    void insertHelper(TrieNode *&root, string str)
    {
        if (str.length() == 0)
        {
            cout << "insert successfully" << endl;
            root->isTerminal = true;
            return;
        }

        char ch = str[0];
        int index = ch - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertHelper(child, str.substr(1));
    }

    // Function to insert a string into the Trie
    void insert(string str)
    {
        insertHelper(root, str);
    }

    // Recursive function to search for a string 'str' in the Trie
    bool searchHelper(TrieNode *&root, string str)
    {
        if (str.length() == 0)
            return root->isTerminal;

        char ch = str[0];
        int index = ch - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        return searchHelper(child, str.substr(1));
    }

    // Function to search for a string in the Trie
    bool search(string str)
    {
        return searchHelper(root, str);
    }

    // Recursive function to traverse the Trie and print all stored strings
    void traverseHelper(TrieNode *&root, string &temp)
    {
        if (root == NULL)
        {
            cout << "Trie is empty" << endl;
            return;
        }

        if (root->isTerminal)
        {
            cout << temp << endl;
        }

        TrieNode *child;
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                child = root->children[i];
                temp += child->data;
                traverseHelper(child, temp);
                temp.pop_back();
            }
        }
    }

    // Function to traverse the Trie and print all stored strings
    void traverse()
    {
        string temp;
        traverseHelper(root, temp);
    }

    // Helper function to check if a TrieNode has any children
    bool isEmpty(TrieNode *&root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
                return false;
        }
        return true;
    }

    // Recursive function to remove a string 'str' from the Trie
    TrieNode *removeHelper(TrieNode *&root, string str)
    {
        if (root == NULL)
        {
            cout << "Trie is empty" << endl;
            return NULL;
        }
        if (str.length() == 0)
        {
            cout << "delete successfully" << endl;
            if (root->isTerminal)
                root->isTerminal = false;

            if (isEmpty(root))
            {
                delete root;
                root = NULL;
            }
            return root;
        }
        char ch = str[0];
        int index = ch - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            cout << "Invalid i/p" << endl;
            return root;
        }

        root->children[index] = removeHelper(child, str.substr(1));

        if (isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }
        return root;
    }

    // Function to remove a string from the Trie
    void remove(string str)
    {
        removeHelper(root, str);
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("code");
    trie->insert("coding");
    trie->insert("coder");
    trie->insert("codemonk");
    trie->insert("codekaze");

    cout << trie->search("coding") << endl;
    cout << trie->search("codestudio") << endl;

    trie->traverse();

    trie->remove("code");
    trie->traverse();

    trie->remove("coding");
    trie->traverse();

    trie->remove("coder");
    trie->traverse();

    trie->remove("codekaze");
    trie->traverse();

    trie->remove("codeblizz");
    trie->traverse();

    trie->remove("codemonk");
    trie->traverse();

    return 0;
}
