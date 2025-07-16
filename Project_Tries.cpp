#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>

using namespace std;

// -------------------- TRIE NODE --------------------

class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        this->isTerminal = false;
    }
};

// -------------------- TRIE --------------------

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // root with null character
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode(c);
            node = node->children[c];
        }
        node->isTerminal = true;
    }
};

// -------------------- PREFIX SEARCH --------------------

void dfs(TrieNode* node, string prefix, vector<string>& results) {
    if (node->isTerminal)
        results.push_back(prefix);

    for (auto& [ch, child] : node->children)
        dfs(child, prefix + ch, results);
}

vector<string> getWordsWithPrefix(Trie* trie, string prefix) {
    TrieNode* node = trie->root;
    for (char c : prefix) {
        if (!node->children.count(c)) return {};
        node = node->children[c];
    }
    vector<string> results;
    dfs(node, prefix, results);
    return results;
}

// -------------------- LEVENSHTEIN DISTANCE --------------------

int levenshtein(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = min({ dp[i-1][j] + 1,
                             dp[i][j-1] + 1,
                             dp[i-1][j-1] + (a[i-1] != b[j-1]) });

    return dp[n][m];
}

// -------------------- FUZZY MATCHING --------------------

void collectAllWords(TrieNode* node, string current, vector<string>& allWords) {
    if (node->isTerminal)
        allWords.push_back(current);

    for (auto& [ch, child] : node->children)
        collectAllWords(child, current + ch, allWords);
}

vector<pair<string, int>> getFuzzyMatches(Trie* trie, const string& query, int maxDistance = 2) {
    vector<string> allWords;
    collectAllWords(trie->root, "", allWords);

    vector<pair<string, int>> candidates;

    for (const string& word : allWords) {
        int dist = levenshtein(query, word);
        if (dist <= maxDistance)
            candidates.push_back({word, dist});
    }

    sort(candidates.begin(), candidates.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    return candidates;
}

// -------------------- DICTIONARY LOADING --------------------

void loadDictionaryFromFile(Trie* trie, const string& filename) {
    ifstream file(filename);
    string word;

    if (!file.is_open()) {
        cerr << "Error: Could not open dictionary file.\n";
        exit(1);
    }

    while (getline(file, word)) {
        if (!word.empty())
            trie->insert(word);
    }

    file.close();
}

// -------------------- MAIN --------------------

int main() {
    Trie* trie = new Trie();

    // Load words from dictionary.txt
    loadDictionaryFromFile(trie, "dictionary.txt");

    string query;
    cout << "Enter your search query: ";
    cin >> query;

    // Prefix Matches
    cout << "\nPrefix Matches:\n";
    vector<string> prefixMatches = getWordsWithPrefix(trie, query);
    if (prefixMatches.empty()) {
        cout << "No exact prefix matches found.\n";
    } else {
        for (const string& word : prefixMatches)
            cout << "- " << word << "\n";
    }

    // Fuzzy Matches
    cout << "\nFuzzy Matches (Levenshtein ≤ 2):\n";
    vector<pair<string, int>> fuzzyMatches = getFuzzyMatches(trie, query, 2);
    if (fuzzyMatches.empty()) {
        cout << "No fuzzy matches found.\n";
    } else {
        for (auto& [word, dist] : fuzzyMatches)
            cout << "- " << word << " (distance: " << dist << ")\n";
    }

    return 0;
}
