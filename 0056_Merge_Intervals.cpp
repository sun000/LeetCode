/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a, Interval b) {
        if(a.start == b.start) return a.end > b.end;
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size() == 0) return ret;
        sort(intervals.begin(), intervals.end(), Solution::cmp);
        int ts = intervals[0].start;
        int te = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++) {
            if(te >= intervals[i].start) 
                te = max(te, intervals[i].end);
            else {
                ret.push_back(Interval(ts, te));
                ts = intervals[i].start;
                te = intervals[i].end;
            }
        }
        ret.push_back(Interval(ts, te));
        return ret;
    }
};