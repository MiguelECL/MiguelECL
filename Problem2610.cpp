/*
    The following code is intended to run inside the LeetCode environment for the given problem, if you wish to run this program outside of LeetCode,
    you would need to create a main() function, (as required by the C++ language specifications), aswell as include iostream, and vector.
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Without using std::map or std::multiset
        vector<vector<int>> ResultArray;
        vector<int> TempArray;
        vector<int> Remainders;

        //[1,3,4,1,2,3,1]
        // [1, 3 ,1]
        // [1]
        while(nums.size()){
            for (int Number: nums){ //cada valor en el arreglo nums
                bool RepeatFlag = false;
                
                if(TempArray.size() == 0){
                    TempArray.push_back(Number);
                    continue;
                }
                // [1]
                for (int TempNumber : TempArray){ //cada valor en el arreglo temporal
                    if (Number == TempNumber){
                        RepeatFlag = true;
                        Remainders.push_back(Number); // [1,3,1]
                        break;
                    } else {
                        RepeatFlag = false;
                    }
                }

                if(!RepeatFlag){
                    TempArray.push_back(Number); // [1,3,4,2]
                }
            }
            nums = Remainders; //[1,3,1];
            Remainders.clear();
            ResultArray.push_back(TempArray); // se anaden los que no se repitieron
            TempArray.clear();
        }
        return ResultArray;
    }
};