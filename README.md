# String Tokenizer

## 함수: `char **get_tokenized_array(const char *str)`

이 함수는 문자열을 매개변수로 받아, 이를 토큰화하고 토큰들의 배열을 반환합니다.

### 매개변수:

`const char *str`: 토큰화될 상수 문자열 포인터입니다.
### 반환:

문자열들(토큰)의 배열에 대한 포인터를 반환합니다. 함수 실행 도중 어떤 오류가 발생하면 (예: `malloc` 실패), 함수는 `NULL`을 반환합니다.

---

## 함수: `int get_number_of_tokens(const char *str)`

이 함수는 주어진 문자열에서 토큰의 수를 계산합니다.

### 매개변수:

`const char *str`: 토큰화될 상수 문자열 포인터입니다.
### 반환:

제공된 문자열에서 토큰의 수를 나타내는 정수를 반환합니다.

---

## 함수: `char *get_next_token(const char **str)`

이 함수는 제공된 문자열에서 다음 토큰을 가져옵니다.

### 매개변수:

`const char **str`: 상수 문자열 포인터에 대한 포인터입니다. 이 함수는 원본 문자열 포인터(`*str`)를 토큰 다음의 문자를 가리키도록 업데이트합니다.
### 반환:

문자열에서 다음 토큰을 가리키는 포인터를 반환합니다. 함수 실행 중에 오류가 발생하면 (예: `malloc` 실패), 함수는 `NULL`을 반환합니다.

---

## 함수: `int push_to_the_next_token(const char **str)`

이 함수는 문자열 포인터를 문자열의 다음 토큰 시작 부분으로 밀어냅니다.

### 매개변수:

`const char **str`: 상수 문자열 포인터에 대한 포인터입니다. 이 함수는 원본 문자열 포인터(`*str`)를 다음 토큰의 시작을 가리키도록 업데이트합니다.
### 반환:

다음 토큰의 길이를 나타내는 정수를 반환합니다.

---

## Function: `char **get_tokenized_array(const char *str)`

This function takes a string as an argument, tokenizes it, and returns an array of these tokens.

### Parameters:

`const char *str`: A constant string pointer which will be tokenized.
### Return:

Returns a pointer to an array of strings (tokens). If any error occurs during the function execution (e.g., if `malloc` fails), the function returns `NULL`.

---

## Function: `int get_number_of_tokens(const char *str)`

This function calculates the number of tokens in a given string.

### Parameters:

`const char *str`: A constant string pointer that represents the string to be tokenized.
### Return:

Returns an integer representing the number of tokens in the provided string.

---

## Function: `char *get_next_token(const char **str)`

This function gets the next token from the provided string.

### Parameters:

`const char **str`: A pointer to a constant string pointer. The function will update the original string pointer (`*str`) to point at the character following the token.
### Return:

Returns a pointer to the next token in the string. If any error occurs during the function execution (e.g., if `malloc` fails), the function returns `NULL`.

---

## Function: `int push_to_the_next_token(const char **str)`

This function pushes the string pointer to the start of the next token in the string.

### Parameters:

`const char **str`: A pointer to a constant string pointer. The function will update the original string pointer (`*str`) to point at the start of the next token.
### Return:

Returns an integer representing the length of the next token.
