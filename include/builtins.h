#define BUILTIN(f)    { .type = VALUE_BUILTIN_FUNCTION, .builtin_function = (f), .tags = 0 }
#define INT(k)        { .type = VALUE_INTEGER,          .integer          = (k), .tags = 0 }
#define FLOAT(x)      { .type = VALUE_REAL,             .real             = (x), .tags = 0 }

{ .module = NULL,     .name = "print",             .value = BUILTIN(builtin_print)                         },
{ .module = NULL,     .name = "die",               .value = BUILTIN(builtin_die)                           },
{ .module = NULL,     .name = "read",              .value = BUILTIN(builtin_read)                          },
{ .module = NULL,     .name = "rand",              .value = BUILTIN(builtin_rand)                          },
{ .module = NULL,     .name = "int",               .value = BUILTIN(builtin_int)                           },
{ .module = NULL,     .name = "float",             .value = BUILTIN(builtin_float)                         },
{ .module = NULL,     .name = "str",               .value = BUILTIN(builtin_str)                           },
{ .module = NULL,     .name = "bool",              .value = BUILTIN(builtin_bool)                          },
{ .module = NULL,     .name = "regex",             .value = BUILTIN(builtin_regex)                         },
{ .module = NULL,     .name = "blob",              .value = BUILTIN(builtin_blob)                          },
{ .module = NULL,     .name = "min",               .value = BUILTIN(builtin_min)                           },
{ .module = NULL,     .name = "max",               .value = BUILTIN(builtin_max)                           },
{ .module = NULL,     .name = "hash",              .value = BUILTIN(builtin_hash)                          },
{ .module = NULL,     .name = "getenv",            .value = BUILTIN(builtin_getenv)                        },
{ .module = NULL,     .name = "setenv",            .value = BUILTIN(builtin_setenv)                        },
{ .module = "math",   .name = "log2",              .value = BUILTIN(builtin_log2)                          },
{ .module = "math",   .name = "log",               .value = BUILTIN(builtin_log)                           },
{ .module = "math",   .name = "exp",               .value = BUILTIN(builtin_exp)                           },
{ .module = "math",   .name = "pow",               .value = BUILTIN(builtin_pow)                           },
{ .module = "math",   .name = "asin",              .value = BUILTIN(builtin_asin)                          },
{ .module = "math",   .name = "acos",              .value = BUILTIN(builtin_acos)                          },
{ .module = "math",   .name = "atan",              .value = BUILTIN(builtin_atan)                          },
{ .module = "math",   .name = "atan2",             .value = BUILTIN(builtin_atan2)                         },
{ .module = "math",   .name = "sin",               .value = BUILTIN(builtin_sin)                           },
{ .module = "math",   .name = "cos",               .value = BUILTIN(builtin_cos)                           },
{ .module = "math",   .name = "tan",               .value = BUILTIN(builtin_tan)                           },
{ .module = "math",   .name = "sqrt",              .value = BUILTIN(builtin_sqrt)                          },
{ .module = "math",   .name = "cbrt",              .value = BUILTIN(builtin_cbrt)                          },
{ .module = "math",   .name = "PI",                .value = FLOAT(3.1415926535f)                           },
{ .module = "bit",    .name = "and",               .value = BUILTIN(builtin_bit_and)                       },
{ .module = "bit",    .name = "or",                .value = BUILTIN(builtin_bit_or)                        },
{ .module = "bit",    .name = "xor",               .value = BUILTIN(builtin_bit_xor)                       },
{ .module = "bit",    .name = "complement",        .value = BUILTIN(builtin_bit_complement)                },
{ .module = "bit",    .name = "shiftLeft",         .value = BUILTIN(builtin_bit_shift_left)                },
{ .module = "bit",    .name = "shiftRight",        .value = BUILTIN(builtin_bit_shift_right)               },
{ .module = "os",     .name = "open",              .value = BUILTIN(builtin_os_open)                       },
{ .module = "os",     .name = "close",             .value = BUILTIN(builtin_os_close)                      },
{ .module = "os",     .name = "read",              .value = BUILTIN(builtin_os_read)                       },
{ .module = "os",     .name = "write",             .value = BUILTIN(builtin_os_write)                      },
{ .module = "os",     .name = "listdir",           .value = BUILTIN(builtin_os_listdir)                    },
{ .module = "os",     .name = "fcntl",             .value = BUILTIN(builtin_os_fcntl)                      },
{ .module = "os",     .name = "spawn",             .value = BUILTIN(builtin_os_spawn)                      },
{ .module = "os",     .name = "stat",              .value = BUILTIN(builtin_os_stat)                       },
{ .module = "os",     .name = "fork",              .value = BUILTIN(builtin_os_fork)                       },
{ .module = "os",     .name = "pipe",              .value = BUILTIN(builtin_os_pipe)                       },
{ .module = "os",     .name = "dup2",              .value = BUILTIN(builtin_os_dup2)                       },
{ .module = "os",     .name = "poll",              .value = BUILTIN(builtin_os_poll)                       },
{ .module = "os",     .name = "kill",              .value = BUILTIN(builtin_os_kill)                       },
{ .module = "os",     .name = "exit",              .value = BUILTIN(builtin_os_exit)                       },
{ .module = "os",     .name = "exec",              .value = BUILTIN(builtin_os_exec)                       },
{ .module = "os",     .name = "utime",             .value = BUILTIN(builtin_os_utime)                      },
{ .module = "os",     .name = "getpid",            .value = BUILTIN(builtin_os_getpid)                     },
{ .module = "os",     .name = "getppid",           .value = BUILTIN(builtin_os_getppid)                    },
{ .module = "os",     .name = "getuid",            .value = BUILTIN(builtin_os_getuid)                     },
{ .module = "os",     .name = "geteuid",           .value = BUILTIN(builtin_os_geteuid)                    },
{ .module = "os",     .name = "getgid",            .value = BUILTIN(builtin_os_getgid)                     },
{ .module = "os",     .name = "getegid",           .value = BUILTIN(builtin_os_getegid)                    },
{ .module = "os",     .name = "setuid",            .value = BUILTIN(builtin_os_setuid)                     },
{ .module = "os",     .name = "seteuid",           .value = BUILTIN(builtin_os_seteuid)                    },
{ .module = "os",     .name = "setgid",            .value = BUILTIN(builtin_os_setgid)                     },
{ .module = "os",     .name = "setegid",           .value = BUILTIN(builtin_os_setegid)                    },
{ .module = "os",     .name = "waitpid",           .value = BUILTIN(builtin_os_waitpid)                    },
{ .module = "os",     .name = "WIFSTOPPED",        .value = BUILTIN(builtin_os_WIFSTOPPED)                 },
{ .module = "os",     .name = "WIFEXITED",         .value = BUILTIN(builtin_os_WIFEXITED)                  },
{ .module = "os",     .name = "WEXITSTATUS",       .value = BUILTIN(builtin_os_WEXITSTATUS)                },
{ .module = "os",     .name = "WIFSIGNALED",       .value = BUILTIN(builtin_os_WIFSIGNALED)                },
{ .module = "os",     .name = "WTERMSIG",          .value = BUILTIN(builtin_os_WTERMSIG)                   },
{ .module = "os",     .name = "WSTOPSIG",          .value = BUILTIN(builtin_os_WSTOPSIG)                   },
#ifdef WCOREDUMP
{ .module = "os",     .name = "WCOREDUMP",         .value = BUILTIN(builtin_os_WCOREDUMP)                  },
#endif
#ifdef WIFCONTINUED
{ .module = "os",     .name = "WIFCONTINUED",      .value = BUILTIN(builtin_os_WIFCONTINUED)               },
#endif
{ .module = "os",     .name = "connect",           .value = BUILTIN(builtin_os_connect)                    },
{ .module = "os",     .name = "usleep",            .value = BUILTIN(builtin_os_usleep)                     },
{ .module = "os",     .name = "POLLIN",            .value = INT(POLLIN)                                    },
{ .module = "os",     .name = "POLLOUT",           .value = INT(POLLOUT)                                   },
{ .module = "os",     .name = "POLLHUP",           .value = INT(POLLHUP)                                   },
{ .module = "os",     .name = "POLLERR",           .value = INT(POLLERR)                                   },
{ .module = "os",     .name = "POLLNVAL",          .value = INT(POLLNVAL)                                  },
{ .module = "os",     .name = "O_RDWR",            .value = INT(O_RDWR)                                    },
{ .module = "os",     .name = "O_CREAT",           .value = INT(O_CREAT)                                   },
{ .module = "os",     .name = "O_RDONLY",          .value = INT(O_RDONLY)                                  },
{ .module = "os",     .name = "O_WRONLY",          .value = INT(O_WRONLY)                                  },
{ .module = "os",     .name = "O_TRUNC",           .value = INT(O_TRUNC)                                   },
{ .module = "os",     .name = "O_APPEND",          .value = INT(O_APPEND)                                  },
{ .module = "os",     .name = "O_NONBLOCK",        .value = INT(O_NONBLOCK)                                },
#ifdef WNOHANG
{ .module = "os",     .name = "WNOHANG",           .value = INT(WNOHANG)                                   },
#endif
#ifdef WUNTRACED
{ .module = "os",     .name = "WUNTRACED",         .value = INT(WUNTRACED)                                 },
#endif
#ifdef WCONTINUED
{ .module = "os",     .name = "WCONTINUED",        .value = INT(WCONTINUED)                                },
#endif
{ .module = "os",     .name = "F_SETFD",           .value = INT(F_SETFD)                                   },
{ .module = "os",     .name = "F_GETFD",           .value = INT(F_GETFD)                                   },
{ .module = "os",     .name = "F_GETFL",           .value = INT(F_GETFL)                                   },
{ .module = "os",     .name = "F_SETFL",           .value = INT(F_SETFL)                                   },
{ .module = "os",     .name = "F_DUPFD",           .value = INT(F_DUPFD)                                   },
#ifdef __APPLE__
{ .module = "os",     .name = "F_DUPFD_CLOEXEC",   .value = INT(F_DUPFD_CLOEXEC)                           },
{ .module = "os",     .name = "F_GETOWN",          .value = INT(F_GETOWN)                                  },
{ .module = "os",     .name = "F_SETOWN",          .value = INT(F_SETOWN)                                  },
{ .module = "os",     .name = "F_GETPATH",         .value = INT(F_GETPATH)                                 },
{ .module = "os",     .name = "F_PREALLOCATE",     .value = INT(F_PREALLOCATE)                             },
{ .module = "os",     .name = "F_SETSIZE",         .value = INT(F_SETSIZE)                                 },
{ .module = "os",     .name = "F_RDADVISE",        .value = INT(F_RDADVISE)                                },
{ .module = "os",     .name = "F_RDAHEAD",         .value = INT(F_RDAHEAD)                                 },
{ .module = "os",     .name = "F_NOCACHE",         .value = INT(F_NOCACHE)                                 },
{ .module = "os",     .name = "F_LOG2PHYS",        .value = INT(F_LOG2PHYS)                                },
{ .module = "os",     .name = "F_LOG2PHYS_EXT",    .value = INT(F_LOG2PHYS_EXT)                            },
{ .module = "os",     .name = "F_FULLFSYNC",       .value = INT(F_FULLFSYNC)                               },
{ .module = "os",     .name = "F_SETNOSIGPIPE",    .value = INT(F_SETNOSIGPIPE)                            },
{ .module = "os",     .name = "F_GETNOSIGPIPE",    .value = INT(F_GETNOSIGPIPE)                            },
#endif
{ .module = "errno",  .name = "get",               .value = BUILTIN(builtin_errno_get)                     },
{ .module = "errno",  .name = "str",               .value = BUILTIN(builtin_errno_str)                     },
{ .module = "errno",  .name = "ENOENT",            .value = INT(ENOENT)                                    },
{ .module = "errno",  .name = "ENOMEM",            .value = INT(ENOMEM)                                    },
{ .module = "errno",  .name = "EINVAL",            .value = INT(EINVAL)                                    },
{ .module = "errno",  .name = "EACCES",            .value = INT(EACCES)                                    },
{ .module = "errno",  .name = "EINTR",             .value = INT(EINTR)                                     },
{ .module = "errno",  .name = "EAGAIN",            .value = INT(EAGAIN)                                    },
{ .module = "errno",  .name = "ENOTDIR",           .value = INT(ENOTDIR)                                   },
{ .module = "errno",  .name = "ENOSPC",            .value = INT(ENOSPC)                                    },
{ .module = "errno",  .name = "EFAULT",            .value = INT(EFAULT)                                    },
{ .module = "errno",  .name = "EPERM",             .value = INT(EPERM)                                     },
{ .module = "json",   .name = "parse",             .value = BUILTIN(builtin_json_parse)                    },

