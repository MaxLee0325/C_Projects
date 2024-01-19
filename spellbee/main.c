
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(char word[], bool letters[]);
int findWord(bool dic[][26], const bool letters[], int num);

int main() {
    int num;
    scanf("%d", &num);
    getchar();
    char word[num][30];
    bool letters[num][26];
    for(int i = 0; i < num; i++){
        //Reminder for myself: memset can only be used continuously, i.e. each row
        memset(letters[i], false, sizeof(letters[i]));
        //array of letters should be initialized each time
        scanf("%s", word[i]);
        check(word[i], letters[i]);
    }

    for(int i = 0; i < num; i++){
        if(check(word[i], letters[i])){
            printf("%s : ", word[i]);
            //check each element in the array, index of true value is the ascii value of char
            for(int j = 0; j < 26; j++){
                if(letters[i][j]){
                    printf("%c ", (char)(j + 'A'));
                }
            }
            int dups = findWord(letters, letters[i], num);
            printf("; %d\n", dups);
        }
    }

    return 0;
}

/**
 *
 * @param word The word from the input
 * @param letters a bool array represents the panagram
 * @return a bool that is true when it's a panagram with number of 7
 *
 * Check method is called to check if the word has a panagram of number of 7, the idea is that I start with an array of
 * all false values, the once the letter appears, use the ascii value of the letter to locate an index in the array and
 * change the value to true.
 */
bool check(char word[], bool letters[]){
    int count = 0;
    //use an array to record the appearance of the letter
    for(int i = 0; i < strlen(word); i++){
        //use the ascii value of the letter as the index in the array
        letters[word[i] - 'A'] = true;
    }
    for(int i = 0; i < 26; i++){
        if(letters[i] == true){
            count++;
        }
    }
    if(count == 7){
        return true;
    }
    return false;
}

/**
 *
 * @param dic The dictionary that contains all the input words
 * @param letters The bool array that represents the panagram
 * @param num The number of words input
 * @return The number of the words that can be covered by the panagram
 *
 * The findWord method is called to check if the panagram can cover the word
 * The only situation that the panagram can't cover the word is the letter exists in the word, but not in the panagram
 * So I loop through the dictionary and check the number of word that is marked (can be covered by the panagram
 */
int findWord(bool dic[][26], const bool letters[], int num){
    int dups = 0;
    for(int i = 0; i < num; i++){
        bool makable = true;
        for(int j = 0; j < 26; j++){
            //when there is a letter that exists in word but not the panagram, it's not marked
            if(dic[i][j] == true && letters[j] == false){
                makable = false;
                break;
            }
        }
        if(makable){
            dups++;
        }
    }
    return dups;
}
