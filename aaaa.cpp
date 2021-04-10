#include<bits/stdc++.h>
using namespace std;




void dif(vector<int> v1, vector<int> v2,vector<int> &v3)
{
	int i,j,a,borrow=0;
    int c=0;
    if(v1.size()==v2.size())
    {
		for(i=0;i<v1.size();++i)
        if(v1[i]>v2[i])
		{
			c=1;
			break;
		}
    }
    else
    if(v1.size()>v2.size())
    c=1;
    


	if(c==1)
	{
        //cout<<"asd\n";        
		i=v1.size()-1;
		for(j=v2.size()-1;j>=0;--j,--i)
		{
			if(borrow==1)
			{
				v1[i]--;
				borrow=0;
			}
			
			if(v1[i]>=v2[j])
			{
				a=v1[i]-v2[j];
			}
			else
			{
				a=10+v1[i]-v2[j];
				borrow=1;
			}
			
			v3.push_back(a);
		}
		for(;i>=0;i--)
		{
			if(borrow==1)
			{
				v1[i]--;
				borrow=0;
			}
			if(v1[i]>=0)
			{
				a=v1[i];
			}
			else
			{
				a=10+v1[i];
				borrow=1;
			}
			v3.push_back(a);
		}
	}
	else
	{
        //cout<<"wqe\n";
		i=v1.size()-1;
		for(j=v2.size()-1;i>=0;--j,--i)
		{
			if(borrow==1)
			{
				v2[j]--;
				borrow=0;
			}
			
			if(v2[j]>=v1[i])
			{
				a=v2[j]-v1[i];
			}
			else
			{
				a=10+v2[j]-v1[i];
				borrow=1;
			}
			//cout<<a<<endl;
			v3.push_back(a);
		}
		for(;j>=0;j--)
		{
			if(borrow==1)
			{
				v2[j]--;
				borrow=0;
			}
			if(v2[j]>=0)
			{
				a=v2[j];
			}
			else
			{
				a=10+v2[j];
				borrow=1;
			}
            //cout<<a<<endl;
			v3.push_back(a);

		}
        int k=v3.size()-1;
        while(k--)
        {
            if(v3[k]>0)
            break;
        }
		v3[k]=-1*v3[k];
	}

}

void sum(vector<int> v1, vector<int> v2,vector<int> &v3)
{
	int i,j,a,carry=0;
	if(v1.size()>=v2.size())
	{
		i=v1.size()-1;
		for(j=v2.size()-1;j>=0;--j,--i)
		{
			a=v1[i]+v2[j]+carry;
			carry=0;
			if(a>=10)
			{
				carry=1;
				a=a-10;
			}
			//cout<<a<<endl;
			v3.push_back(a);
		}
		for(;i>=0;i--)
		{
			a=v1[i]+carry;
			carry=0;
			if(a>=10)
			{
				carry=1;
				a=a-10;
			}
			//cout<<a<<endl;
			v3.push_back(a);
		}
		if(carry==1)
		v3.push_back(1);
	}
	else
	{
		j=v2.size()-1;
		for(i=v1.size()-1;i>=0;--j,--i)
		{
			a=v1[i]+v2[j]+carry;
			carry=0;
			if(a>=10)
			{
				carry=1;
				a=a-10;
			}
            //cout<<a<<endl;
			v3.push_back(a);
		}
		for(;j>=0;j--)
		{
			a=v2[j]+carry;
			carry=0;
			if(a>10)
			{
				carry=1;
				a=a-10;
			}
            //cout<<a<<endl;
			v3.push_back(a);
		}
		if(carry==1)
		v3.push_back(1);
	}

}

void show(vector<int> &v)
{
    int i;
    
	for(i=0;i<v.size();++i)
    {
        if(v[i]!=0)
        break;
        
    }
    for(;i<v.size();++i)
    {
        cout<<v[i];
    }
	cout<<"\n";
}
int main()
{
	vector<int> v1={9,9,8,7};
	vector<int> v2={9,9,8,8};
	vector<int> v3;
	//sum
	if(v1[0]>0)
	{
		if(v2[0]>0)
		{
			//both +ve  i.e v1+v2
			//cout<<"asd\n";
			sum(v1,v2,v3);
		}
		else
		{
			// v1 is +ve and v2 is -ve   i.e v1-v2
			v2[0]=v2[0]*-1;
           
			dif(v1,v2,v3);
            v2[0]=v2[0]*-1;

		}
	}
	else
	{
		if(v2[0]>0)
		{
			//v1 -ve and v2 +ve i.e v2-v1
			v1[0]=-1*v1[0];
			dif(v2,v1,v3);
            v1[0]=-1*v1[0];
		}
		else
		{
			//both -ve i.e -v1-v2
			v1[0]=-1*v1[0];
			v2[0]=-1*v2[0];
			sum(v1,v2,v3);
			
            v1[0]=-1*v1[0];
			v2[0]=-1*v2[0];
            v3[v3.size()-1]=-1*v3[v3.size()-1];
		}
	}
	reverse(v3.begin(), v3.end());
	show(v3);

	v3.clear();
	//Diff
    if(v1==v2)
    {
        cout<<"0\n";
    }
    else{
        
    
	if(v1[0]>0)
	{
		if(v2[0]>0)
		{
			//both +ve so v1-v2
			dif(v1,v2,v3);
		}
		else
		{
			// v1 is +ve and v2 is -ve   i.e v1-(-v2)
			v2[0]=-1*v2[0];
            //cout<<"asd\n";
			sum(v1,v2,v3);
		}
	}
	else
	{
		if(v2[0]>0)
		{
			//v1 -ve and v2 +ve i.e -v1-v2
			v1[0]=-1*v1[0];
			sum(v1,v2,v3);
			v3[v3.size()-1]=-1*v3[v3.size()-1];
		}
		else
		{
			//both -ve   -v1-(-v2) ie v2-v1
			v2[0]=-1*v2[0];
			v1[0]=-1*v1[0];
			dif(v2,v1,v3);

		}
	}

    
	reverse(v3.begin(), v3.end());
    show(v3);

    }


	
	return 0;
}
