/*
** EPITECH PROJECT, 2020
** my_fscanf.c
** File description:
** extract data from file
*/

#include "my_printf.h"

void double_parse(int file, va_list li, char buff[3])
{
    float *b = va_arg(li, float *);

    *b = 0;
    for (int i = 0; i < 1024 && read(file, buff, 1) > 0 &&
            !my_grep(" \n", buff[0]); i++)
        *b = *b * 10 + buff[0] - 48;
}

void short_parse(int file, va_list li, char buff[3])
{
    unsigned short *c = va_arg(li, unsigned short *);

    *c = 0;
    for (int i = 0; i < 1024 && read(file, buff, 1) > 0 &&
            !my_grep(" \n", buff[0]); i++)
        *c = *c * 10 + buff[0] - 48;
}

int format_parse(int file, const char c, va_list li)
{
    int *a;
    char buff[3];

    if (my_grep("di", c)) {
        a = va_arg(li, int *);
        *a = 0;
        for (int i = 0; i < 1024 && read(file, buff, 1) > 0 &&
            !my_grep(" \n", buff[0]); i++)
            *a = *a * 10 + buff[0] - 48;
    }
    if (my_grep("f", c))
        double_parse(file, li, buff);
    if (my_grep("s", c))
        short_parse(file, li, buff);
    return (1);
}

int my_fscanf(int file, const char *format, ...)
{
    va_list li;
    int ac = 0;

    va_start(li, format);
    for (int i = 0; format[i] && ac < MAX_ARGS; i++)
        if (format[i] == '%')
            ac += format_parse(file, format[++i], li);
    va_end(li);
    if (ac == 0)
        return (-1);
    return (ac);
}
