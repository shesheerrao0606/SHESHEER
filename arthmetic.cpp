#include<bits/stdc++.h> 
using namespace std; 
   
string findSum(string str1, string str2) 
{ 
  
   if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    
    string str = ""; 
  
    
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    
    int carry = 0; 
   
    for (int i=n1-1; i>=0; i--) 
    { 
         
        
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    
    if (carry) 
        str.push_back(carry+'0'); 
  

    reverse(str.begin(), str.end()); 
  
    return str; 
}
bool isSmaller(string str1, string str2) 
{ 
 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
  
 
string findDiff(string str1, string str2) 
{ 

    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
 
    string str = ""; 
  
 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
 
    int carry = 0; 
  
 
    for (int i=n2-1; i>=0; i--) 
    { 
 
 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 



string division(string number, int divisor)
{
    string ans;
    int index=0;
    int temp=number[index]-'0';
    while (temp<divisor)
    temp=temp*10+(number[++index]-'0');

    while(number.size()>index)
    {
        ans += (temp/divisor)+'0';
        temp= (temp%divisor) *10 + number[++index]-'0';

    }
        if (ans.length()==0)
        return "0";
        return ans;
    }
    
int main ()
{
    string s1,s2;
    cout<<"Enter the first number :";
    cin>>s1;
    cout<<"Enter the second number :";
    cin>>s2;
    cout<<"SUM OF TWO NUMBERS="<<findSum(s1,s2)<<endl;
    cout<<"DIFFERNCE TWO NUMBERS="<<findDiff(s1,s2)<<endl;

     string number;int divisor;
      cout<<"Enter number for division = : ";
      cin>>number;
      cout<<"Enter divisor= : " ;
      cin>>divisor;
      cout<<"SOLUTION="<<division( number,divisor)<<endl;
      
    
    
    
        return 0;
}



