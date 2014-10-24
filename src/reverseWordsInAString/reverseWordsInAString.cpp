//Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : Bryce
// Date   : 2014-10-24

/********************************************************************************** 
* 
* Given an input string, reverse the string word by word.
* 
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
* 
* 
* Clarification:
* 
* What constitutes a word?
* A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
* 
*               
**********************************************************************************/

#include <stdio.h>

void swap(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

// first reverse every word, and then reverse the whole sentence
void reverseWordsInAString(char *s)
{
	if (s == NULL)
		return;

	char *p = s;		
	char *wrdBegin = s;
	char *wrdEnd = s;

	// reverse every word
	while (*p != '\0')
	{
		if (*p == ' ')			
			wrdEnd = p-1;	

		if (*(p+1) == '\0')
			wrdEnd = p;	

		if  (wrdBegin != wrdEnd)
		{
			while (wrdBegin < wrdEnd)
				swap(wrdBegin++, wrdEnd--);

			wrdBegin = wrdEnd = p+1;
		}

		p++;
	}

	wrdBegin = s;	
	wrdEnd = p-1;

	while (wrdBegin < wrdEnd)
		swap(wrdBegin++, wrdEnd--);
}

int main()
{
	char s[] = {"the sky is blue"};
	reverseWordsInAString(s);
	printf("%s\n", s);

	//TODO: no complete 3 clarificatons.

	return 0;
}
