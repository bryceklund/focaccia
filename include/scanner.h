#ifndef focaccia_scanner_h
#define focaccia_scanner_h

typedef enum {
  // Single-character tokens
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_BRACK,
  TOKEN_RIGHT_BRACK,
  TOKEN_COMMA,
  TOKEN_DOT,
  TOKEN_MINUS,
  TOKEN_PLUS,
  TOKEN_SLASH,
  TOKEN_STAR,
  TOKEN_SEMICOLON,

  // One or two character tokens
  TOKEN_BANG,
  TOKEN_BANG_EQUAL,
  TOKEN_EQUAL,
  TOKEN_EQUAL_EQUAL,
  TOKEN_GREATER,
  TOKEN_GREATER_EQUAL,
  TOKEN_LESS,
  TOKEN_LESS_EQUAL,
  TOKEN_SLASH_STAR,
  TOKEN_STAR_SLASH,

  // Literals
  TOKEN_IDENTIFIER,
  TOKEN_STRING,
  TOKEN_NUMBER,

  // Keywords
  TOKEN_CLASS,
  TOKEN_FN,
  TOKEN_IF,
  TOKEN_ELSE,
  TOKEN_FALSE,
  TOKEN_TRUE,
  TOKEN_FOR,
  TOKEN_WHILE,
  TOKEN_AND,
  TOKEN_OR,
  TOKEN_NULL,
  TOKEN_SUPER,
  TOKEN_THIS,
  TOKEN_VAR,
  TOKEN_PRINT,
  TOKEN_RETURN,

  TOKEN_ERROR,
  TOKEN_EOF
} TokenType;

typedef struct {
  TokenType type;
  const char *start;
  int length;
  int line;
} Token;

void initScanner(const char *source);
Token scanToken();

#endif
