#include<iostream>
#include<ctype.h>
using namespace std;
int countDots(string url){
    int dots = 0;
    for(char ch : url){
        if(ch == '.'){
            dots++;
        }
    }
    return dots;
}
int countHyphens(string url){
    int hyphens = 0;
    for(char ch : url){
        if(ch == '-'){
            hyphens++;
        }
    }
    return hyphens;
}
void printVedict(int score){
     if(score < 30){
        cout<<"Verdict : Safe"<<endl;
    }
    else if(score < 60){
        cout<<"Verdict : Suspicious"<<endl;
    }
    else{
        cout<<"Verdict : Dangerous"<<endl;
    }
}
bool containsIPaddress(string url){
    int digits = 0;
    for(char ch : url){
        if(isdigit(ch)){
            digits++;
        }
    }
    if(digits >= 4 && countDots(url) >=3){
        return true;
    }
    return false;
}
int main(){
    string url;

    cout<<"Enter URL: ";
    cin>>url;

    cout<<"You entered: "<<url<<endl;

    cout<<"URL length: "<<url.length()<<endl;

    int dots = countDots(url);
    int hyphens = countHyphens(url);

    cout<<"Dot: "<<dots<<endl;
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
    if(containsIPaddress(url)){
        cout<<"IP Address detected!"<<endl;
        score += 30;
    }
    cout<<"\nRisk Score: "<<score<<"/100"<<endl;

    printVedict(score);

    return 0;
}
