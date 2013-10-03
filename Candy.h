/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 3, 2013
 Problem:    Candy
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/candy/
 Notes:
 There are N children standing in a line. Each child is assigned a rating value.
 You are giving candies to these children subjected to the following requirements:
 - Each child must have at least one candy.
 - Children with a higher rating get more candies than their neighbors.
 What is the minimum candies you must give?

 Solution: You may refer to https://github.com/AnnieKim/ITint5/blob/master/031_%E5%88%86%E9%85%8D%E7%B3%96%E6%9E%9C.cpp
           1. traverse only once with O(1) space. 2. O(n) space.
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        return candy_1(ratings);
    }
    
    int candy_1(vector<int> &ratings) {
        int N = ratings.size();
        if (N == 0) return 0;
        int candy = 1, res = 1;
        int maxValue = 1, maxIndex = 0;
        for (int i = 1; i < N; ++i)
        {
            if (ratings[i] >= ratings[i-1]) 
            {
                candy = ratings[i] == ratings[i-1] ? 1 : candy + 1;
                maxValue = candy;
                maxIndex = i;
            }
            else
            {
                if (candy == 1) {
                    if (maxValue <= i - maxIndex) {
                        res += i - maxIndex;
                        maxValue++;
                    } else {
                        res += i - maxIndex - 1;
                    }
                }
                candy = 1;
            }
            res += candy;
        }
        return res;
    }
    
    int candy_2(vector<int> &ratings) {
        int N = ratings.size();
        if (N == 0) return 0;
        int candy[N];
        for (int i = 0; i < N; ++i)
            candy[i] = 1;
        for (int i = 1; i < N; ++i)
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        for (int i = N-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
                candy[i] = candy[i+1] + 1;
        int res = 0;
        for (int i = 0; i < N; ++i)
            res += candy[i];
        return res;
    }
};