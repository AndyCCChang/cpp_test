#include <bits/stdc++.h>
using namespace std;
struct Interval{
    int start, end;
};
int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> map;
    for (auto i: intervals){
        map[i.start] = map[i.start] +1;
        map[i.end] = map[i.end] -1;
    }
    int room = 0;
    int maxrooms = 0;
    for (auto m: map){
        
        maxrooms = max(maxrooms, room = room + m.second );
    }
    return maxrooms;
}

int main(){
    vector<Interval> vec = {{0,30}, {5,10}, {15,20}};
    auto res = minMeetingRooms(vec);
    cout <<res <<endl;

}
