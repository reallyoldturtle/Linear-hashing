#include <bits/stdc++.h>

#define S 2

using namespace std;

vector<vector <int> > v(2);


bool isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}

 int nextPowerOf2( int n)
{
  int count = 0;

  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

int main(int argc, char const *argv[])
{
	int m,num,n;
	int key,key2;
	// cin>>m;
	int in_n;
	float loadf=0.0f;
	int insert=0;
	int mod_val=2;
	int split_ptr=0;
	int col_count=0;
	// cin>>n;
	if(argc!=5)
	{
		cout<<"Invalid arguments";
		return 0;
	}
	ifstream infile(argv[3]);

	while(infile>>num)
	{
		
		int size=v.size();
		mod_val=nextPowerOf2(v.size());
		if(isPowerOfTwo(size))
		{
			mod_val=size;
			split_ptr=0;
		}
		
		key=num%mod_val;
		
		if(key+1>size)
		{
			
			key=num%(int)(mod_val/2);
		}
		
		int flag=0;
		for(int i=0;i<v[key].size();i++)
		{
			if(v[key][i]==num)
			{
				flag=1;
				break;
			}
		}

		if(flag==1)
		{
			
			continue;	
		}

		v[key].push_back(num);
		insert++;

		
		loadf=(float)insert/v.size();
		
		if(loadf>=1.5)
		{
		
			v.resize(v.size()+1);
			
				int m=nextPowerOf2(v.size());
				 
				vector<int> dummy;
				for(int p=0;p<v[split_ptr].size();p++)
				{

					dummy.push_back(v[split_ptr][p]);
				}

				for(int p=0;p<dummy.size();p++)
				{
					key2=dummy[p]%m;
					if(key2+1>v.size())
					{
						key2=dummy[p]%(int)(m/2);
					}

					 if(key2!=split_ptr)
					{
						v[key2].push_back(dummy[p]);
						v[split_ptr].erase(remove(v[split_ptr].begin(), v[split_ptr].end(), dummy[p]), v[split_ptr].end());
					}
				}

			
			split_ptr++;
		}
	}



		for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<v[i].size();j++)
				cout<<v[i][j]<<endl;
		}



	return 0;
}
