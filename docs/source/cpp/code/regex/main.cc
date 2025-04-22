// g++ -std=c++11 ./main.cc
#include <algorithm>
#include <cctype>
#include <codecvt>
#include <iostream>
#include <locale>
#include <regex>
#include <string>

std::string ToLowerCase(const std::string &s) {
  std::string ans(s.size(), 0);
  std::transform(s.begin(), s.end(), ans.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return ans;
}

std::wstring ToWideString(const std::string &s) {
  // see
  // https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.from_bytes(s);
}

std::string ToString(const std::wstring &s) {
  // see
  // https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.to_bytes(s);
}

int32_t main() {
  std::string s = "你(好)吗，HoW    are You doIng?  包含\"中文\"和'英文'。are "
                  "you ok? 谢谢!好的;说:一句话…也“可以”";
  std::cout << s << "\n";

  std::vector<std::pair<std::string, std::string>> replace_str_pairs = {
      {"，", ","}, {"；", ";"}, {"。", "."}, {"！", "!"}, {"\\s+", " "},
  };
  for (const auto &p : replace_str_pairs) {
    std::regex re(p.first);
    s = std::regex_replace(s, re, p.second);
  }
  std::cout << s << "\n";

  s = ToLowerCase(s);

  std::cout << s << "\n";

  auto ws = ToWideString(s);

  s = ToString(ws);
  std::cout << s << "\n";

  // https://en.cppreference.com/w/cpp/regex
  // https://stackoverflow.com/questions/37989081/how-to-use-unicode-range-in-c-regex
  std::string expr =
      "([;:,.?!'\"…\\(\\)“”])|([\\u4e00-\\u9fff]+)|([\\u0000-\\u007f]+)";

  std::wstring wexpr = ToWideString(expr);
  std::wregex we(wexpr);

  auto begin = std::wsregex_iterator(ws.begin(), ws.end(), we);
  auto end = std::wsregex_iterator();
  for (std::wsregex_iterator i = begin; i != end; ++i) {
    std::wsmatch match = *i;
    std::wstring match_str = match.str();
    auto ms = ToString(match_str);
    uint8_t c = reinterpret_cast<const uint8_t *>(ms.data())[0];
    if (c < 0x80) {
      std::cout << "Non-Chinese: " << ms << "\n";
    } else {
      std::cout << "Chinese: " << ms << "\n";
    }
  }

  return 0;
}
/*
你好吗，HoW    are You doIng?  包含中文和英文。are you ok? 谢谢
你好吗,HoW are You doIng? 包含中文和英文.are you ok? 谢谢
你好吗,how are you doing? 包含中文和英文.are you ok? 谢谢
你好吗,how are you doing? 包含中文和英文.are you ok? 谢谢
Chinese: 你好吗
Non-Chinese: ,how are you doing?
Chinese: 包含中文和英文
Non-Chinese: .are you ok?
Chinese: 谢谢
 */
