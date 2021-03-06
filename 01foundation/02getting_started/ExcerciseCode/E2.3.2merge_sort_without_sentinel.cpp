#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void merge_without_sentinals(vector<int>&nums , int low , int mid , int high){
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
    int i = 0 ;
    int j = 0;
    int start  = low;

    //You can either use

    //1. for loop  (A)

    // OR

    //2.while loop  + b1 OR while loop + b2



    //A


    for(int k = start ; k <= high ; ++k){
        if((i < size1 ) &&  (j >= size2 || left[i] <= right[j])){
            nums[k] = left[i];
            i++;
        }else{
            nums[k] = right[j];
            j++;
        }
    }





    //B

    /*while(i < size1 && j < size2){
        if(left[i]<right[j]){
            nums[start] = left[i];
            start++;
            i++;
        }else{
            nums[start] = right[j];
            start++;
            j++;
        }
    }*/



    //You can either use while loop or for with above while loop


    //b1


    // while(i < size1){
    //     nums[start] = left[i];
    //     start++;
    //     i++;
    // }
    // while(j < size2){
    //     nums[start] = right[j];
    //     start++;
    //     j++;
    // }



    //b2

    if(i == size1){
        for(int c = j ; c< size2 ; ++c){
            nums[start] = right[c];
            start++;
        }
    }
    if(j == size2){
        for(int c =  i ; c< size1 ; ++c){
            nums[start] = left[c];
            start++;
        }
    }
}


void merge_sort(vector<int>&nums ,int low, int high){
    if(high>low){
        int mid = low+ (high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge_without_sentinals(nums,low,mid,high);
    }
}

void input(vector<int> & nums){
    // Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-9475,396045);

    for(int i = 1 ; i <= 20 ; ++i){
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

int main(){
    vector<int>nums;
    high_resolution_clock::time_point startTime,endTime;

    //Input numbers
    input(nums);

    //Start the clock
    startTime = high_resolution_clock::now();

    //Call the function
    merge_sort(nums,0, static_cast<int>(nums.size()-1));
    //Utility to check if algo worked fine.
    //cout<<(is_sort(nums) ? "Array is sorted.\n" : " Unsorted array.\n");

    //Stop the clock
    endTime = high_resolution_clock::now();

    //Calculate the time taken
    auto duration = duration_cast<nanoseconds>(endTime - startTime).count();

    //Print Sorted array.
    print(nums);

    cout << "Time : " << duration << " nanoseconds." <<std::endl;
    cout << "============================================\n";

    cout<<"\nWorking.";
    return 0;
}
