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

    int score = 0;

    if(url.length() > 30){
        score += 20;
    }
    score += hyphens * 10;

    for(string word : keywords){
    if(url.find(word) != string::npos){
        cout << word << " found" << endl;

        if(word == "login" || word == "verify"){
            score += 20;
        }else{
            score += 15;
        }
    }
}
    cout<<"\nRisk Score: "<<score<<"/100"<<endl;

    if(score < 30){
        cout<<"Verdict : Safe"<<endl;
    }
    else if(score < 60){
        cout<<"Verdict : Suspicious"<<endl;
    }
    else{
        cout<<"Verdict : Dangerous"<<endl;
    }

    return 0;
}
