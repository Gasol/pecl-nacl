dnl $Id$
dnl config.m4 for extension nacl

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(nacl, for nacl support,
dnl Make sure that the comment is aligned:
dnl [  --with-nacl             Include nacl support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(nacl, whether to enable nacl support,
dnl Make sure that the comment is aligned:
dnl [  --enable-nacl           Enable nacl support])

if test "$PHP_NACL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-nacl -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/nacl.h"  # you most likely want to change this
  dnl if test -r $PHP_NACL/$SEARCH_FOR; then # path given as parameter
  dnl   NACL_DIR=$PHP_NACL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for nacl files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       NACL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$NACL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the nacl distribution])
  dnl fi

  dnl # --with-nacl -> add include path
  dnl PHP_ADD_INCLUDE($NACL_DIR/include)

  dnl # --with-nacl -> check for lib and symbol presence
  dnl LIBNAME=nacl # you may want to change this
  dnl LIBSYMBOL=nacl # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $NACL_DIR/lib, NACL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_NACLLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong nacl lib version or lib not found])
  dnl ],[
  dnl   -L$NACL_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(NACL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(nacl, nacl.c, $ext_shared)
fi
