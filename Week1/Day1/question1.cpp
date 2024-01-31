#include<bits/stdc++.h>
using namespace std;


bool checkVowel(char it){
    // return true if vowel present otherwise false
    return it=='a' || it=='e' || it=='i' || it=='o' || it=='u' ||it=='A' || it=='E' || it=='I' || it=='O' || it=='U';
}

bool isValid(string name){
    int cntS=0,cntVowel=0,stIndexOfS=-1,endIndexOfS=-1,ind=0;

    // iterating for vowel i.e, first condition

    for(auto it:name){
        
        if(checkVowel(it)){
            cntVowel++;
            if(cntVowel>1) return false;
        }
        if(it=='S'){
            
            cntS++;
            // to minimize number of iteration we need to set the starting index and ending index where there is S.
            if(cntS==1) stIndexOfS = ind;

            if(cntS==2){
                endIndexOfS = ind;
                
                // since 2 S found so we are cheking if there is 'T' in between them

                for(int i=stIndexOfS;i<=endIndexOfS;i++){
                    if(name[i]=='T') return false;
                }

                // return true;
                cntS--;
                endIndexOfS=-1;
            }
        }
        
        ind++;
        

    }
    if(endIndexOfS==-1) return true;
}

int main(){
    string name;
    cout<<"Enter The Name: ";
    cin>>name;
    cout<<"Your Name Is ";
    if(isValid(name)) cout<<"Valid";
    else cout<<"Invalid";
    return 0;
}

// TC -> O(N) where n is the length of string
// SC ->O(1) we do not take any space in order to solve the question