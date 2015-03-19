begin_unit
comment|'#'
nl|'\n'
comment|'#  utils.py'
nl|'\n'
comment|'#'
nl|'\n'
comment|"#    Auxiliary functions for the `docmaker' tool (library file)."
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
nl|'\n'
name|'import'
name|'string'
op|','
name|'sys'
op|','
name|'os'
op|','
name|'glob'
op|','
name|'itertools'
newline|'\n'
nl|'\n'
nl|'\n'
comment|'# current output directory'
nl|'\n'
comment|'#'
nl|'\n'
DECL|variable|output_dir
name|'output_dir'
op|'='
name|'None'
newline|'\n'
nl|'\n'
nl|'\n'
comment|'# A function that generates a sorting key.  We want lexicographical order'
nl|'\n'
comment|'# (primary key) except that capital letters are sorted before lowercase'
nl|'\n'
comment|'# ones (secondary key).'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# The primary key is implemented by lowercasing the input.  The secondary'
nl|'\n'
comment|'# key is simply the original data appended, character by character.  For'
nl|'\n'
comment|"# example, the sort key for `FT_x' is `fFtT__xx', while the sort key for"
nl|'\n'
comment|"# `ft_X' is `fftt__xX'.  Since ASCII codes of uppercase letters are"
nl|'\n'
comment|"# numerically smaller than the codes of lowercase letters, `fFtT__xx' gets"
nl|'\n'
comment|"# sorted before `fftt__xX'."
nl|'\n'
comment|'#'
nl|'\n'
DECL|function|index_key
name|'def'
name|'index_key'
op|'('
name|'s'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'return'
name|'string'
op|'.'
name|'join'
op|'('
name|'itertools'
op|'.'
name|'chain'
op|'('
op|'*'
name|'zip'
op|'('
name|'s'
op|'.'
name|'lower'
op|'('
op|')'
op|','
name|'s'
op|')'
op|')'
op|')'
newline|'\n'
nl|'\n'
nl|'\n'
comment|"# Sort `input_list', placing the elements of `order_list' in front."
nl|'\n'
comment|'#'
nl|'\n'
DECL|function|sort_order_list
dedent|''
name|'def'
name|'sort_order_list'
op|'('
name|'input_list'
op|','
name|'order_list'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'new_list'
op|'='
name|'order_list'
op|'['
op|':'
op|']'
newline|'\n'
name|'for'
name|'id'
name|'in'
name|'input_list'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'not'
name|'id'
name|'in'
name|'order_list'
op|':'
newline|'\n'
indent|'            '
name|'new_list'
op|'.'
name|'append'
op|'('
name|'id'
op|')'
newline|'\n'
dedent|''
dedent|''
name|'return'
name|'new_list'
newline|'\n'
nl|'\n'
nl|'\n'
comment|'# Divert standard output to a given project documentation file.  Use'
nl|'\n'
comment|"# `output_dir' to determine the filename location if necessary and save the"
nl|'\n'
comment|'# old stdout handle in a tuple that is returned by this function.'
nl|'\n'
comment|'#'
nl|'\n'
DECL|function|open_output
dedent|''
name|'def'
name|'open_output'
op|'('
name|'filename'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'global'
name|'output_dir'
newline|'\n'
nl|'\n'
name|'if'
name|'output_dir'
name|'and'
name|'output_dir'
op|'!='
string|'""'
op|':'
newline|'\n'
indent|'        '
name|'filename'
op|'='
name|'output_dir'
op|'+'
name|'os'
op|'.'
name|'sep'
op|'+'
name|'filename'
newline|'\n'
nl|'\n'
dedent|''
name|'old_stdout'
op|'='
name|'sys'
op|'.'
name|'stdout'
newline|'\n'
name|'new_file'
op|'='
name|'open'
op|'('
name|'filename'
op|','
string|'"w"'
op|')'
newline|'\n'
name|'sys'
op|'.'
name|'stdout'
op|'='
name|'new_file'
newline|'\n'
nl|'\n'
name|'return'
op|'('
name|'new_file'
op|','
name|'old_stdout'
op|')'
newline|'\n'
nl|'\n'
nl|'\n'
comment|"# Close the output that was returned by `open_output'."
nl|'\n'
comment|'#'
nl|'\n'
DECL|function|close_output
dedent|''
name|'def'
name|'close_output'
op|'('
name|'output'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'output'
op|'['
number|'0'
op|']'
op|'.'
name|'close'
op|'('
op|')'
newline|'\n'
name|'sys'
op|'.'
name|'stdout'
op|'='
name|'output'
op|'['
number|'1'
op|']'
newline|'\n'
nl|'\n'
nl|'\n'
comment|'# Check output directory.'
nl|'\n'
comment|'#'
nl|'\n'
DECL|function|check_output
dedent|''
name|'def'
name|'check_output'
op|'('
op|')'
op|':'
newline|'\n'
indent|'    '
name|'global'
name|'output_dir'
newline|'\n'
name|'if'
name|'output_dir'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'output_dir'
op|'!='
string|'""'
op|':'
newline|'\n'
indent|'            '
name|'if'
name|'not'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isdir'
op|'('
name|'output_dir'
op|')'
op|':'
newline|'\n'
indent|'                '
name|'sys'
op|'.'
name|'stderr'
op|'.'
name|'write'
op|'('
string|'"argument"'
nl|'\n'
op|'+'
string|'" \'"'
op|'+'
name|'output_dir'
op|'+'
string|'"\' "'
nl|'\n'
op|'+'
string|'"is not a valid directory"'
op|')'
newline|'\n'
name|'sys'
op|'.'
name|'exit'
op|'('
number|'2'
op|')'
newline|'\n'
dedent|''
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'            '
name|'output_dir'
op|'='
name|'None'
newline|'\n'
nl|'\n'
nl|'\n'
DECL|function|file_exists
dedent|''
dedent|''
dedent|''
name|'def'
name|'file_exists'
op|'('
name|'pathname'
op|')'
op|':'
newline|'\n'
indent|'    '
string|'"""Check that a given file exists."""'
newline|'\n'
name|'result'
op|'='
number|'1'
newline|'\n'
name|'try'
op|':'
newline|'\n'
indent|'        '
name|'file'
op|'='
name|'open'
op|'('
name|'pathname'
op|','
string|'"r"'
op|')'
newline|'\n'
name|'file'
op|'.'
name|'close'
op|'('
op|')'
newline|'\n'
dedent|''
name|'except'
op|':'
newline|'\n'
indent|'        '
name|'result'
op|'='
name|'None'
newline|'\n'
name|'sys'
op|'.'
name|'stderr'
op|'.'
name|'write'
op|'('
name|'pathname'
op|'+'
string|'" couldn\'t be accessed\\n"'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'return'
name|'result'
newline|'\n'
nl|'\n'
nl|'\n'
DECL|function|make_file_list
dedent|''
name|'def'
name|'make_file_list'
op|'('
name|'args'
op|'='
name|'None'
op|')'
op|':'
newline|'\n'
indent|'    '
string|'"""Build a list of input files from command-line arguments."""'
newline|'\n'
name|'file_list'
op|'='
op|'['
op|']'
newline|'\n'
comment|"# sys.stderr.write( repr( sys.argv[1 :] ) + '\\n' )"
nl|'\n'
nl|'\n'
name|'if'
name|'not'
name|'args'
op|':'
newline|'\n'
indent|'        '
name|'args'
op|'='
name|'sys'
op|'.'
name|'argv'
op|'['
number|'1'
op|':'
op|']'
newline|'\n'
nl|'\n'
dedent|''
name|'for'
name|'pathname'
name|'in'
name|'args'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'string'
op|'.'
name|'find'
op|'('
name|'pathname'
op|','
string|"'*'"
op|')'
op|'>='
number|'0'
op|':'
newline|'\n'
indent|'            '
name|'newpath'
op|'='
name|'glob'
op|'.'
name|'glob'
op|'('
name|'pathname'
op|')'
newline|'\n'
name|'newpath'
op|'.'
name|'sort'
op|'('
op|')'
comment|'# sort files -- this is important because'
newline|'\n'
comment|'# of the order of files'
nl|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'            '
name|'newpath'
op|'='
op|'['
name|'pathname'
op|']'
newline|'\n'
nl|'\n'
dedent|''
name|'file_list'
op|'.'
name|'extend'
op|'('
name|'newpath'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'if'
name|'len'
op|'('
name|'file_list'
op|')'
op|'=='
number|'0'
op|':'
newline|'\n'
indent|'        '
name|'file_list'
op|'='
name|'None'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
comment|'# now filter the file list to remove non-existing ones'
nl|'\n'
indent|'        '
name|'file_list'
op|'='
name|'filter'
op|'('
name|'file_exists'
op|','
name|'file_list'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'return'
name|'file_list'
newline|'\n'
nl|'\n'
comment|'# eof'
nl|'\n'
dedent|''
endmarker|''
end_unit
