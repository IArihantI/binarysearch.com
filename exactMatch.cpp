#include<bits/stdc++.h>
using namespace std;

bool exactMatch(char *text,char *pat)
{
	if(*text=='\0' && *pat!='\0')
		return false;
	if(*text==*pat)
		return exactMatch(text+1,pat+1);
	if(*pat=='\0')
		return 1;
}
bool contains(char *text, char *pat)
{
	if(*text=='\0')
		return false;
	if(*text==*pat)
	{
		if(exactMatch(text,pat))
			return 1;
		else
			return contains(text+1,pat);
	}
	return conatins(text+1,pat);
}