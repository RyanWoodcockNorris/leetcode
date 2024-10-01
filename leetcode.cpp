#include <iostream>
#include <vector>        
#include <unordered_map>
#include <map>
#include <stack>


int main()
{
    // Solution 1. Two Sum
    class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
                if (map.find(complement) != map.end()) {
                    return { map[complement], i };
                }
                map[nums[i]] = i;
            }
            return {};
        }
    };
    // Solution 9. Palindrome Number
    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x == 0) {
                return true;
            }
            if (x < 0 || x % 10 == 0) {
                return false;
            }
            double y = 0;
            int tempx = x;
            while (tempx > 0) {
                y = tempx % 10 + y * 10;
                tempx /= 10;
            }

            return x == y;
        }
    };
    // Solution 13. Roman to Integer
    class Solution {
    public:
        int romanToInt(std::string s) {
            std::map<char, int> charToIntMap =
            { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

            int sum = 0;

            for (int i = 0; i < s.size(); i++) {
                if (i < s.size() - 1 && charToIntMap[s[i]] < charToIntMap[s[i + 1]]) {
                    sum -= charToIntMap[s[i]];
                }
                else {
                    sum += charToIntMap[s[i]];
                }
            }
            return sum;
        }
    };
    // Solution 14. Longest Common Prefix
    class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            std::string prefix;

            for (int j = 0; j < strs[0].size(); j++) {
                char c = strs[0][j];
                for (int i = 0; i < strs.size(); i++) {
                    if (j >= strs[i].size() || strs[i][j] != c) {
                        return prefix;
                    }
                }
                prefix.push_back(c);
            }
            return prefix;
        }
    };
    // Solution 20. Valid Parentheses
