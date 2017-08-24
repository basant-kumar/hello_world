/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int size=intervals.size();
    int i=0,j,k,flag=0;
    while(i<size){
        if(flag==1){
            if(intervals[i].start<=newInterval.end && intervals[i].end>=newInterval.end){
                k=i;break;
            }
            
        }
        else{
            if(intervals[i].end>=newInterval.start && intervals[i].start<=newInterval.start){
                j=i;flag=1;i++;
            }
        }
    }
    int start=intervals[j].start;
    int end=intervals[k].end;
    intervals.erase(intervals.begin()+j,intervals.begin()+k);
    intervals[j].start=start;
    intervals[j].end=end;
    return intervals;
}
