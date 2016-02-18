// Christine Wang


#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

char isValid(char *);
int main()
{
	int num;
	cin >> num;
	string temp;
	char * c;
	char *op;
	op = new char[num];
	for(int i=0; i<num; i++)
	{
		cin >> temp;
		c=new char[num + 1];
		strcpy(c, temp.c_str());
		op[i]=isValid(c);
	}
	cout << endl << num << endl;
	for(int i=0; i<num; i++)
	{
		if(op[i]=='i')
			cout << "Found an Integer." << endl;
		else if(op[i]=='d')
			cout << "Found a Decimal." << endl;
		else if(op[i]=='s')
			cout << "Found a Scientific." << endl;
		else
			cout << "Invalid!" << endl;
	}
	delete [] op;
	return 0;
}

char isValid(char* s)
{
     int i=0;
     int state=1;
     char c=s[i];
     while(c!='\0')
     {
          switch(state)
          {
               case 1:
			   		if(c=='+' || c=='-')
						state=2;
					else if(isdigit(c))
						state=3;
					else
						state=-1;
					break;
			   case 2:
			   		if(isdigit(c))
						state=3;
					else
						state=-1;
					break;
			   case 3:
			   		if(isdigit(c))
						state=3;
					else if(c=='.')
						state=4;
					else
						state=-1;
					break;
			   case 4:
			   		if(isdigit(c))
						state=5;
					else
						state=-1;
					break;
			   case 5:
			   		if(isdigit(c))
						state=5;
					else if(c=='E')
						state=6;
					else
						state=-1;
					break;
			   case 6:
			   		if(c=='+' || c=='-' || c=='0')
						state=7;
					else if(isdigit(c))
						state=8;
					else
						state=-1;
					break;
			   case 7:
			   		if(c=='0')
						state=7;
			   		if(isdigit(c))
						state=8;
					else
						state=-1;
			   case 8:
			   		if(c>='1' && c<='9')
				   		state=8;
					else
						state=-1;
					break;
			   default:
			   		return '\0';
          }
		  i++;
		  c=s[i];
     }
	 if(state==3)
		 return 'i';
	 else if(state==5)
		 return 'd';
	 else if(state==8)
		 return 's';
	 else
		 return '\0';
}