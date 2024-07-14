
//This is a CGPA Calculator
//This works on the number of credits received by the student per subject then dividing it by the total number of grade points in semester

#include <bits/stdc++.h>

using namespace std;

//main starts here
int main() {

    cout<<"*************************************************************************"<<endl;
    cout<<"                         CGPA Calculator"<<endl;
    cout<<"*************************************************************************"<<endl<<endl<<endl;

    //Basic details entered
    int sem;
    cout<<endl<<"Which semester's CGPA do you want to calculate : ";
    cin>>sem;

    int subjs;
    cout<<endl<<"How many subjects do you have : ";
    cin>>subjs;

    int maxGrade;
    cout<<endl<<"What is the maximum grade point for this semester :";
    cin>>maxGrade;

    vector<int> credits(subjs);
    vector<int> gradeReceived(subjs);

    //Step-1 : Information gathered about each subject , grade received and total credits of each subject
    for(int i=0;i<subjs;i++){
        cout<<endl<<"For Subject "<<i+1<<" : "<<endl;
        cout<<"Enter Credit points for this subject : ";
        cin>>credits[i];
        cout<<"Enter the grade you received in this subject : ";
        cin>>gradeReceived[i];
    }

    int totalPoints=0;
    int pointsReceived=0;

    //Step-2 : calculating the final points received and total amount of points
    for(int i=0;i<subjs;i++){
        totalPoints+=(maxGrade*credits[i]);
        pointsReceived+=(gradeReceived[i]*credits[i]);
    }

    //Step-3 : calculating the CGPA by dividing 'pointsReceived' and 'totalPoints'
    float cgpa = (pointsReceived*10)/(float)totalPoints;
    cout<<endl<<"*************************************************************************"<<endl;
    cout<<            "Your CGPA Calculated for semester "<<sem<<" is : "<<cgpa<<endl;
    cout<<"*************************************************************************"<<endl;

    return 0;
}

