#include <iostream>
#include <string>
using namespace std;

int *sort_asc(int arr[], int arr_len){
    for (int i = 1; i < arr_len; i++){
        for (int j = 0; j < arr_len - i; j++){
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return arr;
}

int *sort_desc(int arr[], int arr_len){
    int i = 0;
    for (int i = 1; i < arr_len; i++){
        for (int j = 0; j < arr_len - i; j++){
            if (arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return arr;
}

int main(){
    int mode = 1;
    int arr[5] = {0,};
    int arr_len = sizeof(arr)/sizeof(*arr);

    cout << "please type 5 digits" << endl;

    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    cout << "select mode: 1. ascending sort 2. descending sort" << endl;
    cout << "mode: ";
    cin >> mode;

    if (mode == 1){
        sort_asc(arr, arr_len);
    } 
    else {
        sort_desc(arr, arr_len);
    }

    for (int i=0; i<arr_len; i++)
        cout << arr[i] << endl;
}