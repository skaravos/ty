#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define BUILTIN_FUNCTION(name) Value builtin_##name(Ty *ty, int argc, Value *kwargs)

#include "ty.h"
#include "value.h"

BUILTIN_FUNCTION(print);

BUILTIN_FUNCTION(doc);
BUILTIN_FUNCTION(set_doc);

BUILTIN_FUNCTION(ident);

BUILTIN_FUNCTION(eprint);

BUILTIN_FUNCTION(slurp);

BUILTIN_FUNCTION(die);

BUILTIN_FUNCTION(rand);

BUILTIN_FUNCTION(abs);

BUILTIN_FUNCTION(round);

BUILTIN_FUNCTION(iround);

BUILTIN_FUNCTION(ceil);

BUILTIN_FUNCTION(floor);

BUILTIN_FUNCTION(gcd);

BUILTIN_FUNCTION(lcm);

BUILTIN_FUNCTION(hash);

BUILTIN_FUNCTION(object);

BUILTIN_FUNCTION(bind);

BUILTIN_FUNCTION(unbind);

BUILTIN_FUNCTION(doc_ref);

BUILTIN_FUNCTION(define_method);

BUILTIN_FUNCTION(apply);

BUILTIN_FUNCTION(type);

BUILTIN_FUNCTION(subclass);

BUILTIN_FUNCTION(members);

BUILTIN_FUNCTION(member);

BUILTIN_FUNCTION(finalizer);

BUILTIN_FUNCTION(int);

BUILTIN_FUNCTION(float);

BUILTIN_FUNCTION(isnan);

BUILTIN_FUNCTION(str);

BUILTIN_FUNCTION(show);

BUILTIN_FUNCTION(fmt);

BUILTIN_FUNCTION(bool);

BUILTIN_FUNCTION(regex);

BUILTIN_FUNCTION(array);

BUILTIN_FUNCTION(tuple);

BUILTIN_FUNCTION(dict);

BUILTIN_FUNCTION(blob);

BUILTIN_FUNCTION(max);

BUILTIN_FUNCTION(min);

BUILTIN_FUNCTION(read);

BUILTIN_FUNCTION(log2);

BUILTIN_FUNCTION(log10);

BUILTIN_FUNCTION(pow);

BUILTIN_FUNCTION(cbrt);

BUILTIN_FUNCTION(sqrt);

BUILTIN_FUNCTION(exp);

BUILTIN_FUNCTION(log);

BUILTIN_FUNCTION(sinh);

BUILTIN_FUNCTION(cosh);

BUILTIN_FUNCTION(tanh);

BUILTIN_FUNCTION(atan2);

BUILTIN_FUNCTION(atan);

BUILTIN_FUNCTION(asin);

BUILTIN_FUNCTION(acos);

BUILTIN_FUNCTION(tan);

BUILTIN_FUNCTION(sin);

BUILTIN_FUNCTION(cos);

BUILTIN_FUNCTION(bit_and);

BUILTIN_FUNCTION(bit_or);

BUILTIN_FUNCTION(bit_xor);

BUILTIN_FUNCTION(bit_shift_left);

BUILTIN_FUNCTION(bit_shift_right);

BUILTIN_FUNCTION(bit_complement);

BUILTIN_FUNCTION(getenv);

BUILTIN_FUNCTION(setenv);

BUILTIN_FUNCTION(locale_setlocale);

BUILTIN_FUNCTION(json_parse);

BUILTIN_FUNCTION(json_encode);

BUILTIN_FUNCTION(md5);

BUILTIN_FUNCTION(sha1);

BUILTIN_FUNCTION(sha256);

BUILTIN_FUNCTION(base64_encode);

BUILTIN_FUNCTION(base64_decode);

BUILTIN_FUNCTION(ord);

BUILTIN_FUNCTION(chr);

BUILTIN_FUNCTION(os_open);

BUILTIN_FUNCTION(os_umask);

BUILTIN_FUNCTION(os_close);

BUILTIN_FUNCTION(os_mktemp);

BUILTIN_FUNCTION(os_mkdtemp);

BUILTIN_FUNCTION(os_opendir);

BUILTIN_FUNCTION(os_readdir);

BUILTIN_FUNCTION(os_telldir);

BUILTIN_FUNCTION(os_seekdir);

BUILTIN_FUNCTION(os_rewinddir);

BUILTIN_FUNCTION(os_closedir);

BUILTIN_FUNCTION(os_getcwd);

BUILTIN_FUNCTION(os_chdir);

BUILTIN_FUNCTION(os_mkdir);

