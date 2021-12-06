#include<bits/stdc++.h>
using namespace std;

#define STR_LEN 600
#define STR_NUM 20
string Strings[STR_NUM]; //making array for storing the strings

//Used to generate a random string consisting of the given Strings
string generateRandomString(){

    string corpus="ACGT";
    string str="";

    for(int i=0; i<STR_LEN/10; i++){
        str+= corpus[rand()%4];
    }

    return str;
}


int main(){

    //putting seed as time to make sure it forces rand() to produce different values
    srand(time(NULL)); 

    for(int i=0; i<STR_NUM; i++){
        Strings[i]=generateRandomString();
    }
    
    //printing the strings
   for( string s: Strings) cout<<s<<"\n";



   return 0;
}