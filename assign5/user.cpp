#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

std::ostream& operator<< (std::ostream& os, const User& user) {
    os << "User(name=" << user.get_name() << ", friends=[";
    for (size_t i = 0; i < user.size(); ++i) {
        os << user._friends[i];
        if (i < user.size() - 1) {
            os << ", ";
        }
    }
    os << "])";
    return os;
}

/* 
    * Destructor for the User class.
*/
User::~User() {
    delete[] _friends; // Safe: matches new[]
}
/*
    * Copy constructor for the User class.
*/
User::User(const User& user) 
    : _name(user._name), _size(user._size), _capacity(user._capacity) {
    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _friends[i] = user._friends[i];
    }
}

/*
Copy assignment operator for the User class.
*/
User& User::operator=(const User& user) {
    if (this == &user) {
        return *this; // Handle self-assignment
    }
    // Allocate new memory first
    std::string* newFriends = new std::string[user._capacity];

    // Copy the data from the user object
    for (size_t i = 0; i < user._size; ++i) {
        newFriends[i] = user._friends[i];
    }
    // Delete the old memory
    delete[] _friends;

    // Copy the data from the user object
    _name = user._name;
    _size = user._size;
    _capacity = user._capacity;
    _friends = newFriends;

    return *this;
}

/*
    * Operator += for adding a friend to the User class.
    must be symmetric (i.e., if A += B, then automatically B += A)
*/
User& User::operator+=(User& new_friend) {
    // Check if the new friend is the same as this user
    if (this == &new_friend) {
        return *this; // No self-friendship
    }
    // Check if the friend is already in the list
    for (size_t i = 0; i < _size; ++i) {
        if (_friends[i] == new_friend.get_name() && &new_friend != this) {
            return *this; // Friend already exists, no need to add
        }
    }

    // Check if this user is already in the new friend's friend list
    for (size_t i = 0; i < new_friend._size; ++i) {
        if (new_friend._friends[i] == _name && &new_friend != this) {
            return *this; // Already mutual friends
        }
    }

    // Add the new friend
    add_friend(new_friend.get_name());
    new_friend.add_friend(_name); // Add this user as a friend to the new friend

    return *this;
}

/*
    * Operator < for comparing two users.
*/
bool User::operator<(const User& rhs) const {
    return _name < rhs._name; // Compare based on names
}