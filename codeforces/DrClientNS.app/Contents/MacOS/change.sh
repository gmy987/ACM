#!/bin/sh

APPNAME=drcomauthsvr
FULLPATH=$1/$APPNAME
echo $FULLPATH
chmod 4755 "$FULLPATH"
chown root:admin "$FULLPATH"

echo "YES"