BUILTIN_FUNCTION(os_rmdir);

BUILTIN_FUNCTION(os_chmod);

BUILTIN_FUNCTION(os_chown);

BUILTIN_FUNCTION(os_unlink);

BUILTIN_FUNCTION(os_rename);

BUILTIN_FUNCTION(os_link);

BUILTIN_FUNCTION(os_symlink);

BUILTIN_FUNCTION(os_read);

BUILTIN_FUNCTION(os_write);

BUILTIN_FUNCTION(os_fsync);

BUILTIN_FUNCTION(os_sync);

BUILTIN_FUNCTION(os_listdir);

BUILTIN_FUNCTION(os_usleep);

BUILTIN_FUNCTION(os_sleep);

BUILTIN_FUNCTION(os_fcntl);

BUILTIN_FUNCTION(os_flock);

BUILTIN_FUNCTION(os_spawn);

BUILTIN_FUNCTION(os_stat);

BUILTIN_FUNCTION(os_truncate);

BUILTIN_FUNCTION(os_ftruncate);

BUILTIN_FUNCTION(os_realpath);

BUILTIN_FUNCTION(os_fork);

BUILTIN_FUNCTION(os_isatty);

BUILTIN_FUNCTION(termios_tcgetattr);

BUILTIN_FUNCTION(termios_tcsetattr);

BUILTIN_FUNCTION(thread_create);

BUILTIN_FUNCTION(thread_mutex);

BUILTIN_FUNCTION(thread_mutex_destroy);

BUILTIN_FUNCTION(thread_join);

BUILTIN_FUNCTION(thread_detach);

BUILTIN_FUNCTION(thread_kill);

BUILTIN_FUNCTION(thread_lock);

BUILTIN_FUNCTION(thread_unlock);

BUILTIN_FUNCTION(thread_trylock);

BUILTIN_FUNCTION(thread_cond);

BUILTIN_FUNCTION(thread_cond_destroy);

BUILTIN_FUNCTION(thread_cond_broadcast);

BUILTIN_FUNCTION(thread_cond_signal);

BUILTIN_FUNCTION(thread_cond_wait);

BUILTIN_FUNCTION(thread_getname);

BUILTIN_FUNCTION(thread_self);

BUILTIN_FUNCTION(thread_id);

BUILTIN_FUNCTION(thread_setname);

BUILTIN_FUNCTION(thread_send);

BUILTIN_FUNCTION(thread_recv);

BUILTIN_FUNCTION(thread_channel);

BUILTIN_FUNCTION(thread_close);

BUILTIN_FUNCTION(os_pipe);

BUILTIN_FUNCTION(os_dup);

BUILTIN_FUNCTION(os_dup2);

BUILTIN_FUNCTION(os_poll);

BUILTIN_FUNCTION(os_epoll_create);

BUILTIN_FUNCTION(os_epoll_ctl);

BUILTIN_FUNCTION(os_epoll_wait);

BUILTIN_FUNCTION(os_getaddrinfo);

BUILTIN_FUNCTION(os_gai_strerror);

BUILTIN_FUNCTION(os_bind);

BUILTIN_FUNCTION(os_socket);

BUILTIN_FUNCTION(os_setsockopt);

BUILTIN_FUNCTION(os_getsockopt);

BUILTIN_FUNCTION(os_getpeername);

BUILTIN_FUNCTION(os_getsockname);

BUILTIN_FUNCTION(os_getnameinfo);

BUILTIN_FUNCTION(os_listen);

BUILTIN_FUNCTION(os_accept);

BUILTIN_FUNCTION(os_connect);

BUILTIN_FUNCTION(os_recvfrom);

BUILTIN_FUNCTION(os_sendto);

BUILTIN_FUNCTION(os_shutdown);

BUILTIN_FUNCTION(os_waitpid);

BUILTIN_FUNCTION(os_WIFEXITED);

BUILTIN_FUNCTION(os_WIFSIGNALED);

#ifdef WIFCONTINUED
BUILTIN_FUNCTION(os_WIFCONTINUED);
#endif

BUILTIN_FUNCTION(os_WIFSTOPPED);

#ifdef WCOREDUMP
BUILTIN_FUNCTION(os_WCOREDUMP);
#endif

BUILTIN_FUNCTION(os_WEXITSTATUS);

BUILTIN_FUNCTION(os_WTERMSIG);

BUILTIN_FUNCTION(os_WSTOPSIG);

BUILTIN_FUNCTION(os_getpid);

BUILTIN_FUNCTION(os_getppid);

