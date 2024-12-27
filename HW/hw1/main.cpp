#include <iostream>
#include<string>

using namespace std;

int cal_sum(int arr[]){
    int sum = 0;
    for(int i=0; i<5; i++){
        sum += arr[i];
    }
    return sum;
}
int cal_avg(int arr[], int arr_len){
    int sum = cal_sum(arr);
    int avg = sum/arr_len;
    return avg;
}   

int main(){
    int sum = 0;
    double avg = 0;
    int arr[5] = {0,};
    int arr_len = sizeof(arr)/sizeof(*arr);

    for (int i = 0; i < 5; i++)
        cin >> arr[i];
    sum = cal_sum(arr);
    avg = cal_avg(arr, arr_len);
    cout <<"sum: " + to_string(sum) << endl;
    cout <<"average: " + to_string(avg) << endl;

}
