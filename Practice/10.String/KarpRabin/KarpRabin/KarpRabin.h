#ifndef _KARPRABIN_H_
#define _KARPRABIN_H_

int KarpRabin(char* Text, int TextSize, int Start, char* Pattern, int PatternSize);

int Hash(char* String, int Size);
int ReHash(char* String, int Start, int Size, int HashPrev, int Coefficient);

#endif	// _KARPRABIN_H_
