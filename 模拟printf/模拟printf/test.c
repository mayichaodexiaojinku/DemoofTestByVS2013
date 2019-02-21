#include<stdio.h>
#include<assert.h>
#include<stdarg.h>
int print(char *format, ...)
{
	va_list arg;
	int count = 0;
	char* str_tmp = NULL;
	va_start(arg, format);
	while (*format)
	{
		switch (*format)
		{
		case 'c':
			putchar(va_arg(arg, int));
			count++;
			break;
		case 's':
			str_tmp = (char*)va_arg(arg, int);
			while (*str_tmp)
			{
				putchar(*str_tmp);
				count++;
				str_tmp++;
			}
			break;
		case 'd':
			str_tmp=(int*)va_arg(arg, int);
			puts(*str_tmp);
			count++;
			break;
		default:
			putchar(*format);
				count++;
			break;
		}
		format++;
	}
	va_end(arg);
	return count;
}
int main()
{
	print("s ccc d\n","hello",'b','i','t',100);
	return 0;
}