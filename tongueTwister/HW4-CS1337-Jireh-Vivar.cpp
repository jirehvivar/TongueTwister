/*<----------------------------------------tongue Twisters -------------------------------------------->
JirehVivar 03.06.2004            --fixed file output after creating and implementing debugger file
                                 --vector name changed for easier understanding and ability to read code
                                 --moved convert text into its own function because it has too much code to understand in the main function
jirehVivar 03.07.2023            --deleted part of debugger that did not output what i was looking for
                                 --changed code so the user has options to choose which sentence type they would like
                                 -- game user choice whether to see program whole, or one by one
                                 --changed convert sentences to have their own individual functions
                                 --fixed toggleCase function to lowercase things inside parameters like ("liza")
                                 --edited the findVowels case into just a string, saved space in code
                                 --deleted capitalization function of unmodified words and simply added capitalization to each time function was used to save useless use of functions
 JirehVivar 03.12.2023           --created a title for smoother output
special features:
    -- can choose whether to look at it one by one, only one sentence, or one by one all three sentences, or run the whole program


*/

#include<iostream>
#include<vector>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<cctype>
#include<algorithm>

using namespace std;

// change to true to use debugger
bool showFlow = false;
vector<string>lines;
vector<string>sensitiveWords = {"gobbled", "for", "dog", "soundly", "and", "wood", "clawing",
                                "an", "mainly", "seashore" , "into" };

string longestWord;

//  debugging show line
void showflow(string line)
{
    cout << endl << line  <<endl;
}
//  save the words into a vector
void saveWords(string line)
{
    if(showFlow)
        showflow("Entering function saveWords");

    stringstream ss(line);
    string word;
    // count of how many words are in the line
    int countWords = 0;
    bool longWord = false;
    while(ss >> word)
        {
            lines.push_back(word);
            countWords++;
            if(longWord)
            {
                longestWord = word;
                longWord = false;
            }
            if(word.length()>longestWord.length())
            {
                longestWord = word;
            }

        }
        cout << "The number of words in this function is: " << countWords << endl;
// if debugger on, shows the words found and what it looks like in vector
        if(showFlow)
        {
            for(string word : lines)
            {
                cout << word << " " ;
            }
        }
        cout << "the longest word is \"" << longestWord << "\"" << endl;
        if(showFlow)
            showflow("Leaving function saveWords");
}
void findSpaces(string text)
{
    if(showFlow)
    {
        showflow("Entering function findSpaces");
    }
    int spaceCount = 0;
    for(int e = 0; e < text.length(); e++)
    {
        if(text[e] == ' ')
        {
            spaceCount++;
        }
    }
    cout << "The number of spaces are: " << spaceCount << endl;
    if(showFlow)
    {
        showflow("Leaving function findSpaces");
    }

}
//  eliminate spaces
void elim_spaces(string text)
{
    if(showFlow)
    {
        showflow("Entering function elim_spaces");
    }
    string gluedLine;
    for(int e = 0; e < text.length(); e++)
    {
        if(text[e] != ' ')
        {
            gluedLine += text[e];
        }
    }

    int charCount = gluedLine.length();
    cout << "This line has: " << charCount << " characters" << endl;

//shows the lines output
    if(showFlow)
    {
        cout << gluedLine << endl;
        showflow("Leaving function elim_spaces"); // does this for every single line
    }
}

//counts punctuation
void findPunc(string text)
{
    if(showFlow)
    {
        showflow("Entering function findPunc");
    }

    string puncChars = ",.\"'!?()";
    int count = 0;

    for (char ch : puncChars) {
        for (int i = 0; (i = text.find(ch, i)) != string::npos; i++) {
            count++;
        }
    }
    cout << "# of Punctuation characters: " << count << endl;


//show what punctuations found, in debugger
    if(showFlow)
    {
        string showPunc;
        for(char ch : text)
        {
        if(ispunct(ch))
            {
                showPunc +=ch;
            }
        }
    cout << "|| " << showPunc << " ||";
    showflow("Leaving the function findPunc");
    }
}

// counts vowels, consonants and other
void findVowels(string text){
    if(showFlow)
    showflow("Entering the function findVowels");
    int vowels = 0, consonants = 0, other = 0;
    string vowelsDefined = "aeiouAEIOU";

//for debugger to show what vowels, consonants and other
        string showVowels = "";
        string showConsonants = "";
        string showOther = "";

    for(int i =0; i<text.length(); i++)
    {
        char c = text[i];
        if(isalpha(c))
        {
        size_t found = vowelsDefined.find(c);
            if(found != string:: npos)
            {
                vowels++;
                    //fordebugger
                    showVowels +=c;
            }
            else {
                    consonants++;
                        //for debugger
                        showConsonants+=c;
                 }
        }
        else {
                other++;
                    // for debugger
                    showOther+=c;
             }
    }
    cout << "# of Vowels: " << vowels << endl;
    cout << "# of consonants: " << consonants << endl;
    cout << "# of other characters: " << other << endl;

// debugger shows what exactly was found
        if(showFlow)
        {
            cout << endl << "|| " << showVowels << " " << showConsonants << " " << showOther  << " ||"<< endl;
            showflow("Leaving the function findVowels");
        }

}


// sentence manipulation for first letter of every word uppercased
void titleCase(string line)
{
    if(showFlow)
    showflow("Entering the function titleCase");
    stringstream ss(line);
    string newSentence;
    string word;
    cout << endl << "title Case: ";
        while(ss >> word)
        {
            if(find(sensitiveWords.begin(), sensitiveWords.end(), word) !=sensitiveWords.end())
            { //keeps words unmodified
                string capitalize;
                for(char CA: word)
                {
                    capitalize += toupper(CA);
                }
                newSentence += capitalize + " ";
            }
                else {
                    word[0] = toupper(word[0]);
                    newSentence += word + " ";
                }
        }
            cout << newSentence << endl;
// debugger
    if(showFlow)
    showflow("Leaving the function titleCase");
}

