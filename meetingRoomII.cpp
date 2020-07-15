#include <bits/stdc++.h>
using namespace std;
struct Interval{
    int start, end;
};
int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> changes;
    for (auto i : intervals) {
        changes[i.start] += 1;
        changes[i.end] -= 1;
    }
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        maxrooms = max(maxrooms, rooms += change.second);
    return maxrooms;
}

int main(){
    vector<Interval> vec = {{0,30}, {5,10}, {15,20}};
    auto res = minMeetingRooms(vec);
    cout <<res <<endl;

}
