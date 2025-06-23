#include<iostream>
using namespace std;
main(){
    
  int row;
  cout<<"Enter the number of rows:\n";
  cin>>row;
  int **r= new int*[row];
  int *col = new int[row];
  for(int i=0; i<row; i++){
    cout<<"Enter the number of columns for the row: "<<i+1<<endl;
    cin>>col[i];
     r[i] =new int[col[i]];
     cout<<"Enter "<<*col<<"elements for the row"<<i+1<<endl;
     for(int j=0; j<col[i]; j++){
        cin>>r[i][j];
     }
  }
  for(int i=0; i<row; i++){
    for(int j=0; j<col[i]; j++){
       cout<<r[i][j]<<" ";
}
cout<<endl;
}
for(int i=0; i<row; i++){
    delete[] r[i];
}
delete[] r; 
delete[] col;
}