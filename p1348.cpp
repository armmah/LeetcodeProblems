#include "LeetCodeProblem.h"
#include "Utility.h"
#include <unordered_map>
#include <vector>

class p1348 : LeetCodeProblem {
    std::unordered_map<string, std::vector<int>> map;
public:
    
    void recordTweet(std::string tweetName, int time) {
        map[tweetName].push_back(time);
    }
    
    std::vector<int> getTweetCountsPerFrequency(std::string freq, std::string tweetName, int startTime, int endTime) {
        auto delta = 60;
        if(freq == "hour")
            delta = 3600;
        else if(freq == "day")
            delta = 86400;

        int len = (endTime - startTime)/delta + 1;
        std::vector<int> res(len);
        auto tweets = map[tweetName];
        for(int el : tweets) {
            if (el >= startTime && el <= endTime) {
                res[(el - startTime) / delta] ++;
            }
        }
        return res;
    }

    void testCase() {    
        p1348 tweetCounts = p1348();
        tweetCounts.recordTweet("tweet3", 0);
        tweetCounts.recordTweet("tweet3", 60);
        tweetCounts.recordTweet("tweet3", 10);
        auto v = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
        Utility::print(v, std::to_string);
        v = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
        Utility::print(v, std::to_string);
        tweetCounts.recordTweet("tweet3", 120);
        v = tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
        Utility::print(v, std::to_string);
    }
};