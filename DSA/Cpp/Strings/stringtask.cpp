/* Link to the probelm- https://codeforces.com/contest/118/problem/A
 Added the solution to the string task problem from codeforces*/

#include <iostream>
#include <string>
using namespace std;
 
int main() {

  string s,s2;
  cin>>s;
   int len=s.length();//calculating the length of the given string
   for(int i=0;i<len;i++){
	if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U'||s[i]=='Y')
		continue;//checking whether the given character is vowel or not according to the question
	
	else
	{//if its not a vowel then it will be added to the new string
		s2+='.';
		s2+=towlower(s[i]);
	}
  }
   cout<<s2;
	return 0;
 }
