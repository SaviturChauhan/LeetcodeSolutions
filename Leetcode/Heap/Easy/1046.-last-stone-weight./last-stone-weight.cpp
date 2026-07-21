class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if (n == 1)
            return stones[0];
        priority_queue<int> pq;
        int last = 0;

        for (int i = 0; i < n; i++) {
            pq.push(stones[i]);
        }

        while (pq.size() > 1) {
            last = pq.top();
            pq.pop();
            int one;
            if (pq.size() >= 1){
                one = pq.top();
                pq.pop();
            }
            if (last != one){
              pq.push(abs(one - last));
            }
              
        }

        return pq.empty() ? 0 : pq.top();
    }
};