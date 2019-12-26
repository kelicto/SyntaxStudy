#include <stdio.h>
#include "entities.cpp"

void studyDoublePointer();
void studyPointerArray();
int calcDayNum(SDate);
void printDate();
void swapBitNumByUnion();
void descNumByUnion();
void descBitNumByPoint();

int main()
{
	studyDoublePointer();
	studyPointerArray();
	printDate();
	swapBitNumByUnion();
	descNumByUnion();
	descBitNumByPoint();

	return 0;
}

void studyDoublePointer()
{
	int nsNum[] = { 32,56, 93, 56, -1, 0 };
	int* npNum = &nsNum[0];

	while (*npNum)
	{
		printf("npNum[%d]=%d\n", npNum - nsNum, *npNum);
		++npNum;
	}
}

 void studyPointerArray()
{
	const char* chpsNum[4] = { "Basic", "Fortran", "C++" };

	printf("chpsNum size: %d\n", sizeof(chpsNum));

	int i = 0;

	//while (i < sizeof(chpsNum) / sizeof(chpsNum[0]))
	while (chpsNum[i])
	{
		printf("current item address: %p\n", &chpsNum[i]);
		printf("chpsNum[%d] pointed to address: %p, pointed to the content: %s\n", i,  chpsNum[i], chpsNum[i]);
		i++;
	}
}

void swapBitNumByUnion()
{
	int nNum = 0x12345678;

	// Sets swaper's nNum value, becasuse it is first member of swaper.
	USwaper swaper = { nNum };

	short snTemp = swaper.snsNum[0];

	swaper.snsNum[0] = swaper.snsNum[1];
	swaper.snsNum[1] = snTemp;

	// Resets nNum value.
	nNum = swaper.nNum;

	printf("nNum: 0x%x\n", nNum);
}

int calcDayNum(SDate* sDate)
{
	int nResult = sDate->nDay;
	int nsMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i = 0;

	while (i < sDate->nMonth-1)
		nResult += nsMonth[i++];

	if (sDate->nMonth > 2)
	{
		int nYear = sDate->nYear;

		if (nYear % 4 == 0 && nYear % 100 != 0 || nYear % 400 == 0)
			++nResult;
	}

	return nResult;
}

void printDate()
{
	SDate sDate;
	int nNum;

	printf("Please input date[yyyy MM dd]: ");

	scanf_s("%d", &nNum);
	sDate.nYear = nNum;
	scanf_s("%d", &nNum);
	sDate.nMonth = nNum;
	scanf_s("%d", &nNum);
	sDate.nDay = nNum;

	int dayNum = calcDayNum(&sDate);

	printf("Date's day num: %d\n", dayNum);
}

void descNumByUnion()
{
	int nNum = 0x12345678;

	// Sets swaper's nNum value, becasuse it is first member of swaper.
	USwaper uSwaper = { nNum };

	char chTemp = uSwaper.chsMark[0];

	uSwaper.chsMark[0] = uSwaper.chsMark[3];
	uSwaper.chsMark[3] = chTemp;

	chTemp = uSwaper.chsMark[1];
	uSwaper.chsMark[1] = uSwaper.chsMark[2];
	uSwaper.chsMark[2] = chTemp;

	// Resets nNum value.
	nNum = uSwaper.nNum;

	printf("nNum: 0x%x\n", nNum);
}

void descBitNumByPoint()
{
	int nNum = 0x12345678;
	char* chpNum = (char*)& nNum;
	char chTemp = chpNum[0];

	printf("Swap before: 0x%x\n", nNum);

	chpNum[0] = chpNum[3];
	chpNum[3] = chTemp;

	printf("Swap atfer: 0x%x\n", nNum);
}