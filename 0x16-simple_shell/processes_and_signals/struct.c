#include "main.h"
typedef struct me
{
	char *name;
	int age;
} i;

int main(void)
{
	i _me = {"rahab", 26}, *ptr;
	
	ptr = &_me;
	ptr->name = "Magiri";
	printf("name: %s, age: %d\n", _me.name, _me.age);
	return (0);
}

