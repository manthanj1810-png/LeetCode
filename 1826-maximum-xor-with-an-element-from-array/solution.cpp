struct Node {
    Node* links[2] = {NULL};

    bool contains(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->contains(bit))
                node->put(bit, new Node());

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->contains(1 - bit)) {
                maxi |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        int q = queries.size();

        for (int i = 0; i < q; i++)
            queries[i].push_back(i);

        sort(queries.begin(), queries.end(), cmp);

        Trie trie;
        vector<int> ans(q, -1);

        int j = 0;
        int n = nums.size();

        for (auto& query : queries) {

            int x = query[0];
            int m = query[1];
            int idx = query[2];

            while (j < n && nums[j] <= m) {
                trie.insert(nums[j]);
                j++;
            }

            if (j == 0) {
                ans[idx] = -1;
            } else {
                ans[idx] = trie.getMax(x);
            }
        }

        return ans;
    }
};