BUILTIN_FUNCTION(os_getuid);

BUILTIN_FUNCTION(os_geteuid);

BUILTIN_FUNCTION(os_getgid);

BUILTIN_FUNCTION(os_getegid);

BUILTIN_FUNCTION(os_setuid);

BUILTIN_FUNCTION(os_seteuid);

BUILTIN_FUNCTION(os_setgid);

BUILTIN_FUNCTION(os_setegid);

BUILTIN_FUNCTION(os_kill);

BUILTIN_FUNCTION(os_signal);

BUILTIN_FUNCTION(os_exit);

BUILTIN_FUNCTION(os_exec);

BUILTIN_FUNCTION(errno_get);

BUILTIN_FUNCTION(errno_str);

BUILTIN_FUNCTION(time_time);

BUILTIN_FUNCTION(time_utime);

BUILTIN_FUNCTION(time_gettime);

BUILTIN_FUNCTION(time_localtime);

BUILTIN_FUNCTION(time_gmtime);

BUILTIN_FUNCTION(time_strftime);

BUILTIN_FUNCTION(time_strptime);

BUILTIN_FUNCTION(stdio_fdopen);

BUILTIN_FUNCTION(stdio_fileno);

BUILTIN_FUNCTION(stdio_tmpfile);

BUILTIN_FUNCTION(stdio_fgets);

BUILTIN_FUNCTION(stdio_fread);

BUILTIN_FUNCTION(stdio_read_signed);

BUILTIN_FUNCTION(stdio_read_unsigned);

BUILTIN_FUNCTION(stdio_read_float);

BUILTIN_FUNCTION(stdio_read_double);

BUILTIN_FUNCTION(stdio_write_float);

BUILTIN_FUNCTION(stdio_write_double);

BUILTIN_FUNCTION(stdio_write_signed);

BUILTIN_FUNCTION(stdio_write_unsigned);

BUILTIN_FUNCTION(stdio_puts);

BUILTIN_FUNCTION(stdio_fwrite);

BUILTIN_FUNCTION(stdio_fgetc);

BUILTIN_FUNCTION(stdio_fputc);

BUILTIN_FUNCTION(stdio_slurp);

BUILTIN_FUNCTION(stdio_fflush);

BUILTIN_FUNCTION(stdio_fclose);

BUILTIN_FUNCTION(stdio_clearerr);

BUILTIN_FUNCTION(stdio_fseek);

BUILTIN_FUNCTION(stdio_ftell);

BUILTIN_FUNCTION(stdio_setvbuf);

BUILTIN_FUNCTION(eval);

BUILTIN_FUNCTION(ty_parse);

BUILTIN_FUNCTION(ty_tokenize);

BUILTIN_FUNCTION(ty_disassemble);

BUILTIN_FUNCTION(ty_copy_source);

BUILTIN_FUNCTION(ty_strip_source);

BUILTIN_FUNCTION(ty_get_source);

BUILTIN_FUNCTION(ty_gensym);

BUILTIN_FUNCTION(ty_gc);

BUILTIN_FUNCTION(ty_bt);

BUILTIN_FUNCTION(token_next);
BUILTIN_FUNCTION(token_peek);

BUILTIN_FUNCTION(parse_source);
BUILTIN_FUNCTION(parse_expr);
BUILTIN_FUNCTION(parse_stmt);
BUILTIN_FUNCTION(parse_fail);
BUILTIN_FUNCTION(parse_show);

BUILTIN_FUNCTION(lex_peek_char);
BUILTIN_FUNCTION(lex_next_char);
BUILTIN_FUNCTION(lex_state);

BUILTIN_FUNCTION(ty_unlock);
BUILTIN_FUNCTION(ty_lock);

BUILTIN_FUNCTION(ptr_typed);
BUILTIN_FUNCTION(ptr_untyped);

BUILTIN_FUNCTION(tdb_eval);
BUILTIN_FUNCTION(tdb_over);
BUILTIN_FUNCTION(tdb_into);
BUILTIN_FUNCTION(tdb_step);
BUILTIN_FUNCTION(tdb_list);
BUILTIN_FUNCTION(tdb_state);
BUILTIN_FUNCTION(tdb_span);
BUILTIN_FUNCTION(tdb_ip);
BUILTIN_FUNCTION(tdb_breakpoint);
BUILTIN_FUNCTION(tdb_context);
BUILTIN_FUNCTION(tdb_locals);
BUILTIN_FUNCTION(tdb_stack);
BUILTIN_FUNCTION(tdb_backtrace);

#endif
