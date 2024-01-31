#include<bits/stdc++.h>
using namespace std;

string isValid(string url){

    // This is use to vaidat the link
    // here pat is the object of regex
    
    regex pat("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    if(url.empty()) return "NO"; // checking if url is empty i.e, there is no url entered by url

    if(regex_match(url,pat)) return "Yes";
    else return "No";
}

int main(){
    string url;
    cin>>url;
    cout<<isValid(url);
    return 0;
}