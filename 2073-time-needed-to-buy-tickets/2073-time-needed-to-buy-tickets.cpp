class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        // have to push all the elements of target into queue
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        int time=0;
        while(!q.empty()){
            int person=q.front();
            q.pop();
            tickets[person]--;
            time++;
            if(person==k && tickets[person]==0){
                return time;
            }
            if(tickets[person]>0){
                q.push(person);
            }
        }
        return time;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna