#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <dirent.h>
#include <sstream>
#include <set>
#include <regex>
#include <vector>
#include <cctype>
using namespace std;

int main() 
{
    map<string,set<string>> word_map;
    set<string> docs ;
    string folder_name = "data";
    DIR* myfile = opendir(folder_name.c_str());
    struct dirent* folder;
    while ((folder = readdir(myfile)) != NULL) 
    {
        if (folder->d_type == DT_REG) 
        {
            ifstream file(folder_name + "/" + folder->d_name);
            string word;
            docs.insert(folder->d_name);
            while (file >> word) 
            {
                regex pattern("[^a-zA-Z0-9 ]");
                word = regex_replace(word, pattern, " ");
                istringstream iss(word);
                string word1;
                while (iss >> word1) 
                {
                    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
                    word_map[word1].insert(folder->d_name);
                }
            }
        }
    }
    closedir(myfile);


    //get input 
    string order ;
    getline(cin , order);
    istringstream iss(order);
    string word;
    set<string> finali;
    while(iss >> word)
    {
        if (word == "+")
        {
            iss >> word ;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word_map.find(word) != word_map.end())
            {
                set<string> files_word = word_map.find(word)->second;
                for (string s : files_word)
                {
                    finali.insert(s);
                }
            }
        }
        else if (word == "-")
        {
            iss >> word ;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word_map.find(word) != word_map.end())
            {
                set<string> files_word = word_map.find(word)->second;
                set<string> negative ;
                for (auto& str1 : docs) 
                {
                    bool find = false ;
                    for (const auto & str2 : files_word) 
                    {
                        if (str1 == str2)
                        {
                            find = true;
                            break;
                        }
                    }
                    if(find == false)
                    {
                        negative.insert(str1);
                    }
                }
                if(finali.size() == 0)
                {
                    for (auto& str : negative)
                    {
                        finali.insert(str);
                    }
                }
                else
                {
                    set<string> result ;
                    for (auto& str1 : finali) 
                    {
                        bool flag = false ;
                        for (const auto & str2 : files_word) 
                        {
                            if (str1 == str2)
                            {
                                flag = true ;
                                break;
                            }
                        }
                        if (flag == false)
                        {
                            result.insert(str1);
                        }
                    }
                    finali = result ;
                }

            }
            
        }
        else
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word_map.find(word) != word_map.end())
            {
                set<string> files_word = word_map.find(word)->second;
                if(finali.size() == 0)
                {
                    for (const auto & str : files_word) 
                    {
                        finali.insert(str);
                    }
                }
                else
                {
                    set<string> result ;
                    for (auto& str1 : finali) 
                    {
                        for (const auto & str2 : files_word) 
                        {
                            if (str1 == str2)
                            {
                                result.insert(str1);
                                break;
                            }
                        }
                    }
                    finali = result ;
                }
            }
        } 
    }
    cout << finali.size() << endl ;

    for (string s : finali)
    {
        cout << s << endl ;
    }    
    return 0;
}