#include <stack>

    class Solution {
    public:
        bool isValid(std::string s) {
            std::stack<char> stack;

            struct BracketData {
                char openBracket;
                char closeBracket;
            };

            std::vector<BracketData> brackets =
            { {'(', ')'}, {'[', ']'}, {'{', '}'} };

            int length = s.size();
            if (length == 1) {
                return false;
            }

            for (int i = 0; i < length; i++) {
                for (int j = 0; j < brackets.size(); j++) {
                    if (s[i] == brackets[j].openBracket) {
                        stack.push(s[i]);
                    }
                    else if (s[i] == brackets[j].closeBracket) {
                        if (stack.empty() || stack.top() != brackets[j].openBracket) {
                            return false;
                        }
                        stack.pop();
                    }
                }
            }

            return stack.empty();
        }
    };
    // Solution 21. Merge Two Sorted Lists
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode temp;
            ListNode* ptr = &temp;

            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    ptr->next = list1;
                    list1 = list1->next;
                }
                else {
                    ptr->next = list2;
                    list2 = list2->next;
                }
                ptr = ptr->next;
            }

            if (list1 != nullptr) {
                ptr->next = list1;
            }
            else {
                ptr->next = list2;
            }

            return temp.next;
        }
    };
    // Solution 26. Remove Duplicates from Sorted Array
    class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            int k = 1;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] != nums[i - 1]) {
                    nums[k] = nums[i];
                    k++;
                }
            }
            return k;
        }
    };
    // Solution 27. Remove Duplicates from Sorted Array
    class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            int ctr = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != val) {
                    nums[ctr] = nums[i];
                    ctr++;
                }
            }
            return ctr;
        }
    };
    // Solution 28. Find the Index of the First Occurrence in a String
    class Solution {
    public:
        int strStr(std::string haystack, std::string needle) {
            for (int i = 0; i < haystack.size(); i++) {
                if (haystack.size() - i < needle.size()) {
                    return -1;
                }
                if (haystack[i] == needle[0]) {
                    int count = 0;
                    for (int j = 0; j < needle.size(); j++) {
                        if (haystack[i + j] == needle[j]) {
                            count++;
                            if (count == needle.size()) {
                                return i;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            return -1;
        }
    };
    // Solution 35. Search Insert Position
    class Solution {
    public:
        int searchInsert(std::vector<int>& nums, int target) {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (target<nums[i + 1] && target>nums[i]) {
                    return i + 1;
                }
                else if (target == nums[i]) {
                    return i;
                }
                else if (target == nums[i + 1]) {
                    return i + 1;
                }
                else if (i + 2 == nums.size() && target > nums[i + 1]) {
                    return i + 2;
                }
            }
            if (nums.size() == 1) {
                if (target > nums[0]) {
                    return 1;
                }
                else if (target == nums[0]) {
                    return 0;
                }
            }
            return 0;
        }
    };
    // Solution 58. Length of Last Word
    class Solution {
    public:
        int lengthOfLastWord(std::string s) {
            int length = 0;

            int i = s.size() - 1;
            while (s[i] == ' ') {
                i--;
            }
            while (i > -1 && s[i] != ' ' && i > -1) {
                length++;
                i--;
            }
            return length;
        }
    };
    // Solution 66. Plus One
    class Solution {
    public:
        std::vector<int> plusOne(std::vector<int>& digits) {
            if (digits[digits.size() - 1] != 9) {
                digits[digits.size() - 1]++;
            }
            else {
                for (int i = 0; i < digits.size(); i++) {
                    if (digits[digits.size() - i - 1] == 9 && digits.size() - i - 1 != 0) {

                        digits[digits.size() - i - 1] = 0;
                    }
                    else if (digits[digits.size() - i - 1] == 9) {
                        for (int j = 0; j < digits.size(); j++) {
                            digits[i] = 0;
                        }
                        digits.resize(digits.size() + 1);
                        digits[0] = 1;
                        break;
                    }
                    else {
                        digits[digits.size() - i - 1]++;
                        break;
                    }
                }
            }
            return digits;
        }
    };
    // Solution 67. Add Binary
    class Solution {
    public:
        std::string addBinary(std::string a, std::string b) {
            std::string s;
            int carry = 0, i = 0;
            int max = a.size(), n = b.size();
            while (i < max || i < n || carry) {
                int sum = carry;
                if (i < max) {
                    sum += a[max - 1 - i] - '0';
                }
                if (i < n) {
                    sum += b[n - 1 - i] - '0';
                }
                carry = sum / 2;
                s = char(sum % 2 + '0') + s;
                i++;
            }
            return s;
        }
    };
    // Solution 79. Word Search
    class Solution {
    public:
        bool exist(std::vector<std::vector<char>>& board, std::string word) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    if (board[i][j] == word[0]) {
                        if (dfs(board, word, i, j, 0))
                            return true;
                    }
                }
            }
            return false;
        }

        bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int pos) {
            if (pos == word.size())
                return true;
            if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != word[pos])
                return false;
            if (board[i][j] == '#')
                return false;
            char temp = board[i][j];
            board[i][j] = '#';
            bool found = dfs(board, word, i - 1, j, pos + 1) ||
                dfs(board, word, i + 1, j, pos + 1) ||
                dfs(board, word, i, j - 1, pos + 1) ||
                dfs(board, word, i, j + 1, pos + 1);
            board[i][j] = temp;

            return found;
        }
    };
    // Solution 344. Reverse String
    class Solution {
    public:
        void reverseString(std::vector<char>& s) {
            char temp;
            for (int i = 0; i < s.size() / 2; i++) {
                temp = s[s.size() - i - 1];
                s[s.size() - i - 1] = s[i];
                s[i] = temp;
            }
        }
    };
    // Solution 409. Longest Palindrome
    class Solution {
    public:
        int longestPalindrome(std::string s) {
            std::unordered_map<char, int> charmap;
            for (char c : s) {
                charmap[c]++;
            }
            int sum = 0, sum2 = 0;
            bool middle, alleven = true;
            for (auto it = charmap.begin(); it != charmap.end(); ++it) {
                if (it->second % 2 == 0) {
                    sum2 += it->second;
                }
                else if (it->second == 1) {
                    middle = true;
                    alleven = false;
                }
                else if (it->second > 0) {
                    sum++;
                    sum2 += it->second;
                    alleven = false;
                }
            }
            if (alleven) {
                return sum2;
            }
            return sum2 - sum + 1;
        }
    };
    // Solution 1002. Find Common Characters
    class Solution {
    public:
        std::vector<std::string> commonChars(std::vector<std::string>& words) {
            std::vector<std::string> dupechars;
            std::map<int, std::unordered_map<char, int>> chars;
            std::unordered_map<char, int> uniquechars;
            for (int i = 0; i < words.size(); i++) {
                for (const char& c : words[i]) {
                    uniquechars[c]++;
                    chars[i][c]++;
                }
            }
            std::string current;
            for (auto i = uniquechars.begin(); i != uniquechars.end(); ++i) {
                char current_char = i->first;
                for (auto it = chars.begin(); it != chars.end(); ++it) {
                    if (it->second[current_char] < uniquechars[current_char]) {
                        uniquechars[current_char] = it->second[current_char];
                    }
                }
                for (int k = 0; k < uniquechars[current_char]; k++) {
                    current = current_char;
                    dupechars.push_back(current);
                }
            }
            return dupechars;
        }
    };
    // Solution 1550. Three Consecutive Odds
    class Solution {
    public:
        bool threeConsecutiveOdds(std::vector<int>& arr) {
            int sum = 0;
            for (int n : arr) {
                if (n % 2 == 1) {
                    sum++;
                    if (sum == 3) {
                        return true;
                    }
                }
                else {
                    sum = 0;
                }
            }
            return false;
        }
    };
    // Solution 2073. Time Needed to Buy Tickets
    class Solution {
    public:
        int timeRequiredToBuy(std::vector<int>& tickets, int k) {
            int time = 0;
            for (int j = tickets[k]; j > 0; j--) {
                for (int i = 0; i < tickets.size(); i++) {
                    if (tickets[i] > 0) {
                        time++;
                        tickets[i]--;
                        if (tickets[k] == 0) {
                            return time;
                        }
                    }
                }
            }
            return time;
        }
    };
    // Solution 2486. Append Characters to String to Make Subsequence
    class Solution {
    public:
        int appendCharacters(std::string s, std::string t) {
            int sum = 0;
            for (int i = 0; i < s.size(); i++) {
                if (t[sum] == s[i]) {
                    sum++;
                }
            }
            return (t.size() - sum);
        }
    };
    // Solution 3110. Score of a String
    class Solution {
    public:
        int scoreOfString(std::string s) {
            int sum = 0;
            for (int i = 0; i < s.size() - 1; i++) {
                sum += (sqrt((s[i] - s[i + 1]) * (s[i] - s[i + 1])));
            }
            return sum;
        }
    };
    // Solution 27. Remove Element
    class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            int ctr = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != val) {
                    nums[ctr] = nums[i];
                    ctr++;
                }
            }
            return ctr;
        }
    };
    // Solution 731. My Calendar II
    class MyCalendarTwo {
    public:
        std::vector<std::pair<int, int>> table;
        std::vector<std::pair<int, int>> overlaps;

        MyCalendarTwo() {
        }

        bool book(int start, int end) {
            for (const auto& overlap : overlaps) {
                if (std::max(overlap.first, start) < std::min(overlap.second, end)) {
                    return false;
                }
            }
            for (const auto& event : table) {
                if (std::max(event.first, start) < std::min(event.second, end)) {
                    overlaps.push_back({ std::max(event.first, start), std::min(event.second, end) });
                }
            }
            table.push_back({ start, end });
            return true;
        }
    };

    /**
     * Your MyCalendarTwo object will be instantiated and called as such:
     * MyCalendarTwo* obj = new MyCalendarTwo();
     * bool param_1 = obj->book(start,end);
     */
     // Solution 729. My Calendar I
    class MyCalendar {
    public:
        MyCalendar() {
        }

        std::vector<std::pair<int, int>> table;
        bool book(int start, int end) {
            for (const auto& event : table) {
                if ((event.first < end && start < event.second)) {
                    return false;
                }
            }
            table.push_back({ start, end });
            return true;
        }
    };

    /**
     * Your MyCalendar object will be instantiated and called as such:
     * MyCalendar* obj = new MyCalendar();
     * bool param_1 = obj->book(start,end);
     */
     // Solution 2. Add Two Numbers
    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode() : val(0), next(nullptr) {}
    *     ListNode(int x) : val(x), next(nullptr) {}
    *     ListNode(int x, ListNode *next) : val(x), next(next) {}
    * };
    */
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummyHead = new ListNode(0);
            //used to create resultant list 3
            ListNode* current = dummyHead;
            int carry = 0;

            //traverse both lists
            while (l1 != nullptr || l2 != nullptr) {
                //carryover can only occur given lists 1 & 2 digitspan overlap
                int x = (l1 != nullptr) ? l1->val : 0;
                int y = (l2 != nullptr) ? l2->val : 0;
                int sum = carry + x + y;
                //greater magnitude digit to carry over
                carry = sum / 10;
                //new elements of list 3 (result) created for sum of lesser digits
                current->next = new ListNode(sum % 10);
                current = current->next;

                //iterate to next node
                if (l1 != nullptr) l1 = l1->next;
                if (l2 != nullptr) l2 = l2->next;
            }

            //given the result is of greater magnitude, create additional list 3 node
            if (carry > 0) {
                current->next = new ListNode(carry);
            }

            //return list 3
            return dummyHead->next;
        }
    };
    // Solution 705. Design HashSet
    class MyHashSet {
    private:
        unordered_map<int, bool> map;
    public:
        MyHashSet() {
        }

        void add(int key) {
            map[key] = true;
        }

        void remove(int key) {
            //map[key] = false;
            map.erase(key);
        }

        bool contains(int key) {
            //if(map[key]){
            //    return true;
            //}
            //return false;
            return map.find(key) != map.end();
        }
    };

    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */
    // Solution 706. Design HashMap
    class MyHashMap {
    private:
        unordered_map<int, int> hashmap;

    public:
        MyHashMap() {
        }

        void put(int key, int value) {
            hashmap[key] = value;
        }

        int get(int key) {
            if (hashmap.find(key) != hashmap.end()) {
                return hashmap[key];
            }
            return -1;
        }

        void remove(int key) {
            hashmap.erase(key);
        }
    };

    /**
     * Your MyHashMap object will be instantiated and called as such:
     * MyHashMap* obj = new MyHashMap();
     * obj->put(key,value);
     * int param_2 = obj->get(key);
     * obj->remove(key);
     */
}