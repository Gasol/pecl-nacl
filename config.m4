PHP_ARG_WITH(nacl, for nacl support,
[  --with-nacl             Include nacl support])

if test "$PHP_NACL" != "no"; then
  SEARCH_FOR="crypto_stream.h"
  if test -r $PHP_NACL/$SEARCH_FOR; then
    NACL_INCDIR=$PHP_NACL
  else
    SEARCH_PATH="/usr/local/include /usr/include/nacl /usr/include"
    AC_MSG_CHECKING([for nacl headers in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        NACL_INCDIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$NACL_INCDIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the nacl distribution])
  fi

  SEARCH_FOR="libnacl.a"
  if test -r $PHP_NACL/$SEARCH_FOR; then
    NACL_LIBDIR=$PHP_NACL
  else
    SEARCH_PATH="/usr/local/lib /usr/lib"
    AC_MSG_CHECKING([for libnacl.a in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        NACL_LIBDIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$NACL_LIBDIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the nacl distribution])
  fi

  PHP_SUBST(NACL_SHARED_LIBADD)
  PHP_ADD_INCLUDE($NACL_INCDIR)
  PHP_ADD_LIBRARY(nacl, 1, NACL_SHARED_LIBADD)
  PHP_EVAL_LIBLINE([-L$NACL_LIBDIR])

  PHP_NEW_EXTENSION(nacl, nacl.c, $ext_shared)
fi
