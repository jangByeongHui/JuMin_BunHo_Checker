#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int check(char*str);
void analyze(FILE *fp,char*jumin,char*name);
int main()
{
	char jumin[100],name[100],trash[1];
	FILE *fp;
	fp = fopen("C:\\Users\\jmkab\\Desktop\\EdwardHopper.jpg", "a");
	printf("<주민번호 체크기>\n\n");
	printf("이름을 입력하세요:");
	scanf("%s", name);
	printf("\n");
	scanf("%c", trash);
	printf("주민번호를 입력하세요:");
	gets_s(jumin);
	if (check(jumin) == 1)
	{
		analyze(fp, jumin,name);
	}
	fclose(fp);
	return 0;
}

int check(char*str)
{
	int sum = 0, count = 2, result;
	if (strlen(str) != 13)
	{
		printf("Error:입력 주민등록번호 범위를 벗어났습니다.!\n");
		return 3;
		//글자수 오버//
	}
	for (int i = 0; i < 12; i++)
	{
		if (str[i] - '0' < 0 || 10 < str[i] - '0')
		{
			printf("Error:숫자 범위를 벗어났습니다!\n");
			return 2;
			//숫자 벗어남//
		}
			
		if (count > 9)
			count = 2;
		sum += (int)(str[i] - '0')*count;
		count++;
	}
	result = 11 - sum%11;
	if (result == 11)
		result = 1;
	if (result == 10)
		result = 0;
	if (result == (int)(str[12] - '0'))
	{
		return 1;
		//정상//
	}
	else
	{
		printf("잘못된 주민번호 입니다.!\n");
		return 0;
		//검정 틀림//
	}
}
void analyze(FILE *fp,char*jumin,char*name)
{
	char  century[3], SEX[2][5] = { { "여자" },{ "남자" } }, country[30];
	int sex = 0, birth;
	if (jumin[6] == '9' || jumin[6] == '0')
	{
		strcpy_s(century, "18");
		birth = (jumin[7] - '0') * 10 + (jumin[8] - '0');
		if (jumin[6] == '9')
			sex = 1;
	}
	else if (jumin[6] == '1' || jumin[6] == '2' || jumin[6] == '5' || jumin[6] == '6')
	{
		strcpy_s(century, "19");
		birth = (jumin[7] - '0') * 10 + (jumin[8] - '0');
		if (jumin[6] == '1' || jumin[6] == '5')
			sex = 1;
	}
	else if (jumin[6] == '3' || jumin[6] == '4' || jumin[6] == '7' || jumin[6] == '8')
	{
		strcpy_s(century, "20");
		birth = (jumin[7] - '0') * 10 + (jumin[8] - '0');
		if (jumin[6] == '3' || jumin[6] == '7')
			sex = 1;
	}
	if (0 <= birth&&birth <= 8)
		strcpy_s(country, "서울");
	else if (9 <= birth&&birth <= 12)
		strcpy_s(country, "부산");
	else if (13 <= birth&&birth <= 15)
		strcpy_s(country, "인천");
	else if (16 <= birth&&birth <= 18)
		strcpy_s(country, "경기도 주요도시");
	else if (19 <= birth&&birth <= 25)
		strcpy_s(country, "경기도 비주요 도시");
	else if (26 <= birth&&birth <= 34)
		strcpy_s(country, "강원도");
	else if (35 <= birth&&birth <= 39)
		strcpy_s(country, "충청북도");
	else if (40 <= birth&&birth <= 47)
		strcpy_s(country, "충청남도");
	else if (48 <= birth&&birth <= 54)
		strcpy_s(country, "전라북도");
	else if (55 <= birth&&birth <= 66)
		strcpy_s(country, "전라남도");
	else if (67 <= birth&&birth <= 90)
		strcpy_s(country, "경상도");
	else
	{
		printf("Error:잘못된 주민번호!");
	}
	printf("\n");
	printf("<주민등록번호 분석 결과>\n\n");
	fprintf(fp,"<주민등록번호 분석 결과>\n\n");
	printf("이름:");
	fprintf(fp, "이름:");
	printf("%s\n\n", name);
	fprintf(fp, "%s\n\n", name);
	printf("주민등록번호:");
	fprintf(fp,"주민등록번호:");
	for (int i = 0; i < 6; i++)
	{
		printf("%c", jumin[i]);
		fprintf(fp,"%c", jumin[i]);
	}
	printf("-");
	for (int i = 6; i < 13; i++)
	{
		printf("%c", jumin[i]);
		fprintf(fp, "%c", jumin[i]);
	}
	printf("\n\n");
	fprintf(fp,"\n\n");
	printf("생년 월일:%s%c%c년 %c%c월 %c%c일\n\n", century, jumin[0], jumin[1], jumin[2], jumin[3], jumin[4], jumin[5]);
	fprintf(fp,"생년 월일:%s%c%c년 %c%c월 %c%c일\n\n", century, jumin[0], jumin[1], jumin[2], jumin[3], jumin[4], jumin[5]);
	printf("성별:%s\n\n", SEX[sex]);
	fprintf(fp,"성별:%s\n\n", SEX[sex]);
	printf("태어난 곳: %s출신\n\n", country);
	fprintf(fp,"태어난 곳: %s출신\n\n", country);
	printf("출생 신고 순서:%c\n\n", jumin[11]);
	fprintf(fp,"출생 신고 순서:%c\n\n\n\n", jumin[11]);
}