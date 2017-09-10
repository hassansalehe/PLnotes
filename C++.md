# Notes for the C++ Programming Language.
* Consice
* Minimal
* Simple illustrative examples

### String Manipulation

##### Getting a substring
```cpp 
//1. get 'count' number of characters, starting at startPos
string substring = myString.substr( startPos, count );

//2. get substring starting from startPos till the end of the string
string tillEnd = myString.substr( startPos ); // [startPos, size())

// Note: 1. Exception is thrown if startPos >= myString.size(). 
//       2. Complexity is linear.
```

#####  Appending string/characters
```cpp
// append a copy of otherStr
string & modifiedStr = myStr.append( otherStr );

// append a copy of substring of otherStr from startPos by count number of characters
string & modifiedStr = myStr.append( otherStr, startPos, count );

// append characters from null-terminated char array
string & modifiedStr = myStr.append( charPtr );

// append 'count' characters from char array
string & modifiedStr = myStr.append( charPtr, count );

// append character c ntimes
string & modifiedStr = myStr.append( ntimes, charC );

// use iterator to append characters from a different string in same order
string & modifiedStr = myStr.append( iterFirst, iterLast );

// appends characters from initializer list, in same order
string & modifiedStr = myStr.append( initializer_char_list );

// Note: 1. The return value is always "*this".
//       2. See also operator+=, push_back( charC )
```

##### Comparing strings
The main function is `compare(...)`. It returns 
* `= 0:` two strings are equal.
* `< 0:` value of 1st char that does'nt match is lower in comparedStr, or comparedStr is shorter.
* `> 0:` value of 1st char that does'nt match is greater in comparedStr, , or comparedStr is longer.
```cpp
int res = comparedStr.compare( comparingStr );
int res = comparedStr.compare( comparedPos, len, comparingStr );
int res = comparedStr.compare( comparedPos, len, comparingStr, comparingPos, comparingLen );
int res = comparedStr.compare( comparingCharPtr );
int res = comparedStr.compare( comparedPos, len, comparingCharPtr );
int res = comparedStr.compare( comparedPos, len, comparingCharPtr, len);

// Note: !=, <, >, ===, etc, are supported.
```

##### Converting to lower/upper case
