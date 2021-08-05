#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//#include <windows.h>


int main()
{
    int num_orig, num_uniq, i, k;
    long len;
	char* visited_optional_courses[10000];
	char* visited_uniq_courses[10000];
	char section[10000];

	setlocale(LC_ALL, "Rus");
	// SetConsoleCP(1251);
	// SetConsoleOutputCP(1251);

	scanf("%d", &num_orig);

	for (i = 0; i < num_orig; i++)
	{
		fflush(stdin);
		gets(section);
		len = strlen(section);
		visited_optional_courses[i] = (char*) realloc(visited_optional_courses[i], sizeof(char) * len);
		strcpy (visited_optional_courses[i], section);
	}

	num_uniq = 0;
	for (i = 0; i < num_orig; i++)
	{
		for (k = 0; k<num_uniq; k++)
		{
			if (strcmp(visited_uniq_courses[k], visited_optional_courses[i]) == 0)
				break;
		}
		if (k == num_uniq)
		{
			len = strlen(visited_optional_courses[i]);
			visited_uniq_courses[num_uniq] = (char*) realloc(visited_uniq_courses[num_uniq], sizeof(char) * len);
			strcpy(visited_uniq_courses[num_uniq], visited_optional_courses[i]);
			num_uniq++;
		}
	}

	for (i = 0; i < num_uniq; i++)
	{
		printf("%s", visited_uniq_courses[i]);
		if (i < num_uniq - 1 && i != 0)
			printf("\n");
	}

	return 0;
}
