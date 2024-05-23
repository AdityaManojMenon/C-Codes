#include <fstream>
#include <iostream>
#include <string>
#include <istream>

bool myLinter(std::istream &file) 
{
  std::string line;
  int count_parentheses = 0, count_brackets = 0;
  while(std::getline(file,line))
  {
    size_t FirstChar = line.find_first_not_of(" \t"); // trimming leading whitespace
    
    if(FirstChar == std::string::npos) //if it is an empty line
    {
      continue;
    }

    if(line[FirstChar] != 'S')
    {
      return false;
    }
    char last_character = line.back();
    if(last_character != '{' && last_character != '}' && last_character != '(' && last_character != ')' && last_character != ';')
    {
      return false;
    }
    for(char ch : line)
    {
      if(ch == '(')
      {
        ++count_parentheses;
      }
      if(ch == ')')
      {
        --count_parentheses;
      }
      if(ch == '{')
      {
        ++count_brackets;
      }
      if(ch == '}')
      {
        --count_brackets;
      }
    }
  }
  if(count_brackets != 0 || count_parentheses != 0)
  {
    return false;
  }

  return true;

}

int main() {
  // provided for your testing convenience
  return 0;
}