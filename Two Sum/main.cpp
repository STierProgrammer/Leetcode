#include <vector>
#include <unordered_map>

using namespace std;

class Solutions
{
    public:
        // Bruteforcing O(n^2)     
        vector<int> twoSumV1(vector<int> &nums, int target)
        {
            vector<int> idxs;

            for (int j = 0; j < nums.size(); j++) {
                for (int i = j + 1; i < nums.size(); i++) {
                    if (nums.at(j) + nums.at(i) == target) {
                        idxs.push_back(j);
                        idxs.push_back(i);

                        break;
                    }          
                }
            }

            return idxs;
        }

        // More efficient
        vector<int> twoSumV2(vector<int> &nums, int target) {
            vector<int> idxs;

            unordered_map<int, int> hashmap;

            for (int j = 0; j < nums.size(); j++) {
                // Value that needs to be found
                int val = target - nums.at(j);

                if (hashmap.find(val) != hashmap.end()) {
                    idxs.push_back(j);
                    idxs.push_back(hashmap.find(val)->second);
                    break; 
                }
                else {
                    hashmap[nums.at(j)] = j;
                }
            }

            return idxs;
        }
};