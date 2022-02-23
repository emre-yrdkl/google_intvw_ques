#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

struct triple{

    char num[3];
};


using namespace std;

int main(){

map<int, triple> numtochar;
map<string, string> pairs;

vector<string> realword;
vector<string> definiteword;
vector<string> laststr;

    //create the numbers and letters that these numbers point to
    triple two= {'a','b','c'}, three= {'d','e','f'}, four= {'g','h','i'}, five= {'j','k','l'}, six= {'m','n','o'}, 
    seven= {'p','r','s'}, eight= {'t','u','v'}, nine= {'x','y','z'}, zero={'q','w',' '};

    //adding pairs of numbers and letters to the map
    numtochar.insert(pair<char, triple>('2', two));
    numtochar.insert(pair<char, triple>('3', three));
    numtochar.insert(pair<char, triple>('4', four));
    numtochar.insert(pair<char, triple>('5', five));
    numtochar.insert(pair<char, triple>('6', six));
    numtochar.insert(pair<char, triple>('7', seven));
    numtochar.insert(pair<char, triple>('8', eight));
    numtochar.insert(pair<char, triple>('9', nine));
    numtochar.insert(pair<char, triple>('0', zero));

    string phonenumber="3662277";

    string word[]={"foo", "bar", "baz", "foobar","emo","cap", "car", "cat"};

    int arrSize = sizeof(word)/sizeof(word[0]);


    map<int, triple>::iterator itr;

    //changing the letter to number in word array
    for(int i=0; i<arrSize; i++){

        int count=0;

        while(word[i][count]){
            count++;
        }

        string charnum ="";

        for(int a=0; a<count; a++){

            for (itr = numtochar.begin(); itr != numtochar.end(); ++itr) {

                for(int b=0; b<3;b++){

                    if(itr->second.num[b]==word[i][a]){
                        charnum.push_back(itr->first);
                    }

                }
                
            }

        }

        realword.push_back(charnum);
        
        pairs.insert(pair<string, string>(word[i], charnum));

    }

    int lenofphone=0;

    while(phonenumber[lenofphone]){
        lenofphone++;
    }

    //find words(actually numbers) that match the phone number
    for (auto i = realword.begin(); i != realword.end(); ++i){

        string num1= *i;

        int count=0;

        while(num1[count]){
            count++;
        }

        for(int a=0; a<lenofphone;a++){

            if(phonenumber[a]==num1[0]){

                int count2=1;
                while(phonenumber[a+count2]==num1[0+count2]){
                    count2++;
                }
                if(count2==count){
                    definiteword.push_back(*i);
                    break;
                }else{
                    count2=1;
                }

            }
        }

    }
    //changing numbers to words
    map<string, string>::iterator itr2;

        for (itr2 = pairs.begin(); itr2 != pairs.end(); ++itr2) {
            
            for (auto i = definiteword.begin(); i != definiteword.end(); ++i){

                if(itr2->second==*i){
                    laststr.push_back(itr2->first);
                    break;
                }
            }

        }
    //print letters
    for (auto i = laststr.begin(); i != laststr.end(); ++i)
        cout << *i << " ";

}


