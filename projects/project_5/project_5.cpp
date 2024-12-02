#include <initializer_list>
#include <iostream>
#include <cassert>

/**********************************************************************************
 * README
 * ********************************************************************************
 * This starter code is a skeleton of the Set and Node classes.
 * You can modify this code to create your project_5 submission.
 * Any main() function or output will be ignoed by testing software.
 * A testing main() can be found on Learn.
 *
 * From Project 5 Specification: 2.1 Development Stratigies
 * "First, implement the node class and all of its member functions. This should be
 *  straight-forward from the course notes, as they are the sam member functions as
 *  for a linked list.
 *
 *  Second, start with a skeleton, where each member function is defined, but where
 *  the default values of the return type is returned. ..."
 *
 * The skeleton has been povided (below) for you to modify.
 */

class Set;
class Node;
std::ostream &operator<<(std::ostream &out, Set const &rhs);

/////////////////////////////
/// Set class declaration ///
/////////////////////////////
class Set
{
public:
  Set(std::initializer_list<int> initial_values);
  ~Set();

  // The instructions will describe exactly what to do
  Set(Set const &orig);
  Set(Set &&orig);

  // The instructions will describe exactly what to do
  Set &operator=(Set const &orig);
  Set &operator=(Set &&orig);

  // Size operations
  bool empty() const;
  std::size_t size() const;

  // Clear all items out of the set
  void clear();

  // Find the value item in the set
  //  - Return the address of the node if found,
  //    and nullptr otherwise.
  Node *find(int const &item) const;

  // Insert the item into the set if it
  // is not already in the set.
  //  - Return 1 if the item is new,
  //    and 0 otherwise.
  std::size_t insert(int const &item);

  // Insert all the items in the array
  // from array[begin] to array[end - 1]
  // that are not already in the set.
  //  - Return the number of items inserted
  //    into the set.
  std::size_t insert(int const array[],
                     std::size_t const begin,
                     std::size_t const end);

  // Remove the item from the set and
  // return the number of items removed.
  std::size_t erase(int const &item);

  // Move any items from 'other', whose values
  // do not appear in 'this', to 'this'
  // Leave any items that already appear
  // in 'this' and 'other' in 'other'.
  std::size_t merge(Set &other);

  // Set operations
  Set &operator|=(Set const &other);
  Set &operator&=(Set const &other);
  Set &operator^=(Set const &other);
  Set &operator-=(Set const &other);

  Set operator|(Set const &other) const;
  Set operator&(Set const &other) const;
  Set operator^(Set const &other) const;
  Set operator-(Set const &other) const;

  // Returns 'true' if the 'other' set
  // is a subset of 'this' set; that is,
  // all entries in the 'other' set are
  // also in this set.
  bool operator<=(Set const &other) const;
  bool operator>=(Set const &other) const;
  bool operator<(Set const &other) const;
  bool operator>(Set const &other) const;

  bool operator==(Set const &other) const;
  bool operator!=(Set const &other) const;

private:
  Node *p_head_;

  friend std::ostream &operator<<(std::ostream &out, Set const &rhs);
};

///////////////////////////////
/// Node class declaration  ///
///////////////////////////////
class Node
{
public:
  Node(int new_value, Node *new_next);
  int value() const;
  Node *next() const;

private:
  int value_;
  Node *next_;

  // Allow any member function in the class
  // 'Set' to access or modify the member
  // variables of any instance of this class.
  friend class Set;
};

///////////////////////////////
/// Node class Definition   ///
///////////////////////////////

// Node constructor
Node::Node(int new_value, Node *new_next)
{
  value_ = new_value;
  next_ = new_next;
}

int Node::value() const
{
  return value_;
}

Node *Node::next() const
{
  return next_;
}

///////////////////////////////
/// Set class definition    ///
///////////////////////////////

// Initializing constructor
Set::Set(std::initializer_list<int> initial_values) : p_head_{nullptr}
{
  for (int const &value : initial_values) // like a foreach loop in java
    insert(value);
}

