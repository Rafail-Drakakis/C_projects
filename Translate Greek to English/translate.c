#include <stdio.h>
#include <stdlib.h>

void dictionary(char* letters[]) {
    letters[0] = "A";
    letters[1] = "V";
    letters[2] = "G";
    letters[3] = "D";
    letters[4] = "E";
    letters[5] = "Z";
    letters[6] = "H";
    letters[7] = "8";
    letters[8] = "I";
    letters[9] = "K";
    letters[10] = "L";
    letters[11] = "M";
    letters[12] = "N";
    letters[13] = "KS";
    letters[14] = "O";
    letters[15] = "P";
    letters[16] = "R";
    letters[17] = "S";
    letters[18] = "T";
    letters[19] = "Y";
    letters[20] = "F";
    letters[21] = "X";
    letters[22] = "PS";
    letters[23] = "W";
    letters[24] = "a";
    letters[25] = "v";
    letters[26] = "g";
    letters[27] = "d";
    letters[28] = "e";
    letters[29] = "z";
    letters[30] = "h";
    letters[31] = "8";
    letters[32] = "i";
    letters[33] = "k";
    letters[34] = "l";
    letters[35] = "m";
    letters[36] = "n";
    letters[37] = "ks";
    letters[38] = "o";
    letters[39] = "p";
    letters[40] = "r";
    letters[41] = "s";
    letters[42] = "s";
    letters[43] = "t";
    letters[44] = "y";
    letters[45] = "f";
    letters[46] = "x";
    letters[47] = "ps";
    letters[48] = "w";
    letters[49] = "'A";
    letters[50] = "'E";
    letters[51] = "'H";
    letters[52] = "'I";
    letters[53] = "'O";
    letters[54] = "'W";
    letters[55] = "'Y";
    letters[56] = "a'";
    letters[57] = "e'";
    letters[58] = "h'";
    letters[59] = "i'";
    letters[60] = "o'";
    letters[61] = "w'";
    letters[62] = "y'";
    letters[63] = "i\"";
    letters[64] = "y\"";
    letters[65] = "i'\"";
    letters[66] = "y'\"";
}

int findChar(int i) {
    if (i >= 193 && i <= 209) {
        return i - 193;
    } else if (i >= 211 && i <= 217) {
        return i - 194;
    } else if (i >= 225 && i <= 249) {
        return i - 201;
    } else if (i >= 220 && i <= 223) {
        return i - 164;
    } else {
        switch (i) {
            case 182:
                return 49;
                break;
            case 184:
                return 50;
                break;
            case 185:
                return 51;
                break;
            case 186:
                return 52;
                break;
            case 188:
                return 53;
                break;
            case 191:
                return 54;
                break;
            case 190:
                return 55;
                break;
            case 252:
                return 60;
                break;
            case 254:
                return 61;
                break;
            case 253:
                return 62;
                break;
            case 250:
                return 63;
                break;
            case 251:
                return 64;
                break;
            case 192:
                return 65;
                break;
            case 224:
                return 66;
                break;
            default:
                return -1;
        }
    }
    return 0;
}

void character_to_print(char *letter) { /*Function from stackoverflow to print the letter*/
    while (*letter) {
        putchar(*letter);    
        letter++;
    }
}

int main() {
    enum State {default_state, b_state, B_state, d_state, D_state};
    enum State state;
    char *array[67];
    int character;

    state = default_state;

    dictionary(array);

    while ((character = getchar()) != EOF) {
        char *to_be_printed;

        if (character < 32) {
            putchar(character);
            continue;
        }
        if (findChar(character) != -1) {
            to_be_printed = array[findChar(character)];
        } else {
            to_be_printed = (char *)malloc(sizeof(char));
            *to_be_printed = character;
        }

        switch (state) {
            case b_state:
                if (character == 240 || character == 208) { /*Π or π */
                    to_be_printed = "b";
                } else {
                    character_to_print("m");
                }
                break;

            case B_state:
                if (character == 240 || character == 208) { /* Π or π */
                    to_be_printed = "B";
                } else {
                    character_to_print("M");
                }
                break;

            case d_state:
                if (character == 244 || character == 212) { /* Τ or τ */
                    to_be_printed = "d";
                } else {
                    character_to_print("n");
                }
                break;

            case D_state:
                if (character == 244 || character == 212) { /* Τ or τ */
                    to_be_printed = "D";
                } else {
                    character_to_print("N");
                }
                break;

            case default_state:
                break;
        }

        state = default_state;

        switch (character) {
            case 204: /*M*/
                state = B_state;
                continue;
            case 205: /*N*/
                state = D_state;
                continue;
            case 236: /*m*/
                state = b_state;
                continue;
            case 237: /*n*/
                state = d_state;
                continue;
        }
        character_to_print(to_be_printed);
    }
    return 0;
}
