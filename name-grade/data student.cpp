#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct grade 
{
	char name[10];
	int points;
} gd[5];

int main()
{
	FILE* fp;
	int i = 0;
	
	if ((fp = fopen("grade.txt", "wb+")) == NULL)
	{
		printf("Error to open file grade.dat\n");
		exit(1);
	}

	strcpy_s(gd[0].name, "Kridsaya ");
	gd[0].points = 70;
	fwrite(&gd[0], sizeof(gd[0]), 1, fp);
	strcpy_s(gd[1].name, "Somchai ");
	gd[1].points = 85;
	fwrite(&gd[1], sizeof(gd[1]), 1, fp);
	strcpy_s(gd[2].name, "Somsak ");
	gd[2].points = 45;
	fwrite(&gd[2], sizeof(gd[2]), 1, fp);
	strcpy_s(gd[3].name, "Somcheye ");
	gd[3].points = 73;
	fwrite(&gd[3], sizeof(gd[3]), 1, fp);
	strcpy_s(gd[4].name, "Somsri ");
	gd[4].points = 66;
	fwrite(&gd[4], sizeof(gd[4]), 1, fp);

	printf("Input Data\n");
	printf("%s %d \n", gd[0].name, gd[0].points);
	printf("%s %d \n", gd[1].name, gd[1].points);
	printf("%s %d \n", gd[2].name, gd[2].points);
	printf("%s %d \n", gd[3].name, gd[3].points);
	printf("%s %d \n", gd[4].name, gd[4].points);
	printf("\n");

	rewind(fp);

	printf("Output Data\n");
	for ( i = 0; i < 5; i++)
	{
		fread(&gd[i], sizeof(gd[i]), 1, fp);
		printf("%s", gd[i].name);
		if (gd[i].points > 80)
			printf("A\n");
		else if (gd[i].points >= 70)
			printf("B\n");
		else if (gd[i].points >= 60)
			printf("C\n");
		else if (gd[i].points >= 50)
			printf("D\n");
		else if (gd[i].points < 50)
			printf("F\n");
	}
	_getch();
}