// Destructor
Set::~Set()
{
  clear();
}

// Copy constructor
Set::Set(Set const &orig)
{
  p_head_ = nullptr; // possibly made a memory leak, look into later
  for (Node *ptr{orig.p_head_}; ptr != nullptr; ptr = ptr->next())
  {
    // Call 'insert(...)' with the value returned by ptr->value()
    insert(ptr->value());
  }
}

// Move constructor
Set::Set(Set &&orig)
{
  p_head_ = orig.p_head_;
  orig.p_head_ = nullptr;
}

// Copy assignment
Set &Set::operator=(Set const &orig)
{
  if (this != &orig)
  {
    clear();
    Node *p_temp{orig.p_head_};
    while (p_temp != nullptr)
    {
      insert(p_temp->value());
      p_temp = p_temp->next();
    }
  }
  return *this;
}

// Move assignment
Set &Set::operator=(Set &&orig)
{
  if (this != &orig)
  {
    p_head_ = orig.p_head_;
    orig.p_head_ = nullptr;
  }
  return *this;
}

// Empty
bool Set::empty() const
{
  return (p_head_ == nullptr);
}

// Size
size_t Set::size() const
{
  size_t count{0};
  Node *p_temp{p_head_};
  while (p_temp != nullptr)
  {
    p_temp = p_temp->next();
    count++;
  }
  return count;
}

// Clear
void Set::clear()
{
  Node *p_current = p_head_;
  while (p_current != nullptr)
  {
    Node *nextNode = p_current->next();
    delete p_current;
    p_current = nextNode;
  }
  p_head_ = nullptr;
}

// Find
Node *Set::find(int const &item) const
{
  Node *p_temp{p_head_};
  while (p_temp != nullptr)
  {
    if (item == p_temp->value())
      return p_temp;
    p_temp = p_temp->next();
  }
  return nullptr;
}

// Insert the item into the set
std::size_t Set::insert(int const &item)
{
  if (find(item) == nullptr) // i.e that value is not in the list
  {
    Node *newNode = new Node(item, nullptr); // Stores on heap instead of locally, thus no var deallocating issues
    if (p_head_ == nullptr)
    {
      p_head_ = newNode;
    }
    else
    {
      Node *p_current = p_head_;
      while (p_current->next() != nullptr)
      {
        p_current = p_current->next();
      }
      p_current->next_ = newNode;
    }
    return 1;
  }
  return 0;
}

// Insert all the items in the array
std::size_t Set::insert(int const array[],
                        std::size_t const begin,
                        std::size_t const end)
{
  size_t totIn{0};
  for (size_t i{begin}; i < end; i++)
  {
    if (insert(array[i]))
      totIn++;
  }
  return totIn;
}

// Remove the item from the set and
// return the number of items removed.
std::size_t Set::erase(int const &item)
{
  if (find(item) != nullptr) // in the linked list
  {
    size_t totRemoved{0};
    while (find(item) != nullptr)
    {
      Node *p_current{p_head_};
      if (find(item) == p_head_)
      {
        totRemoved++;
        Node *p_temp{p_head_->next()};
        delete p_head_;
        p_head_ = p_temp;
        break;
      }
      while (p_current->next()->value() != item)
      {
        p_current = p_current->next();
      }
      Node *p_temp{p_current->next()};
      p_current->next_ = find(item)->next();
      delete p_temp;
      totRemoved++;
    }
    return totRemoved;
  }
  return 0;
}

// Move any items from 'other', whose values
// do not appear in 'this', to 'this'.
// Leave any items that already appear
// in both sets, in both sets.
std::size_t Set::merge(Set &other)
{
  /*
  std::size_t count{0};
  Node *p_current{other.p_head_};
  while (p_current != nullptr)
  {
    if (find(p_current->value()) == nullptr) // just in other list
    {
      insert(p_current->value());
      Node *p_temp{p_current};
      p_current = p_current->next();
      other.erase(p_temp->value());
      count++;
    }
    else
      p_current = p_current->next();
  }
  */
   std::size_t count{0};
  Node *p_current{other.p_head_};
  Node *p_prev{nullptr};

  while (p_current != nullptr)
  {
    if (find(p_current->value()) == nullptr) // just in other list
    {
      Node *to_move = p_current;
      p_current = p_current->next();

      if (p_prev == nullptr)
        other.p_head_ = p_current;
      else
        p_prev->next_ = p_current;
      
      to_move->next_ = p_head_;
      p_head_ = to_move;

      count++;
    }
    else
    {
      p_prev = p_current;
      p_current = p_current->next();
    }
  }
  return count;
}

