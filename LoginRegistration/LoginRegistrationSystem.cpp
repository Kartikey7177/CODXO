#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void showUI(){
    cout<<endl<<"***************************************************************"<<endl;
    cout<<"              LOGIN AND REGISTRATION SYSTEM                 "<<endl;
    cout<<endl<<"***************************************************************"<<endl<<endl;
    cout<<"1 . LOGIN "<<endl;
    cout<<"2 . REGISTER "<<endl;
    cout<<"3 . FORGOT PASSWORD "<<endl;
    cout<<"4 . EXIT "<<endl;
    cout<<endl<<"Enter your choice --> ";
}

int main(){
    ofstream out;
    out.open("details.txt", std::ofstream::app);
    MAIN:
    showUI();
    int n;
    cin>>n;
    string name;
    string email;
    string password;
    switch(n){
        case 4:{
            exit(0);
        }
        case 2:{
            cout<<endl<<"**************************************"<<endl;
            cout<<"              REGISTER                "<<endl;
            cout<<"**************************************"<<endl;
            fflush(stdin);
            cout<<endl<<"Enter your emailID : ";
            getline(cin,email);
            out<<email<<endl;
            cout<<endl<<"Set your username : ";
            getline(cin,name);
            out<<name<<endl;
            cout<<endl<<"Set your password : ";
            getline(cin,password);
            out<<password<<endl;
            cout<<endl<<"REGISTRATION SUCCESSFULL"<<endl;
            break;
        }
        case 1:{
            ifstream in;
            in.open("details.txt");
            cout<<endl<<"**************************************"<<endl;
            cout<<"              LOGIN                "<<endl;
            cout<<"**************************************"<<endl;
            fflush(stdin);
            string checkEmail;
            string checkUser;
            string checkPass;
            cout<<endl<<"Enter your username : ";
            getline(cin,name);
            cout<<endl<<"Enter your password : ";
            getline(cin,password);
            int found=0;
            while(!in.eof()){
                getline(in,checkEmail);
                getline(in,checkUser);
                getline(in,checkPass);
                if( checkUser==name && checkPass==password){
                    cout<<endl<<"LOGIN SUCESSFUL . VALID CREDENTIALS !!!"<<endl<<endl;
                    found=1;
                    break;
                }
            }
            if(found==0)
                cout<<endl<<"LOGIN UNSUCESSFUL . INVALID CREDENTIALS .(PLEASE REGISTER YOURSELF FIRST)!!!"<<endl<<endl;
            in.close();
            break;
        }
        case 3:{
            ifstream in;
            in.open("details.txt");
            cout<<endl<<"**************************************"<<endl;
            cout<<"            FORGOT PASSWORD                "<<endl;
            cout<<"**************************************"<<endl;
            fflush(stdin);
            string checkEmail;
            string checkUser;
            string checkPass;
            cout<<endl<<"Enter your registered email : ";
            getline(cin,email);
            int found=0;
            while(!in.eof()){
                getline(in,checkEmail);
                getline(in,checkUser);
                getline(in,checkPass);
                if( checkEmail==email){
                    cout<<endl<<"EMAIL FOUND !!!"<<endl;
                    cout<<"Your username is : "<<checkUser<<endl;
                    cout<<"Your password is : "<<checkPass<<endl;
                    found=1;
                    break;
                }
            }
            if(found==0)
                cout<<endl<<"NO EMAIL EXISTS LIKE THIS .(PLEASE REGISTER YOURSELF FIRST)!!!"<<endl<<endl;
            in.close();
            break;
        }
        default:{
            cout<<endl<<"*******INVALID INPUT********"<<endl;
            break;
        }
    }
    goto MAIN;
    out.close();
    return 0;
}
