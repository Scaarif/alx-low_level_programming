// #include "main.h"
#include <stdio.h>

int main(void)
{
	int i = 0, j = 0;
	char num[10], *s;

	s = "Storm 402da9";
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			/*then the char is a num*/
			while (s[i] >= '0' && s[i] <= '9')
			{
				// printf("%c\n", s[i]);
				num[j] = s[i];
				// printf("%c\n", num[j]);
				i++;
				j++;
			}
			break;
		}
		i++;
	}
	printf("%s\n", num);
	return (0);

}
