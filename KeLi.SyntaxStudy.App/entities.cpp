union USwaper
{
	int nNum;
	short snsNum[2];
	char chsMark[4];
};

struct SDate
{
	unsigned int nYear : 16;
	unsigned int nMonth : 4;
	unsigned int nDay : 5;
};