class Solution {
struct node{
    int w, h;
    node(int ww, int hh):w(ww),h(hh){}
};
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<node> s;
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            int w = 1;
            while(!s.empty() && s.top().h >= heights[i]) {
                w += s.top().w;
                ans = max(ans, s.top().h * (w - 1));
                s.pop();    
            }
            s.push(node(w, heights[i]));
            ans = max(ans, w * heights[i]);
        }
        return ans;
    }
};