#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream fi("ppp.txt");
    string name[10];
    int grade[10];
    
    // Input initial student data
    for(int i=0; i<3; i++){
        cout<<"Enter the name of "<<i+1<<" student: ";
        getline(cin, name[i]); // Use getline to allow spaces in names
        cout<<"Enter the grade of "<<i+1<<" student: ";
        cin>>grade[i];
        fi<<name[i]<<" "<<grade[i]<<endl;
    }
    fi.close();

    // Open file for modification
    ifstream f("ppp.txt");
    string li, tar, newName;
    int newGrade;
    cout<<"Enter the name of the student you want to replace: ";
    cin>>tar;
    cout<<"Enter the new student name: ";
    cin>>newName;
    cout<<"Enter the new student grade: ";
    cin>>newGrade;

    string tempn[10];
    int tempg[10];
    int count = 0;

    // Process file
    while(getline(f,li)){
        size_t po = li.find(tar);
        if(po != string::npos){ // If student to replace is found
            // Replace with new student
            tempn[count] = newName;
            tempg[count] = newGrade;
            count++;
        }
        else { // Keep other students
            size_t spacePos = li.find(' ');
            tempn[count] = li.substr(0, spacePos);
            tempg[count] = stoi(li.substr(spacePos+1));
            count++;
        }
    }
    f.close();

    // Rewrite file
    ofstream g("ppp.txt");
    for(int i=0; i<count; i++){
        g<<tempn[i]<<" "<<tempg[i]<<endl;
    }
    g.close();

    cout<<"Student record updated successfully!"<<endl;
    return 0;
}