#include <string>
#include <iostream>
#include <limits>
using namespace std;

int main(){
    int n, m;
    cout << "請輸入學生人數n: ";
    cin >> n;
    cout << "請輸入姓名最大長度m: ";
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string* names= new string[n];

    
    for (int i = 0; i < n; ++i) {
      
    int ture =1;
      
      while(ture){
        cout <<"請輸入 第" << i+1 << "位學生的姓名 (長度不超過 " << m << " 個字元):" <<endl;
        getline(cin,names[i]);
        
        if(names[i].length() <= m){
          ture=0;
        }else{
          cout<<"超出長度，請重新輸入"<<endl;
        }
      }
    }

    string longest = names[0];
    for(int j =1;j<n;++j){
        if(names[j].length() > longest.length()){
            longest = names[j];
        }else{
            continue;
        }
    }
    int y = longest.length();
    
    int z = longest.find(' ');//空白前面要有z個字元
    if (z == string::npos) {
        z = longest.length();
    }else{
        
    }
    
    cout << "輸入的學生姓名如下:"<<endl;

    
    for(int k=0;k<n;++k){    //控制換行
        
        int b= names[k].find(' '); //now name where
        if (z == string::npos) {
            z = longest.length();
        }else{
            
        }
        
        int c= b-1;  //now name first name length
        
        for(int l=0;l<z-c;l++ ){   //控制空白(z-c個空白)
            cout<<" ";
        }
    cout <<names[k]<<endl;    
    }
    
    
delete[] names;
return 0;
}
