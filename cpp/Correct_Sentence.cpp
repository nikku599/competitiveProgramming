#include<bits/stdc++.h>
using namespace std;

int checkLowerOrUpperOrMix(string s){
    int flag_lower = 0, flag_upper =0;
    for(int i=0;i<s.size();i++){
        if (s[i] >= 'a' && s[i] <= 'm'){
            flag_lower += 1;
        } else if (s[i] >= 'N' && s[i] <= 'Z') {
            flag_upper += 1;
        }
        else return 3; // invalid char found
    }
    if (flag_lower > 0 && flag_upper == 0) {
        return 0; // lower case only
    }
    if (flag_lower == 0 && flag_upper > 0){
        return 1; // only upper case
    }
    if (flag_lower > 0 && flag_upper > 0){
        return 2; // both mixcases
    }
}

bool getAns (vector <string> v){
    int n=v.size();
    for(int i =0;i<n;i++){
        string s=v[i];
        if (checkLowerOrUpperOrMix(s) == 2 || checkLowerOrUpperOrMix(s) == 3){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<string> v;
        while(k--){
            string s; cin>>s;
            v.push_back(s);
        }
        if (getAns(v)){
            cout <<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}