// case 2
void sentenceCase(string line)
{
    if(showFlow)
    showflow("Entering the function sentenceCase");
    stringstream ss(line);
    string newSentence;
    string word;
    bool firstWord = true;
    cout << endl << "Sentence case: ";

        while(ss >> word)
        {
        if(find(sensitiveWords.begin(), sensitiveWords.end(), word) !=sensitiveWords.end())
            { //keeps words unmodified
                string capitalize;
                for(char CA: word)
                {
                    capitalize += toupper(CA);
                }
                newSentence += capitalize + " ";
            }
        else {
                if(firstWord == true)
                word[0]=toupper(word[0]);

                if(firstWord == false)
                {
                    if(isalpha(word[0]))
                   {
                       word[0] = tolower(word[0]);
                   }
                   else {
                       for(int i=1; i <word.length(); i++)
                            {
                                if(isalpha(word[i]))
                                word[i] =tolower(word[i]);
                            }
                       }
                }
                firstWord =false;
            newSentence += word + " ";
            }
        }
            cout << newSentence << endl;
// for debugger
    if(showFlow)
    showflow("Leaving the function sentenceCase");
}

//case 3
void toggleCase(string line)
{
    if (showFlow) {
        showflow("Entering the function toggleCase");
    }

    stringstream ss(line);
    string newSentence;
    string word;

    while (ss >> word)
    {
    if (find(sensitiveWords.begin(), sensitiveWords.end(), word) != sensitiveWords.end())
    { //keeps words unmodified
                string capitalize;
                for(char CA: word)
                {
                    capitalize += toupper(CA);
                }
                newSentence += capitalize + " ";
            }
        else {
            // process the word
            bool firstWord = true;
            for (int i = 0; i < word.size(); i++)
                {
                char c = word[i];
                if (isalpha(c) || isdigit(c))
                {
                    if (firstWord)
                    {
                        word[i] = tolower(c);
                    }
                        else {
                            word[i] = toupper(c);
                             }
                firstWord = false;
                }
                 else{
                        firstWord = true;
                     }
                }
            newSentence += word + " ";
        }
    }
    cout << endl << "Toggle Case: " << newSentence << endl;
// for debugger
    if (showFlow) {
        showflow("Leaving the function toggleCase");
    }
}


// optional: SPECIAL
void convertText(string line)
{
    if(showFlow)
        showflow("Entering convertText");
    stringstream ss(line);
    string newSentence;
    string word;
    int textChangeOption;
    cout << endl << "input 1 for title case. " << endl;
    cout << "input 2 for sentence case. " << endl;
    cout << "input 3 for toggle case. " << endl;
    cout << "input 4 for all three at the same time. " << endl;
    cin >> textChangeOption;
    switch(textChangeOption)
        {
        case 1: // capitalize first of every word <-- title case
          titleCase(line);
            break;
        case 2: // capitalize first character of line<-- sentence case
            sentenceCase(line);
            break;
        case 3: // capitalize others except first letter of every word<-- toggle case
            toggleCase(line);
            break;
        case 4: //does all three sentences
            titleCase(line);
            sentenceCase(line);
            toggleCase(line);
            break;
        default:
            cout << "Goodbye." << endl;
            exit(0);
        }
    if(showFlow)
    showflow("Leaving the function convertText");
}

int main()
{
    ifstream inputFile("TongueTwisters.txt"); // covers #1 in rubric
    string line;
    char caseChoice;
    cout << endl << setw(50) << "Tongue Twisters" << endl << endl;
    cout << "*inputFile should be named TongueTwisters.txt*" << endl;
    if(inputFile.is_open())
    {
    cout << "Look out for these words that cannot be modified!" << endl;
    for(int i=0; i < sensitiveWords.size(); i++)
    {
        cout << sensitiveWords[i] << " " << endl;
    }
    cout << endl << "Would you like case options (type Y), just run the program with no stop (Type N)" << endl << "or anything else to quit program. " << endl ;
    cin >> caseChoice;
    if(caseChoice =='Y' || caseChoice == 'y')
    {
        while(getline(inputFile, line)) // covers #3 in rubric
        {
        cout << line << endl; // covers #4
        saveWords(line);// saves word and counts words <<--covers #2 & #5 in rubric
        findSpaces(line);// covers #7
        elim_spaces(line);// eliminates spaces and counts characters << covers #4
        findPunc(line); //covers #7
        findVowels(line);// covers #7 with consonants and any other characters
        convertText(line); //if user wants to look at the sentence one by one
        cout << "<------------------------------------------------------------------------->" << endl;

        }
    }
    else if(caseChoice == 'N' || caseChoice == 'n')
    {
        while(getline(inputFile, line)) // covers #3 in rubric
        {
        cout << line << endl; // covers #4
        saveWords(line);// saves word and counts words <<--covers #2 & #5 in rubric
        findSpaces(line);// covers #7
        elim_spaces(line);// eliminates spaces and counts characters << covers #4
        findPunc(line); //covers #7
        findVowels(line);// covers #7 with consonants and any other characters
         //the user just wants an output
        titleCase(line);
        sentenceCase(line);
        toggleCase(line);
        cout << endl;
        cout << "<------------------------------------------------------------------------->" << endl;

        }
    }


    inputFile.close();
    }
    else {
        cout << "cannot open file: TongueTwisters.txt" << endl;
        }

    return 0;
}
