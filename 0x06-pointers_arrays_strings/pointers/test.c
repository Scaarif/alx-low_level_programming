#include <stdio.h>

int main(void)
{
	char last, *p, str[98] = "Hello World", apd[] = "Damn";
	int i, j;

	/*print the last char in str*/
	for (i = 0; str[i] != '\0'; i++);
	last = str[i - 1]; /*str[i] = the null character*/
	printf("Printing the last string: ");
	printf("%c\n", last);
	/*and to append apd */
	p = &last + 1;
	for (j = 0; apd[j] != '\0'; j++)
	{
		 *(p + j) = apd[j];
	}
	printf("Appended: %s\n", str);
	return (0);
}
