#include <iostream>
#include <string>
#include <limits>
using namespace std;

void bubble(string* names, int n) {
    for (int i = 0; i < n - 1; ++i) {
      
        for (int j = 0; j < n - i - 1; ++j) {
          
            size_t len1 = names[j].length();
            size_t len2 = names[j + 1].length();
          
            if (len1 > 0 && len2 > 0 && names[j][len1 - 1] > names[j + 1][len2 - 1]) {
              
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
              
            }
        }
    }
}

int main(){
    int n,m;
  
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

  bubble(names,n);
  cout << "輸入的學生姓名如下:"<<endl;
      
    for (int i = 0; i < n; ++i) {
        cout << "第 " << i + 1 << " 位學生: " << names[i] << endl;
    }

    delete[] names;
}