#ifdef SIGHUP
{ .module = "os",      .name = "SIGHUP",                 .value = INT(SIGHUP)                              },
#endif
#ifdef SIGINT
{ .module = "os",      .name = "SIGINT",                 .value = INT(SIGINT)                              },
#endif
#ifdef SIGQUIT
{ .module = "os",      .name = "SIGQUIT",                 .value = INT(SIGQUIT)                              },
#endif
#ifdef SIGILL
{ .module = "os",      .name = "SIGILL",                 .value = INT(SIGILL)                              },
#endif
#ifdef SIGTRAP
{ .module = "os",      .name = "SIGTRAP",                 .value = INT(SIGTRAP)                              },
#endif
#ifdef SIGABRT
{ .module = "os",      .name = "SIGABRT",                 .value = INT(SIGABRT)                              },
#endif
#ifdef SIGEMT
{ .module = "os",      .name = "SIGEMT",                 .value = INT(SIGEMT)                              },
#endif
#ifdef SIGFPE
{ .module = "os",      .name = "SIGFPE",                 .value = INT(SIGFPE)                              },
#endif
#ifdef SIGKILL
{ .module = "os",      .name = "SIGKILL",                 .value = INT(SIGKILL)                              },
#endif
#ifdef SIGBUS
{ .module = "os",      .name = "SIGBUS",                 .value = INT(SIGBUS)                              },
#endif
#ifdef SIGSEGV
{ .module = "os",      .name = "SIGSEGV",                 .value = INT(SIGSEGV)                              },
#endif
#ifdef SIGSYS
{ .module = "os",      .name = "SIGSYS",                 .value = INT(SIGSYS)                              },
#endif
#ifdef SIGPIPE
{ .module = "os",      .name = "SIGPIPE",                 .value = INT(SIGPIPE)                              },
#endif
#ifdef SIGALRM
{ .module = "os",      .name = "SIGALRM",                 .value = INT(SIGALRM)                              },
#endif
#ifdef SIGTERM
{ .module = "os",      .name = "SIGTERM",                 .value = INT(SIGTERM)                              },
#endif
#ifdef SIGURG
{ .module = "os",      .name = "SIGURG",                 .value = INT(SIGURG)                              },
#endif
#ifdef SIGSTOP
{ .module = "os",      .name = "SIGSTOP",                 .value = INT(SIGSTOP)                              },
#endif
#ifdef SIGTSTP
{ .module = "os",      .name = "SIGTSTP",                 .value = INT(SIGTSTP)                              },
#endif
#ifdef SIGCONT
{ .module = "os",      .name = "SIGCONT",                 .value = INT(SIGCONT)                              },
#endif
#ifdef SIGCHLD
{ .module = "os",      .name = "SIGCHLD",                 .value = INT(SIGCHLD)                              },
#endif
#ifdef SIGTTIN
{ .module = "os",      .name = "SIGTTIN",                 .value = INT(SIGTTIN)                              },
#endif
#ifdef SIGTTOU
{ .module = "os",      .name = "SIGTTOU",                 .value = INT(SIGTTOU)                              },
#endif
#ifdef SIGIO
{ .module = "os",      .name = "SIGIO",                 .value = INT(SIGIO)                              },
#endif
#ifdef SIGXCPU
{ .module = "os",      .name = "SIGXCPU",                 .value = INT(SIGXCPU)                              },
#endif
#ifdef SIGXFSZ
{ .module = "os",      .name = "SIGXFSZ",                 .value = INT(SIGXFSZ)                              },
#endif
#ifdef SIGVTALRM
{ .module = "os",      .name = "SIGVTALRM",                 .value = INT(SIGVTALRM)                              },
#endif
#ifdef SIGPROF
{ .module = "os",      .name = "SIGPROF",                 .value = INT(SIGPROF)                              },
#endif
#ifdef SIGWINCH
{ .module = "os",      .name = "SIGWINCH",                 .value = INT(SIGWINCH)                              },
#endif
#ifdef SIGINFO
{ .module = "os",      .name = "SIGINFO",                 .value = INT(SIGINFO)                              },
#endif
#ifdef SIGUSR1
{ .module = "os",      .name = "SIGUSR1",                 .value = INT(SIGUSR1)                              },
#endif
#ifdef SIGUSR2
{ .module = "os",      .name = "SIGUSR2",                 .value = INT(SIGUSR2)                              },
#endif

#undef INT
#undef FLOAT
#undef BUILTIN

