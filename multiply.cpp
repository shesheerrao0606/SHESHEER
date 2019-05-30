#include<bits/stdc++.h> 
using namespace std; 
   
 
string multiply(string str1, string str2) 
{ 
    int n1 = str1.size(); 
    int n2 = str2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    
    vector<int> result(n1 + n2, 0); 
   
     
    int i_n1 = 0;  
    int i_n2 = 0;  
       
     
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = str1[i] - '0'; 
   
       
        i_n2 = 0;  
                      
        for (int j=n2-1; j>=0; j--) 
        { 
            int n2 = str2[j] - '0'; 
   
             
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
    
            carry = sum/10; 
   
        
            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
   
        
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        
        i_n1++; 
    } 
   
     
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
   
    if (i == -1) 
    return "0"; 
   
    string s = ""; 
       
    while (i >= 0) 
        s += std::to_string(result[i--]); 
   
    return s; 
} 
   
int main ()
{
  
     string str1,str2;
    cout<<"Enter the first number :";
    cin>>str1;
    cout<<"Enter the second number :";
    cin>>str2;
       
         
    if((str1.at(0) == '-' || str2.at(0) == '-') &&  
        (str1.at(0) != '-' || str2.at(0) != '-' )) 
        cout<<"-"; 
   
   
    if(str1.at(0) == '-' && str2.at(0)!='-') 
        { 
            str1 = str1.substr(1); 
        } 
        else if(str1.at(0) != '-' && str2.at(0) == '-') 
        { 
            str2 = str2.substr(1); 
        } 
        else if(str1.at(0) == '-' && str2.at(0) == '-') 
        { 
            str1 = str1.substr(1); 
            str2 = str2.substr(1); 
        } 
    cout << multiply(str1, str2); 
    return 0; 
} 