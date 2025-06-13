#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            pair<string, int> p = q.front();
            string word = p.first;
            int ladder = p.second;
            q.pop();
            if (word == endWord) return ladder;
            dict.erase(word);
            for (int j = 0; j < word.size(); j++) {
                char c = word[j];
                for (int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;
                    if (dict.find(word) != dict.end()) q.push({word, ladder + 1});
                }
                word[j] = c;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}