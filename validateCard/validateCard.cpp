
//This is a Valid Credit Card Number Checker
//It utilises Luhn's Algorithm to check for a valid Credit Card Number

#include <bits/stdc++.h>

using namespace std;

//This checks if the string contain all characters from 0 to 9(character validity)
bool areAllnum(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

//This checks the length of number entered (it should be between 13 to 16) (size validity)
bool sizeValidity(string s){
    if(s.length() <= 13 || s.length() >=16 )
        return false;
    return true;
}

int main() {
    cout<<"*************************************************************************"<<endl;
    cout<<"                Validate Credit Card Number"<<endl;
    cout<<"*************************************************************************"<<endl<<endl<<endl;

    string num;

    //This keeps on asking for inputs until 0 is entered
    while (true) {

        cout << "Please enter a Credit Card number to validate(enter 0 to exit): ";
        cin >> num;

        //to exit the execution
        if (num == "0"){
            cout<<endl<<endl<<"--------Thank You--------"<<endl<<endl;
            break;
        }

        //checking for character validity
        else if (!areAllnum(num)) {
            cout <<endl<<endl<< "************************You have entered a wrong Credit Card Number ************************"<<endl<<endl<<endl;
            continue;
        }

        //checking for size validity
        else if (!sizeValidity(num)) {
            cout <<endl<<endl<< "************************You have entered a wrong Credit Card Number ************************"<<endl<<endl<<endl;
            continue;
        }

        //Luhn's ALgorithm

        int len = num.length();
        int evenDigitSum = 0;
        int oddDigitSum=0;


        // Step 1 is to double every second digit, starting from the right. If it
        // results in a two digit number, add both the digits to obtain a single
        // digit number. Finally, sum all the answers to obtain 'evenDigitSum'.

        for (int i=len-2;i>=0;i-=2 ) {
            int doubleofDig = ((num[i] - 48) * 2);
            if (doubleofDig > 9)
                doubleofDig = (doubleofDig / 10) + (doubleofDig % 10);
            evenDigitSum += doubleofDig;
        }

        // Step 2 is to add every odd placed digit from the right to get the
        // 'oddDigitSum'.

        for (int i=len-1;i>=0;i-=2 )
            oddDigitSum += (num[i] - 48);


        // Step 3 is to add the 'oddDigitSum' and 'evenDigitSum'

        int totalSum=oddDigitSum+evenDigitSum;

        // Step 4 is to check if the final 'totalSum' is a multiple of 10.
        // If yes, it is a valid Credit Card number. Otherwise, not.

        if( totalSum%10 == 0 ){
            cout <<endl<<endl<< "-------------------------------It is a Valid Credit Card Number------------------------"<<endl<<endl<<endl;
        }

        else{
            cout <<endl<<endl<< "************************You have entered a wrong Credit Card Number ************************"<<endl<<endl<<endl;
        }

    }

    return 0;
}
