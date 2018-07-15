//
//  mystring.c
//  hw2
//
//  Created by 刘逸丰 on 2018/7/13.
//  Copyright © 2018年 W.Studio. All rights reserved.
//

#include <stdio.h>
#include"mystring.h"

string* str_create(string* s, const char* source)
{
    int i,j;
    for(i=1;*(source+i)!=NULL;i++);
    s->length=i;
    for(j=0;j<=i;j++)
    {
        s->content=source;
    }
    return s;
}

void str_free(string* s)
{
    free(s);
}

unsigned int str_len(const string* s)
{
    int i;
    for(i=0;*(s->content+i)!=NULL;i++);
    return i;
}

string* str_copy(string* dest, const string* source)
{
    dest->length=source->length;
    dest->content=source->content;
    return dest;
}

string* str_concat(string* dest, const string* source)
{
    char temp[100];
    char* temptr;
    int t=dest->length;
    dest->length=(dest->length)+(source->length);
    for(int i=0;i<dest->length;i++)
    {
        temp[i]=*(dest->content+i);
    }
    for(int i=0;i<source->length;i++)
    {
        temp[i+t]=*(source->content+i);
    }
    temptr=temp;
    dest->content=temptr;
    return dest;
}

void str_print(const string* s)
{
    printf("%s\n",s->content);
}

string* str_readline(string* s)
{
    char st[100];
    printf("please input a string!");
    gets(st);
    for(int i=0;*(st+i)!='\0';i++)
    {
        if(*(st+i)=='\0')
        {
            *(st+i)=NULL;
        }
    }
    str_create(s,st);
    return s;
}
