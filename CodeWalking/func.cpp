#include <bits/stdc++.h> 
#include <iostream>

using namespace std;
typedef unsigned long long UL;

 
UL po5(UL x)
{
    UL x2 = x*x,   x4 = x2*x2;
    return x*x4;
}
 

int main(int argc, const char * argv[])
{
   	UL a,b,c,d,e, n;
	n = 300;
	
	for (e = 1; e <= n; ++e){
		cout << "e :" << e << '\n';

		for (d = 1; d <= e; ++d)
			for (c = 1; c <= d; ++c)
				for (b = 1; b <= c; ++b)
					for (a = 1; a <= b; ++ a)
						if (po5(a) + po5(b) + po5(c) + po5(d) == po5(e))
							cout << "solve: "  << a << " " << b << " "<< c << " "<< d << " "<< e << '\n'; 
	}
	return 0;
}
