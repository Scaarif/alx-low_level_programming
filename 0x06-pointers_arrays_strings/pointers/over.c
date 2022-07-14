#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "ssss\n";
	int i = 0, overflow, letter, actual;

	printf("%s\n", s);
	while (s[i] != '\0')
	{
		/*rotate small letters*/
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] < 't')
			{
				s[i] = s[i] + 13;
			}
			else
			{
				overflow =(int) s[i];
				printf("s[i]: %d\n, ", overflow);
				letter = overflow + 13;
				actual = (letter - 122) - 1;
				s[i] = 'a' + actual;
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 13;
			if (s[i] > 'Z')
			{
				overflow = s[i] - 'Z';
				printf("overflow: %d\n", overflow);
				s[i] = ('A' - 1) + (s[i] - 'Z');
			}
		}
		i++;
	}
	printf("%s\n", s);
	return (0);
}
