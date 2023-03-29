#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Given a string s, find the length of the longest
//substring
//without repeating characters.

int lengthOfLongestSubstring(char *str);
int check_reap(char *str,bool *was_char,size_t size);

int main() {
    char str[]="abcabcbb\n";
    int len=lengthOfLongestSubstring(str);
    printf("length is %d",len);
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int cache[256]={-1};
    size_t size=strlen(s);
    int start = -1, maxRes = 0;
    for(int i = 0; i < size; i++) {
        start = start> cache[s[i]] ? start: cache[s[i]];
        cache[s[i]] = i;
        maxRes = (maxRes > (i - start)) ? maxRes:(i-start);
    }
    return maxRes;
}
