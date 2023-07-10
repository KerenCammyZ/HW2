/*
 * Author: Keren (Cammy) Zaig
 * ID:329878656
 * Description: Homework Assignment 2
 */
//------------------including------------------
#include <iostream>
//------------------using------------------
using std::cout;
using std::cin;
using std::endl;
//------------------const variables------------------
const int N = 6; //size of array

/**
 * this function checks how many cells in the array exist that all the numbers after it
 * divide by it with no remainder and all the cells before it can be divided with no remainder
 * @return int number of cells that satisfy the condition
 */
int a(){
    //declaring variables

    int arr[N];
    int count = 0;

    //user inputs array
    for(int m = 0; m< N; m++){
        cin >> arr[m];
    }

    //checking array
    for(int i = 1; i < N-1; i++){
        if((arr[i] % arr[i-1] == 0) && (arr[i+1]%arr[i] == 0))
            count++;
    }

    //print to console
    cout<<count;
    return count;

}//end of a()


int findIndex(int arr[]){
    int count = 0;
    bool divide = true;
    for(int i = 1; i < N; i++){
        if(arr[i+1] % arr[i]!=0)
            divide = false;
        if(divide)
            count++;
    }
    return count;
}

/**
 * finds first cell in array has an int that divides by all the ints that come before
 * with no remainder and all the cells after it can be divided by it with no remainder
 * @return int of cell number
 */
int b(){

    //declaring variables
    int arr[N];
    bool before = true;
    bool after = true;


    //input array
    for(int m = 0; m< N; m++){
        cin >> arr[m];
    }

    //checking array
    for (int i = 0; i < N; i++) {
        before = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] % arr[i] != 0) {
                before = false;
                break;
            }
        }

        after = true;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] % arr[i] != 0) {
                after = false;
                break;
            }
        }

        if (before && after) {
            cout<<i;
            return i;
        }
    }
    cout<<"ERROR";
    return -1;




}//end of b()

/**
 * this function checks if given array is a palindrome between 2 indexes
 * @param arr given array
 * @param i first index
 * @param j last index
 * @return bool true if array is palindrome
 */
bool(isPalindrome)(int arr[],int i, int j) {

    //declaring variables
    bool palindrome = true;


    while(palindrome){
            if (arr[i] != arr[j])
                palindrome = false;
            else{
                if(j = i+1)
                    break;
                else{
                    i++;
                    j--;
                }
            }
    }//end while(palindrome)
    return palindrome;
}//end isPalindrome


/**
 * finds how many palindromes exist in the array
 * @return int number of palindromes
 */
int c() {
    //declaring variables
    int count = 0;
    int arr[N];
    //input array
    for(int m = 0; m< N; m++){
        cin >> arr[m];
    }

    //checking array
    for(int i = 0;i<N-1;i++){
        if(isPalindrome(arr,i,i+1))
            count++;
    }

    //return to user
    cout<<count;
    return count;

}//end of c()

int main() {
    cout << "choose 1 2 or 3\n" << endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"RUNNING A\n";
            a();
            break;
        case 2:
            cout<<"RUNNING B\n";
            b();
            break;
        case 3:
            cout<<"RUNNING C\n";
            c();
            break;
        default:
            cout<<"ERROR\n";
            break;
    }

    return 0;
}
