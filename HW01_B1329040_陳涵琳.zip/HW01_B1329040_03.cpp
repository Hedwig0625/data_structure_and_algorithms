#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

void bubble(char** names, int n) {
    for (int i = 0; i < n - 1; ++i) {
      
        for (int j = 0; j < n - i - 1; ++j) {
          
            int len1 = strlen (names[j]);
            int len2 = strlen (names[j+1]);
          
            if (len1 > 0 && len2 > 0 && names[j][len1 - 1] > names[j + 1][len2 - 1]) {
              
                char temp[101];
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
}

int first_name(char* str){
    char* p = strchr(str,' ');
    if(p == nullptr){
        return strlen(str);
    }else{
        return p - str;
    }
}

void space_sort(char** names,int n){
    
    int max =0;
    
    for(int k=0;k <n-1;++k){
        int x= first_name (names[k]);
        if(x > max){
            max =x;
        }
    }

    for(int m=0;m<n;++m){
        int x = first_name(names[m]);
        int space =max -x;

        for(int o=0;o< space;++o){
            cout <<" ";
        }
    cout << names[m] << endl;
    }
    
    
}

int main(){
    int n;
    cout << "請輸入學生人數n: ";
    cin >> n;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char** names= new char*[n];
    
    int max= 101;
    
    for (int i = 0; i < n; ++i) {

        names[i] = new char[max];
        
        cout <<"請輸入 第" << i+1 << "位學生的姓名" <<endl;
        
        cin.getline(names[i],max);
        
    }

    bubble(names,n);
    
    cout << "輸入的學生姓名如下:"<<endl;
    
    space_sort(names,n);
    
    for(int l=0;l<n;++l){
        delete[] names[l];
    }
    delete[] names;
return 0;
}
