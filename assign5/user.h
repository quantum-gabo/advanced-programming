/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  friend std::ostream& operator<<(std::ostream& os, const User& user);

  // Destructor
    ~User();

    // Copy constructor
    User(const User& user);

    // Copy assignment operator
    User& operator=(const User& user);

    // Move constructor
    User(User&& user) = delete; // Disable move constructor

    // Move assignment operator
    User& operator=(User&& user) = delete; // Disable move assignment

    // Operator += for adding a friend
    User& operator+=(User& new_friend);

    // Operator < for comparing two users
    bool operator<(const User& rhs) const;


private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};