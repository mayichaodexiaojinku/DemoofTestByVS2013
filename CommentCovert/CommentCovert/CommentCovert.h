#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include<stdio.h>
#include<stdlib.h>   
 
enum state
{
	NULL_STATE,
	C_STATE,
	Cpp_STATE,
	END_STATE
};

void DoCommentCovert(FILE*pfIn, FILE*pfOut);
void DoNULLSTATE(FILE*pfIn, FILE*pfOut,enum state *ps);
void DoCSTATE(FILE*pfIn, FILE*pfOut,enum state *ps);
void DoCppSTATE(FILE*pfIn, FILE*pfOut,enum state *ps);

#endif  // __COMMENT_CONVERT_H__