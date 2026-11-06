class Solution {
public:
    vector<int> probs;
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i ++)
            for (int n = 0; n < w[i]; n++)
                probs.push_back(i);
    }
    
    int pickIndex() {
        int n = probs.size(); // Upper bound
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(0, n-1);
        int random_num = distrib(gen);
        return probs[random_num];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */