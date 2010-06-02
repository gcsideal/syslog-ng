#include "block-ref-parser.h"
#include "block-ref-grammar.h"

extern int block_ref_debug;
int block_ref_parse(CfgLexer *lexer, CfgArgs **node);

static CfgLexerKeyword block_ref_keywords[] = {
  { CFG_KEYWORD_STOP },
};

CfgLexerKeyword *block_def_keywords = block_ref_keywords;

CfgParser block_ref_parser =
{
  .debug_flag = &block_ref_debug,
  .name = "block reference",
  .context = LL_CONTEXT_BLOCK_REF,
  .keywords = block_ref_keywords,
  .parse = (gint (*)(CfgLexer *, gpointer *)) block_ref_parse,
};

CFG_PARSER_IMPLEMENT_LEXER_BINDING(block_ref_, CfgArgs **)
