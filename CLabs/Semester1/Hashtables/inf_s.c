#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "inf_s.h"

void init_s (inf_s *str)
{
	str->s = (char *)calloc(START_LENGTH_S,sizeof(char));
	str->length = START_LENGTH_S;
	str->count = -1;
}

static void add(inf_s *str,char c) // добавлем в бесконечную строку символ
{
	assert(str);
	(str->count)++;
	int coun = str->count;

	int l = str->length;
	if (coun == l)
	{
		char *p = (char *)calloc(l*RESIZE_S,sizeof(char));
		assert(p);

		memcpy(p, str->s, (l*RESIZE_S-l)*sizeof(char));
		p[coun] = c;
		free(str->s);
		str->s = p;
		(str->length) *= RESIZE_S;
	}
	else
	{
		str->s[coun] = c;
	}		
	return;
}

void get_inf_s_from_file(inf_s *str,FILE *input_file)
{
	assert(input_file);
	char c;
	while(((c = getc(input_file)) != ' ') && (c != EOF))
	{
		add(str,c);
		assert(str);
	}
	
	add(str,'\0');
	assert(str);
}

void get_inf_s_std(inf_s *str)
{
	char c;
	while(((c = getchar()) != ' ') && (c != '\n'))
	{
		add(str,c);
		assert(str);
	}

	add(str,'\0');
	assert(str);
}