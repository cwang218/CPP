// Christine Wang
// CS 3500
// Homework 2 - Recursive Descent Parser

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

string token;

void getToken();

void isExp();
void isSimpExp();
void isTerm();
void isFactor();
bool isRel();
bool isAdd();
bool isMul();
void isAssign();
void isRoutCall();
void isIf();
void isWhile();
void isPrint();
void isState();
void isStateSeq();
void isRoutDec();

bool isIdent();

int main()
{
	getToken();

	if(token != "routine")
	{
		printf("INVALID!\n");
		return 0;
	}

	isRoutDec();

	if(cin.eof())
		printf("CORRECT\n");
	else
		printf("INVALID!\n");
}

void getToken()
{
	cin >> token;
}

void isExp()
{
	isSimpExp();

	if(isRel())
	{
		getToken();
		isSimpExp();
	}
}

void isSimpExp()
{
	isTerm();

	if(isAdd())
	{
		getToken();
		isTerm();
	}
}

void isTerm()
{
	isFactor();

	if(isMul())
	{
		getToken();
		isFactor();
	}
}

void isFactor()
{
	if(isIdent() || ((token[0] == '\"') && (token[token.size()-1] == '\"')))
		getToken();
	else if(token[0] == '+' || token[0] == '-' || isdigit(token[0]))
	{
		token = token.substr(0, token.size());

		for(int x=0; x< token.size(); x++)
		{
			if(!isdigit(token[x]) && token[x] != '.')
				return;
		}

		getToken();
	}
	else if(token == "(")
	{
		getToken();
		isExp();
		getToken();
	}
	else if(token == "not")
	{
		getToken();
		isFactor();
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

bool isRel()
{
	return (token == "<" || token == ">" || token == "=");
}

bool isAdd()
{
	return (token == "+" || token == "-" || token == "or");
}

bool isMul()
{
	return (token == "*" || token == "/" || token == "and");
}

void isAssign()
{
	if(isIdent())
	{
		getToken();

		if(token == "is")
		{
			getToken();

			isExp();
		}
		else
		{
			cerr << "INVALID!\n";
			exit(1);
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

void isRoutCall()
{
	if(token == "run")
	{
		getToken();

		if(isIdent())
			getToken();
		else
		{
			cerr << "INVALID!\n";
			exit(1);
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

void isIf()
{
	if(token == "if")
	{
		getToken();

		isExp();

		if(token == "$")
		{
			getToken();

			isStateSeq();

			if(token == "else")
			{
				getToken();
				isStateSeq();
			}
			
			if(token == "endif")
				getToken();
			else
			{
				cerr << "INVALID!\n";
				exit(1);
			}
		}
		else
		{
			cerr << "INVALID!\n";
			exit(1);
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

void isWhile()
{
	if(token == "while")
	{
		getToken();

		isExp();

		if(token == "$")
		{
			getToken();

			isStateSeq();

			if(token == "endw")
				getToken();
			else
			{
				cerr << "INVALID!\n";
				exit(1);
			}
		}
		else
		{
			cerr << "INVALID!\n";
			exit(1);
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

void isPrint()
{
	if(token == "print")
	{
		getToken();

		if(isIdent())
			getToken();
		else
		{
			cerr << "INVALID!\n";
			exit(1);
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

void isState()
{
	if(token[0] != EOF)
	{
		if(isIdent())
		{
			isAssign();
		}
		else
		{
			switch(token[0])
			{
				case 'r':
					isRoutCall();
					break;
				case 'i':
					isIf();
					break;
				case 'w':
					isWhile();
					break;
				case 'p':
					isPrint();
					break;
				default:
					cerr << "INVALID!\n";
					exit(1);
			}
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

void isStateSeq()
{
	isState();

	while(token == "!")
	{
		getToken();
		isState();
	}
}

void isRoutDec()
{
	if(token=="routine")
	{
		getToken();

		if(isIdent())
		{
			getToken();

			if(token == "$")
			{
				getToken();
				
				isStateSeq();

				if(token == "endr")
					getToken();
				else
				{
					cerr << "INVALID!\n";
					exit(1);
				}
			}
			else
			{
				cerr << "INVALID!\n";
				exit(1);
			}
		}
		else
		{
			cerr << "INVALID!\n";
			exit(1);
		}
	}
	else
	{
		cerr << "INVALID!\n";
		exit(1);
	}
}

bool isIdent()
{
	if(!isalpha(token[0]))
		return false;

	for(int x=0; x<token.size(); x++)
	{
		if(!isalnum(token[x]))
			return false;
	}

	string keys[13] = {"is", "or", "and", "not", "print", "if", "else", "endif", "while", "endw", "routine", "endr", "run"};

	for(int x=0; x<13; x++)
	{
		if(token==keys[x])
			return false;
	}

	return true;
}
