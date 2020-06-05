#include<bits/stdc++.h>
using namespace std;

string convert_to_upper(string &user)
{
    for (size_t i = 0; i < user.length(); i++)
    {
        user.at(i) = toupper(user.at(i));
    }
    return user;
}

void display_welcome_screen()
{
    cout << "************Welcome to Hangman By Shreyans************\n\n";
    cout << "Instructions for the game:\n";
    cout << "You have to guess the correct word\n\nNumber of blanks indicate the number of letters in that word";
    cout << "\n\nIf there is more than one word, space between the words is indicated by dash(-)\n\n";
    cout << "You can enter a dash(-) to see how many separate words are there\n\n";
    cout << "Everytime you enter a letter, all possible occurrences of that letter in the word will be shown\n\n";
    cout << "If the letter you entered does not appear in the word, that will be one strike\n\n";
    cout << "If the total number of strikes reaches 5, you lose.\n\n";
}

void display_category()
{
    string category[] {"1. Movies", "2. Books", "3. Cities", "4. Apps"};
    cout << "These are the different categories\n";
    size_t i = 0;
    for(i = 0; i < 4; i++)
    {
        cout << category[i] << "\n";
    }
}

string select_word(int option)
{
    if(option == 1)
    {
        string movies[] {"INCEPTION", "AVENGERS", "ZATHURA", "STARWARS", "BATMAN", "SUPERMAN", "SPIDERMAN",
        "IRONMAN", "PIKU", "BHOOTNATH", "SALT"};
        int random_number = rand() % 11;
        return movies[random_number];
    }

    if(option == 2)
    {
        string books[] {"GODFATHER", "HOBBIT", "THE-INVISIBLE-MAN", "THREE-MEN-IN-A-BOAT", "ANNE-FRANK",
        "GULLIVERS-TRAVELS", "HARRY-POTTER", "LORD-OF-THE-RINGS", "SHERLOCK-HOLMES", "HERCULE-POIROT",
        "THE-CATCHER-IN-THE-RYE"};
        int random_number = rand() % 11;
        return books[random_number];
    }

    if(option == 3)
    {
        string cities[] {"DELHI", "MUMBAI", "SURAT", "KOLKATA", "BHOPAL", "INDORE", "NAGPUR", "BANGALORE",
        "DEHRADUN", "PUNE", "HAZIRABAUG", "THIRUVANANTHAPURAM"};
        int random_number = rand() % 12;
        return cities[random_number];
    }

    if(option == 4)
    {
        string apps[] {"AMAZON", "GOOGLE", "FACEBOOK", "WHATSAPP", "INSTAGRAM", "TWITTER", "EVERNOTE",
        "PUBG", "ONE-DRIVE", "LINKEDIN", "PAYTM", "UBER", "TIKTOK", "ANYBOOKS"};
        int random_number = rand() % 14;
        return apps[random_number];
    }
}

string get_user_string(const string &correct_word, const char &user_input, string &user_string)
{
    for(size_t i = 0; i < correct_word.length(); i++)
    {
        if(correct_word.at(i) == user_input)
            user_string.at(2*i) = user_input;
    }
    return user_string;
}

void display_endgame(const bool &compare, const int &strikes_remaining, const string &correct_word)
{
    if(compare == 1)
        cout << "CONGRATS!!!!!!!YOU WON THE GAME!!!!!!\n\n";
    if(strikes_remaining == 0)
        cout << "SORRY........YOU LOST THE GAME.....\nCORRECT WORD WAS: " << correct_word << "\n\n";
}

bool compare_strings(const string &correct_word, const string &user_string)
{
    for(size_t i = 0; i < correct_word.length(); i++)
    {
        if(correct_word.at(i) != user_string.at(2 * i))
            return 0;
    }
    return 1;
}

void gameplay(const string &correct_word, string &user_string)
{
    int strikes_remaining = 5;
    bool compare = 0;
    while(strikes_remaining > 0 && compare == 0)
    {
        cout << "Enter a character or dash(-)";
        char user_input;
        cin >> user_input;
        user_input = toupper(user_input);
        bool check_user_input = (correct_word.find(user_input) < correct_word.length());
        if(check_user_input == 0)
            strikes_remaining--;
        user_string = get_user_string(correct_word, user_input, user_string);
        cout << user_string;
        cout << "\tStrikes Remaining: " << strikes_remaining << "\n\n";
        compare = compare_strings(correct_word, user_string);
    }
    display_endgame(compare, strikes_remaining, correct_word);
}

string get_user_string(const int &word_length)
{
    string user_string {};
    user_string.resize((2 * word_length) - 1, '$');
    for(size_t i = 0; i < (2 * word_length) - 1; i++)
    {
        if(i % 2 == 0)
            user_string.at(i) = '_';
        else
            user_string.at(i) = ' ';
    }
    return user_string;
}

int main(void)
{
    display_welcome_screen();
    string play_again {"YES"};
    while (play_again == "YES" || play_again == "Y")
    {
        display_category();
        cout << "\nSelect an option - 1/2/3/4\n";
        int option;
        cin >> option;
        const string correct_word = select_word(option);
        const int word_length = correct_word.length();
        cout << get_user_string(word_length);
        string user_string = get_user_string(word_length);
        gameplay(correct_word, user_string);
        cout << "Do you want to play again?\n";
        cin >> play_again;
        convert_to_upper(play_again);
        if(play_again == "NO" || play_again == "N")
        {
            cout << "GOODBYE AND HAVE A GOOD DAY!!\n\n********A SHREYANS SINGH PRODUCTION*******";
        }
    }
    return 0;
}
