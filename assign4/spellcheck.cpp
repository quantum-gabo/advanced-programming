#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  Corpus res;
  // Get all the white space pointers 
  auto white_space_pointers = find_all(source.begin(), source.end(), isspace);
  
  // Get the tokens 
  std::transform(white_space_pointers.begin(), white_space_pointers.end()-1, 
                 white_space_pointers.begin() + 1, std::inserter(res, res.end()), [&source](auto a, auto b){
    return Token(source, a, b);
  });


  // Remove empty tokens 
  std::erase_if(res,  [](Token a){return a.content.empty();});
  return res;
}


// Misspell check
std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto view = source 
  | rv::filter([&dictionary](Token a) { return !dictionary.contains(a.content); })
  | rv::transform([&dictionary](Token a) {
      auto suggestions = dictionary 
        | rv::filter([&](std::string dic) { return levenshtein(a.content, dic) == 1; })
        | rv::transform([](std::string s) { return s; });  
      std::set<std::string> set_suggestions(suggestions.begin(), suggestions.end());
      return Mispelling(a, set_suggestions);  
    })
  | rv::filter([](const Mispelling& m) { return !m.suggestions.empty(); });  

  return std::set<Mispelling>(view.begin(), view.end());
}
/* Helper methods */
#include "utils.cpp"
