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
	printf("<�ֹι�ȣ üũ��>\n\n");
	printf("�̸��� �Է��ϼ���:");
	scanf("%s", name);
	printf("\n");
	scanf("%c", trash);
	printf("�ֹι�ȣ�� �Է��ϼ���:");
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
		printf("Error:�Է� �ֹε�Ϲ�ȣ ������ ������ϴ�.!\n");
		return 3;
		//���ڼ� ����//
	}
	for (int i = 0; i < 12; i++)
	{
		if (str[i] - '0' < 0 || 10 < str[i] - '0')
		{
			printf("Error:���� ������ ������ϴ�!\n");
			return 2;
			//���� ���//
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
		//����//
	}
	else
	{
		printf("�߸��� �ֹι�ȣ �Դϴ�.!\n");
		return 0;
		//���� Ʋ��//
	}
}
void analyze(FILE *fp,char*jumin,char*name)
{
	char  century[3], SEX[2][5] = { { "����" },{ "����" } }, country[30];
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
		strcpy_s(country, "����");
	else if (9 <= birth&&birth <= 12)
		strcpy_s(country, "�λ�");
	else if (13 <= birth&&birth <= 15)
		strcpy_s(country, "��õ");
	else if (16 <= birth&&birth <= 18)
		strcpy_s(country, "��⵵ �ֿ䵵��");
	else if (19 <= birth&&birth <= 25)
		strcpy_s(country, "��⵵ ���ֿ� ����");
	else if (26 <= birth&&birth <= 34)
		strcpy_s(country, "������");
	else if (35 <= birth&&birth <= 39)
		strcpy_s(country, "��û�ϵ�");
	else if (40 <= birth&&birth <= 47)
		strcpy_s(country, "��û����");
	else if (48 <= birth&&birth <= 54)
		strcpy_s(country, "����ϵ�");
	else if (55 <= birth&&birth <= 66)
		strcpy_s(country, "���󳲵�");
	else if (67 <= birth&&birth <= 90)
		strcpy_s(country, "���");
	else
	{
		printf("Error:�߸��� �ֹι�ȣ!");
	}
	printf("\n");
	printf("<�ֹε�Ϲ�ȣ �м� ���>\n\n");
	fprintf(fp,"<�ֹε�Ϲ�ȣ �м� ���>\n\n");
	printf("�̸�:");
	fprintf(fp, "�̸�:");
	printf("%s\n\n", name);
	fprintf(fp, "%s\n\n", name);
	printf("�ֹε�Ϲ�ȣ:");
	fprintf(fp,"�ֹε�Ϲ�ȣ:");
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
	printf("���� ����:%s%c%c�� %c%c�� %c%c��\n\n", century, jumin[0], jumin[1], jumin[2], jumin[3], jumin[4], jumin[5]);
	fprintf(fp,"���� ����:%s%c%c�� %c%c�� %c%c��\n\n", century, jumin[0], jumin[1], jumin[2], jumin[3], jumin[4], jumin[5]);
	printf("����:%s\n\n", SEX[sex]);
	fprintf(fp,"����:%s\n\n", SEX[sex]);
	printf("�¾ ��: %s���\n\n", country);
	fprintf(fp,"�¾ ��: %s���\n\n", country);
	printf("��� �Ű� ����:%c\n\n", jumin[11]);
	fprintf(fp,"��� �Ű� ����:%c\n\n\n\n", jumin[11]);
}