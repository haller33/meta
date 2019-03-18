#include "support.h"
static void meta_exp1(void);
static void meta_exp3(void);
char *grammar_name;
static void meta_var_descr(void){enter_parse_rule("meta_var_descr");do{start_user_token();do{read_literal("*");if(test_flag){user_token_stack[utoken_stack_top-1]=pos-strlen(token);read_id();error_if_false();}if(test_flag)break;read_id();if(test_flag){user_token_stack[utoken_stack_top-1]=pos-strlen(token);}}while(0);if(test_flag){do{do{long entry_pos=pos;read_literal("[");pos=entry_pos;}while(0);test_flag^=true;if(test_flag){end_user_token();}if(test_flag)break;read_literal("[");if(test_flag){do{read_literal("++");if(test_flag)break;read_literal("--");if(test_flag)break;test_flag=true;}while(0);error_if_false();do{read_number();if(test_flag)break;read_id();}while(0);error_if_false();do{read_literal("++");if(test_flag)break;read_literal("--");if(test_flag)break;test_flag=true;}while(0);error_if_false();read_literal("]");error_if_false();end_user_token();}}while(0);error_if_false();}}while(0);exit_parse_rule();}
static void meta_hex(void){enter_parse_rule("meta_hex");do{read_any_between('0','9');if(test_flag)break;read_any_between('a','f');if(test_flag)break;read_any_between('A','F');}while(0);exit_parse_rule();}
static void meta_xchar(void){enter_parse_rule("meta_xchar");do{read_literal("\\x");if(test_flag){start_user_token();meta_hex();error_if_false();meta_hex();error_if_false();end_user_token();}}while(0);exit_parse_rule();}
static void meta_xcharp(void){enter_parse_rule("meta_xcharp");do{read_literal("\\x");if(test_flag){emit("'");emit_token(false);meta_hex();error_if_false();emit_char(source[pos-1]);error_if_false();meta_hex();error_if_false();emit_char(source[pos-1]);error_if_false();emit("'");}}while(0);exit_parse_rule();}
static void meta_arg(void){enter_parse_rule("meta_arg");do{read_literal("$");if(test_flag){emit("emit_token(true);");}if(test_flag)break;read_literal("%");if(test_flag){emit("emit_token(false);");}if(test_flag)break;do{read_literal("lf");if(test_flag)break;read_literal("nl");}while(0);if(test_flag){emit("emit_char('\\n');");}if(test_flag)break;read_literal("cr");if(test_flag){emit("emit_char('\\r');");}if(test_flag)break;meta_var_descr();if(test_flag){emit("emit(");emit_token(true);emit(");");}if(test_flag)break;meta_xchar();if(test_flag){emit("emit_char('\\x");emit_token(true);emit("');");}}while(0);exit_parse_rule();}
static void meta_output(void){enter_parse_rule("meta_output");do{read_literal("{");if(test_flag){do{do{read_string();if(test_flag){emit("emit(");emit_token(true);emit(");");}if(test_flag)break;meta_arg();}while(0);}while(test_flag);test_flag=true;error_if_false();read_literal("}");error_if_false();}if(test_flag)break;read_literal("<");if(test_flag){do{do{read_string();if(test_flag){emit_token(false);}if(test_flag)break;meta_arg();}while(0);}while(test_flag);test_flag=true;error_if_false();read_literal(">");error_if_false();}}while(0);exit_parse_rule();}
static void meta_space_control(void){enter_parse_rule("meta_space_control");do{read_literal("\\");if(test_flag){emit("ignore_whitespace=true;");}if(test_flag)break;read_literal("/");if(test_flag){emit("ignore_whitespace=false;");}}while(0);exit_parse_rule();}
static void meta_user_token_delim(void){enter_parse_rule("meta_user_token_delim");do{read_literal(".token");if(test_flag){emit("start_user_token();");}if(test_flag)break;read_literal(".adjtoken");if(test_flag){emit("user_token_stack[utoken_stack_top-1]=pos-strlen(token);");}if(test_flag)break;read_literal(".deftoken");if(test_flag){emit("end_user_token();");}if(test_flag)break;read_literal(".mute");if(test_flag){emit("mute=true;");}if(test_flag)break;read_literal(".unmute");if(test_flag){emit("mute=false;");}if(test_flag)break;read_literal(".capture");if(test_flag){emit("if(capture)free(capture);capture=calloc(1,1);");}if(test_flag)break;read_literal(".defcapture");if(test_flag){emit("capture_to_token();");}}while(0);exit_parse_rule();}
static void meta_user_token_arg(void){enter_parse_rule("meta_user_token_arg");do{read_number();if(test_flag){emit_token(true);}if(test_flag)break;meta_xcharp();if(test_flag)break;read_char_eq(39);if(test_flag){emit_char(source[pos-1]);error_if_false();do{read_char_eq(92);if(test_flag){emit("\\\\");}if(test_flag)break;read_char_eq(39);if(test_flag){emit("\\'");}if(test_flag)break;read_any_between(32,126);if(test_flag){emit_char(source[pos-1]);error_if_false();}}while(0);error_if_false();read_char_eq(39);error_if_false();emit_char(source[pos-1]);error_if_false();}}while(0);exit_parse_rule();}
static void meta_user_tokens(void){enter_parse_rule("meta_user_tokens");do{read_literal(".any(");if(test_flag){emit("read_any_between(");meta_user_token_arg();error_if_false();read_literal(",");error_if_false();emit(",");meta_user_token_arg();error_if_false();read_literal(")");error_if_false();emit(");");}if(test_flag)break;read_literal(".but(");if(test_flag){emit("read_any_but(");meta_user_token_arg();error_if_false();read_literal(",");error_if_false();emit(",");meta_user_token_arg();error_if_false();read_literal(")");error_if_false();emit(");");}if(test_flag)break;read_literal(".eq(");if(test_flag){emit("read_char_eq(");meta_user_token_arg();error_if_false();read_literal(")");error_if_false();emit(");");}if(test_flag)break;read_literal(".neq(");if(test_flag){emit("read_char_neq(");meta_user_token_arg();error_if_false();read_literal(")");error_if_false();emit(");");}if(test_flag)break;read_literal(".putc");if(test_flag){emit("emit_char(source[pos-1]);");}}while(0);exit_parse_rule();}
static void meta_errors(void){enter_parse_rule("meta_errors");do{read_literal(".error(");if(test_flag){read_string();error_if_false();emit("error(");emit_token(true);emit(");");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".warn(");if(test_flag){read_string();error_if_false();emit("warning(");emit_token(true);emit(");");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".expect(");if(test_flag){read_string();error_if_false();emit("expecting=");emit_token(true);emit(";unexpected=NULL;");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".unexpect(");if(test_flag){read_string();error_if_false();emit("expecting=NULL;unexpected=");emit_token(true);emit(";");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".noexpect");if(test_flag){emit("expecting=NULL;unexpected=NULL;");}if(test_flag)break;read_literal(".reason(");if(test_flag){read_string();error_if_false();emit("reason=");emit_token(true);emit(";");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".noreason");if(test_flag){emit("reason=NULL;");}if(test_flag)break;read_literal(".failure");if(test_flag){emit("test_flag=false;exit_parse_rule();return;");}if(test_flag)break;read_literal(".success");if(test_flag){emit("test_flag=true;exit_parse_rule();return;");}}while(0);exit_parse_rule();}
static void meta_user_vars(void){enter_parse_rule("meta_user_vars");do{read_literal(".bind(");if(test_flag){meta_var_descr();error_if_false();emit("char ");emit_token(true);emit("=token;token=NULL;");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".var(");if(test_flag){meta_var_descr();error_if_false();emit("char ");emit_token(true);emit("={0};");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".long(");if(test_flag){meta_var_descr();error_if_false();emit("long ");emit_token(true);emit("=");do{read_literal(",");if(test_flag){do{read_literal("-");if(test_flag){emit_token(true);ignore_whitespace=true;}if(test_flag)break;test_flag=true;}while(0);error_if_false();read_number();error_if_false();ignore_whitespace=false;emit_token(true);emit(";");}if(test_flag)break;test_flag=true;if(test_flag){emit("{0};");}}while(0);error_if_false();read_literal(")");error_if_false();}if(test_flag)break;read_literal(".bool(");if(test_flag){meta_var_descr();error_if_false();emit("bool ");emit_token(true);emit("=");do{read_literal(",");if(test_flag){do{read_literal("true");if(test_flag)break;read_literal("false");}while(0);error_if_false();emit_token(true);emit(";");}if(test_flag)break;test_flag=true;if(test_flag){emit("false;");}}while(0);error_if_false();read_literal(")");error_if_false();}if(test_flag)break;read_literal(".ltoa(");if(test_flag){meta_var_descr();error_if_false();emit("sprintf(");emit_token(true);read_literal(",");error_if_false();meta_var_descr();error_if_false();emit(",\"%ld\",");emit_token(true);emit(");");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".set(");if(test_flag){meta_var_descr();error_if_false();emit_token(true);emit("=token;token=NULL;");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".concat(");if(test_flag){meta_var_descr();error_if_false();emit("concatstr(");emit_token(true);emit(",token);");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".clear(");if(test_flag){meta_var_descr();error_if_false();emit("free(");emit_token(true);emit(");");read_literal(")");error_if_false();}if(test_flag)break;read_literal(".ifte(");if(test_flag){meta_var_descr();error_if_false();emit("if(");emit_token(true);emit(")emit(");emit_token(true);emit(");else emit(");read_literal(",");error_if_false();read_string();error_if_false();emit_token(true);emit(");");read_literal(")");error_if_false();}}while(0);exit_parse_rule();}
static void meta_builtin_tokens(void){enter_parse_rule("meta_builtin_tokens");do{read_literal(".id");if(test_flag){emit("read_id();");}if(test_flag)break;read_literal(".number");if(test_flag){emit("read_number();");}if(test_flag)break;read_literal(".string");if(test_flag){emit("read_string();");}if(test_flag)break;read_literal(".space");if(test_flag){emit("skip_whitespace();");}}while(0);exit_parse_rule();}
static void meta_option_capture(void){enter_parse_rule("meta_option_capture");do{read_literal("^");if(test_flag){if(capture)free(capture);capture=calloc(1,1);meta_exp3();error_if_false();capture_to_token();}}while(0);exit_parse_rule();}
static void meta_multiple_optionals(void){enter_parse_rule("meta_multiple_optionals");do{char *opts_stack[STACK_DEPTH]={0};long last_opt=2;char idx[5]={0};meta_option_capture();if(test_flag){opts_stack[0]=token;token=NULL;meta_option_capture();error_if_false();opts_stack[1]=token;token=NULL;do{do{if(last_opt==STACK_DEPTH-1){error("excess of optionals");}meta_option_capture();if(test_flag){opts_stack[last_opt++]=token;token=NULL;}}while(0);}while(test_flag);test_flag=true;error_if_false();sprintf(idx,"%ld",last_opt);emit("do{bool expr_results[");emit(idx);emit("];");for(long a=0;a<last_opt;a++){sprintf(idx,"%ld",a);emit("do{");emit(opts_stack[a]);emit("}while(0);");emit("expr_results[");emit(idx);emit("]=test_flag;");}for(long a=0;a<last_opt;a++){sprintf(idx,"%ld",a);emit("if(!expr_results[");emit(idx);emit("])do{");emit(opts_stack[a]);free(opts_stack[a]);emit("}while(0);");}emit("}while(0);test_flag=true;");}}while(0);exit_parse_rule();}
static void meta_exp3(void){enter_parse_rule("meta_exp3");do{read_id();if(test_flag){emit(grammar_name);emit("_");emit_token(true);emit("();");}if(test_flag)break;read_string();if(test_flag){emit("read_literal(");emit_token(true);emit(");");}if(test_flag)break;meta_builtin_tokens();if(test_flag)break;meta_user_tokens();if(test_flag)break;read_literal("(");if(test_flag){meta_exp1();error_if_false();read_literal(")");error_if_false();}if(test_flag)break;read_literal(".e");if(test_flag){emit("test_flag=true;");}if(test_flag)break;read_literal("*");if(test_flag){emit("do{");meta_exp3();error_if_false();emit("}while(test_flag);test_flag=true;");}if(test_flag)break;read_literal("!");if(test_flag){emit("do{long entry_pos=pos;");meta_exp3();error_if_false();emit("pos=entry_pos;}while(0);test_flag^=true;");}if(test_flag)break;meta_multiple_optionals();}while(0);exit_parse_rule();}
static void meta_dont_use_flag(void){enter_parse_rule("meta_dont_use_flag");do{meta_user_token_delim();if(test_flag)break;meta_output();if(test_flag)break;meta_space_control();if(test_flag)break;meta_errors();if(test_flag)break;meta_user_vars();}while(0);exit_parse_rule();}
static void meta_exp2(void){enter_parse_rule("meta_exp2");do{do{meta_dont_use_flag();}while(test_flag);test_flag=true;if(test_flag){do{meta_exp3();if(test_flag){do{do{long entry_pos=pos;do{read_literal(";");if(test_flag)break;read_literal("|");if(test_flag)break;read_literal(")");}while(0);pos=entry_pos;}while(0);test_flag^=true;if(test_flag){emit("if(test_flag){");do{do{meta_dont_use_flag();if(test_flag)break;meta_exp3();if(test_flag){emit("error_if_false();");}}while(0);}while(test_flag);test_flag=true;error_if_false();emit("}");}if(test_flag)break;test_flag=true;}while(0);error_if_false();}if(test_flag)break;test_flag=true;}while(0);error_if_false();}}while(0);exit_parse_rule();}
static void meta_exp1(void){enter_parse_rule("meta_exp1");do{read_literal("continue");if(test_flag){test_flag=true;exit_parse_rule();return;}if(test_flag)break;emit("do{");expecting="a sequence of expressions";unexpected=NULL;meta_exp2();if(test_flag){do{do{read_literal("|");if(test_flag){emit("if(test_flag)break;");expecting="a sequence of expressions";unexpected=NULL;meta_exp2();error_if_false();}}while(0);}while(test_flag);test_flag=true;error_if_false();emit("}while(0);");}}while(0);exit_parse_rule();}
static void meta_stat(void){enter_parse_rule("meta_stat");do{read_literal("%");if(test_flag){do{read_char_neq(10);}while(test_flag);test_flag=true;error_if_false();}if(test_flag)break;expecting="a grammar rule identifier";unexpected=NULL;read_id();if(test_flag){emit("static void ");emit(grammar_name);emit("_");emit_token(true);emit("(void)");emit("{enter_parse_rule(\"");emit(grammar_name);emit("_");emit_token(true);emit("\");");expecting="an equal sign";unexpected=NULL;read_literal("=");error_if_false();expecting="a sequence of expressions";unexpected=NULL;meta_exp1();error_if_false();expecting="a ; terminator";unexpected=NULL;read_literal(";");error_if_false();emit("exit_parse_rule();}\n");}}while(0);exit_parse_rule();}
static void meta_initialize(void){enter_parse_rule("meta_initialize");do{read_literal("%");if(test_flag){do{read_char_neq(10);}while(test_flag);test_flag=true;error_if_false();meta_initialize();error_if_false();}if(test_flag)break;read_literal(".initialize");if(test_flag){expecting="a sequence of code instructions (strings)";unexpected=NULL;read_string();error_if_false();emit_token(false);do{do{read_string();if(test_flag){emit_token(false);}}while(0);}while(test_flag);test_flag=true;error_if_false();expecting="a ; terminator";unexpected=NULL;read_literal(";");error_if_false();}if(test_flag)break;test_flag=true;}while(0);exit_parse_rule();}
static void meta_finalize(void){enter_parse_rule("meta_finalize");do{expecting="a compiler mode directive (.end,.multiple,.test,.finalize)";unexpected=NULL;do{read_literal(".end");if(test_flag){expecting="a grammar rule identifier";unexpected=NULL;read_id();error_if_false();emit("int main(int argc, char *argv[]){return first_into_second(argc,argv,");emit(grammar_name);emit("_");emit_token(true);emit(");}\n");}if(test_flag)break;read_literal(".multiple");if(test_flag){expecting="an file extension (string)";unexpected=NULL;read_string();error_if_false();char *extension=token;token=NULL;expecting="a grammar rule identifier";unexpected=NULL;read_id();error_if_false();emit("int main(int argc, char *argv[]){ multiple_files(argc,argv,");emit(extension);emit(",");emit(grammar_name);emit("_");emit_token(true);emit(");return 0; }\n");}if(test_flag)break;read_literal(".test");if(test_flag){expecting="a grammar rule identifier (optionally a maximum input size)";unexpected=NULL;read_id();error_if_false();char *func_name=token;token=NULL;char *max_input_size={0};do{read_number();if(test_flag){max_input_size=token;token=NULL;}if(test_flag)break;test_flag=true;}while(0);error_if_false();emit("int main (int argc, char *argv[]){return test(");if(max_input_size)emit(max_input_size);else emit("4194304");emit(",");emit(grammar_name);emit("_");emit(func_name);emit(");}\n");}if(test_flag)break;read_literal(".finalize");if(test_flag){expecting="a sequence of code instructions (strings)";unexpected=NULL;read_string();error_if_false();emit_token(false);do{do{read_string();if(test_flag){emit_token(false);}}while(0);}while(test_flag);test_flag=true;error_if_false();}}while(0);if(test_flag){expecting="a ; terminator";unexpected=NULL;read_literal(";");error_if_false();}}while(0);exit_parse_rule();}
static void meta_program(void){enter_parse_rule("meta_program");do{read_literal(".syntax");if(test_flag){expecting="a grammar name";unexpected=NULL;skip_whitespace();error_if_false();read_id();error_if_false();grammar_name=token;token=NULL;expecting="a ; terminator";unexpected=NULL;do{read_string();if(test_flag){emit("#include \"");emit_token(false);emit("/support.h\"\n");}if(test_flag)break;test_flag=true;if(test_flag){emit("#include \"support.h\"\n");}}while(0);error_if_false();read_literal(";");error_if_false();meta_initialize();error_if_false();do{meta_stat();}while(test_flag);test_flag=true;error_if_false();meta_finalize();error_if_false();}}while(0);exit_parse_rule();}
int main(int argc, char *argv[]){return first_into_second(argc,argv,meta_program);}
