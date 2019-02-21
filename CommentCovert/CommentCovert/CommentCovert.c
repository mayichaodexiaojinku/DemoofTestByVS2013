#define _CRT_SECURE_NO_WARNINGS

#include "CommentCovert.h"

void DoCommentCovert(FILE*pfIn, FILE*pfOut)
{
	enum state ps = NULL_STATE;
	while (ps != END_STATE)
	{
		switch (ps)
		{
		case NULL_STATE:
			DoNULLSTATE(pfIn, pfOut, &ps);
			break;
		case C_STATE:
			DoCSTATE(pfIn, pfOut, &ps);
			break;
		case Cpp_STATE:
			DoCppSTATE(pfIn, pfOut, &ps);
			break;
		}
	}
}
void DoNULLSTATE(FILE*pfIn, FILE*pfOut, enum state *ps)
{
	int f = fgetc(pfIn);
	switch (f)
	{
	case EOF:
		*ps = END_STATE;
		break;
	case '/':
	{
				int s = fgetc(pfIn);
				switch (s)
				{
				case EOF:
				{
							fputc(f, pfOut);
							*ps = END_STATE;
				}
					break;
				case '/':
				{
							fputc(f, pfOut);
							fputc(s, pfOut);
							*ps = Cpp_STATE;
				}
				break;
				case '*':
				{
							fputc(f, pfOut);
							fputc('/', pfOut);
							*ps = C_STATE;
				}
				break;
				default:
				{
						   fputc(f, pfOut);
						   fputc(s, pfOut);
				}
					break;
				}
	}
		break;
	default:
		fputc(f, pfOut);
		break;
	}
	
}
void DoCSTATE(FILE*pfIn, FILE*pfOut, enum state *ps)
{
	int f = fgetc(pfIn);
	switch (f)
	{
	case '*':
	{
				int s = fgetc(pfIn);
				switch (s)
				{
				case '/':
				{
							int t = fgetc(pfIn);
							switch (t)
							{
							case '\n':
								fputc(t, pfOut);
								*ps = NULL_STATE;
								break;
							default:
								fputc('\n', pfOut);
								fputc(t, pfOut);
								*ps = NULL_STATE;
								break;
							}
					
				}
			    break;
				case '*':
				{
							ungetc(f,pfIn);
				}
				break;
				default:
					fputc(f, pfOut);
					break;
				}
	}
		break;
	case '\n':
		fputc(f, pfOut);
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	default:
		fputc(f, pfOut);
		break;
	}
}
void DoCppSTATE(FILE*pfIn, FILE*pfOut, enum state *ps)
{
	int ch = fgetc(pfIn);
	switch (ch)
	{
	case '\n':
		fputc(ch, pfOut);
		*ps = NULL_STATE;
		break;
	case EOF:
		*ps = END_STATE;
		break;
	default:
		fputc(ch, pfOut);
		break;
	}
}