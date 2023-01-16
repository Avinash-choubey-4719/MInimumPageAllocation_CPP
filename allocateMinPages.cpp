#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return a<b?a:b;
}

int max(int a, int b){
    return a>b?a:b;
}

int sum(int arr[], int start, int end){
    int result = 0;

    for(int i = start;i<=end;i++){
        result+=arr[i];
    }

    return result;
}

int minPageAllocation(int arr[], int start, int end, int k){
    if(k == 1){
        return sum(arr, start, end);
    }

    if(start == end){
        return arr[start];
    }

    int result = INT16_MAX;

    for(int i = start;i<end;i++){
        int tempMax = minPageAllocation(arr, i + 1, end, k - 1);
        tempMax = max(tempMax, sum(arr, start, i));

        result = min(tempMax, result);
    }

    return result;

}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = 4;
    int k = 2;

    int result = minPageAllocation(arr, start, end, k);
    cout<<result<<endl;
    return 0;
}