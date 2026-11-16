class Solution {
public:
    void printStack(std::stack<int> s) {
        while (!s.empty()) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << '\n';
    }
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // monotonically decreasing stack
        // pop until top element is bigger 
        int n = heights.size();
        vector<int> output;
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            int count = 0;
            while (!s.empty() && s.top() < heights[i]) {
                s.pop();
                count++;        // person i sees every shorter person we pop
            }
            if (!s.empty())
                count++;        // person i also sees the first taller person, who blocks everyone behind them
            output.insert(output.begin(), count);   // moved after the loop, and uses count instead of s.size()
            s.push(heights[i]);
        }
        return output;
    }
};