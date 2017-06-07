//
//  rabin_karp.cpp
//  Returns the valid shift position otherwise -1.
//
//  Created by Shravan on 5/11/17.
//  Copyright © 2017 Shravan. All rights reserved.
//
#include <iostream>
#include <cmath>


// T is the entire string
// P is the pattern string to be searched
// d is the base/radix
// q is the largest prime number
int Rabin_Karp_Matcher(std::string T , std::string P, int d , int q )
{
    int s=0;
    bool found_match = false;
    int n = T.length();
    int m = P.length();
    
    int h = int(pow(d,m-1)) % q; // Highest Order Digit for shifting through T
    
    int p = 0; // Hashed Pattern P in terms of digits
    int t = 0; // Hashed Substring of T in terms of digits
    
    for(int i =0 ; i< m ; ++i)
    {
        p = (d*p + P[i]) % q;
        t = (d*t + T[i]) % q;
    }
    
    for(; s<n-m+1; ++s)
    {
        if (p == t)
        {
            for(int j=0; j<m; ++j)
            {
                if(T[s+j]!= P[j]) {found_match=false; break;}
                else
                    found_match=true;
            }
        }
        if(found_match)
            break;
        //Move through T
        t = ( d*(t - int(T[s])*h)+ int(T[s+m])) % q;
        if(t<0) t = t+q;
    }
    
    
    
    if(!found_match) {return -1;}
    return s;
    
    
}