//////////////////////
/// Set operations ///
//////////////////////
Set &Set::operator|=(Set const &other)
{
  Node *p_current{other.p_head_};
  while (p_current != nullptr)
  {
    insert(p_current->value());
    p_current = p_current->next();
  }
  return *this;
}

Set &Set::operator&=(Set const &other)
{
  Node *p_current{p_head_};
  while (p_current != nullptr)
  {
    if (other.find(p_current->value()) == nullptr) // in first set, not second
    {
      Node *p_temp{p_current};
      p_current = p_current->next();
      erase(p_temp->value());
    }
    else
      p_current = p_current->next();
  }
  return *this;
}

Set &Set::operator^=(Set const &other)
{
  Node *p_current{other.p_head_};
  while (p_current != nullptr)
  {
    if (find(p_current->value()) != nullptr)
    {
      Node *p_temp{p_current};
      p_current = p_current->next();
      erase(p_temp->value());
    }
    else
    {
      insert(p_current->value());
      p_current = p_current->next();
    }
  }
  return *this;
}

Set &Set::operator-=(Set const &other)
{
  Node *p_current{other.p_head_};
  while (p_current != nullptr)
  {
    if (find(p_current->value()) != nullptr) // in both sets
      erase(p_current->value());
    p_current = p_current->next();
  }
  return *this;
}

Set Set::operator|(Set const &other) const
{
  Set tmp{*this};
  tmp |= other;
  return tmp;
}

Set Set::operator&(Set const &other) const
{
  Set tmp{*this};
  tmp &= other;
  return tmp;
}

Set Set::operator^(Set const &other) const
{
  Set tmp{*this};
  tmp ^= other;
  return tmp;
}

Set Set::operator-(Set const &other) const
{
  Set tmp{*this};
  tmp -= other;
  return tmp;
}

// Returns 'true' if the 'other' set
// is a subset of 'this' set; that is,
// all entries in the 'other' set are
// also in this set.
bool Set::operator>=(Set const &other) const
{
  Node *p_current{other.p_head_};
  while (p_current != nullptr)
  {
    if (find(p_current->value()) == nullptr)
      return false;
    p_current = p_current->next();
  }
  return true;
}

bool Set::operator<=(Set const &other) const
{
  Node *p_current{p_head_};
  while (p_current != nullptr)
  {
    if (other.find(p_current->value()) == nullptr)
      return false;
    p_current = p_current->next();
  }
  return true;
}

bool Set::operator>(Set const &other) const
{
  if (*this >= other)
  {
    Node *p_current{p_head_};
    while (p_current != nullptr)
    {
      if (other.find(p_current->value()) == nullptr)
        return true;
      p_current = p_current->next();
    }
  }
  return false;
}

bool Set::operator<(Set const &other) const
{
  return (other > *this);
}

bool Set::operator==(Set const &other) const
{
  if (*this >= other && other >= *this)
    return true;
  return false;
}

bool Set::operator!=(Set const &other) const
{
  if (*this >= other && other >= *this)
    return false;
  return true;
}

////////////////////////////////////////////
/// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
/// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream &operator<<(std::ostream &out, Set const &rhs)
{
  out << "{";
  if (!rhs.empty())
  {
    out << rhs.p_head_->value();
    for (Node *ptr{rhs.p_head_->next()}; ptr != nullptr; ptr = ptr->next())
    {
      out << ", " << ptr->value();
    }
  }
  out << "}";

  return out;
}