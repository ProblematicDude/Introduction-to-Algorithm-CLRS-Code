#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-7576,533626);

    for(int i = 1 ; i <= 20000 ; ++i){
        nums.push_back(dist(rng));
    }
}
void print(vector<int>& nums){
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
}

bool is_sort(vector<int>&nums){
    int n = nums.size();
    for(int i =1 ; i < n ; ++i){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}

void insertion_sort(vector<int> & nums){
    for(int i = 1 ; i < static_cast<int>(nums.size()); ++i){
        int key = nums[i];
        int j = i -1;
        while(j>= 0 && nums[j]> key){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = key;
    }
}

int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    insertion_sort(nums);
    //Utility to check if algo worked fine.
    //cout<<(is_sort(nums) ? "Array is sorted.\n" : " Unsorted array.\n");

    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();

    //Print Sorted array.
    //print(nums);

    cout << "Time : " << duration << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0 ;
}
