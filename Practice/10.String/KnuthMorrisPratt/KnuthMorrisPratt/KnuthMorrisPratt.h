#ifndef _KNUTHMORRISPRATT_H_
#define _KNUTHMORRISPRATT_H_

int KnuthMorrisPratt(char* Text, int TextSize, int Start, char* Pattern, int PatternSize);

void Preprocess(char* Pattern, int PatternSize, int* Border);

#endif	// _KNUTHMORRISPRATT_H_
