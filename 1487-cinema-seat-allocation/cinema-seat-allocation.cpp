class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rseats) {

        rseats.push_back({0, 10});
        rseats.push_back({n + 1, 1});

        sort(rseats.begin(), rseats.end());

        int size = rseats.size();
        int count = 0;

        int skipRows, skipCols;

        for(int i = 1; i < size; i++)
        {
            if(rseats[i][0] != rseats[i-1][0])
            {
                // Previous cross is not in same row as current cross

                skipRows = rseats[i][0] - rseats[i-1][0];

                // Case-A
                // Add 2 count for each empty row
                count += 2 * (skipRows - 1);

                // Case-F
                if(rseats[i-1][1] == 1)
                    count += 2;

                // Case-G
                else if(rseats[i-1][1] < 6)
                    count += 1;

                // Case-H
                if(rseats[i][1] == 10)
                    count += 2;

                // Case-I
                else if(rseats[i][1] > 5)
                    count += 1;
            }
            else
            {
                // Previous cross is in same row as current cross

                // Case-B
                if(rseats[i-1][1] == 1 &&
                   rseats[i][1] == 10)
                {
                    count += 2;
                }

                // Case-C
                else if(rseats[i-1][1] < 4 &&
                        rseats[i][1] > 7)
                {
                    count += 1;
                }

                // Case-D
                else if(rseats[i-1][1] == 1 &&
                        rseats[i][1] > 5)
                {
                    count += 1;
                }

                // Case-E
                else if(rseats[i-1][1] < 6 &&
                        rseats[i][1] == 10)
                {
                    count += 1;
                }
            }
        }

        return count;
    }
};