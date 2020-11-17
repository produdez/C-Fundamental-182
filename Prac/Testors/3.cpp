#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

std::string reverseInParentheses(std::string s);
void showstack(stack <int> s) ;

int main()
{
    reverseInParentheses("aaa(aa(bxa))bbb");

}



void showstack(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

std::string reverseInParentheses(std::string s) { //SOLUTION!!
  stack <int> st;
  for (int i = 0; i < s.size(); ++i) {
        cout<<s<<endl;

    if (s[i] == '(')
      st.push(i);
    if (s[i] == ')') {
      int start = st.top(); st.pop();
      reverse(s.begin() + start + 1, s.begin() + i);
    }
  }
  string ans;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] !=  '(' && s[i] != ')')
      ans = ans + s[i];
  return ans;
}
