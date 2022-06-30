#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//16진수 2진수 변환함수 정의.
void Convert16to2(char *Hex_array);



FILE *fp;
char *Hex_array; // 파일서 읽어온 16진수를 문자열로 읽기 위한 포인터 변수
unsigned int fetched_inst; //명령어의 16진수를 정수형으로 읽기 위한 변수

////////////////////////////////////////////////////////////////
int operand; // (0일때 read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
char binary[33];//16 -> 2진수로 변환 저장 공간
///////////////////////////////////////////////////////////////

int main()
{
	char str_file[20] = { 0 };

	// Trace file 입력 받기
	printf("File : ");
	scanf("%s", str_file);

	//  트레이스 파일 읽기
	if((fp=fopen(str_file, "r")) == NULL) {		
		printf("file open error");
		exit(1);
	}
	
	Hex_array = (char *)malloc(sizeof(char) * 11);
	
	while(feof(fp)==false)		//파일 끝까지 문자열 불러오기.
	{
		fscanf(fp, "%d", &operand);
		fscanf(fp, "%s", Hex_array); //명령어를 문자열로 읽음
		/* Trace file 명령어를 정수형으로 읽기 - 명령어를 문자열로 읽는 함수의 대체로 활용 가능
		fscanf(fp, "%x", &fetched_inst);
		*/
		Convert16to2(Hex_array); //16진수 문자열을 2진수 형식의 문자열로 변경
		//정수형으로 명령어를 읽었다면 Convert16to2 함수의 활용은 필요 없음
		
		//정수형 명령어의 특정 bit 자르기 예시 (tag 22bit, index 8bit, direct-mapped cache)
		//index = (fetched_inst<<22);
		//index = (index>>24); -> index에 해당하는 값이 저장됨
		
		if(operand == 0 || operand == 1)		//data cahce 동작 구현
		{
			printf("data %d    %s    %s\n",operand, Hex_array, binary);
		}
		if(operand == 2)				//inst cache 동작 구현
		{
			printf("inst %d    %s    %s\n",operand, Hex_array, binary);
		}
	}
	
	return 0;
}


//16진수 2진수 변환함수.
void Convert16to2(char *Hex_array)
{
	int res=0;
	char temp;
	unsigned long Hex = strtoul(Hex_array, NULL, 16);

	for (int i = 0; i < 32; i++)
	{
		res = Hex & (0x01 << (31 - i));
		if (res == 0)
		{
			temp = '0';
			binary[i] = temp;
		}
		else
		{
			temp = '1';
			binary[i] = temp;
		}
	}
}
