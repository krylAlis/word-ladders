#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>

std::unordered_set<std::string> words;
std::unordered_map<std::string, std::string> parent;

bool isAdjacent(const std::string& a, const std::string& b) {
    int differences = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            differences++;
        }
        if (differences > 1) {
            return false;
        }
    }
    return differences == 1;
}

std::vector<std::string> getWordLadder(const std::string& start, const std::string& end) {
    std::vector<std::string> ladder;
    std::queue<std::string> q;
    q.push(start);
    while (!q.empty()) {
        std::string current = q.front();
        q.pop();
        if (current == end) {
            while (current != start) {
                ladder.push_back(current);
                current = parent[current];
            }
            ladder.push_back(start);
            std::reverse(ladder.begin(), ladder.end());
            return ladder;
        }
        for (const std::string& word : words) {
            if (!parent.count(word) && isAdjacent(current, word)) {
                parent[word] = current;
                q.push(word);
            }
        }
    }
    return {};
}

int main() {
    std::cout << "Enter a list of words, one per line, followed by a blank line:" << std::endl;
    std::string word;
    while (std::cin >> word) {
        words.insert(word);
    }
    std::cout << "Enter the starting word:" << std::endl;
    std::string start;
    std::cin >> start;
    std::cout << "Enter the ending word:" << std::endl;
    std::string end;
    std::cin >> end;
    std::vector<std::string> ladder = getWordLadder(start, end);
   
