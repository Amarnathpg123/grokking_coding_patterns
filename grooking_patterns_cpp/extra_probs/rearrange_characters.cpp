// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    static bool compare(pair<int,int> &a, pair<int, int> &b){ return a.second > b.second;}
    string rearrangeString(string str)
    {
        if(str.length() <= 1) return str;
        vector<pair<int,int>> vec;
        int cntr = 0;
        for(int i=0; i<26; ++i) vec.push_back(make_pair(i,0));
        for(int i=0; i<str.length(); ++i) vec[str[i]-'a'].second += 1;
        sort(vec.begin(), vec.end(), compare);
        if(vec[0].second > (str.length()+1)/2) return "-1";
        vector<string> vstr(vec[0].second, "");
        for(auto i: vec)
        {   if(i.second == 0) break;
            while(i.second-- > 0)
            {
              vstr[cntr] += char('a'+i.first);
              cntr++;
              if(cntr == vec[0].second) cntr = 0;
            }
        }
        string final = "";
        for(string i: vstr) final += i;
        return final;
    }
    
};

// { Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    string str;
		cout << "Enter a string in lower case: 	" << endl;
	    cin>>str;
	    Solution ob;
		auto start = std::chrono::high_resolution_clock::now();
	    string str1=ob.rearrangeString(str);
		auto stop = std::chrono::high_resolution_clock::now();
    	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		cout << "\nString with rearranged characters: \n\t" << str1 << endl;
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
		cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";
	}
	system("pause");
    return 0;
}  // } Driver Code Ends