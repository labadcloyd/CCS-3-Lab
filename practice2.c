#include <stdio.h>

int main(int argc, char const *argv[]) {
	FILE *fp;
	char buff[255];

	fp = fopen("test.txt", "wt");
	fprintf(fp, "this is testing for print f\n");
	fputs("this is testing for fputs\n", fp);
	fclose(fp);

	fp = fopen("test.txt", "r");
	fscanf(fp, "%s", buff);
	printf("1: %s", buff);

	fgets(buff, 255, (FILE*)fp);
	printf("\n2: %s", buff);
	while (fp != EOF)	{
		fgets(buff, 255, (FILE*)fp);
		printf("\n2: %s", buff);
	}
	
	fclose(fp);

	return 0;
}
