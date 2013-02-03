PHP_ARG_WITH(nacl, for nacl support,
[  --with-nacl             Include nacl support])

if test "$PHP_NACL" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/crypto_stream.h"
  if test -r $PHP_NACL/$SEARCH_FOR; then
    NACL_DIR=$PHP_NACL
  else
    AC_MSG_CHECKING([for nacl files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        NACL_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$NACL_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the nacl distribution])
  fi

  PHP_SUBST(NACL_SHARED_LIBADD)
  PHP_ADD_INCLUDE($NACL_DIR/include)
  PHP_ADD_LIBRARY(nacl, 1, NACL_SHARED_LIBADD)
  PHP_EVAL_LIBLINE([-L$NACL_DIR/lib])

  PHP_NEW_EXTENSION(nacl, nacl.c, $ext_shared)
fi
