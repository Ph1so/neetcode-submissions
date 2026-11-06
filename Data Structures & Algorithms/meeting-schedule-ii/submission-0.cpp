/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int min = 0;
        int max_time = 0;
        for (const auto & i : intervals)
            max_time = max(max_time, i.end);
        
        vector<int> mask(max_time, 0);

        for (const auto & inter : intervals)
        {
            for (int i = inter.start; i < inter.end; i++)
                mask[i]++;
        }

        int max_rooms = 0;
        for (int i : mask)
            max_rooms = max(max_rooms, i);
        
        return max_rooms;
    }
};
