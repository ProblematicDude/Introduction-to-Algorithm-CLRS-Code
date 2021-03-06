#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


bool binary_search(vector<int>& nums, int low,int key){
    int high = static_cast<int>(nums.size()-1);
    while(high>=low){
        int mid = low+ (high-low)/2;
        if(nums[mid] == key){
            return true;
        }else if(nums[mid]>key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
}
void merge(vector<int>& nums , int low ,int mid , int high){
    int size1 = mid - low +1;
    int size2= high - mid;
    vector<int>left;
    vector<int>right;
    for(int i = 0  ; i < size1 ; ++i){
        left.push_back(nums[low+i]);
    }
    for(int i = 0 ; i <size2 ; ++i){
        right.push_back(nums[mid+i+1]);
    }
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int i = 0 ;
    int j = 0;
    for(int start = low ; start <= high ; ++start){
        if(left[i]<right[j]){
            nums[start] = left[i];
            i++;
        }else{
            nums[start] = right[j];
            j++;
        }
    }
}
void merge_sort(vector<int>&nums ,int low, int high){
    if(high>low){
        int mid = low+ (high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-9475,396045);

    for(int i = 1 ; i <= 2000 ; ++i){
        nums.push_back(dist(rng));
    }
}


//We can make it efficient by using heap sort instead of merge sort to avoid auxillary arrays.

//#Solution 1
bool sum_check(vector<int>&nums, int sum){
    merge_sort(nums,0,static_cast<int>(nums.size()-1));
    int complement ;
    bool result = false;
    for(int i = 0 ; i < static_cast<int>(nums.size()); ++i){
        complement = sum-nums[i];
        if(binary_search(nums,i+1,complement)){
            result = true;
            break;
        }
    }
    return result;
}

//OR

//#Solution 2


bool sum_check_(vector<int>&nums,int sum){
    merge_sort(nums,0,static_cast<int>(nums.size()-1));
    int i = 0 ;
    int j =static_cast<int>(nums.size()-1);
    while(i<j){
        if(nums[i]+nums[j] == sum){
            return true;
        }else if(nums[i]+nums[j]>sum){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

// Another solution. Though this is O(n)

//#Solution 3
bool sum_checck__(vector<int> & nums , int sum){
    unordered_set<int> set;
    for(int x : nums ){
        if(set.find(sum-x) != set.end()){
            return true;
        }
        set.insert(x);
    }
    return false;
}
int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Sorting the number
    merge_sort(nums,0, static_cast<int>(nums.size()-1));

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    cout<<(sum_check_(nums,-70) ? " Found," : "Not found.");


    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();


    cout << "Time : " << duration << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0 ;
}
