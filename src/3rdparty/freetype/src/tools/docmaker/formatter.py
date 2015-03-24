begin_unit
comment|'#'
nl|'\n'
comment|'#  formatter.py'
nl|'\n'
comment|'#'
nl|'\n'
comment|'#    Convert parsed content blocks to a structured document (library file).'
nl|'\n'
comment|'#'
nl|'\n'
comment|'#  Copyright 2002, 2004, 2007, 2008, 2014 by'
nl|'\n'
comment|'#  David Turner.'
nl|'\n'
comment|'#'
nl|'\n'
comment|'#  This file is part of the FreeType project, and may only be used,'
nl|'\n'
comment|'#  modified, and distributed under the terms of the FreeType project'
nl|'\n'
comment|'#  license, LICENSE.TXT.  By continuing to use, modify, or distribute'
nl|'\n'
comment|'#  this file you indicate that you have read the license and'
nl|'\n'
comment|'#  understand and accept it fully.'
nl|'\n'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# This is the base Formatter class.  Its purpose is to convert a content'
nl|'\n'
comment|"# processor's data into specific documents (i.e., table of contents, global"
nl|'\n'
comment|'# index, and individual API reference indices).'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# You need to sub-class it to output anything sensible.  For example, the'
nl|'\n'
comment|"# file `tohtml.py' contains the definition of the `HtmlFormatter' sub-class"
nl|'\n'
comment|'# to output HTML.'
nl|'\n'
comment|'#'
nl|'\n'
nl|'\n'
nl|'\n'
name|'from'
name|'sources'
name|'import'
op|'*'
newline|'\n'
name|'from'
name|'content'
name|'import'
op|'*'
newline|'\n'
name|'from'
name|'utils'
name|'import'
op|'*'
newline|'\n'
nl|'\n'
nl|'\n'
comment|'################################################################'
nl|'\n'
comment|'##'
nl|'\n'
comment|'##  FORMATTER CLASS'
nl|'\n'
comment|'##'
nl|'\n'
DECL|class|Formatter
name|'class'
name|'Formatter'
op|':'
newline|'\n'
nl|'\n'
DECL|member|__init__
indent|'    '
name|'def'
name|'__init__'
op|'('
name|'self'
op|','
name|'processor'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'self'
op|'.'
name|'processor'
op|'='
name|'processor'
newline|'\n'
name|'self'
op|'.'
name|'identifiers'
op|'='
op|'{'
op|'}'
newline|'\n'
name|'self'
op|'.'
name|'chapters'
op|'='
name|'processor'
op|'.'
name|'chapters'
newline|'\n'
name|'self'
op|'.'
name|'sections'
op|'='
name|'processor'
op|'.'
name|'sections'
op|'.'
name|'values'
op|'('
op|')'
newline|'\n'
name|'self'
op|'.'
name|'block_index'
op|'='
op|'['
op|']'
newline|'\n'
nl|'\n'
comment|'# store all blocks in a dictionary'
nl|'\n'
name|'self'
op|'.'
name|'blocks'
op|'='
op|'['
op|']'
newline|'\n'
name|'for'
name|'section'
name|'in'
name|'self'
op|'.'
name|'sections'
op|':'
newline|'\n'
indent|'            '
name|'for'
name|'block'
name|'in'
name|'section'
op|'.'
name|'blocks'
op|'.'
name|'values'
op|'('
op|')'
op|':'
newline|'\n'
indent|'                '
name|'self'
op|'.'
name|'add_identifier'
op|'('
name|'block'
op|'.'
name|'name'
op|','
name|'block'
op|')'
newline|'\n'
nl|'\n'
comment|'# add enumeration values to the index, since this is useful'
nl|'\n'
name|'for'
name|'markup'
name|'in'
name|'block'
op|'.'
name|'markups'
op|':'
newline|'\n'
indent|'                    '
name|'if'
name|'markup'
op|'.'
name|'tag'
op|'=='
string|"'values'"
op|':'
newline|'\n'
indent|'                        '
name|'for'
name|'field'
name|'in'
name|'markup'
op|'.'
name|'fields'
op|':'
newline|'\n'
indent|'                            '
name|'self'
op|'.'
name|'add_identifier'
op|'('
name|'field'
op|'.'
name|'name'
op|','
name|'block'
op|')'
newline|'\n'
nl|'\n'
dedent|''
dedent|''
dedent|''
dedent|''
dedent|''
name|'self'
op|'.'
name|'block_index'
op|'='
name|'self'
op|'.'
name|'identifiers'
op|'.'
name|'keys'
op|'('
op|')'
newline|'\n'
name|'self'
op|'.'
name|'block_index'
op|'.'
name|'sort'
op|'('
name|'key'
op|'='
name|'index_key'
op|')'
newline|'\n'
nl|'\n'
DECL|member|add_identifier
dedent|''
name|'def'
name|'add_identifier'
op|'('
name|'self'
op|','
name|'name'
op|','
name|'block'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'name'
name|'in'
name|'self'
op|'.'
name|'identifiers'
op|':'
newline|'\n'
comment|'# duplicate name!'
nl|'\n'
indent|'            '
name|'sys'
op|'.'
name|'stderr'
op|'.'
name|'write'
op|'('
string|'"WARNING: duplicate definition for"'
nl|'\n'
op|'+'
string|'" \'"'
op|'+'
name|'name'
op|'+'
string|'"\' "'
nl|'\n'
op|'+'
string|'"in "'
op|'+'
name|'block'
op|'.'
name|'location'
op|'('
op|')'
op|'+'
string|'", "'
nl|'\n'
op|'+'
string|'"previous definition in "'
nl|'\n'
op|'+'
name|'self'
op|'.'
name|'identifiers'
op|'['
name|'name'
op|']'
op|'.'
name|'location'
op|'('
op|')'
nl|'\n'
op|'+'
string|'"\\n"'
op|')'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'            '
name|'self'
op|'.'
name|'identifiers'
op|'['
name|'name'
op|']'
op|'='
name|'block'
newline|'\n'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# formatting the table of contents'
nl|'\n'
comment|'#'
nl|'\n'
DECL|member|toc_enter
dedent|''
dedent|''
name|'def'
name|'toc_enter'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_chapter_enter
dedent|''
name|'def'
name|'toc_chapter_enter'
op|'('
name|'self'
op|','
name|'chapter'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_section_enter
dedent|''
name|'def'
name|'toc_section_enter'
op|'('
name|'self'
op|','
name|'section'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_section_exit
dedent|''
name|'def'
name|'toc_section_exit'
op|'('
name|'self'
op|','
name|'section'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_chapter_exit
dedent|''
name|'def'
name|'toc_chapter_exit'
op|'('
name|'self'
op|','
name|'chapter'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_index
dedent|''
name|'def'
name|'toc_index'
op|'('
name|'self'
op|','
name|'index_filename'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_exit
dedent|''
name|'def'
name|'toc_exit'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|toc_dump
dedent|''
name|'def'
name|'toc_dump'
op|'('
name|'self'
op|','
name|'toc_filename'
op|'='
name|'None'
op|','
name|'index_filename'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'output'
op|'='
name|'None'
newline|'\n'
name|'if'
name|'toc_filename'
op|':'
newline|'\n'
indent|'            '
name|'output'
op|'='
name|'open_output'
op|'('
name|'toc_filename'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'toc_enter'
op|'('
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'chap'
name|'in'
name|'self'
op|'.'
name|'processor'
op|'.'
name|'chapters'
op|':'
newline|'\n'
nl|'\n'
indent|'            '
name|'self'
op|'.'
name|'toc_chapter_enter'
op|'('
name|'chap'
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'section'
name|'in'
name|'chap'
op|'.'
name|'sections'
op|':'
newline|'\n'
indent|'                '
name|'self'
op|'.'
name|'toc_section_enter'
op|'('
name|'section'
op|')'
newline|'\n'
name|'self'
op|'.'
name|'toc_section_exit'
op|'('
name|'section'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'toc_chapter_exit'
op|'('
name|'chap'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'toc_index'
op|'('
name|'index_filename'
op|')'
newline|'\n'
nl|'\n'
name|'self'
op|'.'
name|'toc_exit'
op|'('
op|')'
newline|'\n'
nl|'\n'
name|'if'
name|'output'
op|':'
newline|'\n'
indent|'            '
name|'close_output'
op|'('
name|'output'
op|')'
newline|'\n'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# formatting the index'
nl|'\n'
comment|'#'
nl|'\n'
DECL|member|index_enter
dedent|''
dedent|''
name|'def'
name|'index_enter'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|index_name_enter
dedent|''
name|'def'
name|'index_name_enter'
op|'('
name|'self'
op|','
name|'name'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|index_name_exit
dedent|''
name|'def'
name|'index_name_exit'
op|'('
name|'self'
op|','
name|'name'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|index_exit
dedent|''
name|'def'
name|'index_exit'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|index_dump
dedent|''
name|'def'
name|'index_dump'
op|'('
name|'self'
op|','
name|'index_filename'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'output'
op|'='
name|'None'
newline|'\n'
name|'if'
name|'index_filename'
op|':'
newline|'\n'
indent|'            '
name|'output'
op|'='
name|'open_output'
op|'('
name|'index_filename'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'index_enter'
op|'('
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'name'
name|'in'
name|'self'
op|'.'
name|'block_index'
op|':'
newline|'\n'
indent|'            '
name|'self'
op|'.'
name|'index_name_enter'
op|'('
name|'name'
op|')'
newline|'\n'
name|'self'
op|'.'
name|'index_name_exit'
op|'('
name|'name'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'index_exit'
op|'('
op|')'
newline|'\n'
nl|'\n'
name|'if'
name|'output'
op|':'
newline|'\n'
indent|'            '
name|'close_output'
op|'('
name|'output'
op|')'
newline|'\n'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# formatting a section'
nl|'\n'
comment|'#'
nl|'\n'
DECL|member|section_enter
dedent|''
dedent|''
name|'def'
name|'section_enter'
op|'('
name|'self'
op|','
name|'section'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|block_enter
dedent|''
name|'def'
name|'block_enter'
op|'('
name|'self'
op|','
name|'block'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|markup_enter
dedent|''
name|'def'
name|'markup_enter'
op|'('
name|'self'
op|','
name|'markup'
op|','
name|'block'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|field_enter
dedent|''
name|'def'
name|'field_enter'
op|'('
name|'self'
op|','
name|'field'
op|','
name|'markup'
op|'='
name|'None'
op|','
name|'block'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|field_exit
dedent|''
name|'def'
name|'field_exit'
op|'('
name|'self'
op|','
name|'field'
op|','
name|'markup'
op|'='
name|'None'
op|','
name|'block'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|markup_exit
dedent|''
name|'def'
name|'markup_exit'
op|'('
name|'self'
op|','
name|'markup'
op|','
name|'block'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|block_exit
dedent|''
name|'def'
name|'block_exit'
op|'('
name|'self'
op|','
name|'block'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|section_exit
dedent|''
name|'def'
name|'section_exit'
op|'('
name|'self'
op|','
name|'section'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'pass'
newline|'\n'
nl|'\n'
DECL|member|section_dump
dedent|''
name|'def'
name|'section_dump'
op|'('
name|'self'
op|','
name|'section'
op|','
name|'section_filename'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'output'
op|'='
name|'None'
newline|'\n'
name|'if'
name|'section_filename'
op|':'
newline|'\n'
indent|'            '
name|'output'
op|'='
name|'open_output'
op|'('
name|'section_filename'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'section_enter'
op|'('
name|'section'
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'name'
name|'in'
name|'section'
op|'.'
name|'block_names'
op|':'
newline|'\n'
indent|'            '
name|'skip_entry'
op|'='
number|'0'
newline|'\n'
name|'try'
op|':'
newline|'\n'
indent|'                '
name|'block'
op|'='
name|'self'
op|'.'
name|'identifiers'
op|'['
name|'name'
op|']'
newline|'\n'
comment|"# `block_names' can contain field names also,"
nl|'\n'
comment|'# which we filter out'
nl|'\n'
name|'for'
name|'markup'
name|'in'
name|'block'
op|'.'
name|'markups'
op|':'
newline|'\n'
indent|'                    '
name|'if'
name|'markup'
op|'.'
name|'tag'
op|'=='
string|"'values'"
op|':'
newline|'\n'
indent|'                        '
name|'for'
name|'field'
name|'in'
name|'markup'
op|'.'
name|'fields'
op|':'
newline|'\n'
indent|'                            '
name|'if'
name|'field'
op|'.'
name|'name'
op|'=='
name|'name'
op|':'
newline|'\n'
indent|'                                '
name|'skip_entry'
op|'='
number|'1'
newline|'\n'
dedent|''
dedent|''
dedent|''
dedent|''
dedent|''
name|'except'
op|':'
newline|'\n'
indent|'                '
name|'skip_entry'
op|'='
number|'1'
comment|"# this happens e.g. for `/empty/' entries"
newline|'\n'
nl|'\n'
dedent|''
name|'if'
name|'skip_entry'
op|':'
newline|'\n'
indent|'              '
name|'continue'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'block_enter'
op|'('
name|'block'
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'markup'
name|'in'
name|'block'
op|'.'
name|'markups'
op|'['
number|'1'
op|':'
op|']'
op|':'
comment|'# always ignore first markup!'
newline|'\n'
indent|'                '
name|'self'
op|'.'
name|'markup_enter'
op|'('
name|'markup'
op|','
name|'block'
op|')'
newline|'\n'
nl|'\n'
name|'for'
name|'field'
name|'in'
name|'markup'
op|'.'
name|'fields'
op|':'
newline|'\n'
indent|'                    '
name|'self'
op|'.'
name|'field_enter'
op|'('
name|'field'
op|','
name|'markup'
op|','
name|'block'
op|')'
newline|'\n'
name|'self'
op|'.'
name|'field_exit'
op|'('
name|'field'
op|','
name|'markup'
op|','
name|'block'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'markup_exit'
op|'('
name|'markup'
op|','
name|'block'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'block_exit'
op|'('
name|'block'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'self'
op|'.'
name|'section_exit'
op|'('
name|'section'
op|')'
newline|'\n'
nl|'\n'
name|'if'
name|'output'
op|':'
newline|'\n'
indent|'            '
name|'close_output'
op|'('
name|'output'
op|')'
newline|'\n'
nl|'\n'
DECL|member|section_dump_all
dedent|''
dedent|''
name|'def'
name|'section_dump_all'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'for'
name|'section'
name|'in'
name|'self'
op|'.'
name|'sections'
op|':'
newline|'\n'
indent|'            '
name|'self'
op|'.'
name|'section_dump'
op|'('
name|'section'
op|')'
newline|'\n'
nl|'\n'
comment|'# eof'
nl|'\n'
dedent|''
dedent|''
dedent|''
endmarker|''
end_unit
