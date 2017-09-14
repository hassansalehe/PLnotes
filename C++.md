# Notes for the C++ Programming Language.


 | Consise | Minimal  | Simple, illustrative examples |
 | ------- | ---------- | --------------------------- |

### String Manipulation

###### 1. Finding first match
1. Use `find()` function of string. If no result found, `std::npos (-1) is returned`:
```cpp
size_type idx = myStr.find( str, size_type pos = 0 );	
idx = myStr.find( charPtr, pos, count );
idx = myStr.find( charPtr, pos = 0 );
idx = myStr.find( charC, pos = 0 );
```
2. For a set of characters you want to get first match of one of them, use `find_first_of`.
Its arguments format is the same as of `find`.

3. For finding the last match from the string, use `rfind()`
```cpp
idx = myStr.rfind( str, size_type pos = npos );	
idx = myStr.rfind( charPtr, pos, count );
idx = myStr.rfind( charPtr, pos = npos );
idx = myStr.rfind( charC, pos = npos );
```

4. `find_last_of` works in similar manner to `find_first_of` but from the end of the string.

##### 1. Getting a substring
```cpp 
//1. get 'count' number of characters, starting at startPos
string substring = myString.substr( startPos, count );

//2. get substring starting from startPos till the end of the string
string tillEnd = myString.substr( startPos ); // [startPos, size())

// Note: 1. Exception is thrown if startPos >= myString.size(). 
//       2. Complexity is linear.
```

##### 2. Appending string/characters
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

##### 3. Comparing strings
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

##### 4. Converting to lower/upper case

##### 5. Convert string representation to numeral
```cpp
int  v = stoi( str, posPtr, base );
int  v = stoi( str, posPtr, base );
long v = stol( str, posPtr, base );
long v = stol( str, posPtr, base );
long long v = stoll( str, posPtr, base );
long long v = stoll( str, posPtr, base );

int  v = atoi( charPtr );
long v = atol( charPtr );
long long v atoll( charPtr );

Note: 1. posPtr is for holding number of characters processed. 
      2. base(10) and posPtr(0) are optional. 
      3. stoul() and stoull() are for returning unsigned version of numbers.
      4. stof/stod/stold for float, double and long double. 
      5. Exceptions are through in case of failure.
```

##### 6. Numeral to string representation 
1. Use `std` function `to_string()` to convert any number to string.
```cpp
// accepts int, long, llong, ulong, ullong, float, double, long double
std::string stringRep = std::to_string( value );

Note: May throw bad_alloc in case of failure allocate memory in string constructor.
```
2. Also, you can use `std::sprintf(buff, format, value)`
```cpp
// buff is char *, format is one of "%d", "%ld", "%lld", "%u", "%lu", "%llu", "%f", "%Lf".
// Result is stored in buff
char buff[20];
std::fprintf(buff, "%d", 20170309);
```

##### 5. Sorting characters
* You use `sort()` from `#include<algorithm>`
* ``` std::sort(myStr.begin(), myStr.end());```

##### 6. Reverse string
* You use `reverse()` from `#include<algorithm>`
* ``` std::reverse(myStr.begin(), myStr.end());```


##### 9. Remove duplicate characters

##### 10. [Splitting](https://goo.gl/72PTXP) string


### Algorithms
Algorithms which are found in `algorithm` library. Algorithms operate on 
range of elements `(first, last)` which is the range `[first, last)`.

##### 1. Non-modifying sequence operations 
* 


