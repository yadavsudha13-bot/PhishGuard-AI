#include<iostream>
using namespace std;
int main(){
    string url;

    cout<<"Enter URL: ";
    cin>>url;

    cout<<"You entered: "<<url<<endl;

    cout<<"URL length: "<<url.length()<<endl;

    int dot = 0; 
    int hyphens = 0;

    for(char ch : url){
        if(ch == '.'){
            dot++;
        }
        if(ch == '-'){
            hyphens++;
        }
    }
    cout<<"Dot: "<<dot<<endl;
    cout<<"Hyphens: "<<hyphens<<endl;

    string keywords[] = {"login", "verify", "secure", "update", "banking", "account"};

    cout<<"Keywords found: "<<endl;

for(string word : keywords){
    if(url.find(word) != string::npos){
        cout << word << " found" << endl;
    }
}

    return 0;
}
