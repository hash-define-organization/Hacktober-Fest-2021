#include<bits/stdc++.h>

using namespace std;

//Input function
vector<string> takeinput(){

    string word;
    vector<string> input;

    cin>>word;

    while(word != "-1")
    {

        input.push_back(word);
        cin>>word;
    }

    return input;
    
}

//Print function
void printAns(vector<vector<string>> strs)
{

    for(int index=0; index<strs.size(); index++) //Traversing in main vector
    {

        for(int inner=0; inner<strs[index].size(); inner++) //Traversing vector in vector
        {

            cout<<strs[index][inner]<<" ";
        }

        cout<<endl;
    }
}

//Function grouping anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    unordered_map<string,vector<string>> map;
        
    for(int idx=0; idx<strs.size(); idx++)
    {
            
        string temp = strs[idx];
                
        sort(temp.begin(), temp.end()); //sorting each string
            
        map[temp].push_back(strs[idx]); //pushing original word in map with sorted string as vector
    }
        
    vector<vector<string>> ans;
        
    for(auto keys : map) // Pushing all anagrams(words) in final vector
    {
        ans.push_back(keys.second);
    }
        
    return ans;
}

//Main
void main()
{

    vector<string> input = takeinput(); //Taking input

    vector<vector<string>> finalAns = groupAnagrams(input); // Grouping anagrams and returning answer

    printAns(finalAns); //Printing answer

}