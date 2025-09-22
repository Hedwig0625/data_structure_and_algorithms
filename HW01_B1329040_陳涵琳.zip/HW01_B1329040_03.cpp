#include <string>
#include <iostream>
#include <limits>
using namespace std;

void bubble(char** names, int n) {
    for (int i = 0; i < n - 1; ++i) {
      
        for (int j = 0; j < n - i - 1; ++j) {
          
            int len1 = strlen(names[j]);
            int len2 = strlen(names[j+1]);
          
            if (len1 > 0 && len2 > 0 && names[j][len1 - 1] > names[j + 1][len2 - 1]) {
              
                char temp[101];
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
}

int main(){
    int n;
    cout << "請輸入學生人數n: ";
    cin >> n;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char** names= new char*[n];
    
    for (int i = 0; i < n; ++i) {

        names[i] = new char[m+1];
        
        cout <<"請輸入 第" << i+1 << "位學生的姓名 (長度不超過 " << m << " 個字元):" <<endl;
        cin.getline(names[i],m+1);
        
    }

    bubble(names,n);
    
    
    cout << "輸入的學生姓名如下:"<<endl;
    
    for(int l=0;l<n;++l){
        delete[] names[l];
    }
    delete[] names;
return 0;
}
