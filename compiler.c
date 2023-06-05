#include <stdio.h>

#include "common.h"
#include "compiler.h"
#include "scanner.h"

typedef struct parser_t
{
  token_t current;
  token_t previous;
  bool had_error;
  bool panic_mode;
} parser_t;

parser_t parser;

static void error_at(token_t *token, const char *message)
{
  if (parser.panic_mode)
    return;

  parser.panic_mode = true;
  fprintf(stderr, "[line %d] Error", token->line);

  if (token->type == TOKEN_EOF)
  {
    fprintf(stderr, " at end");
  }
  else if (token->type == TOKEN_ERROR)
  {
    // NOTHING
  }
  else
  {
    fprintf(stderr, "at '%.*s'", token->length, token->start);
  }

  fprintf(stderr, ": %s\n", message);
  parser.had_error = true;
}

static void error(const char *message)
{
  error_at(&parser.current, message);
}

static void error_at_current(const char *message)
{
  error_at(&parser.current, message);
}

bool compile(const char *source, chunk_t *chunk)
{
  init_scanner(source);
  parser.had_error = false;
  parser.panic_mode = false;
  advance();
  expression();
  consume(TOKEN_EOF, "Expect end of expression.");
  return !parser.had_error;
}

static void advance()
{
  parser.previous = parser.current;

  for (;;)
  {
    parser.current = scan_token();
    if (parser.current.type != TOKEN_ERROR)
      break;

    error_at_current(parser.current.start);
  }
}

static void consume(token_type_t type, const char *message)
{
  if (parser.current.type == type)
  {
    advance();
    return;
  }

  error_at_current(message);
}
